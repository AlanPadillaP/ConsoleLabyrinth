#ifndef MELEEENEMYBASEABSTRACTA_H
#define MELEEENEMYBASEABSTRACTA_H

//#include "GameMapBaseAbstracta.h" // Necesario para la referencia circular

class GameMapBaseAbstracta;

class MeleeEnemyBaseAbstracta
{

        public:
            virtual ~MeleeEnemyBaseAbstracta()
            {
            }
            virtual void MoveRandomly(GameMapBaseAbstracta& map) = 0;
            virtual void Moving(int PlayerX, int PlayerY, GameMapBaseAbstracta& map) = 0;
            virtual int GetEnemyCellX()const =0;
            virtual int GetEnemyCellY()const =0;
            virtual int GetLastX() const = 0;
            virtual int GetLastY() const = 0;
            virtual void UpdatePosition(int x, int y) = 0;

            // Agrega más funciones virtuales puras según sea necesario
};

#endif // MELEEENEMYBASEABSTRACTA_H
