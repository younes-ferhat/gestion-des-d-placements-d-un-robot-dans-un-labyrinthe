#ifndef PLEDGE_H
#define PLEDGE_H
#include "../headers/terrain.h"
#include "../headers/Robot.h"

class pledge
{
    public:
        pledge(const Robot &robot , const terrain &Terrain);
        void resoudre() ; 
       ~pledge();

    protected:

    private:
     Robot d_robot ; 
     terrain d_terrain ; 
};

#endif // PLEDGE_H
