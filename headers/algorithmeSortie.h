#ifndef ALGORITHMESORTIE_H
#define ALGORITHMESORTIE_H

#include "./terrain.h"
#include "./Robot.h"

class algorithmeSortie
{
    public:
       algorithmeSortie(const Robot &robot , const terrain &Terrain);
       virtual  ~algorithmeSortie() =default;
       virtual void resoudre() = 0 ; 
        bool estSortie() const ;
       // int nombreCases() const ;
      

    protected:
     Robot d_robot ; 
     terrain d_terrain ; 
    int d_nombreCases ;
};


#endif 