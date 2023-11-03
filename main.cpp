#include "JogoDaCobrinha.h"
#include <windows.h>

int main(){
Mapa jogo(10);
No c(2,2);
jogo.cleanMap();
jogo.spawnPlayer(c);
while(1){
jogo.walk(c);
jogo.printMap();
//system("cls");
std::cout<<std::endl;
Sleep(1200);
}


return 0;
}
