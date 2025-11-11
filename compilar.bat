@echo off
chcp 65001 >nul
echo.
echo 🎮 COMPILANDO MINI GAMES HUB...
echo ===============================
echo.

cd /d "C:\Users\2299r\OneDrive\Escritorio\ProyectoIntegrador"

echo 🔨 Compilando con GCC...
gcc -Wall -Wextra -std=c99 -Iheaders -o minigameshub.exe src/main.c src/tad_jugador.c

if %errorlevel% == 0 (
    echo.
    echo ✅ COMPILACIÓN EXITOSA!
    echo 🚀 Ejecutando Mini Games Hub...
    echo ===============================
    echo.
    minigameshub.exe
) else (
    echo.
    echo ❌ ERROR EN COMPILACIÓN
    echo Revisa los mensajes de error arriba
    pause
)