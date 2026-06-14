param(
    [switch]$Run
)

$ErrorActionPreference = "Stop"

$projectRoot = Split-Path -Parent $PSScriptRoot
$srcDir = Join-Path $projectRoot "src"
$buildDir = Join-Path $projectRoot "build"
$outputFile = Join-Path $buildDir "sistema_irrigacao.exe"

function Add-CompilerCandidate {
    param(
        [System.Collections.ArrayList]$Candidates,
        [string]$CommandName
    )

    $command = Get-Command $CommandName -ErrorAction SilentlyContinue
    if ($command) {
        [void]$Candidates.Add($command.Source)
    }
}

$compilerCandidates = New-Object System.Collections.ArrayList

if ($env:CXX) {
    [void]$compilerCandidates.Add($env:CXX)
}

Add-CompilerCandidate $compilerCandidates "g++"
Add-CompilerCandidate $compilerCandidates "clang++"
Add-CompilerCandidate $compilerCandidates "c++"
Add-CompilerCandidate $compilerCandidates "mingw32-g++"

$devCppCompiler = "C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe"
if (Test-Path -LiteralPath $devCppCompiler) {
    [void]$compilerCandidates.Add($devCppCompiler)
}

$compiler = $compilerCandidates | Select-Object -First 1

if (-not $compiler) {
    Write-Host "No C++ compiler was found." -ForegroundColor Red
    Write-Host "Install MinGW/g++, or set the CXX environment variable with the compiler path."
    exit 1
}

$sourceFiles = Get-ChildItem -Path $srcDir -Recurse -Filter *.cpp |
    Sort-Object FullName |
    ForEach-Object { $_.FullName }

if (-not $sourceFiles) {
    Write-Host "No .cpp files were found in src/." -ForegroundColor Red
    exit 1
}

New-Item -ItemType Directory -Force -Path $buildDir | Out-Null

$compilerArgs = @(
    "-std=c++11",
    "-Wall",
    "-Wextra",
    "-g"
) + $sourceFiles + @(
    "-o",
    $outputFile
)

Write-Host "Compiler: $compiler"
Write-Host "Output:   $outputFile"
Write-Host ""

& $compiler @compilerArgs

if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

Write-Host ""
Write-Host "Build completed." -ForegroundColor Green

if ($Run) {
    Write-Host ""
    Write-Host "Running program..." -ForegroundColor Cyan
    Write-Host ""
    & $outputFile
    exit $LASTEXITCODE
}
