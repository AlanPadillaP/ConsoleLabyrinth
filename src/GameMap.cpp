#include "GameMap.h"
#include "EnemyManager.h"


#include <iostream>
#include <fstream>

using namespace std;

GameMap::GameMap()
{
        PlayerCell=NULL;
        EnemyCell=NULL;
        IsGameOver = false;
        LoadMapFromFile("Map.txt");
}

void GameMap::Draw( EnemyManager& enemyManager)
{
    // Dibujar los elementos existentes del mapa
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            if (Cells[i][j].id == 'X')
            {
                cout << 'X'; // Imprimir 'X' para enemigos
            }
            else if (Cells[i][j].id == '4')
            {
                cout << '4'; // Imprimir '4' para el jugador
            }
            else if (Cells[i][j].id == '$')
            {
                cout << '$'; // Imprimir '$' para la meta
            }
            else if (Cells[i][j].id == '1')
            {
                cout << '1'; // Imprimir '1' para colisiones
            }
            else if (Cells[i][j].id == '0')
            {
                cout << '0'; // Imprimir '0' para celdas vacías
            }
            else
            {
                cout << Cells[i][j].id; // Imprimir cualquier otro carácter
            }
        }
        cout << endl;
    }

    // Dibujar los enemigos
    for (auto& enemy : enemyManager.GetEnemies())
    {
        int enemyX = enemy.GetEnemyCellX();
        int enemyY = enemy.GetEnemyCellY();

        cout << "Enemy at (" <<enemy.GetEnemyCellX() << ", " <<enemy.GetEnemyCellY() << ") - "<<endl;
        if (enemyX >= 0 && enemyX < 40 && enemyY >= 0 && enemyY < 15)
        {
                Cells[enemyY][enemyX].id = 'X'; // Dibujar al enemigo en el mapa
        }
    }


}
void GameMap::DrawIntro()
{
        string Line;
        ifstream MyFileIntro("Intro.txt");

        if(MyFileIntro.is_open())
        {
                while(getline(MyFileIntro,Line))
                {
                        cout<<Line<<endl;
                }
                getchar(); // Pausa el contenido hasta que el usuario presione alguna tecla
        }
        else
        {
                cout<<" Fatal Error. Intro could not be loaded "<<endl;
        }
}

void GameMap::DrawVictory()
{
        string Line;
        ifstream MyFileVictory("Victory.txt");

        if(MyFileVictory.is_open())
        {
                while(getline(MyFileVictory,Line))
                {
                        cout<<Line<<endl;
                }
                getchar(); // Pausa el contenido hasta que el usuario presione alguna tecla
        }
        else
        {
                cout<<" Fatal Error. Outro could not be loaded "<<endl;
        }
}

void GameMap::DrawDefeat()
{
        string Line;
        ifstream MyFile("Defeat.txt");

        if(MyFile.is_open())
        {
                while(getline(MyFile,Line))
                {
                        cout<<Line<<endl;
                }
                getchar(); // Pausa el contenido hasta que el usuario presione alguna tecla
        }
        else
        {
                cout<<" Fatal Error. Outro could not be loaded "<<endl;
        }
}

void GameMap::onDefeat()
{
    DrawDefeat();
}

bool GameMap::CheckGameOver(int PlayerX, int PlayerY)
{
    if (Cells[PlayerY][PlayerX].id == '$')
    {
        DrawVictory();
        IsGameOver = true;
        return true;
    }

    return false;
}

bool GameMap::CheckGameOverDefeat(int EnemyX, int EnemyY)
{
    if (Cells[EnemyY][EnemyX].id == '4')
    {
        DrawDefeat();
        IsGameOver = true;
        return true;
    }

    return false;
}


bool GameMap::SetPlayerCell(Player& player)
{
        int PlayerX = player.GetPlayerCellX();
        int PlayerY = player.GetPlayerCellY();

        if (!isCellBlocked(PlayerX, PlayerY))
        {
                CheckGameOver(PlayerX, PlayerY);
                cout << "Player at (" << PlayerX << ", " << PlayerY << ") "<<endl;
                if (PlayerCell != nullptr)
                {
                        updateCell(player.GetLastXPlayer(), player.GetLastYPlayer(), 0);
                }
                updateCell(PlayerX, PlayerY, Player::getSymbol());
                PlayerCell = &Cells[PlayerY][PlayerX];

                return true;
        }
        else
        {
                cout << "Move blocked." << endl;
                return false; // El jugador no puede avanzar a la siguiente celda porque está bloqueada
        }
}

bool GameMap::GenerateEnemy(MeleeEnemyBaseAbstracta& enemy)
{
    // Obtener las coordenadas propuestas nuevas.
    int NewX = enemy.GetEnemyCellX();
    int NewY = enemy.GetEnemyCellY();

    // Coordenadas antiguas antes de actualizar.
    int OldX = enemy.GetLastX();
    int OldY = enemy.GetLastY();

    // Verificar si la nueva posición está dentro de los límites y no está bloqueada.
    if (NewX >= 0 && NewX < 40 && NewY >= 0 && NewY < 15 && !isCellBlocked(NewX, NewY))
    {
        // Limpieza de la posición antigua, asegurando que se hace con las coordenadas antiguas válidas.
        if (OldX >= 0 && OldY >= 0 && OldX < 40 && OldY < 15) {
            updateCell(OldX, OldY, '0');  // Suponiendo '0' es vacío.

        }

        // Actualizar a la nueva posición después de la limpieza.
        updateCell(NewX, NewY, 'X');


        // Ahora sí, actualizamos las coordenadas "Last".
        enemy.UpdatePosition(NewX, NewY);

        CheckGameOverDefeat(NewX, NewY);
        return true;
    }

    return false;
}


void GameMap::LoadMapFromFile(const std::string& filename)
{

        string Line;
        int Row=0;
        ifstream MyFileMap(filename);

        if(MyFileMap.is_open())
        {
                while(getline(MyFileMap,Line))
                {
                        for(size_t i = 0; i<Line.length();i++) // Line.length es una funcion dentro de las variables string para medir el largo de caracteres
                        {
                                if(Line[i]== '0')  // Si Line lee un caracter 0 dentro del archivo FILE metera un 0 en la celda
                                {
                                        Cells[Row][i].id=0; //El id es de tipo char, asi que no se imprimirá cero sino el caracter cuyo código ascii es 0 (el cual es NULL pero es un caracter que no se imprime)
                                }
                                else
                                {
                                        Cells[Row][i].id = Line[i];
                                }
                        }
                        Row++;
                }
        }
        else
        {
                cout<<" Fatal Error. Press ALT + F4 and Run!! "<<endl;
        }

}


bool GameMap::isCellBlocked(int x, int y) const
{
    return Cells[y][x].IsBlocked();
}

void GameMap::updateCell(int x, int y, char symbol)
{
        Cells[y][x].id = symbol;
}



