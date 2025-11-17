# 🎮 MiniGames Hub - Juegos Clasicos - Proyecto Integrador

## 👨‍🎓 Integrantes del Grupo
- Gonzalez Rocio Anabel
- Ruidiaz Agustin Gabriel  
- Zalazar Aldana Georgina
- Romero Josefina Belen

## 📚 Materia
Algoritmos y Estructuras de Datos II

## 🎯 Tema y Contexto

### Descripcion del Proyecto
MiniGames Hub es una aplicacion de consola en C que ofrece una coleccion de juegos clasicos desarrollados como trabajo practico para la materia Algoritmos y Estructuras de Datos II. El proyecto surgio de la necesidad de aplicar los conceptos aprendidos en clase a un sistema integrado que demuestre el dominio de estructuras de datos dinamicas.

### Contexto de Desarrollo
El proyecto fue el resultado de un proceso de lluvia de ideas grupal donde consideramos multiples alternativas:

- **Sistemas de gestion** con inventarios y bases de datos
- **Aplicaciones educativas** con contenido interactivo  
- **Juegos clasicos** como Ahorcado, Tres en Raya, y sistemas de adivinanza
- **Plataformas interactivas** con multiples minijuegos

Finalmente, optamos por desarrollar MiniGames Hub porque nos permitia:

- Aplicar diversas estructuras de datos en contextos practicos 
- Crear una experiencia de usuario intuitiva en entorno de consola
- Distribuir el trabajo segun las fortalezas de cada integrante
- Demostrar la aplicabilidad de los conceptos teoricos en problemas reales

## 🎯 Objetivo

### Problema que Resuelve
El proyecto aborda la necesidad de demostrar competencia practica en el uso de estructuras de datos dinamicas. MiniGames Hub muestra como las estructuras fundamentales pueden integrarse eficientemente en aplicaciones complejas, resolviendo problemas especificos con las herramientas mas adecuadas.

### Objetivos Especificos
- Implementar al menos 3 estructuras de datos dinamicas diferentes
- Desarrollar TADs para modelar las entidades del sistema
- Aplicar tecnicas de persistencia mediante archivos
- Integrar algoritmos de busqueda y verificacion
- Demostrar gestion eficiente de memoria en C

## 🏗️ Decisiones de Diseño

### Eleccion del Lenguaje y Plataforma
**Lenguaje: C estandar con GCC**

**Justificacion:**
- **Requisito academico:** Lenguaje principal de la materia
- **Control de memoria:** Gestion manual para comprender estructuras dinamicas
- **Eficiencia:** Rendimiento optimo para algoritmos complejos
- **Portabilidad:** Codigo compilable en multiples plataformas

**Alternativas consideradas:**
- **C++:** Ofrece POO pero queriamos enfoque en estructuras puras
- **Java:** Demasiado abstracto para los objetivos de aprendizaje
- **Python:** No permite el control de memoria necesario

### Arquitectura del Sistema
**Sistema modular con TADs independientes**

**Justificacion:**
- **Separacion de responsabilidades:** Cada juego maneja sus propias estructuras
- **Reutilizacion:** TADs utilizables en multiples juegos
- **Mantenibilidad:** Codigo organizado y extensible
- **Pruebas unitarias:** Modulos independientes mas faciles de verificar

## 📊 Estructuras de Datos Implementadas

### Listas Enlazadas 
**¿Donde se usa?**
- `ListaPalabras` en el juego del Ahorcado
- Gestion del diccionario de palabras por categorias
- Secuencia de cartas en el Memorama

**¿Por que es adecuado?**
- **Insercion dinamica:** Nuevos elementos sin redimensionamiento
- **Memoria eficiente:** Solo se usa memoria para elementos existentes
- **Flexibilidad:** Facil agregar/eliminar elementos
- **Complejidad:** aceptable para nuestro volumen

**Alternativas consideradas:**
- **Arrays estaticos:** Descartados por limitacion de tamaño
- **Tablas hash:** Excesivo para nuestro volumen de datos

### Pilas - LIFO 
**¿Donde se usa?**
- `PilaMovimientos` en el juego de Memorama
- Control del historial de movimientos
- Gestion de estados temporales del juego

**¿Por que es adecuado?**
- **Comportamiento natural:** Ultimo movimiento entrado = primero en salir
- **Eficiencia:** Operaciones para apilar/desapilar
- **Simplicidad:** Ideal para historial de acciones
- **Adecuacion:** Coincide con el flujo LIFO del juego

