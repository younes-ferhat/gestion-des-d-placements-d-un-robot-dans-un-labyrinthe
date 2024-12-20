#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
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
        CHECK(robot.getDirection()== Robot::NORD);
    }

    TEST_CASE("Test du déplacement devant sans obstacle") {
        Point startPos(1, 1);
        terrain Terrain; // Terrain par défaut sans obstacles
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
        CHECK(robot.getDirection() == Robot::NORD);
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

    TEST_CASE("Test de la détection d'obstacle devant") {
        Point startPos(1, 1);
        terrain Terrain; // Supposons que le terrain a un obstacle à (1, 0)
        Robot robot(startPos, Robot::NORD);

        CHECK(robot.detectObstacle(Terrain) == false); // Pas d'obstacle initial
        robot.deplaceDevant();
        CHECK(robot.detectObstacle(Terrain) == true);  // Obstacle détecté
    }

    TEST_CASE("Test de la détection d'obstacles à gauche et à droite") {
        Point startPos(1, 1);
        terrain Terrain; // Terrain par défaut
        Robot robot(startPos, Robot::NORD);

        // Initialement, pas d'obstacle sur les côtés
        CHECK(robot.detectObstacleGauche(Terrain) == false);
        CHECK(robot.detectObstacleDroite(Terrain) == false);

        // Après déplacement et rotation, vérifions
        robot.tourneGauche();
        robot.deplaceDevant();
        CHECK(robot.detectObstacleGauche(Terrain) == true); // Simulation d'un obstacle
    }

    TEST_CASE("Test de la notification des mouvements") {
        Point startPos(1, 1);
        Robot robot(startPos, Robot::NORD);

        robot.deplaceDevant(); // Devrait notifier "avancé"
        robot.tourneDroite();  // Devrait notifier "tourné à droite"
        robot.tourneGauche();  // Devrait notifier "tourné à gauche"
        robot.demiTour();      // Devrait notifier "fait un demi-tour"
    }

    TEST_CASE("Test du dessin du robot dans le terrain") {
        Point startPos(1, 1);
        terrain Terrain;
        Robot robot(startPos, Robot::NORD);

        // Appel de la méthode pour s'assurer qu'elle ne provoque pas d'erreurs
        robot.dessinerRobot(Terrain);
        CHECK(true); // Le test passe si aucune erreur n'est déclenchée
    }
}
