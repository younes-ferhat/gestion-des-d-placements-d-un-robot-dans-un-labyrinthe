#include "../headers/algorithmeSortie.h"

algorithmeSortie::algorithmeSortie(const Robot &robot, const terrain &Terrain) :d_robot {robot} , d_terrain {Terrain}
{
}

bool algorithmeSortie::estSortie() const
{
     return d_robot.getPosition() ==d_terrain.getCaseArrivee() ;;
}