
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "../headers/doctest.h"
#include "../headers/terrain.h"
#include "../headers/Robot.h"
#include "../headers/mainDroite.h"
#include "../headers/affichageModeTexteSimple.h"

/*TEST_CASE("Test de l'algorithme de la main droite") {
    // RÃ©initialisation de la grille (terrain) : on fixe les cases comme libres au dÃ©part.
    auto reinitialiserTerrain = [](terrain& t) {
        // Boucle sur chaque case du terrain pour la rÃ©initialiser en '.'
        for (int y = 0; y < t.getHauteur(); ++y) {
            for (int x = 0; x < t.getLargeur(); ++x) {
                t.setCase(Point(x, y), '.'); // Terrain libre par dÃ©faut
            }
        }
        // Puis on fixe les points de dÃ©part et d'arrivÃ©e
        t.setCase(Point(0, 0), 'S'); // Point de dÃ©part
        t.setCase(Point(4, 4), 'E'); // Point d'arrivÃ©e
    };

    // CrÃ©ation du terrain de test et du robot
    terrain terrainTest(5, 5);  // Terrain 5x5
    Robot robot(Point(0, 0), Robot::Direction::EST);  // Robot positionnÃ© au dÃ©part avec une direction vers l'est
    mainDroite algo(robot, terrainTest);  // Instance de l'algorithme de la main droite

    SUBCASE("DÃ©placement dans un labyrinthe simple sans obstacles") {
        // RÃ©initialise le terrain et crÃ©e un parcours simple sans obstacles
        reinitialiserTerrain(terrainTest);
        AffichageModeTexteSimple affichage{terrainTest, robot};

        algo.resoudre(affichage);  // RÃ©solution du labyrinthe
        CHECK(algo.estSortie() == true);  // VÃ©rifie que le robot a bien trouvÃ© la sortie
    }

    SUBCASE("Labyrinthe avec obstacles autour de la solution") {
        // RÃ©initialise le terrain
        reinitialiserTerrain(terrainTest);

        // On place des obstacles autour du chemin direct vers la sortie
        terrainTest.setCase(Point(1, 0), '#');  // Ajouter obstacle Ã  gauche
        terrainTest.setCase(Point(0, 1), '#');  // Ajouter obstacle en haut

       AffichageModeTexteSimple affichage{terrainTest, robot};

        algo.resoudre(affichage);  // RÃ©solution du labyrinthe
        CHECK(algo.estSortie() == true);  // Le robot doit toujours pouvoir sortir malgrÃ© les obstacles, puisqu'il suit la main droite
    }


    SUBCASE("Labyrinthe avec impasse et rÃ©solution avec la main droite") {
    // RÃ©initialise le terrain Ã  l'Ã©tat de dÃ©part
    reinitialiserTerrain(terrainTest);

    // Ajout des obstacles de maniÃ¨re Ã  crÃ©er une impasse
    terrainTest.setCase(Point(1, 0), '#');  // Ajoute un mur Ã  gauche du robot
    terrainTest.setCase(Point(2, 1), '#');  // Ajoute un mur en bas Ã  droite de la position (1, 0)
    terrainTest.setCase(Point(1, 2), '#');  // Ajoute un mur Ã  droite du robot

    // Ce test simule une situation oÃ¹ il y sa des obstacles empÃªchant une progression directe
    AffichageModeTexteSimple affichage{terrainTest, robot};

        algo.resoudre(affichage); ;  // RÃ©solution du labyrinthe par l'algorithme
    CHECK(algo.estSortie() == true);  // VÃ©rifie que l'algorithme a rÃ©ussi Ã  sortir
}

}*/
TEST_CASE("Test de l'algorithme de la main droite avec fichier") {
    // Terrain chargÃ© depuis un fichier
    terrain terrainTest;
    CHECK_NOTHROW(terrainTest.chargerDepuisFichier("../terrain/labyrintheTest.txt"));

    Robot robot(Point(0, 0), Robot::Direction::EST); // Robot initialisÃ© Ã  une position arbitraire
    mainDroite algo(robot, terrainTest);

    SUBCASE("RÃ©solution avec un terrain chargÃ© depuis fichier") {
       AffichageModeTexteSimple affichage{};

        algo.resoudre(affichage);   // Lancer l'algorithme
        affichage.goto_xy(terrainTest.getLargeur(),terrainTest.getHauteur());
        CHECK(algo.estSortie() == true);  // VÃ©rifie que la sortie a Ã©tÃ© atteinte
    }
}
