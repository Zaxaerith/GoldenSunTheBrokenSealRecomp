$ErrorActionPreference = 'Stop'
$ProjectRoot = Split-Path -Parent $PSScriptRoot
$DefaultRom = Join-Path $ProjectRoot 'Golden Sun(UE)(Nintendo)(64Mb).gba'
$DefaultBios = Join-Path $ProjectRoot 'gba_bios.bin'
if (-not (Test-Path -LiteralPath $DefaultBios)) {
    $altBios = Join-Path (Split-Path -Parent $ProjectRoot) 'gbarecomp-cli-windows-x86_64\gbabios\gba_bios.bin'
    if (Test-Path -LiteralPath $altBios) { $DefaultBios = $altBios }
}
function Assert-Rom([string]$Path) {
    $resolved = (Resolve-Path -LiteralPath $Path).Path
    $bytes = [IO.File]::ReadAllBytes($resolved)
    if ($bytes.Length -ne 8388608 -or
        [Text.Encoding]::ASCII.GetString($bytes,0xAC,4) -ne 'AGSE' -or
        (Get-FileHash -LiteralPath $resolved -Algorithm SHA1).Hash.ToLower() -ne '5c4695205413df7db52b9a184815a07783999971') {
        throw 'Expected Golden Sun USA/Europe AGSE ROM (8 MiB), SHA1 5c4695205413df7db52b9a184815a07783999971.'
    }
}
function Assert-Bios([string]$Path) {
    $resolved = (Resolve-Path -LiteralPath $Path).Path
    if ((Get-Item -LiteralPath $resolved).Length -ne 16384 -or
        (Get-FileHash -LiteralPath $resolved -Algorithm SHA1).Hash.ToLower() -ne '300c20df6731a33952ded8c436f7f186d25d3492') {
        throw 'Expected user-supplied 16 KiB GBA BIOS, SHA1 300c20df6731a33952ded8c436f7f186d25d3492.'
    }
}
function Invoke-Logged([string]$Program, [string[]]$Arguments, [string]$Log) {
    $ErrorActionPreference = 'Continue'
    & $Program @Arguments *> $Log
    $code = $LASTEXITCODE
    $ErrorActionPreference = 'Stop'
    if ($code -ne 0) { Get-Content -LiteralPath $Log -Tail 35; throw "$Program exited $code; see $Log" }
}
