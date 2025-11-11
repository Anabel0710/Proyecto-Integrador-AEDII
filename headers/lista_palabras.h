/**
 * LISTA ENLAZADA - Diccionario de palabras para el Ahorcado
 * Implementa una lista enlazada simple para gestionar palabras por categorías
 */

#ifndef LISTA_PALABRAS_H
#define LISTA_PALABRAS_H

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

#endif