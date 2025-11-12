/**
 * JUEGO DEL TRES EN RAYA
 * Implementa el juego del Tres en Raya con dos modos: solo vs máquina y dos jugadores
 */

#ifndef TRES_EN_RAYA_H
#define TRES_EN_RAYA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 9

typedef char tTablero[MAX];

/* PROTOTIPOS DE FUNCIONES */

// Funciones de utilidad
void limpiarPantalla();
void pausarPantalla();

// Funciones del juego
void iniciarTablero(tTablero pTablero);
void imprimirTablero(tTablero pTablero);
bool casillaOcupada(tTablero pTablero, int casilla);
bool checkGanador(tTablero pTablero);
void turnoIA(tTablero pTablero);

// Modos de juego
void tresEnRayaSolo();
void tresEnRayaDuo();

// Menú del juego
void mostrarMenuModosTresEnRaya();
void jugarTresEnRaya();

/* IMPLEMENTACIONES */

/**
 * Limpia la pantalla de la consola
 */
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/**
 * Pausa la ejecución hasta que el usuario presione ENTER
 */
void pausarPantalla() {
    printf("\nPresione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
}

/**
 * Inicializa el tablero con espacios en blanco
 */
void iniciarTablero(tTablero pTablero) {
    int i;
    for (i = 0; i < MAX; i++) {
        pTablero[i] = ' ';    
    }     
}

/**
 * Imprime el tablero actual en la consola
 */
void imprimirTablero(tTablero pTablero) {
    int i;
    printf("\n=========================\n");
    printf("      Tres en Raya\n");
    printf("=========================\n\n");
    for(i = 0; i < MAX; i += 3) {
        printf("     ---------------\n"); 
        printf("      |%d  |%d  |%d  |\n", i+1, i+2, i+3);  
        printf("      | %c | %c | %c |\n", pTablero[i], pTablero[i+1], pTablero[i+2]); 
        printf("      |   |   |   |\n");
    }  
    printf("     ---------------\n\n");
}

/**
 * Verifica si una casilla está ocupada
 * @return true si la casilla está ocupada, false en caso contrario
 */
bool casillaOcupada(tTablero pTablero, int casilla) {
    return (pTablero[casilla] != ' ');    
}

/**
 * Verifica si hay un ganador en el tablero
 * @return true si hay un ganador, false en caso contrario
 */
bool checkGanador(tTablero pTablero) {
    int i;
    // Verificar filas
    for(i = 0; i < MAX; i += 3) {
        if(pTablero[i] != ' ' && pTablero[i] == pTablero[i+1] && pTablero[i] == pTablero[i+2]) 
            return true;
    }
    // Verificar columnas
    for(i = 0; i < 3; i++) {
        if(pTablero[i] != ' ' && pTablero[i] == pTablero[i+3] && pTablero[i] == pTablero[i+6]) 
            return true;
    }
    // Verificar diagonales
    if(pTablero[0] != ' ' && pTablero[0] == pTablero[4] && pTablero[0] == pTablero[8]) 
        return true;
    if(pTablero[2] != ' ' && pTablero[2] == pTablero[4] && pTablero[2] == pTablero[6]) 
        return true;
    return false;
}

/**
 * Realiza el turno de la IA (movimiento aleatorio)
 */
void turnoIA(tTablero pTablero) {
    int casilla;
    do {
        casilla = rand() % MAX;
    } while (pTablero[casilla] != ' ');
    pTablero[casilla] = 'O';  
}

/**
 * Modo de juego: un jugador vs la máquina
 */
void tresEnRayaSolo() {
    int opc, turno, lecturaCorrecta;
    char jugador = 'X';
    bool hayGanador = false;
    tTablero tablero;
    
    srand(time(NULL));
    iniciarTablero(tablero);
    
    for(turno = 1; turno <= 5; turno++) {
        imprimirTablero(tablero);
        printf("Selecciona una casilla vacia (1-9).\n>");
        
        do {
            lecturaCorrecta = scanf("%d", &opc);
            if (lecturaCorrecta != 1 || opc < 1 || opc > MAX) {
                printf("Entrada invalida, Ingresa nuevamente.\n>");
                while (getchar() != '\n');
                continue;
            }
            if (casillaOcupada(tablero, opc-1)) {
                printf("Casilla ocupada, Selecciona otra.\n>");
                continue;
            }
            break;
        } while(true);
        
        limpiarPantalla();
        tablero[opc-1] = jugador;
        hayGanador = checkGanador(tablero);
        
        if(hayGanador) {
            imprimirTablero(tablero);
            printf("    ¡Gana el jugador! \n\n"); 
            break;                         
        }
        
        if (turno != 5) { 
            turnoIA(tablero);
            hayGanador = checkGanador(tablero);
            if(hayGanador) {
                imprimirTablero(tablero);
                printf("    ¡Gana la maquina! \n\n"); 
                break;
            }
        }                         
    }
    
    if (!hayGanador) {
        imprimirTablero(tablero);
        printf("   Empate, no hay mas movimientos.\n\n");  
    }
    pausarPantalla();
}

/**
 * Modo de juego: dos jugadores en el mismo dispositivo
 */
void tresEnRayaDuo() {
    int opc, turno, lecturaCorrecta;
    char jugador = 'X';
    bool hayGanador = false;
    tTablero tablero;
    
    iniciarTablero(tablero);
    
    for(turno = 1; turno <= MAX; turno++) {
        imprimirTablero(tablero);
        printf("Turno del jugador %c\n", jugador);
        printf("Selecciona una casilla vacia (1-9).\n>");
        
        do {
            lecturaCorrecta = scanf("%d", &opc);
            if (lecturaCorrecta != 1 || opc < 1 || opc > MAX) {
                printf("Entrada invalida, Ingresa nuevamente.\n>");
                while (getchar() != '\n');
                continue;
            }
            if (casillaOcupada(tablero, opc-1)) {
                printf("Casilla ocupada, Selecciona otra.\n>");
                continue;
            }
            break;
        } while(true);
        
        limpiarPantalla();
        tablero[opc-1] = jugador;
        hayGanador = checkGanador(tablero);
        
        if(hayGanador) {
            imprimirTablero(tablero);
            printf("    ¡Gana el jugador %c! \n\n", jugador); 
            break;                         
        }
        
        jugador = (jugador == 'X') ? 'O' : 'X';
    }
    
    if (!hayGanador) {
        imprimirTablero(tablero);
        printf("   Empate, no hay mas movimientos.\n\n");  
    }
    pausarPantalla();
}

/**
 * Muestra el menú de selección de modo de juego
 */
void mostrarMenuModosTresEnRaya() {
    printf("\nSelecciona modo de juego:\n");
    printf("1. Solo vs Máquina\n");
    printf("2. Dos Jugadores\n");
    printf("Opción: ");
}

/**
 * Función principal del juego - Maneja el flujo completo
 */
void jugarTresEnRaya() {
    printf("\n=== TRES EN RAYA ===\n");
    
    int modo;
    mostrarMenuModosTresEnRaya();
    scanf("%d", &modo);
    
    if (modo == 1) {
        printf("\nModo: Solo vs Máquina\n");
        tresEnRayaSolo();
    } else if (modo == 2) {
        printf("\nModo: Dos Jugadores\n");
        tresEnRayaDuo();
    } else {
        printf("\nOpción inválida, volviendo al menú...\n");
        pausarPantalla();
        return;
    }
}

#endif