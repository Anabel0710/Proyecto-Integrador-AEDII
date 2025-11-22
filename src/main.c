#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#include "tad_jugador.h"
#include "lista_palabras.h"
#include "ahorcado.h"
#include "tres_en_raya.h" 
#include "memorama.h"     


void mostrarMenuPrincipal();

int main() {
    Jugador* jugadorActual = NULL;
    char nombre[MAX_NOMBRE];
    int opcion;

    printf("=== MINI GAMES HUB ===\n");
    printf("Sistema de videojuegos en C\n\n");

    printf("Ingresa tu nombre: ");
    scanf("%49s", nombre);

    // Cargar o crear jugador
    jugadorActual = cargarJugadorBinario("jugadores.dat", nombre);
    if (jugadorActual == NULL) {
        printf("Nuevo jugador. Creando perfil...\n");
        jugadorActual = crearJugador(nombre);
    } else {
        printf("¡Bienvenido de nuevo, %s!\n", nombre);
    }

    // Menu principal
    do {
        mostrarMenuPrincipal();
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("\nIniciando Ahorcado...\n");
                jugarAhorcado(jugadorActual);  // Directo del header
                break;
            case 2:
                printf("\nIniciando Tres en Raya...\n");
                jugarTresEnRaya(jugadorActual);  // Directo del header
                break;
            case 3:
                printf("\nIniciando Memorama...\n");
                jugarMemorama(jugadorActual);
                break;
            case 4:
                printf("\n");
                mostrarJugador(jugadorActual);
                break;
            case 0:
                printf("¡Gracias por jugar!\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }

        // Guardar datos
        if (opcion != 0) {
            guardarJugadorBinario(jugadorActual, "jugadores.dat");
        }

    } while(opcion != 0);

    destruirJugador(jugadorActual);
    return 0;
}

void mostrarMenuPrincipal() {
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Ahorcado\n");
    printf("2. Tres en Raya\n");
    printf("3. Memorama\n");
    printf("4. Estadisticas\n");
    printf("0. Salir\n");
    printf("Selecciona: ");
}
