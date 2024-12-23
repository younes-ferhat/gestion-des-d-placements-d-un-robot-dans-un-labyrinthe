#include "../headers/terrain.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

terrain::terrain() : d_grille{} {}

terrain::terrain(int d_largeur, int d_hauteur) : d_largeur(d_largeur), d_hauteur(d_hauteur) {
    d_grille.resize(d_hauteur, vector<bool>(d_largeur, false));
}

int terrain::getHauteur() const {
    return d_hauteur;
}

int terrain::getLargeur() const {
    return d_largeur;
}

bool terrain::chargerDepuisFichier(const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cout << "Erreur : impossible d'ouvrir le fichier " << nomFichier << endl;
        return false;
    }

    fichier>>caseDepart>>caseArrivee;
    fichier >> d_hauteur >> d_largeur;
    d_grille.resize(d_hauteur, vector<bool>(d_largeur));
    bool c;
    for (int i = 0; i < d_hauteur; ++i) {
        for (int j = 0; j < d_largeur; ++j) {
            fichier >> c;
            d_grille[i][j] = c;
        }
    }
    fichier.close();
    return true;
}

bool terrain::sauvegarderDansFichier(const string& nomFichier) const {
    if (d_grille.empty() || d_grille[0].empty()) {
        cerr << "Erreur : le terrain est vide, impossible de sauvegarder." << endl;
        return false;
    }

    ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        cerr << "Erreur : impossible d'écrire dans le fichier " << nomFichier << endl;
        return false;
    }

    fichier << d_hauteur << " " << d_largeur << endl;
    for (const auto& ligne : d_grille) {
        for (char c : ligne) {
            fichier << c;
        }
        fichier << endl;
    }

    fichier.close();
    return true;
}

bool terrain::getCase(const Point& position) const {
    if (d_grille.empty() ) {
        cerr << "Erreur : le terrain est vide." << endl;
        return true ;
    }

    int x = position.getX();
    int y = position.getY();
    if (x >= 0 && x < d_largeur && y >= 0 && y < d_hauteur ) {
        return d_grille[y][x] ;
    }
 
   return false ;// Retourne un mur si hors limites
}

void terrain::setCase(const Point& position,bool valeur) {
    if (d_grille.empty() || d_grille[0].empty()) {
        cerr << "Erreur : le terrain est vide, impossible de définir une case." << endl;
        return;
    }

    int x = position.getX();
    int y = position.getY();
    if (x >= 0 && x < d_largeur && y >= 0 && y < d_hauteur ) {
        d_grille[y][x] = valeur;
    }
}

void terrain::setCaseDepart(const Point& position) {
    //setCase(position, 'S');
    caseDepart = position;
}

void terrain::setCaseArrivee(const Point& position) {
    //setCase(position, 'E');
    caseArrivee = position;
}

Point terrain::getCaseDepart() const {
    return caseDepart;
}

Point terrain::getCaseArrivee() const {
    return caseArrivee;
}

void terrain::afficherModeTexteSimple() const {
    if (d_grille.empty() || d_grille[0].empty()) {
        std::cout << "Terrain vide." << std::endl;
        return;
    }

    for (const auto& ligne : d_grille) {
        for (bool c : ligne) {
            std::cout << (c ? "X " : ". ");
        }
        std::cout << std::endl;
    }
}

void terrain::afficherModeTexteAmeliore1() const {
    if (d_grille.empty() || d_grille[0].empty()) {
        std::cout << "Terrain vide." << std::endl;
        return;
    }

    cout << "+";
    for (int i = 0; i < d_largeur; ++i) cout << "-";
    cout << "+" << endl;

    for (const auto& ligne : d_grille) {
        cout << "|";
        for (char c : ligne) {
            if (c == '#') cout << "#";
            else cout << c;
        }
        cout << "|" << endl;
    }

    cout << "+";
    for (int i = 0; i < d_largeur; ++i) cout << "-";
    cout << "+" << endl;
}

void terrain::afficherModeTexteAmeliore2() const {
    if (d_grille.empty() || d_grille[0].empty()) {
        std::cout << "Terrain vide." << std::endl;
        return;
    }

    cout << "┏";
    for (int i = 0; i < d_largeur; ++i) cout << "━";
    cout << "┓" << endl;

    for (const auto& ligne : d_grille) {
        cout << "┃";
        for (char c : ligne) {
            if (c == '#') cout << "█";
            else if (c == 'S') cout << "▷"; // Case départ
            else if (c == 'E') cout << "★"; // Case arrivée
            else cout << c;
        }
        cout << "┃" << endl;
    }

    cout << "┗";
    for (int i = 0; i < d_largeur; ++i) cout << "━";
    cout << "┛" << endl;
}

bool terrain::estAccessible(const Point& position) const {
    if (d_grille.empty() ) {
        cerr << "Erreur : le terrain est vide." << endl;
        return false;
    }

    int x = position.getX();
    int y = position.getY();
    return x >= 0 && x < d_largeur && y >= 0 && y < d_hauteur && !d_grille[y][x] ;
}
