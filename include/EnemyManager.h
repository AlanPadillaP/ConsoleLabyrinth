#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <vector>
#include <string>

#include "MeleeEnemy.h"
#include "GameMapBaseAbstracta.h"


using namespace std;

class EnemyManager
{
        public:

            EnemyManager();
            void AddEnemy(int x, int y);
            void MoveEnemies(int playerX, int playerY, GameMapBaseAbstracta& map);
            void LoadEnemiesFromFile(const std::string& filename);

            vector<MeleeEnemy>& GetEnemies()
            {
                return enemies;
            }

        private:
            vector<MeleeEnemy> enemies; //se declara un vector llamado enemies que almacena objetos de tipo MeleeEnemy
};

#endif // ENEMYMANAGER_H
