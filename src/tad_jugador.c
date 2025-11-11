#include "../headers/tad_jugador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Implementación de las operaciones del TAD */

Jugador* crearJugador(const char* nombre) {
    // Reservar memoria para el nuevo jugador
    Jugador* nuevo = (Jugador*)malloc(sizeof(Jugador));
    if (nuevo == NULL) return NULL;  // Verificar asignación de memoria
    
    // Inicializar campos del jugador - USANDO strcpy ESTÁNDAR
    strcpy(nuevo->nombre, nombre);
    nuevo->puntuacion_total = 0;
    nuevo->partidas_jugadas = 0;
    nuevo->partidas_ganadas = 0;
    
    return nuevo;
}

void destruirJugador(Jugador* jugador) {
    // Liberar memoria ocupada por el jugador
    free(jugador);
}

void actualizarEstadisticas(Jugador* jugador, int ganada, int puntos) {
    // Incrementar contador de partidas jugadas
    jugador->partidas_jugadas++;
    
    // Si ganó la partida, actualizar contadores
    if (ganada) {
        jugador->partidas_ganadas++;
        jugador->puntuacion_total += puntos;
    }
}

void mostrarJugador(const Jugador* jugador) {
    // Mostrar información formateada del jugador
    printf("=== ESTADISTICAS ===\n");
    printf("Jugador: %s\n", jugador->nombre);
    printf("Puntuacion total: %d\n", jugador->puntuacion_total);
    printf("Partidas jugadas: %d\n", jugador->partidas_jugadas);
    printf("Partidas ganadas: %d\n", jugador->partidas_ganadas);
    
    // Calcular y mostrar porcentaje de victorias
    if (jugador->partidas_jugadas > 0) {
        float porcentaje = (jugador->partidas_ganadas * 100.0f) / jugador->partidas_jugadas;
        printf("Porcentaje victorias: %.2f%%\n", porcentaje);
    }
}

int guardarJugadorBinario(const Jugador* jugador, const char* filename) {
    // Abrir archivo en modo append binary - USANDO fopen ESTÁNDAR
    FILE* archivo = fopen(filename, "ab");
    if (archivo == NULL) return 0;
    
    // Escribir estructura completa en archivo binario
    int resultado = fwrite(jugador, sizeof(Jugador), 1, archivo);
    fclose(archivo);
    return resultado == 1;  // Retorna 1 si se escribió correctamente
}

Jugador* cargarJugadorBinario(const char* filename, const char* nombre) {
    // Abrir archivo en modo read binary - USANDO fopen ESTÁNDAR
    FILE* archivo = fopen(filename, "rb");
    if (archivo == NULL) return NULL;
    
    // Buscar jugador por nombre en el archivo
    Jugador* jugador = (Jugador*)malloc(sizeof(Jugador));
    int encontrado = 0;
    
    // Leer secuencialmente hasta encontrar el jugador
    while (fread(jugador, sizeof(Jugador), 1, archivo)) {
        if (strcmp(jugador->nombre, nombre) == 0) {
            encontrado = 1;
            break;
        }
    }
    
    fclose(archivo);
    
    // Si no se encontró, liberar memoria y retornar NULL
    if (!encontrado) {
        free(jugador);
        return NULL;
    }
    return jugador;
}