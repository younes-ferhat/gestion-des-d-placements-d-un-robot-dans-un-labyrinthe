#include "../headers/pledge.h"
pledge::pledge( const Robot &robot , const Terrain &terrain):d_robot {robot} , d_terrain {terrain}
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

  while ( true)
  { 
    //instruction 1 avancer tout droit jusqu'a au mur 
    while (!d_robot.detectObstacle(d_terrain))
    {
        d_robot.deplaceDevant() ;
    }
    //instruction 2
    //tourner à gauche pour longer le mur à droite ;
    d_robot.tourneGauche();
    decompteChangement+=tournerAGauche;
    
     while ( decompteChangement!= 0 )
     {
        if (d_robot.detectObstacle(d_terrain) )
        {
            d_robot.tourneGauche();
            decompteChangement+=tournerAGauche;
        }
        else 
        {
            d_robot.tourneDroite(); 
            decompteChangement+=tournerADroite;
            
        }
     }


  } 

}