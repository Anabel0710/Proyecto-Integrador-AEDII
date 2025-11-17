/**
 * UTILIDADES DEL SISTEMA
 * Funciones auxiliares para todos los juegos
 */

#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #define Sleep(ms) usleep((ms) * 1000)
#endif

/* PROTOTIPOS */
void limpiarPantalla();
void pausarPantalla();
void limpiarBuffer();

/* IMPLEMENTACIONES */

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausarPantalla() {
    printf("\nPresione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

#endif