/*JUEGO DEL MEMORAMA Implementa el juego de memoria con animaciones y niveles progresivos*/

#ifndef MEMORAMA_H
#define MEMORAMA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "tad_jugador.h"
#include "utilidades.h"


// --- ESTRUCTURAS DE DATOS ---
typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

typedef struct ListaEnlazada {
    Nodo* inicio;
    int size;
} ListaEnlazada;

typedef struct Pila {
    int* items;
    int tope;
    int capacidad;
} Pila;

typedef struct Carta {
    int valor;
    int visible;
    int emparejada;
    int x, y;
} Carta;

/* PROTOTIPOS DE FUNCIONES */

// Funciones de animacion
void efectoEscribir(const char* texto, int delay_ms);
void animarCartaVolteo(int numero, int mostrar_valor);
void efectoParEncontrado();
void efectoVictoria(int nivel);

// Funciones lista enlazada
void listaInsertar(ListaEnlazada* lista, int valor);
int* listaGetArray(ListaEnlazada* lista);
void listaLiberar(ListaEnlazada* lista);

// Funciones pila
Pila* pilaCrear(int capacidad);
void pilaApilar(Pila* pila, int valor);
int pilaDesapilar(Pila* pila);
int pilaTamano(Pila* pila);
void pilaVaciar(Pila* pila);
void pilaLiberar(Pila* pila);

// Funciones del juego
void generarValores(int nivel, int** valores, int* total_cartas);
void initTablero(int nivel, Carta** tablero, int* total_cartas, int* intentos, int* aciertos);
void dibujarTableroBonito(Carta* tablero, int total_cartas, int nivel, int intentos, int aciertos);
void activarCartaAnimada(Carta* tablero, int posicion, int total_cartas, int nivel, 
                        int* intentos, int* aciertos, Pila* pila, int* bloqueo);
int verificarVictoria(int aciertos, int total_cartas);
int calcularPuntuacionMemorama(int nivel, int intentos);

// Funcion principal del juego
void jugarMemorama(Jugador* jugador);

/* IMPLEMENTACIONES */

/*Efecto de escritura animada*/
 
void efectoEscribir(const char* texto, int delay_ms) {
    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        printf("%c", texto[i]);
        fflush(stdout);
        Sleep(delay_ms);
    }
}

/*Animacion de volteo de carta */
void animarCartaVolteo(int numero, int mostrar_valor) {
    printf("\nVolteando carta %d: ", numero);
    fflush(stdout);
    
    // Animacion de volteo
    int i;
    for (i = 0; i < 5; i++) {
        printf("|"); fflush(stdout); Sleep(50);
        printf("\b/"); fflush(stdout); Sleep(50);
        printf("\b-"); fflush(stdout); Sleep(50);
        printf("\b\\"); fflush(stdout); Sleep(50);
        printf("\b"); fflush(stdout);
    }
    
    if (mostrar_valor) {
        printf("-> [%d] ", numero);
    } else {
        printf("-> [?] ");
    }
    fflush(stdout);
}

/*Efecto especial cuando se encuentra un par*/
void efectoParEncontrado() {
    printf("\n");
    int i;
    for (i = 0; i < 3; i++) {
        printf("*** PAR ENCONTRADO! ***");
        fflush(stdout);
        Sleep(300);
        printf("\r                      \r");
        fflush(stdout);
        Sleep(300);
    }
    printf("*** PAR ENCONTRADO! ***\n");
}

/* Efecto especial al completar un nivel*/
void efectoVictoria(int nivel) {
    printf("\n");
    int i;
    for (i = 0; i < 5; i++) {
        printf("*** NIVEL %d COMPLETADO! ***", nivel);
        fflush(stdout);
        Sleep(400);
        printf("\r                           \r");
        fflush(stdout);
        Sleep(400);
    }
    printf("*** NIVEL %d COMPLETADO! ***\n", nivel);
}

/*Inserta un valor en la lista enlazada*/
void listaInsertar(ListaEnlazada* lista, int valor) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->valor = valor;
    nuevo_nodo->siguiente = NULL;
    
    if (!lista->inicio) {
        lista->inicio = nuevo_nodo;
    } else {
        Nodo* actual = lista->inicio;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }
    lista->size++;
}

/* Convierte la lista enlazada a un array*/
int* listaGetArray(ListaEnlazada* lista) {
    int* arr = (int*)malloc(lista->size * sizeof(int));
    Nodo* actual = lista->inicio;
    int i = 0;
    
    while (actual) {
        arr[i++] = actual->valor;
        actual = actual->siguiente;
    }
    return arr;
}

