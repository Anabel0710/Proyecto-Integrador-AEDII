@echo off
chcp 65001 >nul
echo.
echo 🎮 COMPILANDO MINI GAMES HUB...
echo ===============================
echo.

cd /d "C:\Users\2299r\OneDrive\Escritorio\ProyectoIntegrador"

echo 🔨 Compilando con GCC...
gcc -Wall -Wextra -std=c99 -Iheaders -o minigameshub.exe src/main.c src/tad_jugador.c src/lista_palabras.c src/ahorcado.c

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
    echo.
    echo Posibles soluciones:
    echo 1. Verificar que todos los archivos .c y .h existen
    echo 2. Revisar los includes en los archivos .c
    echo 3. Ejecutar desde la carpeta correcta
    echo.
    pause
)