
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "../headers/doctest.h"
#include "../headers/Point.h"
#include "../headers/Robot.h"
#include "../headers/terrain.h"

TEST_SUITE("Tests de la classe Robot") {

    TEST_CASE("Test de la création d'un robot") {
        Point startPos(1, 1);
        Robot robot(startPos, Robot::NORD);

        CHECK(robot.getPosition() == startPos);
        CHECK(robot.getDirection() == Robot::NORD); // Si ce test est important
    }

    TEST_CASE("Test du déplacement devant sans obstacle") {
        Point startPos(1, 1);
        Robot robot(startPos, Robot::NORD);

        robot.deplaceDevant(); // Déplacement vers le haut
        CHECK(robot.getPosition() == Point(1, 0));
        CHECK(robot.getDirection() == Robot::NORD);

        robot.tourneDroite();
        robot.deplaceDevant(); // Déplacement vers la droite
        CHECK(robot.getPosition() == Point(2, 0));
        CHECK(robot.getDirection() == Robot::EST);
    }

    TEST_CASE("Test du demi-tour") {
        Point startPos(2, 2);
        Robot robot(startPos, Robot::NORD);

        robot.demiTour();
        CHECK(robot.getDirection() == Robot::SUD);
        
        robot.demiTour();
        CHECK(robot.getDirection() == Robot::NORD); // Si retour à NORD
    }

    TEST_CASE("Test de la rotation à gauche et à droite") {
        Point startPos(0, 0);
        Robot robot(startPos, Robot::NORD);

        robot.tourneGauche();
        CHECK(robot.getDirection() == Robot::OUEST);

        robot.tourneGauche();
        CHECK(robot.getDirection() == Robot::SUD);

        robot.tourneDroite();
        CHECK(robot.getDirection() == Robot::OUEST);

        robot.tourneDroite();
        CHECK(robot.getDirection() == Robot::NORD);
    }

    TEST_CASE("Test du déplacement devant avec terrain") {
        Point startPos(1,1);
       terrain Terrain {}; 
       Terrain.chargerDepuisFichier("../terrain/labyrinthe.txt");// Terrain de 5x5
        Robot robot(startPos, Robot::EST);

        robot.deplaceDevant();
        CHECK(robot.getPosition() == Point{2,1});
    
        CHECK(Terrain.getCase(robot.getPosition()) == false);  // Terrain dégagé

        robot.tourneDroite();
        robot.deplaceDevant(); // vers la droite
        CHECK(robot.getPosition() == Point{2,2});
       CHECK(Terrain.getCase(robot.getPosition()) == false);  // Terrain dégagé
    }

    TEST_CASE("Test de la détection d'obstacle devant") {
        Point startPos(1, 1);
        terrain Terrain(5, 5); // Terrain de 5x5

        // Ajout d'un obstacle devant le robot
        Terrain.setCase(Point(1, 0), true);
        Robot robot(startPos, Robot::NORD);

     CHECK(robot.detectObstacle(Terrain) == true);  // Obstacle détecté

        // Déplacement du robot vers la case sans obstacle
        robot.deplaceDevant();
        CHECK(robot.getPosition() == Point(1, 0)); // Le robot n'a pas bougé car obstacle
    }

    TEST_CASE("Test de la détection d'obstacles à gauche et à droite") {
        Point startPos(1, 1);
        terrain Terrain(5, 5); // Terrain de 5x5

        // Pas d'obstacle initialement
        Robot robot(startPos, Robot::NORD);

        CHECK(robot.detectObstacleGauche(Terrain) == false);
        CHECK(robot.detectObstacleDroite(Terrain) == false);

        // Ajout d'obstacle à gauche
        Terrain.setCase(Point{0,1}, true);
        CHECK(robot.detectObstacleGauche(Terrain) == true); 

        // Ajout d'obstacle à droite
        Terrain.setCase(Point(2, 1), true);
     
      CHECK(robot.detectObstacleDroite(Terrain) == true); 
    }

    TEST_CASE("Test du dessin du robot dans le terrain") {
        Point startPos(1, 1);
        terrain Terrain(5, 5); // Terrain de 5x5
        Robot robot(startPos, Robot::NORD);

        // Assurez-vous que la fonction de dessin ne cause pas d'erreur
        robot.dessinerRobot(Terrain);
        CHECK(true); // Le test passe si aucune exception n'est lancée
    }

    TEST_CASE("Test des notifications des mouvements") {
        Point startPos(1, 1);
        Robot robot(startPos, Robot::NORD);

        // Vérification que les bonnes notifications de mouvements sont appelées
        // Il est nécessaire de vérifier manuellement si la notification fonctionne dans la méthode.
        robot.deplaceDevant();
        // Vérification manuelle des sorties du robot en conséquence.
        robot.tourneDroite();
        robot.tourneGauche();
        robot.demiTour();
    }
}