**Alternativas consideradas:**
- **Colas FIFO:** No se adapta al comportamiento deseado
- **Listas enlazadas:** Mayor complejidad para operaciones simples

### Archivos 
**¿Donde se usa?**
- Persistencia de jugadores en `jugadores.dat` (binario)
- Diccionario de palabras en `palabras.txt` (texto)
- Sistema de configuracion y datos del juego

**¿Por que es adecuado?**
- **Persistencia:** Datos conservados entre ejecuciones
- **Eficiencia:** Archivos binarios para datos estructurados
- **Flexibilidad:** Texto plano para configuracion
- **Portabilidad:** Formatos estandar multiplataforma

### Algoritmos de Busqueda 
**¿Donde se usa?**
- Busqueda lineal en listas de palabras (Ahorcado)
- Verificacion de patrones ganadores (Tres en Raya)
- Localizacion de cartas emparejadas (Memorama)

**¿Por que es adecuado?**
- **Simplicidad:** Algoritmo O(n) para problemas pequeños
- **Claridad:** Codigo facil de entender y mantener
- **Eficiencia:** Suficiente para el tamaño del problema

### Arrays Estaticos
**¿Donde se usa?**
- `tTablero[MAX]` en el juego del Tres en Raya
- Representacion del tablero 3x3 de tamaño fijo

**¿Por que es adecuado?**
- **Acceso directo:** O(1) para cualquier posicion
- **Simplicidad:** Ideal para estructuras de tamaño fijo
- **Eficiencia en memoria:** Sin overhead de punteros
- **Predictibilidad:** Tamaño conocido en tiempo de compilacion

## 🎮 JUEGOS IMPLEMENTADOS

### 🎯 Juego del Ahorcado
**Caracteristicas:**
- Multiples niveles de dificultad
- Sistema de categorias de palabras
- Interfaz visual con progresion del ahorcado
- Puntuacion basada en dificultad e intentos restantes

**Estructuras utilizadas:**
- Listas enlazadas para gestion de diccionario
- Algoritmos de busqueda y filtrado
- Sistema de archivos para persistencia

### ⭕ Juego del Tres en Raya
**Caracteristicas:**
- Dos modos de juego: vs Maquina y Dos Jugadores
- IA basica con movimientos aleatorios
- Deteccion automatica de ganadores y empates
- Sistema de puntuacion integrado

**Estructuras utilizadas:**
- Arrays estaticos para representacion del tablero
- Algoritmos de verificacion de patrones
- Integracion con sistema de estadisticas de jugadores

**Modos de Juego:**
1. **Solo vs Maquina:** Juega contra la computadora (IA basica)
2. **Dos Jugadores:** Juego local para dos personas

### 🎴 MEMORAMA
**Caracteristicas:**
- Niveles progresivos con cartas incrementales
- Animaciones y efectos visuales
- Sistema de puntuacion por eficiencia
- Interfaz intuitiva con controles numericos

**Estructuras utilizadas:**
- Listas enlazadas para gestion de cartas
- Pilas (LIFO) para control de movimientos
- Algoritmos de mezcla y distribucion
- Sistema de niveles progresivos

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

**Operaciones implementadas:**
- `crearJugador()`: Constructor del TAD
- `destruirJugador()`: Destructor del TAD  
- `actualizarEstadisticas()`: Modificador de estado
- `mostrarJugador()`: Observador del estado
- `guardarJugadorBinario()`, `cargarJugadorBinario()`: Persistencia

**Justificacion:** Modela la entidad central del sistema, permitiendo el seguimiento de estadisticas entre juegos.

### TAD 2: Carta (Memorama)
```c
typedef struct Carta {
    int valor;
    int visible;
    int emparejada;
    int x, y;
} Carta;
```

**Operaciones implementadas:**
- Manipulacion del estado de visibilidad
- Verificacion de emparejamiento
- Gestion de posicion en tablero

**Justificacion:** Representa la unidad basica del juego Memorama, encapsulando su estado y comportamiento.

### TAD 3: ListaPalabras (Ahorcado)
```c
typedef struct NodoPalabra {
    char palabra[20];
    char categoria[15];
    struct NodoPalabra* siguiente;
} NodoPalabra;

typedef struct {
    NodoPalabra* cabeza;
    int tamaño;
} ListaPalabras;
```

**Operaciones implementadas:**
- `insertarPalabra()`, `eliminarPalabra()`
- `buscarPalabra()`, `obtenerPalabraAleatoria()`
- `cargarDesdeArchivo()`, `liberarLista()`

