#ifndef MELEEENEMY_H
#define MELEEENEMY_H


#include "MeleeEnemyBaseAbstracta.h"
#include "GameMapBaseAbstracta.h"

class MeleeEnemy: public MeleeEnemyBaseAbstracta
{
        public:
                MeleeEnemy(int X,int Y);
                MeleeEnemy();

                virtual void MoveRandomly(GameMapBaseAbstracta& map) override;
                virtual void Moving(int PlayerX, int PlayerY, GameMapBaseAbstracta& map) override;
                void UpdatePosition(int newX, int newY) override;
                int GetEnemyCellX()const override;
                int GetEnemyCellY()const override;

                void Proximity(int PlayerX,int PlayerY);
                bool Permission();
                bool Damage(int PlayerX,int PlayerY);
                int GetLastX() const;
                int GetLastY() const;


        protected:

        private:
                int ProximityX;
                int ProximityY;
                int x ,y ;
                int LastX, LastY;


};

#endif // MELEEENEMY_H
