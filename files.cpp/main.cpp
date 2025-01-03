#include <iostream>
#include "../headers/Robot.h"
#include "../headers/terrain.h"
#include "../headers/ObservateurAffichage.h"
#include "../headers/ObservateurStatistiques.h" 
int main() {
    // Création d'un terrain simple pour le test
    terrain t{30,50};

    // Définir une position de départ pour le robot (ex : (0, 0)) et une direction (ex : NORD)
    Point startPosition(0, 0);
    Robot::Direction startDirection = Robot::NORD;
    
    // Créer un robot
    Robot robot(startPosition, startDirection);

    // Créer des observateurs
    ObservateurAffichage affichage;
    ObservateurStatistiques statistiques;
    
    // Ajouter les observateurs au robot
    robot.ajouterObservateur(&affichage);
    robot.ajouterObservateur(&statistiques);

    // Test des déplacements et rotations
    std::cout << "Déplacement du robot..." << std::endl;
    
    robot.deplaceDevant(t);  // Déplace le robot vers l'avant
    robot.tourneGauche(t);   // Tourne le robot à gauche
    robot.deplaceDevant(t);  // Déplace le robot encore
    robot.tourneDroite(t);   // Tourne le robot à droite
    robot.deplaceDevant(t);  // Déplace le robot encore
    robot.demiTour();        // Le robot fait un demi-tour

    // Affichage des statistiques
    std::cout << "\n--- Statistiques ---" << std::endl;
    std::cout << "Nombre total de déplacements : " << statistiques.getCompteurDeplacements() << std::endl;
    
    // Afficher les statistiques finales
    statistiques.afficherStatistiquesFinales();

    return 0;
}
