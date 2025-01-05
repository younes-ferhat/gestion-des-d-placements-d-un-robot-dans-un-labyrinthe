 #define DOCTEST_CONFIG_NO_MULTITHREADING
#include "../headers/doctest.h"
#include "../headers/Point.h"
#include "../headers/Robot.h"
#include "../headers/terrain.h"
#include "../headers/affichageModeTexteSimple.h"
 
 
 
TEST_CASE (" test affichage") {

     SUBCASE("Affichage du terrain en mode texte") {

      std::string nomFichier = "../terrain/terrainTest.txt";

    // CrÃ©er un terrain et charger depuis un fichier
    terrain monTerrain {};
    monTerrain.chargerDepuisFichier(nomFichier);


    // CrÃ©er un robot Ã  la position de dÃ©part du terrain
    Robot robot(monTerrain.getCaseDepart(), Robot::EST);

    // CrÃ©er un affichage texte simple
    AffichageModeTexteSimple affichage{};

     }

 }


 