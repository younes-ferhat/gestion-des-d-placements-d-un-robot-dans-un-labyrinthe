#ifndef PLEDGE_H
#define PLEDGE_H
#include "../headers/Terrain.h"
#include "../headers/Robot.h"

class pledge
{
    public:
        pledge(const Robot &robot , const Terrain &terrain);
        void resoudre() ; 
       ~pledge();

    protected:

    private:
     Robot d_robot ; 
     Terrain d_terrain ; 
};

#endif // PLEDGE_H
