# Recover pinned framework source and the preserved GS1 compatibility changes.
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$framework = Join-Path $root 'reference/gbarecomp'
$commit = 'd11a36261aa1d9587a225760135d0ddea0f97344'
$armCommit = 'e372f84549b47122affa0816f9e831aa2f2bcd92'
function Check-Exit([string]$action) {
    if ($LASTEXITCODE -ne 0) { throw "$action failed (exit $LASTEXITCODE)." }
}
if (-not (Test-Path -LiteralPath $framework)) {
    New-Item -ItemType Directory -Path (Split-Path -Parent $framework) -Force | Out-Null
    git clone https://github.com/mstan/gbarecomp.git $framework
    Check-Exit 'Framework clone'
    git -C $framework checkout --detach $commit
    Check-Exit 'Framework pin'
    git -C $framework submodule update --init --recursive external/arm-recomp-core
    Check-Exit 'ARM dependency setup'
    $arm = Join-Path $framework 'external/arm-recomp-core'
    git -C $arm fetch origin $armCommit
    Check-Exit 'ARM pinned commit fetch'
    git -C $arm checkout --detach $armCommit
    Check-Exit 'ARM pin'
    git -C $framework apply (Join-Path $root 'patches/gbarecomp-gs1-compat.patch')
    Check-Exit 'GS1 compatibility patch'
}
$actual = (& git -C $framework rev-parse HEAD).Trim()
Check-Exit 'Framework revision check'
if ($actual -ne $commit) { throw "Framework must be pinned to $commit." }
& (Join-Path $PSScriptRoot 'setup_sdl2.ps1')
Write-Host 'Dependencies restored. Regenerate guest/BIOS code before compiling.'