/*Libera la memoria de la lista enlazada*/
void listaLiberar(ListaEnlazada* lista) {
    Nodo* actual = lista->inicio;
    while (actual) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    lista->inicio = NULL;
    lista->size = 0;
}

/*Crea una nueva pila*/
Pila* pilaCrear(int capacidad) {
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    pila->items = (int*)malloc(capacidad * sizeof(int));
    pila->tope = -1;
    pila->capacidad = capacidad;
    return pila;
}

/*Apila un valor en la pila*/
void pilaApilar(Pila* pila, int valor) {
    if (pila->tope < pila->capacidad - 1) {
        pila->items[++pila->tope] = valor;
    }
}

/*Desapila un valor de la pila */

int pilaDesapilar(Pila* pila) {
    if (pila->tope >= 0) {
        return pila->items[pila->tope--];
    }
    return -1;
}

/*Obtiene el tamaño de la pila*/
int pilaTamano(Pila* pila) {
    return pila->tope + 1;
}

/* Vacia la pila*/
void pilaVaciar(Pila* pila) {
    pila->tope = -1;
}

/*Libera la memoria de la pila*/
void pilaLiberar(Pila* pila) {
    free(pila->items);
    free(pila);
}

/*Genera los valores para las cartas del nivel*/
void generarValores(int nivel, int** valores, int* total_cartas) {
    int i, j;
    *total_cartas = nivel * 4;
    *valores = (int*)malloc(*total_cartas * sizeof(int));
    
    for (i = 0; i < *total_cartas / 2; i++) {
        (*valores)[i] = i + 1;
        (*valores)[i + *total_cartas / 2] = i + 1;
    }
    
    for (i = 0; i < *total_cartas; i++) {
        j = rand() % *total_cartas;
        int temp = (*valores)[i];
        (*valores)[i] = (*valores)[j];
        (*valores)[j] = temp;
    }
}

/*Inicializa el tablero del juego*/
void initTablero(int nivel, Carta** tablero, int* total_cartas, int* intentos, int* aciertos) {
    int* valores;
    int i;
    generarValores(nivel, &valores, total_cartas);
    
    *tablero = (Carta*)malloc(*total_cartas * sizeof(Carta));
    *intentos = 0;
    *aciertos = 0;
    
    for (i = 0; i < *total_cartas; i++) {
        (*tablero)[i].valor = valores[i];
        (*tablero)[i].visible = 0;
        (*tablero)[i].emparejada = 0;
        (*tablero)[i].x = 0;
        (*tablero)[i].y = 0;
    }
    
    free(valores);
}

/*Dibuja el tablero del juego*/
void dibujarTableroBonito(Carta* tablero, int total_cartas, int nivel, int intentos, int aciertos) {
    limpiarPantalla();
    
    printf("===============================================\n");
    printf("              MEMORAMA - MINIGAMES HUB        \n");
    printf("===============================================\n");
    
    // Estadisticas
    printf("Nivel: %d    ", nivel);
    printf("Intentos: %d    ", intentos);
    printf("Aciertos: %d\n", aciertos);
    printf("===============================================\n\n");
    
    // Calcular disposicion
    int columnas = (total_cartas <= 8) ? 4 : 6;
    
    int i;
    for (i = 0; i < total_cartas; i++) {
        if (i % columnas == 0) printf("\n");
        
        if (tablero[i].emparejada) {
            printf(" [OK%2d] ", tablero[i].valor);
        } else if (tablero[i].visible) {
            printf(" [**%2d] ", tablero[i].valor);
        } else {
            printf(" [%2d] ", i + 1);
        }
    }
    
    printf("\n\n");
    printf("===============================================\n");
    printf("CONTROLES:\n");
    printf("- Numeros 1-%d: Seleccionar carta\n", total_cartas);
    printf("- 0: Reiniciar juego\n");
    printf("- 9: Salir\n");
    printf("===============================================\n");
    
    if (aciertos == total_cartas / 2) {
        printf("\n");
        efectoVictoria(nivel);
        printf("Presiona Enter para continuar...");
    } else {
        printf("\nSelecciona una carta: ");
    }
    fflush(stdout);
}

