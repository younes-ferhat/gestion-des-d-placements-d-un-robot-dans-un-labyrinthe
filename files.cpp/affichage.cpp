 #include "../headers/affichage.h"
 #include <windows.h>

void Affichage::maj(const terrain &Terrain, const Robot &robot)
{
    system("cls");
    afficherTerrain(Terrain);
    afficherRobot(robot);
    Sleep(500);
    goto_xy(0,Terrain.getHauteur()+3);
}

void Affichage::goto_xy(int x, int y) {
    HANDLE handle;
  COORD coordinates;
  handle = GetStdHandle(STD_OUTPUT_HANDLE);
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(handle, coordinates);
}