#include <stdio.h>
#include <stdlib.h>
#include "../headers/tad_jugador.h"
#include "../headers/ahorcado.h"
#include "../headers/memorama.h"
#include "../headers/adivinanza.h"


void mostrarMenuPrincipal();

int main() {
    Jugador* jugadorActual = NULL;
    char nombre[MAX_NOMBRE];
    int opcion;
    
    // Encabezado del sistema
    printf("=== MINI GAMES HUB ===\n");
    printf("Sistema de videojuegos en C - Proyecto Academico\n\n");

    printf("Ingresa tu nombre: ");
    scanf("%49s", nombre);
    
    // Intentar cargar jugador existente o crear uno nuevo
    jugadorActual = cargarJugadorBinario("jugadores.dat", nombre);
    if (jugadorActual == NULL) {
        printf("Nuevo jugador detectado. Creando perfil...\n");
        jugadorActual = crearJugador(nombre);
        if (jugadorActual == NULL) {
            printf("Error: No se pudo crear el jugador.\n");
            return 1;
        }
    } else {
        printf("¡Bienvenido de nuevo, %s!\n", nombre);
    }
    
    // Bucle principal del programa
    do {
        mostrarMenuPrincipal();
        scanf("%d", &opcion);
        
        switch(opcion) {
           case 1:
           printf("\nIniciando Juego del Ahorcado...\n");
           jugarAhorcado(jugadorActual); 
           break;
            case 2:
                printf("\nIniciando Memorama...\n");
                // jugarMemorama(jugadorActual);
                printf("(Próximamente)\n");
                break;
            case 3:
                printf("\nIniciando Adivinanza Matematica...\n");
                // jugarAdivinanza(jugadorActual);
                printf("(Próximamente)\n");
                break;
            case 4:
                printf("\n");
                mostrarJugador(jugadorActual);
                break;
            case 0:
                printf("¡Gracias por jugar! Hasta pronto.\n");
                break;
            default:
                printf("Error: Opcion no valida. Intenta de nuevo.\n");
        }
        
        // Guardar datos después de cada operación (excepto salir)
        if (opcion != 0) {
            if (guardarJugadorBinario(jugadorActual, "jugadores.dat")) {
                printf("Datos guardados correctamente.\n");
            } else {
                printf("Error: No se pudieron guardar los datos.\n");
            }
        }
        
    } while(opcion != 0);
    
    // Liberar recursos antes de salir
    destruirJugador(jugadorActual);
    printf("Programa terminado correctamente.\n");
    
    return 0;
}


void mostrarMenuPrincipal() {
    printf("\n=== MINI GAMES HUB ===\n");
    printf("1. 🧠 Juego del Ahorcado\n");
    printf("2. 🎴 Juego de Memorama\n");
    printf("3. 🔢 Adivinanza Matematica\n");
    printf("4. 📊 Ver Estadisticas\n");
    printf("0. 🚪 Salir\n");
    printf("Selecciona una opcion: ");
}