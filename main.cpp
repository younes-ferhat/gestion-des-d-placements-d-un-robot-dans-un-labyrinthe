#include <iostream>
#include <vector>

#include "./headers/Terrain.h"


int main() 
{   
    

   std::cout<<"hello world !";
   Terrain t {20,20};
   t.afficherModeTexteSimple();
   t.afficherModeTexteAmeliore2();
    return 0;
}