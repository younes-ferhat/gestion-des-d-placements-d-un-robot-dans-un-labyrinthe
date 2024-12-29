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
                    << "(3,4)\n"
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
        REQUIRE( Terrain.getCaseArrivee() == Point {3,4});
        // Validation du contenu (case accessible/inaccessible)
        REQUIRE(Terrain.estAccessible(Point(0, 0)) == false); // Case avec 1
        REQUIRE(Terrain.estAccessible(Point(1, 1)) == true);  // Case avec 0
    }


    SUBCASE("Affichage du terrain en mode texte")
    {
        terrain Terrain(3, 3);
        Terrain.setCase(Point(0, 0), 1); // Mur
        Terrain.setCase(Point(1, 1), 0); // Vide
        Terrain.setCase(Point(2, 2), 1); // Mur

        cout << "Affichage simple : " << endl;
       // Terrain.afficherModeTexteSimple();

        cout << "Affichage amélioré : " << endl;
        //Terrain.afficherModeTexteAmeliore2();
    }
}