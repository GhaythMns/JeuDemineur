#ifndef CASE_H
#define CASE_H
#include<string>

using namespace std;
class Case
{
    public:
        Case();
        Case(string s);
        virtual ~Case();
        bool getCovered();
        void setCovered(bool b);
        void setColor(int c);
        int getColor();
        bool getFlag();
        void setFlag( bool f);
        string getSymbol();
        void setSymbol(string s);
    protected:
         string symbol;
        bool covered;
        int color ;
        bool flag;

    private:


};

#endif // CASE_H
