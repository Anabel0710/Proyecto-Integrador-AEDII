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
- **Juegos clásicos** como Ahorcado, Tres en Raya, y sistemas de adivinanza
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

### 2. Arrays Estáticos para Tableros
**¿Dónde se usa?**
- `tTablero[MAX]` en el juego del Tres en Raya
- Representación del tablero 3x3

**¿Por qué es adecuado?**
- **Acceso directo:** O(1) para cualquier posición del tablero
- **Simplicidad:** Ideal para estructuras de tamaño fijo
- **Eficiencia en memoria:** Sin overhead de punteros

### 3. Árboles Binarios de Búsqueda
**¿Dónde se usa?**
- `ArbolJugadores` para búsqueda eficiente de estadísticas
- Sistema de ranking y puntuaciones

**¿Por qué es adecuado?**
- **Búsqueda eficiente:** O(log n) vs O(n) en listas
- **Orden natural:** Ideal para datos ordenables como nombres
- **Escalabilidad:** Mantiene rendimiento con muchos usuarios

### 4. Algoritmos de Verificación
**¿Dónde se usa?**
- Verificación de patrones ganadores en Tres en Raya
- Búsqueda lineal en arrays para estado del juego

**¿Por qué es adecuado?**
- **Simplicidad:** Algoritmos O(n) para problemas pequeños
- **Claridad:** Código fácil de entender y mantener
- **Eficiencia:** Suficiente para el tamaño del problema

### 5. Sistema de Archivos
**¿Dónde se usa?**
- Persistencia de jugadores en `jugadores.dat` (binario)
- Diccionario de palabras en `palabras.txt` (texto)

**¿Por qué es adecuado?**
- **Persistencia:** Datos conservados entre ejecuciones
- **Eficiencia:** Archivos binarios para datos estructurados
- **Flexibilidad:** Texto plano para configuración

## 🎮 JUEGOS IMPLEMENTADOS

### 🎯 Juego del Ahorcado
**Características:**
- Múltiples niveles de dificultad
- Sistema de categorías de palabras
- Interfaz visual con progresión del ahorcado
- Puntuación basada en dificultad e intentos restantes

**Estructuras utilizadas:**
- Listas enlazadas para gestión de diccionario
- Algoritmos de búsqueda y filtrado
- Sistema de archivos para persistencia

### ⭕ Juego del Tres en Raya
**Características:**
- Dos modos de juego: vs Máquina y Dos Jugadores
- IA básica con movimientos aleatorios
- Detección automática de ganadores y empates
- Sistema de puntuación integrado

**Estructuras utilizadas:**
- Arrays estáticos para representación del tablero
- Algoritmos de verificación de patrones
- Integración con sistema de estadísticas de jugadores

**Modos de Juego:**
1. **Solo vs Máquina:** Juega contra la computadora (IA básica)
2. **Dos Jugadores:** Juego local para dos personas

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

### TAD 2: Tablero Tres en Raya
```c
#define MAX 9
typedef char tTablero[MAX];
```
**Operaciones:** iniciar, imprimir, verificar_ganador, verificar_casilla

## 🚀 Compilación y Ejecución

### Requisitos
- Compilador GCC estándar
- Sistema Windows/Linux/macOS

### Compilación
```bash
# Compilación en Windows
gcc -Wall -Wextra -std=c99 -Iheaders -o minigameshub.exe src/*.c

# Compilación en Linux/macOS
gcc -Wall -Wextra -std=c99 -Iheaders -o minigameshub src/*.c
```

### Ejecución
```bash
# Windows
minigameshub.exe

# Linux/macOS
./minigameshub
```

## 🎯 Estructura del Proyecto

```
MiniGamesHub/
├── headers/
│   ├── tad_jugador.h
│   ├── ahorcado.h
│   ├── tres_en_raya.h
│   └── 
├── src/
│   ├── main.c
|
├── data/
│   ├── palabras.txt
│   └── jugadores.dat
└── README.md
```

## 💾 Sistema de Persistencia

### Jugadores
- **Archivo:** `data/jugadores.dat` (binario)
- **Estructura:** Datos de jugadores con estadísticas
- **Operaciones:** Guardado y carga automática

### Diccionario Ahorcado
- **Archivo:** `data/palabras.txt` (texto)
- **Formato:** `categoria:palabra1,palabra2,palabra3`
- **Categorías:** Animales, Países, Frutas, etc.

## 🏆 Sistema de Puntuación

### Ahorcado
- **Fácil:** 100 puntos base + 10 por intento restante
- **Medio:** 200 puntos base + 10 por intento restante  
- **Difícil:** 300 puntos base + 10 por intento restante

### Tres en Raya
- **Vs Máquina:** 100 puntos por victoria
- **Dos Jugadores:** 50 puntos por victoria (solo jugador X)

## 🔧 Características Técnicas

### Gestión de Memoria
- Asignación y liberación adecuada de memoria
- Prevención de memory leaks
- Manejo robusto de errores

### Interfaz de Usuario
- Menús intuitivos y navegables
- Validación de entradas del usuario
- Feedback claro del estado del juego

### Portabilidad
- Código compatible con Windows, Linux y macOS
- Detección automática del sistema operativo
- Funciones de limpieza de pantalla multiplataforma

## 🎮 Flujo de la Aplicación

1. **Inicio:** Carga de jugadores y datos
2. **Menú Principal:** 
   - Gestión de Jugadores
   - Menú de Juegos
   - Estadísticas
   - Salir
3. **Menú de Juegos:**
   - Ahorcado (con selección de dificultad)
   - Tres en Raya (con selección de modo)
4. **Juego:** Ejecución con seguimiento de estadísticas
5. **Persistencia:** Guardado automático al salir

## 💡 Valor Agregado

### Más Allá de los Requisitos
El proyecto demuestra cómo las estructuras de datos fundamentales pueden combinarse para crear sistemas complejos y funcionales:

- **Integración perfecta** entre diferentes estructuras de datos
- **Sistema modular** que permite agregar nuevos juegos fácilmente
- **Persistencia robusta** que mantiene la experiencia del usuario
- **Interfaz intuitiva** que hace los juegos accesibles

### Aprendizajes Clave
- **Diseño de TADs** para problemas específicos
- **Gestión de memoria** en aplicaciones complejas
- **Integración de módulos** independientes
- **Persistencia de datos** en diferentes formatos

---

**🎓 Proyecto Académico - Algoritmos y Estructuras de Datos II**  