# Wrapper delegating to scripts/setup-deps.ps1
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
& (Join-Path $root 'scripts/setup-deps.ps1')
