#ifndef GAMEMAPBASEABSTRACTA_H
#define GAMEMAPBASEABSTRACTA_H


#include "MeleeEnemyBaseAbstracta.h"

class EnemyManager;

class GameMapBaseAbstracta
{
        public:

            virtual ~GameMapBaseAbstracta()
            {
            }
            virtual void Draw( EnemyManager& enemyManager)  = 0;
            virtual bool GenerateEnemy(MeleeEnemyBaseAbstracta& enemy) =0;
            virtual bool isCellBlocked(int x, int y) const = 0;
            virtual void updateCell(int x, int y, char symbol) = 0;
            virtual void onDefeat() = 0;

        protected:

        private:
};

#endif // GAMEMAPBASEABSTRACTA_H
