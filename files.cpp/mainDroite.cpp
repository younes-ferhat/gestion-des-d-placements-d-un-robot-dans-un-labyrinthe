#include "C:\Users\youne\Desktop\prjct labyrinth\gestion-des-d-placements-d-un-robot-dans-un-labyrinthe\headers\mainDroite.h"


mainDroite::mainDroite(vector<vector<char>> lab, int startX, int startY, char startDir)
    : labyrinthe(lab), x(startX), y(startY), direction(startDir) {}

// Vérifie si une position est libre
bool mainDroite::estLibre(int nx, int ny) {
    return labyrinthe[nx][ny] == '.';
}

// Met à jour la direction selon la règle de la main droite
void mainDroite::tournerDroite() {
    if (direction == 'U') direction = 'R';
    else if (direction == 'R') direction = 'D';
    else if (direction == 'D') direction = 'L';
    else if (direction == 'L') direction = 'U';
}

void mainDroite::tournerGauche() {
    if (direction == 'U') direction = 'L';
    else if (direction == 'L') direction = 'D';
    else if (direction == 'D') direction = 'R';
    else if (direction == 'R') direction = 'U';
}

void mainDroite::demiTour() {
    if (direction == 'U') direction = 'D';
    else if (direction == 'D') direction = 'U';
    else if (direction == 'L') direction = 'R';
    else if (direction == 'R') direction = 'L';
}

// Avance dans la direction actuelle
void mainDroite::avancer() {
    labyrinthe[x][y] = '.'; // Libérer l'ancienne position
    if (direction == 'U') x--;
    else if (direction == 'D') x++;
    else if (direction == 'L') y--;
    else if (direction == 'R') y++;
    labyrinthe[x][y] = '>'; // Met à jour la nouvelle position
}

// Méthode principale pour résoudre le labyrinthe
void mainDroite::resoudre() {
    while (true) {
        // Condition d'arrêt : si le robot est à une sortie
        if (x == 0 || x == labyrinthe.size() - 1 || y == 0 || y == labyrinthe[0].size() - 1) {
            cout << "Sortie trouvée à (" << x << ", " << y << ")!" << endl;
            break;
        }

        // Appliquer la règle de la main droite
        int nx = x, ny = y;

        // Calculer la position à droite
        if (direction == 'U') { nx = x; ny = y + 1; }
        else if (direction == 'R') { nx = x + 1; ny = y; }
        else if (direction == 'D') { nx = x; ny = y - 1; }
        else if (direction == 'L') { nx = x - 1; ny = y; }

        if (estLibre(nx, ny)) {
            tournerDroite();
            avancer();
        } else if (estLibre(x + (direction == 'U' ? -1 : direction == 'D' ? 1 : 0),
                            y + (direction == 'L' ? -1 : direction == 'R' ? 1 : 0))) {
            avancer();
        } else {
            tournerGauche();
            if (!estLibre(x + (direction == 'U' ? -1 : direction == 'D' ? 1 : 0),
                          y + (direction == 'L' ? -1 : direction == 'R' ? 1 : 0))) {
                demiTour();
            }
        }
        /*Si la direction est 'U' (haut), le robot vérifie la cellule juste au-dessus de lui : (x - 1, y).
        
          Si la direction est 'D' (bas), le robot vérifie la cellule juste en dessous de lui : (x + 1, y).
        
          Si la direction est 'L' (gauche), le robot vérifie la cellule à gauche de lui : (x, y - 1).
         
          Si la direction est 'R' (droite), le robot vérifie la cellule à droite de lui : (x, y + 1).*/

        // Afficher le labyrinthe à chaque étape
        afficherLabyrinthe();
    }
}

// Afficher le labyrinthe
void mainDroite::afficherLabyrinthe() {
    for (const auto &ligne : labyrinthe) {
        for (char c : ligne) cout << c;
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}