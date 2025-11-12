/**
 * LISTA ENLAZADA - Diccionario de palabras para el Ahorcado
 * Implementa una lista enlazada simple para gestionar palabras por categorías
 */

#ifndef LISTA_PALABRAS_H
#define LISTA_PALABRAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PALABRA 20
#define MAX_CATEGORIA 15

// Nodo de la lista enlazada
typedef struct NodoPalabra {
    char palabra[MAX_PALABRA];        // Palabra almacenada
    char categoria[MAX_CATEGORIA];    // Categoría de la palabra
    int dificultad;                   // Nivel de dificultad (1-3)
    struct NodoPalabra* siguiente;    // Puntero al siguiente nodo
} NodoPalabra;

// Estructura de la lista enlazada
typedef struct {
    NodoPalabra* cabeza;              // Primer nodo de la lista
    int tamaño;                       // Cantidad de elementos
} ListaPalabras;

// Crea una nueva lista vacía
ListaPalabras* crearListaPalabras();

// Inserta una nueva palabra en la lista
void insertarPalabra(ListaPalabras* lista, const char* palabra, 
                    const char* categoria, int dificultad);

// Busca una palabra específica en la lista
NodoPalabra* buscarPalabra(const ListaPalabras* lista, const char* palabra);

// Obtiene una palabra aleatoria de una dificultad específica
NodoPalabra* obtenerPalabraAleatoria(const ListaPalabras* lista, int dificultad);

// Muestra todas las palabras de la lista (para debugging)
void mostrarListaPalabras(const ListaPalabras* lista);

// Libera toda la memoria utilizada por la lista
void liberarListaPalabras(ListaPalabras* lista);

// Carga palabras desde un archivo de texto
int cargarPalabrasDesdeArchivo(ListaPalabras* lista, const char* filename);

/* IMPLEMENTACIONES COMPLETAS */
ListaPalabras* crearListaPalabras() {
    ListaPalabras* nuevaLista = (ListaPalabras*)malloc(sizeof(ListaPalabras));
    if (nuevaLista == NULL) return NULL;
    
    nuevaLista->cabeza = NULL;
    nuevaLista->tamaño = 0;
    return nuevaLista;
}

void insertarPalabra(ListaPalabras* lista, const char* palabra, const char* categoria, int dificultad) {
    NodoPalabra* nuevoNodo = (NodoPalabra*)malloc(sizeof(NodoPalabra));
    if (nuevoNodo == NULL) return;
    
    strcpy(nuevoNodo->palabra, palabra);
    strcpy(nuevoNodo->categoria, categoria);
    nuevoNodo->dificultad = dificultad;
    nuevoNodo->siguiente = lista->cabeza;
    lista->cabeza = nuevoNodo;
    lista->tamaño++;
}

NodoPalabra* buscarPalabra(const ListaPalabras* lista, const char* palabra) {
    NodoPalabra* actual = lista->cabeza;
    while (actual != NULL) {
        if (strcmp(actual->palabra, palabra) == 0) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

NodoPalabra* obtenerPalabraAleatoria(const ListaPalabras* lista, int dificultad) {
    if (lista->cabeza == NULL) return NULL;
    
    int contador = 0;
    NodoPalabra* actual = lista->cabeza;
    
    while (actual != NULL) {
        if (actual->dificultad == dificultad) contador++;
        actual = actual->siguiente;
    }
    
    if (contador == 0) return NULL;
    
    int indiceAleatorio = rand() % contador;
    actual = lista->cabeza;
    contador = 0;
    
    while (actual != NULL) {
        if (actual->dificultad == dificultad) {
            if (contador == indiceAleatorio) return actual;
            contador++;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

void mostrarListaPalabras(const ListaPalabras* lista) {
    printf("=== DICCIONARIO (%d palabras) ===\n", lista->tamaño);
    NodoPalabra* actual = lista->cabeza;
    int i = 1;
    while (actual != NULL) {
        printf("%d. %s [%s] - Nivel: %d\n", i, actual->palabra, actual->categoria, actual->dificultad);
        actual = actual->siguiente;
        i++;
    }
}

void liberarListaPalabras(ListaPalabras* lista) {
    NodoPalabra* actual = lista->cabeza;
    while (actual != NULL) {
        NodoPalabra* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

int cargarPalabrasDesdeArchivo(ListaPalabras* lista, const char* filename) {
    FILE* archivo = fopen(filename, "r");
    if (archivo == NULL) {
        printf("❌ Error: No se pudo abrir '%s'\n", filename);
        return 0;
    }
    
    char linea[256];
    char palabra[MAX_PALABRA];
    char categoria[MAX_CATEGORIA];
    int dificultad;
    int palabrasCargadas = 0;
    
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (linea[0] == '#' || linea[0] == '\n') continue;
        
        if (sscanf(linea, "%19s %14s %d", palabra, categoria, &dificultad) == 3) {
            insertarPalabra(lista, palabra, categoria, dificultad);
            palabrasCargadas++;
        }
    }
    
    fclose(archivo);
    
    if (palabrasCargadas == 0) {
        printf("❌ No se cargaron palabras de '%s'\n", filename);
    } else {
        printf("✅ Cargadas %d palabras de '%s'\n", palabrasCargadas, filename);
    }
    
    return palabrasCargadas;
}

#endif