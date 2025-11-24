# ConsoleLabyrinth
Juego de laberinto en consola donde un jugador debe evadir enemigos mientras navega a través de un mapa generado desde archivos externos.
---

## 🧩 Descripción general

**ConsoleLabyrinth** es un proyecto escrito en **C++**, ejecutado totalmente en la consola.  
El juego carga mapas, enemigos y pantallas decorativas desde archivos `.txt`, y utiliza un sistema modular basado en clases, herencia y componentes separados en archivos `.h` y `.cpp`.

El objetivo del jugador (representado por el símbolo `4`) es llegar a la meta (símbolo `@`) mientras evita a los enemigos que se desplazan dinámicamente dentro del mapa.

---

## 📂 Estructura del proyecto
```
ConsoleLabyrinth/
├── src/
│ ├── EnemyManager.cpp
│ ├── GameMap.cpp
│ ├── GameMapBaseAbstracta.cpp
│ ├── MapCell.cpp
│ ├── MeleeEnemy.cpp
│ ├── MeleeEnemyBaseAbstracta.cpp
│ ├── Player.cpp
│ └── main.cpp
│
├── include/
│ ├── EnemyManager.h
│ ├── GameMap.h
│ ├── GameMapBaseAbstracta.h
│ ├── MapCell.h
│ ├── MeleeEnemy.h
│ ├── MeleeEnemyBaseAbstracta.h
│ └── Player.h
│
├── assets/
│ ├── Intro.txt
│ ├── Map.txt
│ ├── Map2.txt
│ ├── EnemiesMap1.txt
│ ├── Victory.txt
│ └── Defeat.txt
│ 
│
├── README.md
└── LICENSE 

```
---

## 🕹️ Mecánicas del juego

- **Movimiento del jugador:**  
  Controles de una sola tecla:  


W = arriba
A = izquierda
S = abajo
D = derecha

- **Meta:** Llega al símbolo **$** para ganar.
- **Jugador:** Representado como `4`
- **Enemigos:** se mueven automáticamente:
  - Persecución si hay proximidad con el jugador.
  - Movimiento aleatorio si no pueden seguirlo.
- **Pantallas de estado:**
- `Intro.txt` para menú inicial  
- `Victory.txt` al ganar  
- `Defeat.txt` al perder

---

## 📄 Archivos externos usados por el juego

### `Map.txt`
Mapa principal. Cada carácter representa una celda:
- `1` = muro  
- `0` = camino  (mostrados como espacios vacios en el programa)
- `$` = meta  
- `X` = Enemigo

### `EnemiesMap1.txt`
Archivo con posiciones iniciales de enemigos.  
Formato:
x y
5 1
1 9
11 4
...


### `Intro.txt`, `Victory.txt`, `Defeat.txt`
Dibujos ASCII que el juego muestra en consola.

---

## 🧱 Arquitectura del código

El proyecto está dividido por responsabilidades:

- **MapCell**  
  Maneja cada celda del mapa.
- **GameMapBaseAbstracta**  
  Clase base abstracta para la lectura y representación del mapa.
- **GameMap**  
  Implementación concreta del mapa (lectura de archivos, colisiones, impresión, etc.)
- **Player**  
  Control de movimiento, posición y verificación de victoria.
- **MeleeEnemyBaseAbstracta**  
  Clase abstracta para enemigos.
- **MeleeEnemy**  
  Enemigos que se mueven de acuerdo a proximidad del jugador.
- **EnemyManager**  
  Carga, administra y mueve todos los enemigos del mapa.
- **main.cpp**  
  Punto de entrada, control del flujo del juego.

---

## 🛠️ Cómo compilar

### **Opción 1 — CodeBlocks**
1. Crear un proyecto tipo *Console application*.
2. Agregar todos los `.cpp` del directorio `/src`.
3. Agregar todos los `.h` del directorio `/include`.
4. Asegurarse de que los archivos `.txt` estén en carpeta `assets/` o junto al ejecutable.

### **Opción 2 — g++ (terminal)**
Ejemplo de compilación:

```bash
g++ src/*.cpp -I include -o ConsoleLabyrinth.exe


Ejecutar:
./ConsoleLabyrinth.exe

