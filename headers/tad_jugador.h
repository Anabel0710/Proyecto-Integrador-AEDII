/**
 * TAD JUGADOR - Gestiona la información de los jugadores
 */

#ifndef TAD_JUGADOR_H
#define TAD_JUGADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50

// Estructura que representa un jugador del sistema
typedef struct {
    char nombre[MAX_NOMBRE];           
    int puntuacion_total;             // Puntuación acumulada
    int partidas_jugadas;             // Total de partidas jugadas
    int partidas_ganadas;             
} Jugador;

Jugador* crearJugador(const char* nombre);

// Libera la memoria ocupada por un jugador
void destruirJugador(Jugador* jugador);

// Actualiza las estadísticas después de una partida
void actualizarEstadisticas(Jugador* jugador, int ganada, int puntos);

// Muestra la información del jugador por consola
void mostrarJugador(const Jugador* jugador);

// Guarda un jugador en archivo binario (persistencia)
int guardarJugadorBinario(const Jugador* jugador, const char* filename);

// Carga un jugador desde archivo binario
Jugador* cargarJugadorBinario(const char* filename, const char* nombre);

/* IMPLEMENTACIONES COMPLETAS */
Jugador* crearJugador(const char* nombre) {
    Jugador* nuevo = (Jugador*)malloc(sizeof(Jugador));
    if (nuevo == NULL) return NULL;
    
    strcpy(nuevo->nombre, nombre);
    nuevo->puntuacion_total = 0;
    nuevo->partidas_jugadas = 0;
    nuevo->partidas_ganadas = 0;
    
    return nuevo;
}

void destruirJugador(Jugador* jugador) {
    free(jugador);
}

void actualizarEstadisticas(Jugador* jugador, int ganada, int puntos) {
    jugador->partidas_jugadas++;
    if (ganada) {
        jugador->partidas_ganadas++;
        jugador->puntuacion_total += puntos;
    }
}

void mostrarJugador(const Jugador* jugador) {
    printf("=== ESTADISTICAS ===\n");
    printf("Jugador: %s\n", jugador->nombre);
    printf("Puntuacion total: %d\n", jugador->puntuacion_total);
    printf("Partidas jugadas: %d\n", jugador->partidas_jugadas);
    printf("Partidas ganadas: %d\n", jugador->partidas_ganadas);
    
    if (jugador->partidas_jugadas > 0) {
        float porcentaje = (jugador->partidas_ganadas * 100.0f) / jugador->partidas_jugadas;
        printf("Porcentaje victorias: %.2f%%\n", porcentaje);
    }
}

int guardarJugadorBinario(const Jugador* jugador, const char* filename) {
    FILE* archivo = fopen(filename, "ab");
    if (archivo == NULL) return 0;
    
    int resultado = fwrite(jugador, sizeof(Jugador), 1, archivo);
    fclose(archivo);
    return resultado == 1;
}

Jugador* cargarJugadorBinario(const char* filename, const char* nombre) {
    FILE* archivo = fopen(filename, "rb");
    if (archivo == NULL) return NULL;
    
    Jugador* jugador = (Jugador*)malloc(sizeof(Jugador));
    int encontrado = 0;
    
    while (fread(jugador, sizeof(Jugador), 1, archivo)) {
        if (strcmp(jugador->nombre, nombre) == 0) {
            encontrado = 1;
            break;
        }
    }
    
    fclose(archivo);
    
    if (!encontrado) {
        free(jugador);
        return NULL;
    }
    return jugador;
}

#endif