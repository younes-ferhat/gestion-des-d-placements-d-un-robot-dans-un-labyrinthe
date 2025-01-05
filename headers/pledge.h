#ifndef PLEDGE_H
#define PLEDGE_H
#include "../headers/terrain.h"
#include "../headers/Robot.h"
#include "../headers/algorithmeSortie.h"



class pledge : public algorithmeSortie
{
    public:
        pledge(const Robot &robot , const terrain &Terrain);
            void resoudre( Affichage &affichage) override;
           ~pledge();

 

    private:
    
};

#endif // PLEDGE_H