/* Activa una carta con animacion*/
void activarCartaAnimada(Carta* tablero, int posicion, int total_cartas, int nivel, 
                        int* intentos, int* aciertos, Pila* pila, int* bloqueo) {
    if (*bloqueo) return;
    if (tablero[posicion].visible || tablero[posicion].emparejada) return;
    
    // Animacion de volteo
    animarCartaVolteo(posicion + 1, 0);
    Sleep(200);
    
    tablero[posicion].visible = 1;
    pilaApilar(pila, posicion);
    
    dibujarTableroBonito(tablero, total_cartas, nivel, *intentos, *aciertos);
    
    if (pilaTamano(pila) == 2) {
        *bloqueo = 1;
        (*intentos)++;
        
        int pos1 = pilaDesapilar(pila);
        int pos2 = pilaDesapilar(pila);
        
        printf("\nComparando... ");
        fflush(stdout);
        Sleep(500);
        
        if (tablero[pos1].valor == tablero[pos2].valor) {
            // Acierto
            tablero[pos1].emparejada = 1;
            tablero[pos2].emparejada = 1;
            (*aciertos)++;
            
            efectoParEncontrado();
            Sleep(1000);
            
            *bloqueo = 0;
        } else {
            // Error - mostrar cartas por un momento
            printf("X No coinciden\n");
            fflush(stdout);
            Sleep(1500);
            
            // Voltear de vuelta con animacion
            printf("Volteando cartas de vuelta...");
            fflush(stdout);
            
            int i;
            for (i = 0; i < 3; i++) {
                printf(".");
                fflush(stdout);
                Sleep(300);
            }
            
            tablero[pos1].visible = 0;
            tablero[pos2].visible = 0;
            *bloqueo = 0;
        }
    }
}

/* Verifica si se alcanzo la victoria*/
int verificarVictoria(int aciertos, int total_cartas) {
    return (aciertos == total_cartas / 2);
}

/*Calcula la puntuacion basada en nivel e intentos*/
int calcularPuntuacionMemorama(int nivel, int intentos) {
    int puntuacionBase = nivel * 50;
    int bonus = (nivel * 10) - (intentos / 2);
    return puntuacionBase + (bonus > 0 ? bonus : 0);
}

/*Funcion principal del juego - Maneja el flujo completo*/
void jugarMemorama(Jugador* jugador) {
    printf("\n=== MEMORAMA ===\n");
    
    // Efecto de inicio
    limpiarPantalla();
    printf("Iniciando ");
    efectoEscribir("MEMORAMA", 100);
    printf("\n");
    Sleep(1000);
    
    srand(time(NULL));
    
    int nivel = 1;
    int intentos = 0;
    int aciertos = 0;
    int total_cartas = 0;
    int bloqueo = 0;
    Carta* tablero = NULL;
    Pila* pila = pilaCrear(2);
    int puntuacionTotal = 0;
    
    initTablero(nivel, &tablero, &total_cartas, &intentos, &aciertos);
    
    int ejecutando = 1;
    while (ejecutando) {
        dibujarTableroBonito(tablero, total_cartas, nivel, intentos, aciertos);
        
        if (aciertos == total_cartas / 2) {
            // Nivel completado
            int puntuacionNivel = calcularPuntuacionMemorama(nivel, intentos);
            puntuacionTotal += puntuacionNivel;
            
            printf("\nPuntuacion nivel %d: %d puntos\n", nivel, puntuacionNivel);
            printf("Puntuacion total: %d puntos\n", puntuacionTotal);
            
            getchar(); // Esperar Enter
            limpiarBuffer();
            
            nivel++;
            free(tablero);
            pilaVaciar(pila);
            initTablero(nivel, &tablero, &total_cartas, &intentos, &aciertos);
            bloqueo = 0;
            continue;
        }
        
        int entrada;
        if (scanf("%d", &entrada) != 1) {
            limpiarBuffer();
            continue;
        }
        limpiarBuffer();
        
        if (entrada == 9) {
            ejecutando = 0;
        } else if (entrada == 0) {
            // Reiniciar juego
            free(tablero);
            pilaVaciar(pila);
            nivel = 1;
            puntuacionTotal = 0;
            initTablero(nivel, &tablero, &total_cartas, &intentos, &aciertos);
            bloqueo = 0;
            
            printf("\nReiniciando juego...\n");
            Sleep(1000);
        } else if (entrada >= 1 && entrada <= total_cartas) {
            int posicion = entrada - 1;
            activarCartaAnimada(tablero, posicion, total_cartas, nivel, &intentos, &aciertos, pila, &bloqueo);
        }
    }
    
    // Actualizar estadisticas del jugador
    if (jugador != NULL && puntuacionTotal > 0) {
        printf("\n🏆 Puntuacion final: %d puntos\n", puntuacionTotal);
        actualizarEstadisticas(jugador, 1, puntuacionTotal);
    } else if (jugador != NULL) {
        actualizarEstadisticas(jugador, 0, 0);
    }
    
    // Efecto de salida
    printf("\n\n");
    efectoEscribir("Gracias por jugar Memorama!", 80);
    printf("\n");
    Sleep(1000);
    
    free(tablero);
    pilaLiberar(pila);
    
    pausarPantalla();
}

#endif