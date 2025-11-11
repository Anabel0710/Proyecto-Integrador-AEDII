/**
 * IMPLEMENTACIÓN JUEGO DEL AHORCADO
 * Usa listas enlazadas para el diccionario y algoritmos de búsqueda
 */

#include "ahorcado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void jugarAhorcado(Jugador* jugador) {
    printf("\n🎮 === JUEGO DEL AHORCADO === 🎮\n");
        srand(time(NULL));
    
    // Crear y cargar lista enlazada de palabras
    ListaPalabras* diccionario = crearListaPalabras();
    if (diccionario == NULL) {
        printf("Error: No se pudo crear el diccionario.\n");
        return;
    }
    
    // Cargar palabras desde archivo - CORREGIDA LA RUTA
    if (cargarPalabrasDesdeArchivo(diccionario, "data/palabras.txt") == 0) {
        printf("Error: No hay palabras disponibles.\n");
        liberarListaPalabras(diccionario);
        return;
    }
    
    // Seleccionar dificultad
    int dificultad;
    printf("\nSelecciona la dificultad:\n");
    printf("1. Fácil (palabras cortas)\n");
    printf("2. Media (palabras medianas)\n");
    printf("3. Difícil (palabras largas)\n");
    printf("Opción: ");
    scanf("%d", &dificultad);
    
    if (dificultad < 1 || dificultad > 3) {
        printf("Dificultad inválida. Usando dificultad media.\n");
        dificultad = 2;
    }
    
    // Obtener palabra aleatoria usando la lista enlazada
    NodoPalabra* palabraObjetivo = obtenerPalabraAleatoria(diccionario, dificultad);
    if (palabraObjetivo == NULL) {
        printf("Error: No hay palabras para la dificultad seleccionada.\n");
        liberarListaPalabras(diccionario);
        return;
    }
    
    printf("\n✅ Categoría: %s\n", palabraObjetivo->categoria);
    
    // Variables del juego
    char palabraSecreta[MAX_PALABRA];
    char palabraAdivinada[MAX_PALABRA];
    char letrasUsadas[26] = {0};
    int intentos = 6;
    int letrasAdivinadas = 0;
    int longitud = strlen(palabraObjetivo->palabra);
    
    // Convertir a mayúsculas y preparar palabra adivinada
    for (int i = 0; i < longitud; i++) {
        palabraSecreta[i] = toupper(palabraObjetivo->palabra[i]);
        palabraAdivinada[i] = '_';
    }
    palabraSecreta[longitud] = '\0';
    palabraAdivinada[longitud] = '\0';
    
    // Bucle principal del juego
    while (intentos > 0 && letrasAdivinadas < longitud) {
        printf("\n");
        dibujarAhorcado(6 - intentos);
        printf("\nPalabra: ");
        
        // Mostrar palabra con espacios entre letras
        for (int i = 0; i < longitud; i++) {
            printf("%c ", palabraAdivinada[i]);
        }
        
        printf("\nIntentos restantes: %d\n", intentos);
        
        // Mostrar letras usadas
        printf("Letras usadas: ");
        for (int i = 0; i < 26; i++) {
            if (letrasUsadas[i]) {
                printf("%c ", 'A' + i);
            }
        }
        printf("\n");
        
        // === PARTE QUE FALTABA ===
        // Solicitar letra al jugador
        char letra;
        printf("Ingresa una letra: ");
        scanf(" %c", &letra);
        letra = toupper(letra);
        
        // Validar entrada
        if (letra < 'A' || letra > 'Z') {
            printf("❌ Por favor ingresa una letra válida (A-Z).\n");
            continue;
        }
        
        // Verificar si la letra ya fue usada
        if (letrasUsadas[letra - 'A']) {
            printf("❌ Ya usaste la letra '%c'. Intenta con otra.\n", letra);
            continue;
        }
        
        // Marcar letra como usada
        letrasUsadas[letra - 'A'] = 1;
        
        // ALGORITMO DE BÚSQUEDA: Buscar la letra en la palabra secreta
        int letraEncontrada = 0;
        for (int i = 0; i < longitud; i++) {
            if (palabraSecreta[i] == letra && palabraAdivinada[i] == '_') {
                palabraAdivinada[i] = letra;
                letrasAdivinadas++;
                letraEncontrada = 1;
            }
        }
        
        // Verificar resultado de la búsqueda
        if (letraEncontrada) {
            printf("✅ ¡Bien! La letra '%c' está en la palabra.\n", letra);
        } else {
            intentos--;
            printf("❌ La letra '%c' no está en la palabra.\n", letra);
        }
        
        // Verificar victoria
        if (letrasAdivinadas == longitud) {
            printf("\n🎉 ¡FELICIDADES! ¡GANASTE! 🎉\n");
            printf("La palabra era: %s\n", palabraSecreta);
            
            int puntuacion = calcularPuntuacion(dificultad, intentos);
            printf("Puntuación obtenida: %d puntos\n", puntuacion);
            
            actualizarEstadisticas(jugador, 1, puntuacion);
            break;
        }
    }
    
    // Verificar derrota
    if (intentos == 0) {
        printf("\n💀 ¡PERDISTE! Se te acabaron los intentos.\n");
        printf("La palabra era: %s\n", palabraSecreta);
        dibujarAhorcado(6);  // Dibujo completo del ahorcado
        
        actualizarEstadisticas(jugador, 0, 0);
    }
    
    // Liberar memoria de la lista enlazada
    liberarListaPalabras(diccionario);
}

void dibujarAhorcado(int intentosFallidos) {
    printf("  ____\n");
    printf("  |  |\n");
    
    switch (intentosFallidos) {
        case 0:
            printf("  |\n  |\n  |\n  |\n");
            break;
        case 1:
            printf("  |  O\n  |\n  |\n  |\n");
            break;
        case 2:
            printf("  |  O\n  |  |\n  |\n  |\n");
            break;
        case 3:
            printf("  |  O\n  | /|\n  |\n  |\n");
            break;
        case 4:
            printf("  |  O\n  | /|\\\n  |\n  |\n");
            break;
        case 5:
            printf("  |  O\n  | /|\\\n  | /\n  |\n");
            break;
        case 6:
            printf("  |  O\n  | /|\\\n  | / \\\n  |\n");
            break;
    }
    
    printf("__|________\n");
}

int calcularPuntuacion(int dificultad, int intentosRestantes) {
    int puntosBase = 100;
    
    // Multiplicador por dificultad
    int multiplicadorDificultad = dificultad * 2;
    
    // Bonus por intentos restantes
    int bonusIntentos = intentosRestantes * 10;
    
    return (puntosBase * multiplicadorDificultad) + bonusIntentos;
}