
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "../headers/doctest.h"
#include "../headers/terrain.h"
#include "../headers/Robot.h"
#include "../headers/mainDroite.h"

TEST_CASE("Test de l'algorithme de la main droite") {
    // Réinitialisation de la grille (terrain) : on fixe les cases comme libres au départ.
    auto reinitialiserTerrain = [](terrain& t) {
        // Boucle sur chaque case du terrain pour la réinitialiser en '.'
        for (int y = 0; y < t.getHauteur(); ++y) {
            for (int x = 0; x < t.getLargeur(); ++x) {
                t.setCase(Point(x, y), '.'); // Terrain libre par défaut
            }
        }
        // Puis on fixe les points de départ et d'arrivée
        t.setCase(Point(0, 0), 'S'); // Point de départ
        t.setCase(Point(4, 4), 'E'); // Point d'arrivée
    };

    // Création du terrain de test et du robot
    terrain terrainTest(5, 5);  // Terrain 5x5
    Robot robot(Point(0, 0), Robot::Direction::EST);  // Robot positionné au départ avec une direction vers l'est
    mainDroite algo(robot, terrainTest);  // Instance de l'algorithme de la main droite

    SUBCASE("Déplacement dans un labyrinthe simple sans obstacles") {
        // Réinitialise le terrain et crée un parcours simple sans obstacles
        reinitialiserTerrain(terrainTest);
        algo.executer();  // Résolution du labyrinthe
        CHECK(algo.estSorti() == true);  // Vérifie que le robot a bien trouvé la sortie
    }

    SUBCASE("Labyrinthe avec obstacles autour de la solution") {
        // Réinitialise le terrain
        reinitialiserTerrain(terrainTest);
        
        // On place des obstacles autour du chemin direct vers la sortie
        terrainTest.setCase(Point(1, 0), '#');  // Ajouter obstacle à gauche
        terrainTest.setCase(Point(0, 1), '#');  // Ajouter obstacle en haut

        algo.executer();  // Résolution du labyrinthe
        CHECK(algo.estSorti() == true);  // Le robot doit toujours pouvoir sortir malgré les obstacles, puisqu'il suit la main droite
    }


    SUBCASE("Labyrinthe avec impasse et résolution avec la main droite") {
    // Réinitialise le terrain à l'état de départ
    reinitialiserTerrain(terrainTest);

    // Ajout des obstacles de manière à créer une impasse
    terrainTest.setCase(Point(1, 0), '#');  // Ajoute un mur à gauche du robot
    terrainTest.setCase(Point(2, 1), '#');  // Ajoute un mur en bas à droite de la position (1, 0)
    terrainTest.setCase(Point(1, 2), '#');  // Ajoute un mur à droite du robot

    // Ce test simule une situation où il y sa des obstacles empêchant une progression directe
    algo.executer();  // Résolution du labyrinthe par l'algorithme
    CHECK(algo.estSorti() == true);  // Vérifie que l'algorithme a réussi à sortir
}


   
}
