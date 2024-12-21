#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
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
        // PrÃ©paration : CrÃ©ation d'un fichier de test
        ofstream fichierTest("terrainTest.txt");
        fichierTest << "5 5\n"
                    << "0 0 0 1 0\n"
                    << "0 0 1 0 0\n"
                    << "0 1 0 0 0\n"
                    << "0 0 0 0 1\n"
                    << "1 0 0 0 0\n";
        fichierTest.close();

        // Test : Lecture du fichier
        terrain Terrain;
        bool charge = Terrain.chargerDepuisFichier("terrainTest.txt");
        REQUIRE(charge == true);

        // Validation des dimensions
        REQUIRE(Terrain.getHauteur() == 5);
        REQUIRE(Terrain.getLargeur() == 5);

        // Validation du contenu (case accessible/inaccessible)
        // REQUIRE(terrain.estAccessible(Point(0, 0)) == false); // Case avec 1
        REQUIRE(Terrain.estAccessible(Point(1, 1)) == true); // Case avec 0
    }

    SUBCASE("Sauvegarde et vÃ©rification du contenu d'un terrain")
    {
        // Initialisation
        terrain Terrain(3, 3);
        Terrain.setCase(Point(0, 0), 1); // Mur
        Terrain.setCase(Point(1, 1), 0); // Vide
        Terrain.setCase(Point(2, 2), 1); // Mur

        // Sauvegarde dans un fichier
        string fichierSauvegarde = "terrainSauvegarde.txt";
        bool sauvegarde = Terrain.sauvegarderDansFichier(fichierSauvegarde);
        REQUIRE(sauvegarde == true);

        // Lecture du fichier pour vÃ©rifier
        ifstream fichierVerif(fichierSauvegarde);
        REQUIRE(fichierVerif.is_open());

        int hauteur, largeur;
        fichierVerif >> hauteur >> largeur;
        REQUIRE(hauteur == 3);
        REQUIRE(largeur == 3);

        int valeur;
        fichierVerif >> valeur;
        REQUIRE(valeur == 1); // Case (0, 0)
        fichierVerif >> valeur;
        REQUIRE(valeur == 0); // Case (0, 1)
    }

    SUBCASE("Test des cases dÃ©part et arrivÃ©e")
    {
        terrain Terrain(4, 4);

        // DÃ©finir la case de dÃ©part
        Point depart(1, 1);
        Terrain.setCaseDepart(depart);
        REQUIRE(Terrain.getCaseDepart() == depart);

        // DÃ©finir la case d'arrivÃ©e
        Point arrivee(3, 3);
        Terrain.setCaseArrivee(arrivee);
        REQUIRE(Terrain.getCaseArrivee() == arrivee);

        // VÃ©rifier les symboles spÃ©cifiques
        REQUIRE(Terrain.getCase(depart) == 'S');  // 'S' pour dÃ©part
        REQUIRE(Terrain.getCase(arrivee) == 'E'); // 'E' pour arrivÃ©e
    }

    SUBCASE("Affichage du terrain en mode texte")
    {
        terrain Terrain(3, 3);
        Terrain.setCase(Point(0, 0), 1); // Mur
        Terrain.setCase(Point(1, 1), 0); // Vide
        Terrain.setCase(Point(2, 2), 1); // Mur

        cout << "Affichage simple : " << endl;
        Terrain.afficherModeTexteSimple();

        cout << "Affichage amÃ©liorÃ© : " << endl;
        Terrain.afficherModeTexteAmeliore2();
    }
}