#include <iostream>
#include <vector>

#include "C:\Users\youne\Desktop\prjct labyrinth\gestion-des-d-placements-d-un-robot-dans-un-labyrinthe\headers\mainDroite.h"
using namespace std;


int main() 
{   
   std::vector<std::vector<char>> labyrinthe = {
        {'X', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', '.', '.', '.', 'X', '.', 'X'},
        {'X', '.', 'X', '.', 'X', '.', 'X'},
        {'X', '.', 'X', '.', '.', '.', 'X'},
        {'X', '.', 'X', 'X', 'X', 'X', 'X'},
        {'X', '.', '.', '.', '.', '.', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X'}
    };

    // Créer l'instance de mainDroite pour résoudre le labyrinthe
    mainDroite robotSolver(labyrinthe, 1, 1, 'R'); // Position (1,1), orienté à droite ('R')
    robotSolver.resoudre();

    return 0;
}