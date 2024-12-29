// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "../headers/doctest.h"
// #ifndef AFFICHAGE_DYNAMIQUE_H
// #define AFFICHAGE_DYNAMIQUE_H

// #endif // AFFICHAGE_DYNAMIQUE_H
#include <iostream>
#include <windows.h>
#include "../headers/terrain.h"
#include "../headers/Robot.h"
#include "../headers/AffichageModeTexteSimple.h"
#include "../headers/Point.h"

int main()
{
    // Nom du fichier contenant le labyrinthe
    std::string nomFichier = "C:/Users/youne/Desktop/labyrinth_younes/gestion-des-d-placements-d-un-robot-dans-un-labyrinthe/terrain/terrainTest.txt";

    // Créer un terrain et charger depuis un fichier
    terrain monTerrain;
    if (!monTerrain.chargerDepuisFichier(nomFichier))
    {
        std::cerr << "Erreur lors du chargement du labyrinthe depuis le fichier." << std::endl;
        return 1;
    }

    // Créer un robot à la position de départ du terrain
    Robot robot(monTerrain.getCaseDepart(), Robot::EST);

    // Créer un affichage texte simple
    AffichageModeTexteSimple affichage{monTerrain, robot};

    // Déplacer le robot et afficher chaque étape
    for (int i = 0; i < 10; ++i)
    {
        Sleep(1000); // Pause de 500ms (0.5 seconde)

        Point anciennePosition = robot.getPosition(); // Sauvegarder l'ancienne position
        robot.deplaceDevant();
        robot.demiTour();
        robot.tourneGauche();

        // Tourner le robot à droite
        // Vérifier si la nouvelle position est accessible
        if (monTerrain.estAccessible(robot.getPosition()))
        {
            affichage.effacerRobot(anciennePosition); // Effacer l'ancienne position
            affichage.afficherRobot(robot);           // Afficher le robot à la nouvelle position
        }
        else
        {  break;
        }
    }
    affichage.goto_xy(monTerrain.getLargeur(), monTerrain.getHauteur()); // pour placer le cursseur a la fin du labyrinth a la fin

    return 0;
}
