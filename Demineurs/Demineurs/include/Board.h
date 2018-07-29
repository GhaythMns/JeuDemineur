#ifndef BOARD_H
#define BOARD_H
#include "Case.h"


class Board
{
    public:
        Board(int l, int c , int nb);
        virtual ~Board();
        void placerBoomb();
        void afficher();
        void placerReference();
        void initialiser();
        int creuser(int i , int j);
        int nbCovered();
        void placerDrapeau(int i , int j);
        void tout_afficher();
        //void afficher_scores();


    protected:

    private:
        Case matrix [100][100];
        int ligne;
        int colonne ;
        int score ;
        int coups;
        int nbMines;
};

#endif // BOARD_H
