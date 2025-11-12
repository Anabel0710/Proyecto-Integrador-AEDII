@echo off
chcp 65001 >nul
echo.
echo 🎮 COMPILANDO MINI GAMES HUB...
echo.

cd /d "C:\Users\2299r\OneDrive\Escritorio\ProyectoIntegrador"

gcc -Wall -std=c99 -Iheaders -o minigameshub.exe src/main.c

if %errorlevel% == 0 (
    echo ✅ COMPILACIÓN EXITOSA!
    echo.
    minigameshub.exe
) else (
    echo ❌ ERROR EN COMPILACIÓN
    pause
)