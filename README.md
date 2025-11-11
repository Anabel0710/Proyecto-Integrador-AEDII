```markdown
# 🎮 MiniGames Hub - Juegos Clásicos - Proyecto Integrador

## 👨‍🎓 Integrantes del Grupo
- Gonzalez Rocío Anabel
- Ruidíaz Agustín Gabriel  
- Zalazar Aldana Georgina
- Romero Josefina Belén

## 📚 Materia
Algoritmos y Estructuras de Datos II

## 🎯 Tema y Contexto

### Descripción del Proyecto
MiniGames Hub es una aplicación de consola en C que ofrece una colección de juegos clásicos desarrollados como trabajo práctico para la materia Algoritmos y Estructuras de Datos II. El proyecto surgió de la necesidad de aplicar los conceptos aprendidos en clase a un sistema integrado que demuestre el dominio de estructuras de datos dinámicas.

### Contexto de Desarrollo
El proyecto fue el resultado de un proceso de lluvia de ideas grupal donde consideramos múltiples alternativas:

- **Sistemas de gestión** con inventarios y bases de datos
- **Aplicaciones educativas** con contenido interactivo  
- **Juegos clásicos** como Ahorcado, Memorama, y sistemas de adivinanza
- **Plataformas interactivas** con múltiples minijuegos

Finalmente, optamos por desarrollar MiniGames Hub porque nos permitía:

- Aplicar diversas estructuras de datos en contextos prácticos 
- Crear una experiencia de usuario intuitiva en entorno de consola
- Distribuir el trabajo según las fortalezas de cada integrante
- Demostrar la aplicabilidad de los conceptos teóricos en problemas reales

## 🎯 Objetivo

### Problema que Resuelve
El proyecto aborda la necesidad de demostrar competencia práctica en el uso de estructuras de datos dinámicas. MiniGames Hub muestra cómo las estructuras fundamentales pueden integrarse eficientemente en aplicaciones complejas, resolviendo problemas específicos con las herramientas más adecuadas.

### Objetivos Específicos
- Demostrar la aplicabilidad práctica de las estructuras de datos en C
- Implementar un sistema modular que pueda extenderse con nuevos juegos
- Integrar conocimientos de algoritmos y gestión de memoria
- Crear una experiencia de usuario fluida en entorno de consola
- Aplicar los conceptos de TADs y persistencia de datos

## 🏗️ Decisiones de Diseño

### Elección del Lenguaje y Plataforma
**Lenguaje: C estándar con GCC**

**Justificación:**
- **Requisito académico:** Lenguaje principal de la materia
- **Control de memoria:** Gestión manual para comprender estructuras dinámicas
- **Eficiencia:** Rendimiento óptimo para algoritmos complejos
- **Portabilidad:** Código compilable en múltiples plataformas

**Alternativas consideradas:**
- **C++:** Ofrece POO pero queríamos enfoque en estructuras puras
- **Java:** Demasiado abstracto para los objetivos de aprendizaje
- **Python:** No permite el control de memoria necesario

### Arquitectura del Sistema
**Sistema modular con TADs independientes**

**Justificación:**
- **Separación de responsabilidades:** Cada juego maneja sus propias estructuras
- **Reutilización:** TADs utilizables en múltiples juegos
- **Mantenibilidad:** Código organizado y extensible
- **Pruebas unitarias:** Módulos independientes más fáciles de verificar

## 📊 Estructuras de Datos Implementadas

### 1. Listas Enlazadas
**¿Dónde se usa?**
- `ListaPalabras` en el juego del Ahorcado
- Gestión del diccionario de palabras por categorías

**¿Por qué es adecuado?**
- **Inserción dinámica:** Nuevas palabras sin redimensionamiento
- **Memoria eficiente:** Solo se usa memoria para elementos existentes
- **Flexibilidad:** Fácil agregar/eliminar categorías y palabras

**Alternativas consideradas:**
- **Arrays estáticos:** Descartados por limitación de tamaño
- **Tablas hash:** Excesivo para nuestro volumen de datos

### 2. Pilas (LIFO)
**¿Dónde se usa?**
- `PilaMovimientos` en el juego de Memorama
- Sistema de deshacer/rehacer movimientos

**¿Por qué es adecuado?**
- **Comportamiento natural:** Último movimiento entrado = primero en salir
- **Eficiencia:** Operaciones O(1) para apilar/desapilar
- **Simplicidad:** Ideal para historial de acciones

### 3. Árboles Binarios de Búsqueda
**¿Dónde se usa?**
- `ArbolJugadores` para búsqueda eficiente de estadísticas
- Sistema de ranking y puntuaciones

**¿Por qué es adecuado?**
- **Búsqueda eficiente:** O(log n) vs O(n) en listas
- **Orden natural:** Ideal para datos ordenables como nombres
- **Escalabilidad:** Mantiene rendimiento con muchos usuarios

### 4. Recursividad
**¿Dónde se usa?**
- Recorrido de árboles binarios
- Algoritmos de verificación en Memorama
- Búsqueda en profundidad en estructuras

**¿Por qué es adecuado?**
- **Elegancia:** Código más conciso y legible
- **Natural para árboles:** Coincide con estructura recursiva
- **Problema dividido:** Soluciones más comprensibles

### 5. Algoritmos de Ordenamiento
**¿Dónde se usa?**
- QuickSort para ranking de jugadores
- Ordenamiento de palabras por dificultad

**¿Por qué es adecuado?**
- **Eficiencia:** O(n log n) en caso promedio
- **Versatilidad:** Aplicable a diferentes tipos de datos
- **Estabilidad:** Mantiene orden relativo

### 6. Sistema de Archivos
**¿Dónde se usa?**
- Persistencia de jugadores en `jugadores.dat` (binario)
- Diccionario de palabras en `palabras.txt` (texto)

**¿Por qué es adecuado?**
- **Persistencia:** Datos conservados entre ejecuciones
- **Eficiencia:** Archivos binarios para datos estructurados
- **Flexibilidad:** Texto plano para configuración

## 📦 TADs Implementados

### TAD 1: Jugador
```c
typedef struct {
    char nombre[50];
    int puntuacion_total;
    int partidas_jugadas;
    int partidas_ganadas;
} Jugador;
```
**Operaciones:** crear, destruir, actualizar, mostrar, guardar/cargar

### TAD 2: Carta
```c
typedef struct {
    int id;
    char simbolo;
    int visible;
    int x, y;
} Carta;
```
**Operaciones:** crear, destruir, voltear, comparar

## 🎮 Desarrollo Obtenido

### ✅ Sistema Core Completado

**Arquitectura Principal**
- Menú de navegación intuitivo
- Sistema de gestión de jugadores
- Persistencia automática de datos
- Manejo robusto de errores

**Gestión de Usuarios**
- Identificación por nombre
- Estadísticas individuales
- Ranking global actualizado
- Persistencia en archivos binarios

### ✅ Juego del Ahorcado Completado

**Lógica del Juego**
- Sistema de palabras por categorías
- Múltiples niveles de dificultad
- Interfaz visual con progresión
- Sistema de puntuación inteligente

**Estructuras Utilizadas**
- Listas enlazadas para diccionario
- Algoritmos de búsqueda lineal
- Archivos de texto para palabras

### ✅ Juego de Memorama Completado

**Lógica del Juego**
- Tablero dinámico de cartas
- Sistema de emparejamiento
- Conteo de movimientos
- Puntuación por eficiencia

**Estructuras Utilizadas**
- Pilas para historial de movimientos
- Recursividad para verificación
- TAD Carta para modelado

### 🔄 Sistema de Adivinanza en Desarrollo

**Características Planeadas**
- Árboles binarios para preguntas
- Algoritmos de búsqueda eficiente
- Sistema de aprendizaje adaptativo

## 🚀 Compilación y Ejecución

### Requisitos
- Compilador GCC estándar
- Sistema Windows/Linux

### Compilación
```bash
gcc -Wall -Wextra -std=c99 -Iheaders -o minigameshub.exe \
    src/main.c src/tad_jugador.c src/tad_carta.c \
    src/lista_encadenada.c src/pila_movimientos.c \
    src/arbol_binario.c src/ahorcado.c src/memorama.c
