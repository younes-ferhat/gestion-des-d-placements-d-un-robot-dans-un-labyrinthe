#ifndef PLEDGE_H
#define PLEDGE_H

class robot ;
class terrain ;
class pledge
{
    public:
        pledge(const robot &robot , const terrain &terrain);
        void resoudre() ; 
       ~pledge();

    protected:

    private:
     robot d_robot ; 
     terrain d_terrain ; 
};

#endif // PLEDGE_H
