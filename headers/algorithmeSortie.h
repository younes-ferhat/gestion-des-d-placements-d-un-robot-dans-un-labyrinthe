#ifndef ALGORITHMESORTIE_H
#define ALGORITHMESORTIE_H

#include "./terrain.h"
#include "./Robot.h"
#include "./affichage.h"

class algorithmeSortie
{
    public:
       algorithmeSortie(const Robot &robot , const terrain &Terrain);
       virtual  ~algorithmeSortie() =default;
       virtual void resoudre( Affichage &affichage) = 0 ;
        bool estSortie() const ;



    protected:
     Robot d_robot ;
     terrain d_terrain ;

};

#endif 