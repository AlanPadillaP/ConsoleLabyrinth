#ifndef PLAYER_H
#define PLAYER_H


class Player
{
        public:


                Player();

                CallInput();
                int GetPlayerCellX();
                int GetPlayerCellY();
                void ResetToSafePosition();
                int GetLastXPlayer();
                int GetLastYPlayer();
                static char getSymbol();

        private:
                int x,y;
                int LastX,LastY;
                static const char Symbol;
};

#endif // PLAYER_H
