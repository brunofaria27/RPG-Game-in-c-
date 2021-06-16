#include <cstdlib>
#include <string.h>
#include <iostream>
#include <ctime>
#include "jogo.h"

using namespace std;

/* FUNÇÕES E PROCEDIMENTOS */
int menu();
int menuAcoes();
int menuEscolherPersonagem(Personagens *p1, Personagens *p2);
void criaPersonagem(int cod, Personagens *p);
int Agir(Personagens *p1, Personagens *p2, int atacante, int acao);
/* END FUNÇÕES E PROCEDIMENTOS */

/* --------------------------------------------------------------------------------------------------------- */

/* INT MAIN */
int main()
{
    int op;
    Personagens *p1, *p2;

    cout << "\nSeja bem vindo ao Batalha Medieval! :D";

    op = menu();

    while (op != 3)
    {
        if (op == 1)
        {
            menuEscolherPersonagem(p1, p2);
            op = menu();
        }
        else if (op == 2)
        {
            int turno, jogador = 1, acao, op2;

            for (turno = 1; (p1->getVida() > 0 && p2->getVida() > 0); turno++)
            {
                cout << "\nTURNO " << turno;

                if (jogador == 1)
                {
                    cout << "\nVez do jogador " << jogador;
                    acao = menuAcoes();
                    while (acao == 4)
                    {
                        cout << "\nDeseja sair e perder todo o progresso do jogo? (1 - Prosseguir; 2 - Cancelar)\n";
                        cin >> op2;

                        while (op2 > 2 || op2 < 1)
                        {
                            cout << "Opcao invalida, insira novamente: ";
                            cin >> op2;
                        }

                        if (op2 == 1)
                        {
                            cout << "Parabens! Voce perdeu por W.O!\nVencedor: Jogador 2";
                            cout << "Obrigado por jogar mais ou menos! Da proxima ve se termina :D";
                            return 0;
                        }
                        else
                        {
                            acao = menuAcoes();
                        }
                    }
                    Agir(p1, p2, jogador, acao);
                    jogador++;
                }
                else
                {
                    cout << "\nVez do jogador " << jogador;
                    acao = menuAcoes();
                    while (acao == 4)
                    {
                        cout << "\nDeseja sair e perder todo o progresso do jogo? (1 - Prosseguir; 2 - Cancelar)\n";
                        cin >> op2;

                        while (op2 > 2 || op2 < 1)
                        {
                            cout << "Opcao invalida, insira novamente: ";
                            cin >> op2;
                        }

                        if (op2 == 1)
                        {
                            return 0;
                        }
                        else
                        {
                            acao = menuAcoes();
                        }
                    }
                    Agir(p1, p2, jogador, acao);
                    jogador--;
                }
            }
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

int Agir(Personagens *p1, Personagens *p2, int atacante, int acao)
{
    if(acao == 1){
        
    }
}

/* MENU ACOES */
int menuAcoes()
{
    int op;

    cout << "\nMENU DE ACOES";
    cout << "\n1 - Usar Magia de cura";
    cout << "\n2 - Usar Magia de ataque";
    cout << "\n3 - Usar Arma";
    cout << "\n4 - Sair do jogo";

    cout << "\n\nOpcao escolhida: ";
    cin >> op;

    while (op < 1 || op > 3)
    {
        cout << "Opcao invalida, insira novamente: ";
        cin >> op;
    }

    return op;
}
/* END MENU ACOES */

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
int menuEscolherPersonagem(Personagens *p1, Personagens *p2)
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

        criaPersonagem(cod1, p1);
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

        criaPersonagem(cod2, p2);
    }
    else
    {
        return 0;
    }

    return 0;
}
/* END MENU ESCOLHER PERSONAGEM */

void criaPersonagem(int cod, Personagens *p)
{
    if (cod == 1)
    {
        p = new Personagens("Guerreiro", 1, 4000, 30, 100, 20, 80, 20, 20);
    }
    else if (cod == 2)
    {
        p = new Personagens("Ladrao", 2, 2800, 50, 50, 30, 40, 50, 80);
    }
    else if (cod == 3)
    {
        p = new Personagens("Mago", 3, 2500, 100, 40, 100, 30, 80, 40);
    }
    else if (cod == 4)
    {
        p = new Personagens("Paladino", 4, 3200, 80, 60, 50, 60, 60, 60);
    }
    else if (cod == 5)
    {
        p = new Personagens("Animal", 5, 3200, 30, 80, 20, 80, 20, 50);
    }
    else if (cod == 6)
    {
        p = new Personagens("Troll", 6, 2800, 20, 100, 20, 80, 20, 20);
    }
    else if (cod == 7)
    {
        p = new Personagens("Dragao", 7, 3000, 40, 100, 20, 50, 50, 30);
    }
    else if (cod == 8)
    {
        p = new Personagens("Zumbi", 8, 2500, 20, 40, 20, 40, 80, 50);
    }
}
