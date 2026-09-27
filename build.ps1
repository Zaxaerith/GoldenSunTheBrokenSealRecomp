# One-click native build for GoldenSunTheBrokenSealRecomp
param(
    [string]$BuildType = "Release",
    [string]$GbarecompRoot = "",
    [string]$Generator = "Ninja"
)

$ErrorActionPreference = "Stop"
$root = $PSScriptRoot
Set-Location $root

Write-Host "=== Golden Sun: The Broken Seal (GBARecomp) Builder ===" -ForegroundColor Cyan

if (-not $GbarecompRoot) {
    if ($env:GBARECOMP_ROOT) {
        $GbarecompRoot = $env:GBARECOMP_ROOT
    } elseif (Test-Path (Join-Path $root "reference\gbarecomp\CMakeLists.txt")) {
        $GbarecompRoot = (Join-Path $root "reference\gbarecomp")
    } else {
        $GbarecompRoot = (Join-Path (Split-Path -Parent $root) "gbarecomp-main")
    }
}

if (-not (Test-Path (Join-Path $GbarecompRoot "CMakeLists.txt"))) {
    throw "GBARecomp not found at $GbarecompRoot. Clone https://github.com/mstan/gbarecomp (with submodules) or pass -GbarecompRoot."
}

# Auto-detect cmake if not already on PATH
$cmake = Get-Command cmake.exe -ErrorAction SilentlyContinue
if (-not $cmake) {
    $vswhere = Join-Path ${env:ProgramFiles(x86)} "Microsoft Visual Studio\Installer\vswhere.exe"
    if (Test-Path $vswhere) {
        $cmakePath = & $vswhere -latest -products * -find "Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" | Select-Object -First 1
        if ($cmakePath) {
            $env:PATH = (Split-Path $cmakePath) + ";" + $env:PATH
        }
    }
}

$cmakeArgs = @(
    "-S", $root,
    "-B", (Join-Path $root "build"),
    "-G", $Generator,
    "-DCMAKE_BUILD_TYPE=$BuildType",
    "-DGBARECOMP_ROOT=$GbarecompRoot"
)

Write-Host "Configuring CMake with $Generator ..." -ForegroundColor Cyan
cmake @cmakeArgs
if ($LASTEXITCODE -ne 0) { throw "CMake configure failed" }

Write-Host "Building gs1.exe ..." -ForegroundColor Cyan
cmake --build (Join-Path $root "build") --target gs1 --config $BuildType --parallel
if ($LASTEXITCODE -ne 0) { throw "Build failed" }

$exe = Join-Path $root "build\gs1.exe"
Write-Host ""
Write-Host "Build successful!" -ForegroundColor Green
Write-Host "  Executable : $exe"
Write-Host "  Run command: .\build\gs1.exe" -ForegroundColor Yellow
