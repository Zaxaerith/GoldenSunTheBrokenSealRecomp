# Regenerate src/game/ cart code from your legally obtained ROM.
# Usage: .\scripts\generate.ps1 -Rom "path\to\Golden Sun(UE)(Nintendo)(64Mb).gba"
param(
    [Parameter(Mandatory = $true)][string]$Rom,
    [string]$Tool = "",
    [string]$Config = "",
    [string]$Shards = "16"
)

$ErrorActionPreference = "Stop"
$root = Split-Path -Parent $PSScriptRoot
if (-not $Config) { $Config = Join-Path $root "game.toml" }
if (-not (Test-Path $Rom)) { throw "ROM not found: $Rom" }
if (-not (Test-Path $Config)) { throw "Config not found: $Config" }

if (-not $Tool) {
    $candidates = @(
        (Join-Path $root "..\gbarecomp-cli-windows-x86_64\gbarecomp.exe"),
        (Join-Path $root "..\gbarecomp-main\build\Release\gbarecomp.exe"),
        (Join-Path $root "..\gbarecomp-main\build-mingw\gbarecomp.exe"),
        (Join-Path $root "..\gbarecomp-main\build\gbarecomp.exe"),
        (Join-Path $root "reference\gbarecomp\build\gbarecomp.exe")
    )
    foreach ($c in $candidates) {
        if (Test-Path $c) { $Tool = $c; break }
    }
}
if (-not $Tool -or -not (Test-Path $Tool)) {
    throw "gbarecomp executable not found. Build GBARecomp or pass -Tool."
}

$out = Join-Path $root "src\generated"
New-Item -ItemType Directory -Force -Path $out | Out-Null

$symbolsFile = Join-Path $root "symbols\gs_functions.tsv"
$argsList = @(
    "build",
    "--rom", $Rom,
    "--config", $Config,
    "--output", $out,
    "--codegen-shards", $Shards,
    "--force"
)
if (Test-Path $symbolsFile) {
    $argsList += @("--symbols", $symbolsFile)
}

Write-Host "=== Regenerating cart C++ from ROM ===" -ForegroundColor Cyan
Write-Host "ROM    : $Rom"
Write-Host "Config : $Config"
Write-Host "Tool   : $Tool"

& $Tool @argsList
if ($LASTEXITCODE -ne 0) { throw "gbarecomp build failed" }

# Copy nested generated files if present
$nested = Join-Path $out "generated"
if (Test-Path $nested) {
    Copy-Item (Join-Path $nested "*") $out -Force
    Remove-Item $nested -Recurse -Force -ErrorAction SilentlyContinue
}

Write-Host "Splitting into src/game modules with functional names ..." -ForegroundColor Cyan
$py = Get-Command python -ErrorAction SilentlyContinue
if (-not $py) { $py = Get-Command python3 -ErrorAction SilentlyContinue }
if (-not $py) { throw "Python is required to run split_generated.py" }

& $py.Source (Join-Path $root "scripts\split_generated.py") `
    --gen-dir $out `
    --out-dir (Join-Path $root "src\game") `
    --symbols-in $symbolsFile `
    --symbols-out $symbolsFile

if ($LASTEXITCODE -ne 0) { throw "split_generated.py failed" }

Write-Host "src/game/ updated successfully. Rebuild with .\build.ps1" -ForegroundColor Green
