#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "../headers/doctest.h"
#include "../headers/Terrain.h"
#include <iostream>
#include <fstream>

using namespace std;

TEST_CASE("Test de la classe Terrain")
{

    SUBCASE("Initialisation et lecture du terrain depuis un fichier")
    {
        // Préparation : Création d'un fichier de test
        ofstream fichierTest("../terrain/terrainTest.txt");
        fichierTest << "(0,1)\n" 
                    << "(4,3)\n"
                    << "5 5\n"
                    << "1 1 1 1 1\n"
                    << "0 0 0 0 1\n"
                    << "1 1 0 1 1\n"
                    << "1 0 0 0 0\n"
                    << "1 1 1 1 1\n";
        fichierTest.close();

        // Test : Lecture du fichier
        terrain Terrain;
        bool charge = Terrain.chargerDepuisFichier("../terrain/terrainTest.txt");
        REQUIRE(charge == true);

        // Validation des dimensions
        REQUIRE(Terrain.getHauteur() == 5);
        REQUIRE(Terrain.getLargeur() == 5);
        //validation des caseDepart et caseArrivée
        REQUIRE( Terrain.getCaseDepart() == Point {0,1});
        REQUIRE( Terrain.getCaseArrivee() == Point {4,3});
        // Validation du contenu (case accessible/inaccessible)
        REQUIRE(Terrain.estAccessible(Point(0, 0)) == false); // Case avec 1
        REQUIRE(Terrain.estAccessible(Point(1, 1)) == true);  // Case avec 0
    }


    
}