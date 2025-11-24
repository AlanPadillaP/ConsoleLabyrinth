#include "EnemyManager.h"
#include <fstream>
#include <string>
#include <iostream>

EnemyManager::EnemyManager()

{
    // Puedes inicializar aquí o cargar desde un archivo los enemigos iniciales
}

void EnemyManager::AddEnemy(int x, int y)
{
    enemies.emplace_back(x, y);
}

void EnemyManager::MoveEnemies(int playerX, int playerY, GameMapBaseAbstracta& map)
{
    for (auto& enemy : enemies)
    {
            // Guarda las coordenadas actuales antes de intentar mover
            int oldX = enemy.GetEnemyCellX();
            int oldY = enemy.GetEnemyCellY();

            enemy.Proximity(playerX, playerY);
            if (enemy.Permission())
            {
                enemy.Moving(playerX, playerY, map); // Intenta mover el enemigo basado en la proximidad del jugador
            }
            else
            {
                enemy.MoveRandomly(map); // Mueve el enemigo aleatoriamente si no tiene permiso para moverse hacia el jugador
            }

            // Actualiza la posición del enemigo en el mapa solo si cambió
            int newX = enemy.GetEnemyCellX();
            int newY = enemy.GetEnemyCellY();


            if (oldX != newX || oldY != newY)
            {
                    if (oldX >= 0 && oldX < 40 && oldY >= 0 && oldY < 15)
                    {
                            map.updateCell(oldX, oldY, 0);  // Limpia la posición antigua
                    }

                    map.updateCell(newX, newY, 'X');  // Actualiza la nueva posición

                    enemy.UpdatePosition(newX, newY);  // Actualiza las coordenadas de la última posición del enemigo


                    if (enemy.GetEnemyCellX() == playerX && enemy.GetEnemyCellY() == playerY)
                    {
                            map.onDefeat();
                            break;
                    }
            }
    }

}
void EnemyManager::LoadEnemiesFromFile(const std::string& filename)
{
    ifstream fileEnemies(filename);

    if (!fileEnemies.is_open())
    {
        cerr << "Error: Unable to open file " << filename << endl; // cerr imprime mensajes de error en la consola.
        return;  // se asocia comúnmente con el dispositivo de salida de error estándar.
    }

    int x, y;

    while (fileEnemies >> x >> y) //la operación >> en C++ devuelve un objeto de flujo de entrada (ifstream en este caso)y los
    {   //objetos de flujo de entrada tienen una conversión a bool que se evalúa como false si ha ocurrido un error durante la lectura.

        AddEnemy(x, y);  // Utiliza la función AddEnemy para agregar enemigos al vector
        cout << "Enemy at (" <<x << ", " <<y << ") - "<<endl;

    }

    fileEnemies.close();

}
