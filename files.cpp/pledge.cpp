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
            
            d_robot.deplaceDevant() ;
            d_nombreCases++;
            //if (!d_robot.murDroite())
            { if(!d_robot.detectObstacle(d_terrain) )
               {
                d_robot.tourneDroite(); 
                decompteChangement+=tournerADroite;
               }
             
            }
            
            
        }
     }


  } 

}

bool pledge::estSortie() const 
{ 
    //return d_robot.position() ==
    // d_terrain.getCaseArrivee() ;
    return true ; 
}

int pledge::nombreCases () const 
{ 
    return d_nombreCases;
}