**Justificacion:** Gestiona el diccionario del Ahorcado mediante lista enlazada.

## 🚀 Compilacion y Ejecucion

### Requisitos
- Compilador GCC estandar
- Sistema Windows/Linux/macOS

### Compilacion
```bash
# Compilacion en Windows
gcc -Wall -Wextra -std=c99 -Iheaders -o minigameshub.exe src/*.c

# Compilacion en Linux/macOS
gcc -Wall -Wextra -std=c99 -Iheaders -o minigameshub src/*.c
```

### Ejecucion
```bash
# Windows
minigameshub.exe

# Linux/macOS
./minigameshub
```

## 📁 Estructura del Proyecto

```
MiniGamesHub/
├── headers/
│   ├── utilidades.h      # Funciones comunes del sistema
│   ├── tad_jugador.h     # TAD para gestion de jugadores
│   ├── lista_palabras.h  # TAD para diccionario del ahorcado
│   ├── ahorcado.h        # Juego completo del ahorcado
│   ├── tres_en_raya.h    # Juego completo del tres en raya
│   └── memorama.h        # Juego completo del memorama
├── src/
│   └── main.c            # Programa principal
├── data/
│   ├── palabras.txt      # Diccionario para ahorcado
│   └── jugadores.dat     # Datos de jugadores (binario)
└── README.md
```

## 💾 Sistema de Persistencia

### Jugadores
- **Archivo:** `data/jugadores.dat` (binario)
- **Estructura:** Datos de jugadores con estadisticas
- **Operaciones:** Guardado y carga automatica

### Diccionario Ahorcado
- **Archivo:** `data/palabras.txt` (texto)
- **Formato:** `categoria:palabra1,palabra2,palabra3`
- **Categorias:** Animales, Paises, Frutas, etc.

## 🏆 Sistema de Puntuacion

### Ahorcado
- **Facil:** 100 puntos base + 10 por intento restante
- **Medio:** 200 puntos base + 10 por intento restante  
- **Dificil:** 300 puntos base + 10 por intento restante

### Tres en Raya
- **Vs Maquina:** 100 puntos por victoria
- **Dos Jugadores:** 50 puntos por victoria (solo jugador X)

### Memorama
- **Base:** 50 puntos por nivel completado
- **Bonus:** Puntos adicionales por eficiencia en intentos

## 🔧 Caracteristicas Tecnicas

### Gestion de Memoria
- Asignacion y liberacion adecuada de memoria
- Prevencion de memory leaks
- Manejo robusto de errores

### Interfaz de Usuario
- Menus intuitivos y navegables
- Validacion de entradas del usuario
- Feedback claro del estado del juego

### Portabilidad
- Codigo compatible con Windows, Linux y macOS
- Deteccion automatica del sistema operativo
- Funciones de limpieza de pantalla multiplataforma

## 🎮 Flujo de la Aplicacion

1. **Inicio:** Carga de jugadores y datos
2. **Menu Principal:** 
   - 1. Ahorcado
   - 2. Tres en Raya
   - 3. Memorama
   - 4. Estadisticas
   - 0. Salir
3. **Ejecucion de Juego:** Con seguimiento de estadisticas
4. **Persistencia:** Guardado automatico al salir

## 💡 Valor Agregado

### Integracion de Conceptos
- Aplicacion practica de estructuras de datos dinamicas
- Implementacion de multiples TADs
- Sistema de persistencia robusto
- Algoritmos de busqueda y verificacion

### Aprendizajes Clave
- **Diseño de TADs** para problemas especificos
- **Gestion de memoria** en aplicaciones complejas
- **Integracion de modulos** independientes
- **Persistencia de datos** en diferentes formatos


### Conclusion
MiniGames Hub demuestra la aplicacion practica de los conceptos que aprendimos durante toda la cursada de Algoritmos y Estructuras de Datos II en un sistema integrado. El proyecto cumple con todos los requisitos tecnicos establecidos y muestra competencia en el uso de estructuras de datos dinamicas, TADs, algoritmos de busqueda, y sistemas de persistencia.

El desarrollo de este proyecto nos ha permitido aplicar los conocimientos teoricos en un contexto practico, fortalecer habilidades de trabajo en equipo y crear un programa funcional que integra múltiples componentes.
---
**🎓 Proyecto Academico - Algoritmos y Estructuras de Datos II**