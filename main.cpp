#include <iostream>
#include <vector>

#include "./headers/Terrain.h"


int main() 
{   
    

   std::cout<<"hello world !"<<std::endl;
   Terrain t {};
   t.chargerDepuisFichier("./terrain/labyrinthe.txt");
   t.afficherModeTexteSimple();
    return 0;
}