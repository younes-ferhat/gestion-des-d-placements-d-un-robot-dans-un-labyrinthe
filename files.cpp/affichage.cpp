 #include "../headers/affichage.h"
 #include <windows.h>

void Affichage::maj(const terrain &Terrain, const Robot &robot)
{
    system("cls");
    afficherTerrain(Terrain);
    afficherRobot(robot);
    Sleep(500);

}
