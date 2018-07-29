#ifndef REFERENCE_H
#define REFERENCE_H
#include "Case.h"


class Reference: public Case
{
    public:
        Reference(int n);
        virtual ~Reference();

    protected:

    private:
        int number;
};

#endif // REFERENCE_H
