#include "../headers/pledge.h"
pledge::pledge( const Robot &robot , const terrain &Terrain):d_robot {robot} , d_terrain {Terrain} , d_nombreCases {0}
{
    //ctor
}

pledge::~pledge()
{
    //dtor
}

void pledge::resoudre()  
{
   const int tournerADroite {-1} ;
   const int tournerAGauche {1}; 
   int decompteChangement {0}; 

  while ( !estSortie())
  { 
    //instruction 1 avancer tout droit jusqu'a au mur 
   while (!d_robot.detectObstacle(d_terrain))
    {
        d_robot.deplaceDevant() ;
        d_nombreCases++;
        std::cout << " a avancé avec l'instruction 1 \n";
         }
    //instruction 2
    //tourner à gauche pour longer le mur à droite ;
    d_robot.tourneGauche();
    decompteChangement+=tournerAGauche;
    
    do 
   { 
    if (estSortie())
    break;
    if (!d_robot.detectObstacleDroite(d_terrain)) 
    {
        // Si le mur à droite n'est pas présent, tourner à gauche pour le suivre
        d_robot.tourneDroite();
        decompteChangement += tournerADroite;
        if(!d_robot.detectObstacle(d_terrain))
          {d_robot.deplaceDevant();
        d_nombreCases++;
          }
    } 
    else if (!d_robot.detectObstacle(d_terrain)) 
    {
        // Si un obstacle est devant, tourner à gauche
        d_robot.deplaceDevant();
        d_nombreCases++;
    } 
    else 
    {
        // Sinon, avancer tout droit
       
         d_robot.tourneGauche();
        decompteChangement += tournerAGauche;
    }
  } while (decompteChangement != 0);


  }  

}

bool pledge::estSortie() const 
{ 
    return d_robot.getPosition() ==d_terrain.getCaseArrivee() ;
    return true ; 
}

int pledge::nombreCases () const 
{ 
    return d_nombreCases;
}