#include "Case.h"
#include<string>
using namespace std ;

Case::Case()
{
 covered=true;
   color=15;
}

Case::Case(string s):symbol(s)
{
    covered=true;
    color=15;
    flag=false;
}

Case::~Case()
{
    //dtor
}

 bool Case::getCovered(){
        return covered;
 }

void Case::setCovered(bool b){
    covered=b ;
}

 int Case::getColor(){
        return color;
 }

void Case::setColor(int c){
    color=c ;
}

 string Case::getSymbol(){
        return symbol;
 }

void Case::setSymbol(string s){
    symbol=s ;
}
bool Case::getFlag(){
    return flag;
}
void Case::setFlag( bool f){
    flag=f;
}

