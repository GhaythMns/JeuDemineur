#include "Reference.h"
#include "Case.h"
#include<string>

Reference::Reference(int n):number(n)
{
    symbol= '0'+n;
    if (n==1) color =9;
    else color = n;

}

Reference::~Reference()
{
    //dtor
}
