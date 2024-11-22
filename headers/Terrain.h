#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include <string>
#include "Point.h"

class Terrain {
private:
    std::vector<std::vector<char>> grille;  // Représente le labyrinthe
    int largeur;  // Largeur du terrain
    int hauteur;  // Hauteur du terrain
    Point caseDepart;  // Coordonnées de la case de départ
    Point caseArrivee; // Coordonnées de la case d'arrivée

public:
    // Constructeur par défaut
    Terrain();

    // Constructeur avec dimensions
    Terrain(int largeur, int hauteur);

    // Charger un terrain depuis un fichier
    bool chargerDepuisFichier(const std::string& nomFichier);

    // Sauvegarder un terrain dans un fichier
    bool sauvegarderDansFichier(const std::string& nomFichier) const;

    // Accéder ou modifier une case
    char getCase(const Point& position) const;
    void setCase(const Point& position, char valeur);

    // Définir les cases de départ et d'arrivée
    void setCaseDepart(const Point& position);
    void setCaseArrivee(const Point& position);
    Point getCaseDepart() const;
    Point getCaseArrivee() const;

    // Afficher le terrain en mode texte
    void afficherModeTexteSimple() const;
    void afficherModeTexteAmeliore1() const;
    void afficherModeTexteAmeliore2() const;

    // Vérifier si une position est valide et accessible
    bool estAccessible(const Point& position) const;
};

#endif // TERRAIN_H