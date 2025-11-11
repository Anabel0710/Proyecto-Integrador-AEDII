/**
 * TAD JUGADOR - Gestiona la información de los jugadores
 */

#ifndef TAD_JUGADOR_H
#define TAD_JUGADOR_H

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

#endif