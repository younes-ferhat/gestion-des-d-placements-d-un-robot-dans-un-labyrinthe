#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include <string>
#include "../headers/Point.h"

class terrain {
private:
    std::vector<std::vector<bool>> d_grille;  // Représente le labyrinthe
    int d_largeur;  // Largeur du terrain
    int d_hauteur;  // Hauteur du terrain
    Point caseDepart;  // Coordonnées de la case de départ
    Point caseArrivee; // Coordonnées de la case d'arrivée

public:
    // Constructeur par défaut
    terrain();

    // Constructeur avec dimensions
    terrain(int largeur, int hauteur);
    int getHauteur() const;
    int getLargeur()const;

    // Charger un terrain depuis un fichier
    bool chargerDepuisFichier(const std::string& nomFichier);

    // Sauvegarder un terrain dans un fichier
    bool sauvegarderDansFichier(const std::string& nomFichier) const;

    // Accéder ou modifier une case
    bool getCase(const Point& position) const;
    void setCase(const Point& position, bool valeur);

    // Définir les cases de départ et d'arrivée
    void setCaseDepart(const Point& position);
    void setCaseArrivee(const Point& position);
    Point getCaseDepart() const;
    Point getCaseArrivee() const;


    // Vérifier si une position est valide et accessible
    bool estAccessible(const Point& position) const;
   
};

#endif // TERRAIN_H