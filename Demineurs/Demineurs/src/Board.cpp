#include "Board.h"
#include "time.h"
#include<windows.h>
#include<iostream>
#include<string>
#include"Boomb.h"
#include "Reference.h"
#include "Case.h"
#include "White.h"
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std ;
void couleur(int color , string message)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle,color);
    cout << "   "<<message ;
    SetConsoleTextAttribute(handle,7);

}


Board::Board(int l, int c , int nb):ligne(l),colonne(c),nbMines(nb)
{

}

Board::~Board()
{
    //dtor
}
///////////////////////////////
// FONCTION PLACER LES MINES //
///////////////////////////////
void Board::placerBoomb(){
  int i,j;
   srand(time(NULL));
   int nb_mines = nbMines ;
   int compteMines;
       for (compteMines=0;compteMines<nb_mines;compteMines++)
       {
           i=rand()%ligne; j=rand()%colonne;
           if(matrix[i][j].getSymbol()=="X")//On vérifie que la case est libre
                 matrix[i][j]=Boomb();//on place un M pour indiquer qu'il y a une mine
           else
               nb_mines++;//Sinon, il y a déjà un M et il faut faire un tour de plus
       }
}

/////////////////////////////////////////////
// FONCTION CALCULER LE NB DE MINES AUTOUR //
/////////////////////////////////////////////
void Board::placerReference(){

    int cmp ;
    for(int i=0 ; i<ligne ; i++){
        for (int j=0 ; j<colonne ;j++)
            {
                cmp = 0 ;
                if (matrix[i][j].getSymbol()=="X")
                  {
                    if ( (i-1 >=0)  && (j-1 >= 0)  && matrix[i-1][j-1].getSymbol()=="M" ) cmp++;
                    if ( (i-1 >=0) && (j >= 0) && (matrix[i-1][j].getSymbol()=="M"))  cmp++;

                    if ( (i-1 >=0) && (j+1 >= 0) && (j+1<colonne) && (matrix[i-1][j+1].getSymbol()=="M")) cmp++;

                    if ( (i >=0) && (j+1 >= 0) && (j+1 <colonne) && matrix[i][j+1].getSymbol()=="M") cmp++;
                    if ( (i >=0) && (j-1 >= 0) && matrix[i][j-1].getSymbol()=="M") cmp++;

                    if ( (i+1 >=0) && (j-1 >= 0) && (i+1 <ligne) && matrix[i+1][j-1].getSymbol()=="M") cmp++;
                    if ( (i+1 >=0) && (j >= 0) && (i+1 <ligne) && matrix[i+1][j].getSymbol()=="M") cmp++;
                    if ( (i+1 >=0) && (j+1 >= 0) && (i+1 <ligne) && (j+1 <colonne) && matrix[i+1][j+1].getSymbol()=="M") cmp++;
                 }

                 if (matrix[i][j].getSymbol()=="X" && cmp >0)
                       matrix[i][j]= Reference(cmp);

            }
    }
}
////////////////////////////////
//FONCTION PLACER UN DRAPEAU ///
///////////////////////////////
void Board::placerDrapeau(int i , int j){
    if (matrix[i][j].getFlag()==true)
        matrix[i][j].setFlag(false);
    else
        matrix[i][j].setFlag(true);

}
////////////////////////////////////////////////
//FONCTION CALCULER LE NB DE CAS NON DEVOILES //
///////////////////////////////////////////////
int Board::nbCovered(){
    int cov=0;
    for(int i=0;i<ligne;i++)
        for(int j=0;j<colonne;j++)
    {
        if (matrix[i][j].getCovered()==true)
        cov ++;
    }
    return cov;
}
/////////////////////////////////////////////
//     FONCTION DEVOILER UNE CASE          //
/////////////////////////////////////////////
int Board::creuser(int i , int j){

if (i<ligne && j<colonne && i>=0 && j>=0 &&  matrix[i][j].getCovered()==true &&matrix[i][j].getFlag()==false)
{


    matrix[i][j].setCovered(false);

    if(matrix[i][j].getSymbol()=="M") return 0;

    else if (matrix[i][j].getSymbol()=="X")
    {
                    creuser(i-1,j-1);
                    creuser(i-1,j);
                    creuser(i-1,j+1);
                    creuser(i,j+1);
                    creuser(i,j-1);
                    creuser(i+1,j-1);
                    creuser(i+1,j);
                    creuser(i+1,j+1);

                    return 1 ;

}

else return 2;
}

return -1;

}




//////////////////////////////
// FONCTION INITIALISATION ///
//////////////////////////////
void Board::initialiser(){

    for (int i=0;i<ligne;i++)
        {
            for (int j=0;j<colonne;j++)
            {
                   matrix[i][j]=White();
            }

            }

}


void Board::tout_afficher()
{
    for (int i=0 ; i<ligne;i++)
            for(int j=0;j<colonne;j++){
                            matrix[i][j].setCovered(false);

                                    }
                                     afficher();

}


////////////////////////////////////////
// FONCTION AFFICHER LA GRILLE DE JEU //
////////////////////////////////////////
void Board::afficher(){
    cout<<"\n\n\n";
     cout<<"                                                ";

    for (int i=0;i<colonne;i++)
    {   if(i<9)
            cout<<" "<<i+1<<"  ";
        else
            cout<<" "<<i+1<<" ";
    }cout<<endl;

    for (int i=0;i<ligne;i++)
        {

            cout<<"                                         ";
            if(i<9)
              printf(" %d | ",i+1);
                      else
                      printf("%d | ",i+1);
            for (int j=0;j<colonne;j++)
            {

            if(matrix[i][j].getFlag()==true)
                        cout<<"   D";
                        else {
            if (matrix[i][j].getCovered()==false)
                {

                        couleur(matrix[i][j].getColor(),matrix[i][j].getSymbol());
                }


                else couleur(15,"#");
            }
            }

            cout<<endl;

            }


}

