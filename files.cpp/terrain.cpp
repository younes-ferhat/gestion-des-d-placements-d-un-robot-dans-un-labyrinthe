#include "../headers/terrain.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

terrain::terrain() : d_grille {} {}

terrain::terrain(int d_largeur, int d_hauteur) : d_largeur(d_largeur), d_hauteur(d_hauteur) {
    d_grille.resize(d_hauteur, vector<bool>(d_largeur, '.'));
}
  int terrain:: getHauteur() const{
    return d_hauteur;
  }
  int terrain:: getLargeur()const{
        return d_largeur;
    }

bool terrain::chargerDepuisFichier(const string& nomFichier) {
    ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cout << "Erreur : impossible d'ouvrir le fichier " << nomFichier << endl;
        return false;
    }

    fichier >> d_hauteur >> d_largeur;
    d_grille.resize(d_hauteur, vector<bool>(d_largeur));
    bool c;
    for (int i = 0; i < d_hauteur; ++i) {
        for (int j = 0; j < d_largeur; ++j) {
            fichier>>c; 
            d_grille[i][j]=c;

           /* fichier >> d_grille[i][j];
            if (d_grille[i][j] == 'S') {
              caseDepart = Point(i, j);}
               // Conversion en Point

           else if (d_grille[i][j] == 'E') {
              caseArrivee = Point(i, j); // Conversion en Point */
}

        }
        fichier.close();
    return true;

    }

    

bool terrain::sauvegarderDansFichier(const string& nomFichier) const {
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

char terrain::getCase(const Point& position) const {
    int x = position.getX();
    int y = position.getY();
    if (x >= 0 && x < d_hauteur && y >= 0 && y < d_largeur) {
        return d_grille[x][y];
    }
    return '#'; // Retourne un mur si hors limites
}

void terrain::setCase(const Point& position, char valeur) {
    int x = position.getX();
    int y = position.getY();
    if (x >= 0 && x < d_hauteur && y >= 0 && y < d_largeur) {
        d_grille[x][y] = valeur;
    }
}

void terrain::setCaseDepart(const Point& position) {
    caseDepart = position;
    setCase(position, 'S');
}

void terrain::setCaseArrivee(const Point& position) {
    caseArrivee = position;
    setCase(position, 'E');
}


Point terrain::getCaseDepart() const {
    return caseDepart;
}

Point terrain::getCaseArrivee() const {
    return caseArrivee;
}

void terrain::afficherModeTexteSimple() const {
    for (const auto& ligne : d_grille) {
        for (char c : ligne) {
            if (c)
            {
            std::cout<<"X "; 
            }
            else 
            {
               std::cout << ". ";
            }
          
            
        }
        cout << endl;
    }
}

void terrain::afficherModeTexteAmeliore1() const {
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
    int x = position.getX();
    int y = position.getY();
    return x >= 0 && x < d_hauteur && y >= 0 && y < d_largeur && d_grille[x][y] != '#';
}