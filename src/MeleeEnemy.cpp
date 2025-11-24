#include "MeleeEnemy.h"

#include <cmath>
#include <cstdlib>  // Para utilizar funciones relacionadas con la generación de números aleatorios
#include <iostream>

using namespace std;



MeleeEnemy::MeleeEnemy()
{
        x=4;
        y=8;
        ProximityX=0;
        ProximityY=0;
}
MeleeEnemy::MeleeEnemy(int X, int Y) : x(X), y(Y), LastX(X), LastY(Y)
{
        ProximityX=0;
        ProximityY=0;
}
void MeleeEnemy::Proximity(int PlayerX,int PlayerY)
{
        ProximityX=(x-PlayerX);// Obtenemos la cercania del Enemigo al Player
        ProximityY=(y-PlayerY);
}


void  MeleeEnemy::Moving(int PlayerX,int PlayerY,  GameMapBaseAbstracta& map)
{

    Proximity(PlayerX, PlayerY);

    if (abs(ProximityX) == 2)
    {
        int new_x = (PlayerX > x) ? x + 1 : x - 1;

        // Verificar si la nueva posición es válida antes de actualizar
        if (!map.isCellBlocked(new_x,y))
        {
            x = new_x;
            UpdatePosition(x,y);
            return;  // Salir para evitar que la lógica de movimiento aleatorio se ejecute después
        }
    }

    if (abs(ProximityY) == 2)
    {
        int new_y = (PlayerY > y) ? y + 1 : y - 1;

        // Verificar si la nueva posición es válida antes de actualizar
        if (!map.isCellBlocked(x,new_y))
        {
            y = new_y;
            UpdatePosition(x,y);
            return;  // Salir para evitar que la lógica de movimiento aleatorio se ejecute después
        }
    }
     // Si no puede seguir al jugador, mover aleatoriamente
    MoveRandomly(map);
    UpdatePosition(x,y);


}

bool MeleeEnemy::Permission()
{
        return (abs(ProximityX) >= 2 || abs(ProximityY) >= 2);
}


bool MeleeEnemy::Damage(int PlayerX,int PlayerY)
{
    if (x == PlayerX && y == PlayerY)
    {
            return true;
    }else
    {
            return false;
    }
}

int MeleeEnemy::GetEnemyCellX() const
{
    return x;
}
int MeleeEnemy::GetEnemyCellY() const
{
    return y;
}

void MeleeEnemy::UpdatePosition(int newX, int newY)
{
    // Primero actualizamos las coordenadas antiguas
    LastX = x;
    LastY = y;

    // Luego actualizamos a las nuevas coordenadas
    x = newX;
    y = newY;

    // Imprimir para depuración

}

int MeleeEnemy::GetLastX() const
{
    return LastX;
}

int MeleeEnemy::GetLastY() const
{
    return LastY;
}

void MeleeEnemy::MoveRandomly(GameMapBaseAbstracta& map)
{
        int randomX;
        int randomY;

        do
        {
                // Generar un número aleatorio entre -1 y 1 para determinar el movimiento en el eje X
                randomX = rand() % 3 - 1;
                int new_x = x + randomX;

                // Verificar si la nueva posición es válida antes de actualizar
                if (!map.isCellBlocked(new_x,y))
                {
                        x = new_x;
                        UpdatePosition(x,y);
                }

                // Generar un número aleatorio entre -1 y 1 para determinar el movimiento en el eje Y
                randomY = rand() % 3 - 1;
                int new_y = y + randomY;

                // Verificar si la nueva posición es válida antes de actualizar
                if (!map.isCellBlocked(x,new_y))
                {
                        y = new_y;
                        UpdatePosition(x,y);
                }

        } while (randomX == 0 && randomY == 0);
}

