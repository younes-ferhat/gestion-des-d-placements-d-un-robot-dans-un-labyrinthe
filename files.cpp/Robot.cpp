#include "../headers/Robot.h"
#include "../headers/terrain.h"

Robot::Robot(Point startPosition, Direction startDirection)
    : d_position(startPosition), d_direction(startDirection) {}

Point Robot:: getPosition() const{
    return d_position;
}
Robot::Direction Robot:: getDirection() const {
    return d_direction;
}


void Robot::deplaceDevant() {
    switch (d_direction) {
        case NORD: d_position.move(0, -1); break;
        case EST: d_position.move(1, 0); break;
        case SUD: d_position.move(0, 1); break;
        case OUEST: d_position.move(-1, 0); break;
    }
    notifyMovement("avancé");
}

void Robot::tourneGauche() {
    d_direction = static_cast<Direction>((d_direction + 3) % 4);
    notifyMovement("tourné à gauche");
}

void Robot::tourneDroite() {
    d_direction = static_cast<Direction>((d_direction + 1) % 4);
    notifyMovement("tourné à droite");
}

void Robot::demiTour() {
    d_direction = static_cast<Direction>((d_direction + 2) % 4); // Inversion de direction
    notifyMovement("fait un demi-tour");
}

bool Robot::detectObstacle(const terrain& Terrain) {
    Point nextPosition = d_position; // Copie de la position actuelle
    switch (d_direction) {
        case NORD: nextPosition.move(0, -1); break;
        case EST: nextPosition.move(1, 0); break;
        case SUD: nextPosition.move(0, 1); break;
        case OUEST: nextPosition.move(-1, 0); break;
    }
    std::cout<< nextPosition.getX() << nextPosition.getY() <<" \n";
    return !Terrain.estAccessible(nextPosition);
}
bool Robot::detectObstacleGauche(const terrain& Terrain) const {
    // Calculer la position à gauche du robot en fonction de sa direction actuelle
    Point positionGauche = d_position;
    switch (d_direction) {
        case NORD: positionGauche.move(-1, 0); break; // Vers l'ouest
        case EST:  positionGauche.move(0, -1); break; // Vers le nord
        case SUD:  positionGauche.move(1, 0); break;  // Vers l'est
        case OUEST: positionGauche.move(0, 1); break; // Vers le sud
    }

    // Vérifier si la position est accessible
    return !Terrain.estAccessible(positionGauche);
}
bool Robot::detectObstacleDroite(const terrain& Terrain) const {
    // Calculer la position à droite du robot en fonction de sa direction actuelle
    Point positionDroite = d_position;
    switch (d_direction) {
        case NORD: positionDroite.move(1, 0); break;  // Vers l'est
        case EST:  positionDroite.move(0, 1); break;  // Vers le sud
        case SUD:  positionDroite.move(-1, 0); break; // Vers l'ouest
        case OUEST: positionDroite.move(0, -1); break; // Vers le nord
    }

    // Vérifier si la position est accessible
    return !Terrain.estAccessible(positionDroite);
}
void Robot::dessinerRobot(const terrain& Terrain) const {
    // Dimensions du terrain
    int hauteur = Terrain.getHauteur();
    int largeur = Terrain.getLargeur();

    // Créer une copie temporaire de la grille
    std::vector<std::vector<char>> grille(hauteur, std::vector<char>(largeur, '.'));

    // Remplir la copie avec les obstacles du terrain
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            if (!Terrain.estAccessible(Point(i, j))) {
                grille[i][j] = '#'; // Murs
            }
        }
    }

    // Ajouter les points de départ et d'arrivée
    Point caseDepart = Terrain.getCaseDepart();
    Point caseArrivee = Terrain.getCaseArrivee();
    grille[caseDepart.getY()][caseDepart.getX()] = 'S';
    grille[caseArrivee.getY()][caseArrivee.getX()] = 'E';

    // Ajouter le robot à sa position actuelle
    char symbole;
    switch (d_direction) {
        case NORD: symbole = '^'; break;
        case EST: symbole = '>'; break;
        case SUD: symbole = 'v'; break;
        case OUEST: symbole = '<'; break;
    }
    grille[d_position.getY()][d_position.getX()] = symbole;

    // Afficher la grille
    for (const auto& ligne : grille) {
        for (char c : ligne) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
}




void Robot::notifyMovement(const std::string& action) {
    std::cout << "Robot a " << action
              << " à la position (" << d_position.getX() << ", " << d_position.getY() << ") en direction ";
    switch (d_direction) {
        case NORD: std::cout << "Nord"; break;
        case EST: std::cout << "Est"; break;
        case SUD: std::cout << "Sud"; break;
        case OUEST: std::cout <<"Ouest"; break;
    }
    std::cout << "." << std::endl;
}

/* Explication de la méthode demi tour 
Le robot a 4 directions possibles : NORD, EST, SUD, et OUEST, qui forment un cycle. cad que si on avances d'une direction, ton passes à la suivante. 
exple: si on arrives à OUEST, on reviens à NORD.

Quand on fait un demi-tour, on veut que le robot change de direction de deux étapes, c'est-à-dire qu'il prenne la direction opposée.

Pour obtenir cela :

    On ajoute 2 à la direction actuelle. Par exemple :
        Si le robot est NORD, on ajoute 2 et il passe à SUD.
        Si le robot est EST, il passe à OUEST.
    Le modulo 4 sert  à "revenir au début" du cycle des directions si on dépasse OUEST. Par exemple :
        Si on est à SUD (direction 2) et qu'on ajoute 2, cela nous donne 4, mais le modulo 4 transforme 4 en 0, donc on revient à NORD.

*/


/*
Explication de la méthode detectObstacle
Dans chaque cas, on modifie la copie de la position (nextPosition) en fonction de la direction :

    NORD : on déplace le robot de 0 cases en X et -1 case en Y (le robot va vers le haut).
    EST : on déplace le robot de 1 case en X et 0 case en Y (le robot va vers la droite).
    SUD : on déplace le robot de 0 case en X et 1 case en Y (le robot va vers le bas).
    OUEST : on déplace le robot de -1 case en X et 0 case en Y (le robot va vers la gauche).
    return !terrain.estAccessible(nextPosition);
  appelle la méthode estAccessible de la classe Terrain.
elle vérifie si la position(nextPosition) est accessible 
(c'est-à-dire qu'il n'y a pas d'obstacle comme un mur à cet endroit).

    Si estAccessible retourne true, cela veut dire que la case est libre, donc pas d'obstacle.
    Si estAccessible retourne false, cela veut dire qu'il y a un obstacle, donc la case est bloquée.

*/
