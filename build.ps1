# One-click native build for GoldenSunTheBrokenSealRecomp
param(
    [int]$Jobs = 4,
    [string]$Toolchain = "C:/MYAPPLY/mingw64",
    [string]$SdlRoot = "D:/Project/GameRecomp/_sdl2/SDL2-2.32.8/x86_64-w64-mingw32",
    [switch]$BuildContractTest
)

$ErrorActionPreference = "Stop"
$root = $PSScriptRoot

& "$root/tools/build-host.ps1" -Jobs $Jobs -Toolchain $Toolchain -SdlRoot $SdlRoot -BuildContractTest:$BuildContractTest
