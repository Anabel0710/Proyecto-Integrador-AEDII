/**
 * IMPLEMENTACIÓN LISTA ENLAZADA - Ahorcado
 * Gestiona el diccionario de palabras usando listas enlazadas
 */

#include "../headers/lista_palabras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Implementación de la lista enlazada */

ListaPalabras* crearListaPalabras() {
    ListaPalabras* nuevaLista = (ListaPalabras*)malloc(sizeof(ListaPalabras));
    if (nuevaLista == NULL) return NULL;
    
    nuevaLista->cabeza = NULL;
    nuevaLista->tamaño = 0;
    return nuevaLista;
}

void insertarPalabra(ListaPalabras* lista, const char* palabra, 
                    const char* categoria, int dificultad) {
    // Crear nuevo nodo
    NodoPalabra* nuevoNodo = (NodoPalabra*)malloc(sizeof(NodoPalabra));
    if (nuevoNodo == NULL) return;
    
    // Copiar datos al nuevo nodo
    strcpy(nuevoNodo->palabra, palabra);
    strcpy(nuevoNodo->categoria, categoria);
    nuevoNodo->dificultad = dificultad;
    nuevoNodo->siguiente = NULL;
    
    // Insertar al inicio de la lista (más eficiente)
    if (lista->cabeza == NULL) {
        lista->cabeza = nuevoNodo;
    } else {
        nuevoNodo->siguiente = lista->cabeza;
        lista->cabeza = nuevoNodo;
    }
    
    lista->tamaño++;
}

NodoPalabra* buscarPalabra(const ListaPalabras* lista, const char* palabra) {
    // ALGORITMO DE BÚSQUEDA LINEAL en lista enlazada
    NodoPalabra* actual = lista->cabeza;
    
    while (actual != NULL) {
        // Comparar la palabra buscada con la del nodo actual
        if (strcmp(actual->palabra, palabra) == 0) {
            return actual;  // Palabra encontrada
        }
        actual = actual->siguiente;  // Avanzar al siguiente nodo
    }
    
    return NULL;  // Palabra no encontrada
}

NodoPalabra* obtenerPalabraAleatoria(const ListaPalabras* lista, int dificultad) {
    if (lista->cabeza == NULL) return NULL;
    
    // Contar cuántas palabras hay de la dificultad solicitada
    int contador = 0;
    NodoPalabra* actual = lista->cabeza;
    
    while (actual != NULL) {
        if (actual->dificultad == dificultad) {
            contador++;
        }
        actual = actual->siguiente;
    }
    
    if (contador == 0) return NULL;
    
    // Seleccionar una palabra aleatoria
    int indiceAleatorio = rand() % contador;
    actual = lista->cabeza;
    contador = 0;
    
    while (actual != NULL) {
        if (actual->dificultad == dificultad) {
            if (contador == indiceAleatorio) {
                return actual;
            }
            contador++;
        }
        actual = actual->siguiente;
    }
    
    return NULL;
}

void mostrarListaPalabras(const ListaPalabras* lista) {
    printf("=== DICCIONARIO DE PALABRAS ===\n");
    printf("Total de palabras: %d\n", lista->tamaño);
    
    NodoPalabra* actual = lista->cabeza;
    int contador = 1;
    
    while (actual != NULL) {
        printf("%d. %s [%s] - Dificultad: %d\n", 
               contador, actual->palabra, actual->categoria, actual->dificultad);
        actual = actual->siguiente;
        contador++;
    }
}

void liberarListaPalabras(ListaPalabras* lista) {
    NodoPalabra* actual = lista->cabeza;
    NodoPalabra* siguiente;
    
    // Recorrer la lista liberando cada nodo
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    
    free(lista);
}

int cargarPalabrasDesdeArchivo(ListaPalabras* lista, const char* filename) {
    FILE* archivo = fopen(filename, "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo %s\n", filename);
        return 0;
    }
    
    char palabra[MAX_PALABRA];
    char categoria[MAX_CATEGORIA];
    int dificultad;
    int palabrasCargadas = 0;
    
    // Leer el archivo línea por línea
    while (fscanf(archivo, "%19s %14s %d", palabra, categoria, &dificultad) == 3) {
        insertarPalabra(lista, palabra, categoria, dificultad);
        palabrasCargadas++;
    }
    
    fclose(archivo);
    printf("✅ Cargadas %d palabras desde %s\n", palabrasCargadas, filename);
    return palabrasCargadas;
}