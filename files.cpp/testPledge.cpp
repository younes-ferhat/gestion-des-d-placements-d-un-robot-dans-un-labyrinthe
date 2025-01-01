
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "../headers/doctest.h"
#include "../headers/Point.h"
#include "../headers/Robot.h"
#include "../headers/terrain.h"
#include "../headers/pledge.h"
#include "../headers/affichageModeTexteSimple.h"

TEST_SUITE("Tests de la classe pledge") {

   TEST_CASE("Test de la mÃ©thode rÃ©soudre") {
    terrain Terrain {};
     Terrain.chargerDepuisFichier("../terrain/labyrintheTest.txt");
   Robot robot {Terrain.getCaseDepart(),Robot::EST};
     pledge algo {robot,Terrain};
      AffichageModeTexteSimple affichage{Terrain, robot};

      algo.resoudre(affichage);
      affichage.goto_xy(Terrain.getLargeur(),Terrain.getHauteur());
      REQUIRE ( algo.estSortie() == true );


   }



}