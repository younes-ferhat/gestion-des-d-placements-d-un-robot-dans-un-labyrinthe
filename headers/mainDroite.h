#ifndef MAINDROITE_H
#define MAINDROITE_H
#include <vector>
#include <iostream>
using namespace std;

class mainDroite
{
    public:
    mainDroite(vector<vector<char>> lab, int startX, int startY, char startDir);

    // Méthode principale pour résoudre le labyrinthe
    void resoudre();

    // Afficher le labyrinthe
    void afficherLabyrinthe();
   private:
   std:: vector<vector<char>> labyrinthe; // Le labyrinthe
    int x, y;                        // Position du robot
    char direction;                  // Orientation du robot: 'U', 'D', 'L', 'R'

    // Vérifie si une position est libre
    bool estLibre(int nx, int ny);

    // Met à jour la direction selon la règle de la main droite
    void tournerDroite();
    void tournerGauche();
    void demiTour();

    // Avance dans la direction actuelle
    void avancer();

};

#endif