```

### Ejecución
```bash
./minigameshub.exe
```

## 📈 Estructuras de Datos en Acción

### En el Ahorcado:
```c
// Lista enlazada de palabras
typedef struct NodoPalabra {
    char palabra[20];
    char categoria[15];
    struct NodoPalabra* siguiente;
} NodoPalabra;

// Recorrido de lista para búsqueda
NodoPalabra* buscarPalabra(ListaPalabras* lista, const char* palabra) {
    NodoPalabra* actual = lista->cabeza;
    while (actual != NULL) {
        if (strcmp(actual->palabra, palabra) == 0) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}
```

### En el Sistema General:
```c
// Árbol binario para búsqueda eficiente
Jugador* buscarJugador(ArbolJugadores* arbol, const char* nombre) {
    // Implementación de búsqueda binaria
    if (arbol == NULL) return NULL;
    int comparacion = strcmp(nombre, arbol->jugador->nombre);
    if (comparacion == 0) return arbol->jugador;
    if (comparacion < 0) return buscarJugador(arbol->izquierdo, nombre);
    else return buscarJugador(arbol->derecho, nombre);
}
```

## 💡 Impacto y Valor Agregado

### Más Allá de los Requisitos
El proyecto demuestra cómo las estructuras de datos fundamentales pueden combinarse para crear sistemas complejos y funcionales. Cada estructura fue seleccionada específicamente para resolver problemas concretos:

- **Listas enlazadas** para datos dinámicos y frecuentemente modificados
- **Pilas** para comportamientos LIFO naturales
- **Árboles binarios** para búsqueda eficiente en datos ordenados
- **Recursividad** para problemas inherentemente recursivos

### Aprendizaje Integral
Cada integrante aportó desde diferentes perspectivas:

- **Diseño de algoritmos:** Optimización y eficiencia
- **Gestión de memoria:** Prevención de leaks y errores
- **Diseño de TADs:** Abstracción y encapsulamiento
- **Integración:** Ensamblaje de módulos independientes

Esta diversidad enriqueció el proyecto y demostró cómo los fundamentos de algoritmos y estructuras de datos permiten la colaboración efectiva en el desarrollo de software complejo.

---

**🎓 Proyecto Académico - Algoritmos y Estructuras de Datos II**  
*Demostrando dominio práctico de estructuras de datos en C*
```