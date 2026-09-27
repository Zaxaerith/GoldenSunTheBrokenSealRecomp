# Alias wrapper for generate.ps1
param(
    [Parameter(Mandatory = $true)][string]$Rom,
    [string]$Tool = "",
    [string]$Config = "",
    [string]$Shards = "16"
)

$ErrorActionPreference = "Stop"
$root = Split-Path -Parent $PSScriptRoot
& (Join-Path $root "scripts\generate.ps1") -Rom $Rom -Tool $Tool -Config $Config -Shards $Shards
