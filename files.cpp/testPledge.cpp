#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "../headers/doctest.h"
#include "../headers/Point.h"
#include "../headers/Robot.h"
#include "../headers/terrain.h"
#include "../headers/pledge.h"

TEST_SUITE("Tests de la classe pledge") {
   
   TEST_CASE("Test de la méthode résoudre") {
     Point positionDebut {2,4};
    Robot robot {positionDebut,Robot::EST};

    terrain Terrain {};
     Terrain.chargerDepuisFichier("../terrain/labyrinthe.txt");
     Terrain.setCaseArrivee( Point {19,14});

     pledge algo {robot,Terrain};

        algo.resoudre(); 
        CHECK ( algo.estSortie() == true );
       



   }

    

}