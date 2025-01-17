#include "../headers/pledge.h"
pledge::pledge( const Robot &robot , const terrain &Terrain):algorithmeSortie{robot,Terrain}
{}

pledge::~pledge()
{
    //dtor
}

void pledge::resoudre( Affichage &affichage)
{
   const int tournerADroite {-1} ;
   const int tournerAGauche {1};
   int decompteChangement {0};

  while ( !estSortie())
  {
    //instruction 1 avancer tout droit jusqu'a au mur
   while (!d_robot.detectObstacleDevant(d_terrain))
    {
        d_robot.deplaceDevant() ;
        affichage.maj(d_terrain,d_robot);
      
         }
    //instruction 2
    //tourner Ã  gauche pour longer le mur Ã  droite ;
    d_robot.tourneGauche();
     affichage.maj(d_terrain,d_robot);
    decompteChangement+=tournerAGauche;

    do
   {
    if (estSortie())
    break;
    if (!d_robot.detectObstacleDroite(d_terrain))
    {
        // Si le mur Ã  droite n'est pas prÃ©sent, tourner Ã  gauche pour le suivre
        d_robot.tourneDroite();
         affichage.maj(d_terrain,d_robot);
        decompteChangement += tournerADroite;
        if(!d_robot.detectObstacleDevant(d_terrain))
          {d_robot.deplaceDevant();
           affichage.maj(d_terrain,d_robot);
        
          }
    }
    else if (!d_robot.detectObstacleDevant(d_terrain))
    {
        // Si un obstacle est devant, tourner Ã  gauche
        d_robot.deplaceDevant();
         affichage.maj(d_terrain,d_robot);
       
    }
    else
    {
        // Sinon, avancer tout droit

         d_robot.tourneGauche();
          affichage.maj(d_terrain,d_robot);
        decompteChangement += tournerAGauche;
    }
  } while (decompteChangement != 0);


  }

}

