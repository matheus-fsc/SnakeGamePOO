#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <conio.h>

class No{
    private:
        int x,y;
        No* lig;
    public:
        No(int,int);
        inline int getX(void) {return x;}
        inline int getY(void) {return y;}
        inline void setX(int x) {this->x=x;}
        inline void setY(int y) {this->y=y;}

};


class Mapa{
    private:
        int** mapa;
        int tam;
    public:
        Mapa(int);
        void cleanMap(void);
        void printMap(void);
        void spawnPlayer(No&);
        bool walk(No&);
        ~Mapa(void);
};

#endif
