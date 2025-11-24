#include "Player.h"
#include <iostream>

using namespace std;

const char Player::Symbol = '4';

Player::Player()
{
        x=1;
        y=1;

}

Player::CallInput()
{
        char UserInput=' ';
        cin>>UserInput;

        LastX = x;
        LastY = y;

        switch(UserInput)
        {
                case 'w':

                        y=y-1;
                break;

                case 's':

                        y=y+1;
                break;

                case 'd':

                        x=x+1;
                break;

                case 'a':

                        x=x-1;
                break;
        }

}

int Player::GetPlayerCellX()
{
    return x;
}
int Player::GetPlayerCellY()
{
    return y;
}

void Player::ResetToSafePosition()
{
        x=LastX;
        y=LastY;
}

int Player::GetLastXPlayer()
{
        return LastX;
}
int Player::GetLastYPlayer()
{
        return LastY;
}

char Player::getSymbol() {
    return Symbol;
}

