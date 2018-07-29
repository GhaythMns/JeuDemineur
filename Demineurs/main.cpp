#include"Board.h"
#include<bits/stdc++.h>
#include<windows.h>


using namespace std;
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
//waiting a i seconds
void delay(int i){
  clock_t start,end;
  start=clock();
  while(((end=clock())-start)<=i*CLOCKS_PER_SEC);
}

void afficher_scores(){
    ifstream fichier("score.txt");
      if(fichier)
      {
            string ligne; //Une variable pour stocker les lignes lues
            while(getline(fichier, ligne)) //Tant qu'on n'est pas à la fin, on lit
            {
                  cout << ligne << endl;   //Et on l'affiche dans la console
            }
      }

}

int main()
{   Color(11,0);
    cout<<"                                       __________________________________________"<<endl;
    cout<<"                                      |                                          |"<<endl;
    cout<<"                                      |             Jeu du demineur              |"<<endl;
    cout<<"                                      |__________________________________________|"<<endl<<endl;
    while(1) {int e,f,bo,choix;
    int nb=0;
    int choice;
    string name;

    Color(10,0);
    cout<<"tapez --1-- pour jouer"<<endl;
    cout <<"tapez --2-- pour voir les scores"<<endl;
    cout<<"tapez --3-- pour lire la regle de jeu"<<endl;
    cout<<"tapez --4-- pour quitter"<<endl;

    Color(15,0);
    cin>>choice;
    switch(choice){
    case 1:
    {
        cout<<"                                               START NEW GAME"<<endl;
        cout<<"donner la taille du matrice : lignes [espace] colonnes"<<endl;
        cin>>e>>f;
        cout<<"combien de mines voulez-vous!"<<endl;
        cin>>bo;
        cout<<"D'accord, vous avez choisi de jouer avec "<< bo << " mines" << endl;
        cout <<" Voici votre grille : A vous de jouer !\n\n" <<endl;


        Board b = Board(e,f,bo);
        b.initialiser();
        b.placerBoomb();
        b.placerReference();
        b.afficher();

        int l , c ;
        while (true){
                cout <<"Veuillez entrer la case choisie (numero de ligne [espace] numero de colonne):\t ";
                cin >> l >> c;
                cout<<"tapez --1-- pour decouvrir une case"<<endl;
                cout<<"tapez --2--pour placer un drapeau"<<endl;
                cout<<"tapez --3--pour arreter de jouer"<<endl;
                cout<<"tapez --4--pour mettre en pause le jeu"<<endl;
                cin>>choix;
                switch(choix){
                    case 1:{
                        int v =b.creuser(l-1,c-1);
                        system("cls");
                        b.afficher();
                        if (v==0){
                                cout<<endl<<endl;
                                system("cls");
                                cout << "                      YOU LOOOOOSED!!"<<endl;

                                b.tout_afficher();
                               return 0;
                        }

                        if (v==1 || v==2)
                            {
                                   nb+=10;
                                    if (b.nbCovered()==bo)
                                    {
                                            cout<<endl<<endl;
                                            cout<<"YEEEEES!!YOU WON BRAVOOOO"<<endl;
                                            cout<<"your record is :"<<nb<<endl;
                                            cout<<"YOUR NAME : ";
                                            cin>>name;
                                            return 0;
                                            ofstream fichier("score.txt", ios::app);  // on ouvre en lecture
                                            if(fichier)  // si l'ouverture a fonctionné
                                                {
                                                    fichier <<"player : "<<name<<" score : "<<nb<<endl;
                                                    fichier.close();
                                                }
                                        break;
                                    }



                            }

                            else
                                cout<<"code errone(numero de case invalide ou Drapeau mis)"<<endl;


                    break;
                    }

                case 2:{
                    b.placerDrapeau(l-1,c-1);
                    system("cls");
                    b.afficher();
                    break;
                    }
                //arreter de jouer
                case 3:{
                    exit(0);
                }
                //mettre en pause le jeu jusqu'a la prochaine ENTRER
                case 4:{
                    std::cin.ignore();
                    std::cin.get();
                }
                }

    }

        break;
  }
        case 2 :
        {

            afficher_scores();
            delay(1);
            break;

        }

        case 3:{
            Color(13,0);
            cout<<"                                    REGLE DE JEU"<<endl;
            cout<<"                    Vous disposez d'une grille contenant des mines cachees."<<endl;
            cout<<"   En choisissant une case vous connaissez le nombre de mines se trouvant dans les cases ( 8 au maximum) qui l'entourent"<<endl;
            cout<<"               Le but du jeu est de détecter toutes les mines sans cliquer dessus."<<endl;
            delay(3);
            Color(15,0);
            break;
        }
        case 4:
            exit(0);
            break;
    }
}
}



