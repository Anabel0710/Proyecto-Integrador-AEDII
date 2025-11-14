/**JUEGO DEL AHORCADO Implementa el juego usando listas enlazadas y algoritmos de busqueda
 */

#ifndef AHORCADO_H
#define AHORCADO_H

#include "tad_jugador.h"
#include "lista_palabras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* Interfaz publica del juego del Ahorcado */

// Juega una partida completa del ahorcado
void jugarAhorcado(Jugador* jugador);

// Muestra el dibujo del ahorcado segun los intentos fallidos
void dibujarAhorcado(int intentosFallidos);

// Calcula la puntuacion basada en la dificultad e intentos
int calcularPuntuacion(int dificultad, int intentosRestantes);

/* IMPLEMENTACIONES COMPLETAS */
void jugarAhorcado(Jugador* jugador) {
	int i;
    printf("\n=== JUEGO DEL AHORCADO === \n");
    
    srand(time(NULL));
    ListaPalabras* diccionario = crearListaPalabras();
    if (diccionario == NULL) return;
    
    if (cargarPalabrasDesdeArchivo(diccionario, "data/palabras.txt") == 0) {
        liberarListaPalabras(diccionario);
        return;
    }
    
    int dificultad;
    printf("\nSelecciona dificultad:\n");
    printf("1. Facil\n2. Media\n3. Dificil\nOpcion: ");
    scanf("%d", &dificultad);
    
    if (dificultad < 1 || dificultad > 3) dificultad = 2;
    
    NodoPalabra* palabraObj = obtenerPalabraAleatoria(diccionario, dificultad);
    if (palabraObj == NULL) {
        printf("No hay palabras para dificultad %d\n", dificultad);
        liberarListaPalabras(diccionario);
        return;
    }
    
    printf("\n Categoria: %s\n", palabraObj->categoria);
    
    char palabraSecreta[MAX_PALABRA];
    char palabraAdivinada[MAX_PALABRA];
    char letrasUsadas[26] = {0};
    int intentos = 6, letrasAdivinadas = 0;
    int longitud = strlen(palabraObj->palabra);
    
    for ( i = 0; i < longitud; i++) {
        palabraSecreta[i] = toupper(palabraObj->palabra[i]);
        palabraAdivinada[i] = '_';
    }
    palabraSecreta[longitud] = '\0';
    palabraAdivinada[longitud] = '\0';
    
    while (intentos > 0 && letrasAdivinadas < longitud) {
        printf("\n");
        dibujarAhorcado(6 - intentos);
        printf("\nPalabra: ");
        for (i = 0; i < longitud; i++) printf("%c ", palabraAdivinada[i]);
        
        printf("\nIntentos: %d\n", intentos);
        printf("Letras usadas: ");
        for ( i = 0; i < 26; i++) {
            if (letrasUsadas[i]) printf("%c ", 'A' + i);
        }
        printf("\n");
        
        char letra;
        printf("Ingresa una letra: ");
        scanf(" %c", &letra);
        letra = toupper(letra);
        
        if (letra < 'A' || letra > 'Z') {
            printf("Letra invalida\n");
            continue;
        }
        
        if (letrasUsadas[letra - 'A']) {
            printf("Ya usaste '%c'\n", letra);
            continue;
        }
        
        letrasUsadas[letra - 'A'] = 1;
        int encontrada = 0;
        
        for (i = 0; i < longitud; i++) {
            if (palabraSecreta[i] == letra && palabraAdivinada[i] == '_') {
                palabraAdivinada[i] = letra;
                letrasAdivinadas++;
                encontrada = 1;
            }
        }
        
        if (encontrada) {
            printf("'%c' esta en la palabra\n", letra);
        } else {
            intentos--;
            printf("'%c' no esta\n", letra);
        }
        
        if (letrasAdivinadas == longitud) {
            printf("\n¡GANASTE! La palabra: %s\n", palabraSecreta);
            int puntuacion = calcularPuntuacion(dificultad, intentos);
            printf("Puntuacion: %d\n", puntuacion);
            actualizarEstadisticas(jugador, 1, puntuacion);
            break;
        }
    }
    
    if (intentos == 0) {
        printf("\n ¡PERDISTE! La palabra: %s\n", palabraSecreta);
        dibujarAhorcado(6);
        actualizarEstadisticas(jugador, 0, 0);
    }
    
    liberarListaPalabras(diccionario);
}

void dibujarAhorcado(int intentosFallidos) {
    printf("  ____\n");
    printf("  |  |\n");
    
    switch (intentosFallidos) {
        case 0: printf("  |\n  |\n  |\n  |\n"); break;
        case 1: printf("  |  O\n  |\n  |\n  |\n"); break;
        case 2: printf("  |  O\n  |  |\n  |\n  |\n"); break;
        case 3: printf("  |  O\n  | /|\n  |\n  |\n"); break;
        case 4: printf("  |  O\n  | /|\\\n  |\n  |\n"); break;
        case 5: printf("  |  O\n  | /|\\\n  | /\n  |\n"); break;
        case 6: printf("  |  O\n  | /|\\\n  | / \\\n  |\n"); break;
    }
    printf("__|________\n");
}

int calcularPuntuacion(int dificultad, int intentosRestantes) {
    return (100 * dificultad * 2) + (intentosRestantes * 10);
}

#endif
