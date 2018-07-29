#ifndef WHITE_H
#define WHITE_H
#include"Case.h"
#include<string>




class White : public Case
{
    public:
        White(std::string s="X");
        virtual ~White();

    protected:

    private:
};

#endif // WHITE_H
