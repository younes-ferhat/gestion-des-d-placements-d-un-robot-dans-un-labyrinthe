
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "../headers/doctest.h"
#include "../headers/Point.h"
#include "../headers/Robot.h"
#include "../headers/terrain.h"
#include "../headers/pledge.h"
#include "../headers/affichageModeTexteSimple.h"
#include "../headers/ObservateurStatistiques.h"
#include <memory> 

TEST_SUITE("Tests de la classe pledge") {

   TEST_CASE("Test de la mÃ©thode rÃ©soudre") {
    terrain Terrain {};
     Terrain.chargerDepuisFichier("../terrain/terrainTest.txt");
   Robot robot {Terrain.getCaseDepart(),Robot::EST};
      AffichageModeTexteSimple affichage{};
      std::shared_ptr<ObservateurStatistiques> observ = std::make_shared<ObservateurStatistiques>(); 
    robot.ajouterObservateur(observ);
       pledge algo(robot, Terrain);
     // algo.resoudre(affichage);
      observ->afficherStatistiquesFinales();
//        CHECK(algo.estSortie() == true); 



   }



}