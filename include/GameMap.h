#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "GameMapBaseAbstracta.h"
#include "MapCell.h"
#include "EnemyManager.h"
#include "Player.h"

#include <string>

using namespace std;

class GameMap : public GameMapBaseAbstracta
{


        public:
                bool IsGameOver;

                GameMap();
                MapCell *PlayerCell;
                MapCell *EnemyCell;
                MapCell Cells[15][40];

                virtual void Draw( EnemyManager& enemyManager) override; //const EnemyManager& enemyManager antes de interfaces
                virtual bool GenerateEnemy(MeleeEnemyBaseAbstracta& enemy)override;
                virtual bool isCellBlocked(int x, int y) const override;
                virtual void updateCell(int x, int y, char symbol) override;
                virtual void onDefeat() override;



                void DrawIntro();
                void DrawVictory();
                void DrawDefeat();
                bool SetPlayerCell(Player& player); // Obtiene las cordenadas de player y lo actualiza el mapa
                void LoadMapFromFile(const string& filename);
                bool CheckGameOver(int PlayerX, int PlayerY);
                bool CheckGameOverDefeat(int EnemyX, int EnemyY);








        protected:
                void LoadMapFromFile();
        private:
};

#endif // GAMEMAP_H
