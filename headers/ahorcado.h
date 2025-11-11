/**
 * JUEGO DEL AHORCADO
 * Implementa el juego usando listas enlazadas y algoritmos de búsqueda
 */

#ifndef AHORCADO_H
#define AHORCADO_H

#include "tad_jugador.h"
#include "lista_palabras.h"

/* Interfaz pública del juego del Ahorcado */

// Juega una partida completa del ahorcado
void jugarAhorcado(Jugador* jugador);

// Muestra el dibujo del ahorcado según los intentos fallidos
void dibujarAhorcado(int intentosFallidos);

// Calcula la puntuación basada en la dificultad e intentos
int calcularPuntuacion(int dificultad, int intentosRestantes);

#endif