#include <cstdlib>
#include <string.h>
#include <iostream>
#include "jogo.h"

using namespace std;

/* FUNÇÕES E PROCEDIMENTOS */
int menu();
int menuEscolherPersonagem();
/* END FUNÇÕES E PROCEDIMENTOS */

/* --------------------------------------------------------------------------------------------------------- */

/* INT MAIN */
int main()
{

    int op;

    cout << "\nSeja bem vindo ao Batalha Medieval! :D";

    op = menu();

    while (op != 3)
    {
        if (op == 1)
        {
            menuEscolherPersonagem();
            op = menu();
        }
        else if (op == 2)
        {
        }
    }

    cout << "\nObrigado por jogar, volte sempre! :D";

    return 0;
}
/* END INT MAIN */

/* --------------------------------------------------------------------------------------------------------- */

/******************************************
********* FUNÇÕES E PROCEDIMENTOS *********
******************************************/

/* MENU */
int menu()
{
    int op;

    cout << "\nMENU";
    cout << "\n1 - Escolher Personagem";
    cout << "\n2 - Comecar a Jogar";
    cout << "\n3 - Sair";
    cout << "\n\nOpcao escolhida: ";
    cin >> op;

    while (op < 1 || op > 3)
    {
        cout << "Opcao invalida, insira novamente: ";
        cin >> op;
    }

    return op;
}
/* END MENU */

/* MENU ESCOLHER PERSONAGEM */
int menuEscolherPersonagem()
{
    int op, cod1, cod2;

    cout << "\nMENU ESCOLHER PERSONAGEM";
    cout << "\n1 - Jogador 1";
    cout << "\n2 - Jogador 2";
    cout << "\n3 - Retornar ao menu";

    cout << "\n\nOpcao escolhida: ";
    cin >> op;

    while (op < 1 || op > 3)
    {
        cout << "Opcao invalida, insira novamente: ";
        cin >> op;
    }

    if (op != 3)
    {
        cout << "\nMENU ESCOLHER PERSONAGEM";
        cout << "\n\nHUMANOS:";
        cout << "\n   1 - Guerreiro";
        cout << "\n   2 - Ladrao";
        cout << "\n   3 - Mago";
        cout << "\n   4 - Paladino";
        cout << "\n\nINUMANOS:";
        cout << "\n   5 - Animal";
        cout << "\n   6 - Troll";
        cout << "\n   7 - Dragao";
        cout << "\n   8 - Zumbi";
    }

    if (op == 1)
    {
        cout << "\n\nOpcao escolhida: ";
        cin >> cod1;

        while (cod1 < 1 || cod1 > 8)
        {
            cout << "Opcao invalida, insira novamente: ";
            cin >> cod1;
        }
    }
    else if (op == 2)
    {
        cout << "\n\nOpcao escolhida: ";
        cin >> cod2;

        while (cod2 < 1 || cod2 > 8)
        {
            cout << "Opcao invalida, insira novamente: ";
            cin >> cod2;
        }
    }
    else
    {
        return 0;
    }

    return 0;
}
/* END MENU ESCOLHER PERSONAGEM */