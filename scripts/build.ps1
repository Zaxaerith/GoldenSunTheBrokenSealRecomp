# One-click native build for GoldenSunTheBrokenSealRecomp
param(
    [string]$BuildType = "Release",
    [string]$GbarecompRoot = "",
    [string]$Generator = "Ninja"
)

$ErrorActionPreference = "Stop"
$root = Split-Path -Parent $PSScriptRoot
& (Join-Path $root "build.ps1") -BuildType $BuildType -GbarecompRoot $GbarecompRoot -Generator $Generator
