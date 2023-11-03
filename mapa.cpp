#include "JogoDaCobrinha.h"

Mapa::Mapa(int t){
    this->tam=t;
    mapa = new int*[t];
    for(int i=0;i<t;i++)
        mapa[i]= new int[t];
}

void Mapa::cleanMap(void){
    for(int i=0;i<this->tam;i++){
        for(int j=0;j<this->tam;j++)
            mapa[i][j]=0;
    }
}

void Mapa::printMap(void){
    for(int i=0;i<this->tam;i++){
        for(int j=0;j<this->tam;j++)
            std::cout<<mapa[i][j]<< " ";
        std::cout<<std::endl;
    }
}

// quando eu inverto tempx e tempy aqui resolve porem acho que aqui não é a fonte
// do problema : matriz[x][y] não matriz [y][x]

void Mapa::spawnPlayer(No &C){
    //int tempx=C.getX(),tempy=C.getY();
    //mapa[tempx][tempy]=1;
    mapa[C.getX()][C.getY()]=1;
    //std::cout<< C.getX() << C.getY() << std::endl; // debug
}

bool Mapa::walk(No &c){
    if(_kbhit()){
        char key = _getch();
        int x = c.getX();
        int y = c.getY();
        std::cout<< "coords: "<< std::endl << "x:"<<x<<" y"<<y<< std::endl; //debug cordenadas
        if(key == 'w' || key == 72){
            c.setY(++y);
            spawnPlayer(c);
            return true;
        }
        else if(key == 's' || key == 80){
            c.setY(--y);
            spawnPlayer(c);
            return true;
        }
        else if(key == 'a' || key == 75){
            c.setX(--x);
            spawnPlayer(c);
            return true;
        }
        else if(key =='d' || key == 77){
            c.setX(++x);
            spawnPlayer(c);
            return true;
        }
    }
    return false;
}

Mapa::~Mapa(){
    for(int i=0;i<this->tam;i++)
        delete[] mapa[i];
    delete[] mapa;
}
