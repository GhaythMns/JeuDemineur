#ifndef BOOMB_H
#define BOOMB_H
#include "Case.h"


class Boomb : public Case
{
    public:
        Boomb(string s="M");
        virtual ~Boomb();
        void placerBoomb();
        void afficher();

    protected:

    private:
};

#endif // BOOMB_H
