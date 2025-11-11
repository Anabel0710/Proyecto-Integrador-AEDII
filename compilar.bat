@echo off
chcp 65001 >nul
echo.
echo 🎮 COMPILANDO MINI GAMES HUB...
echo ===============================
echo.

cd /d "C:\Users\2299r\OneDrive\Escritorio\ProyectoIntegrador"

echo 📁 Verificando archivos...
if not exist "headers\tad_jugador.h" (
    echo ❌ ERROR: No se encuentra headers\tad_jugador.h
    echo 💡 Solución: Usar rutas relativas en los includes
    echo    Cambia: #include "tad_jugador.h"
    echo    Por:    #include "../headers/tad_jugador.h"
    pause
    exit /b 1
)

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
    echo 💡 Solución rápida: Editar src/main.c y cambiar includes
    pause
)