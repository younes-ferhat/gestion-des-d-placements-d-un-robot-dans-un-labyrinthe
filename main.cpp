#include <iostream>

int main() 
{   
    std::cout << "show the labyrinth "<<std::endl ;
    int m=9;
    int n=7;
    for (int i = 0; i <8 ; i++) {
        for (int j = 0; j < 9; j++) {
         if (i == 0 && j == 1) {
                std::cout << "  ";
            }
            // Ajouter la sortie (droite de la dernière ligne)
            else if (i == n - 1 && j == m - 2) {
                std::cout << "  ";
            }
            // Bords extérieurs
            else if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                std::cout << "* ";
            }
            // Mur tous les deux blocs pour former des "salles"
            else if (i % 2 == 0 && j % 2 == 0) {
                std::cout << "* ";
            }
            // Ajouter un mur entre certaines "salles" pour plus de structure
            else if (i % 2 == 0 || j % 2 == 0) {
                std::cout << "* ";
            }
            // Espaces vides pour les chemins
            else {
                std::cout << "  ";
            }
        }
        std::cout <<std:: endl;
    }

    return 0;
}