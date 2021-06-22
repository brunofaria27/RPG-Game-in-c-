#include <cstdlib>
#include <string.h>
#include <iostream>
#include <ctime>
#include <ctype.h>
#include "jogo.h"

using namespace std;

/* FUNÇÕES E PROCEDIMENTOS */
int menu();
int menuAcoes();
void menuEscolherPersonagem(Personagem *p, int jogador);
int Agir(Personagem *p1, Personagem *p2, int atacante, int acao);
int menuMagias(Personagem *p);
int menuArmas(Personagem *p);
/* END FUNÇÕES E PROCEDIMENTOS */

/* --------------------------------------------------------------------------------------------------------- */

/* INT MAIN */
int main()
{
    int op;
    Personagem *p1 = new Personagem();
    Personagem *p2 = new Personagem();

    cout << "\nSeja bem vindo ao Batalha Medieval! :D";

    op = menu();

    while (op != 3)
    {
        if (op == 1)
        {
            cout << "\nExplicacao de como jogar\n";
            system("pause");

            op = menu();
        }
        else if (op == 2)
        {   
            menuEscolherPersonagem(p1, 1);
            cout << "\nvida 1 = " << p1->getVida();
            cout << "\nNome 1 = " << p1->getNome();

            menuEscolherPersonagem(p2, 2);
            cout << "\nvida 2 = " << p2->getVida();
            cout << "\nNome 2 = " << p2->getNome();

            int turno = 1, jogador = 1, acao, op2;
            int vida1 = p1->getVida(), vida2 = p2->getVida();

            while (vida1 > 0 && vida2 > 0)
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
                    while (acao == 3)
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
                            cout << "Parabens! Voce perdeu por W.O!\nVencedor: Jogador 1";
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
                turno++;
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

int Agir(Personagem *p1, Personagem *p2, int atacante, int acao)
{
    if (acao == 1)
    {
        int codMagia;

        if (atacante == 1)
        {
            codMagia = menuMagias(p1);
        }
        else
        {
            codMagia = menuMagias(p2);
        }
    }
}

/* MENU MAGIAS */
int menuMagias(Personagem *p)
{
    /*cout << "\nMENU DE MAGIAS DE " << toupper(p->getNome());
    int i = 1, codM = 1, codP = p->getCodP;

    for (codM = 1; codM <= 7; codM++)
    {
        if(p->getCodP == 4 || p->getCodP == 5){
            cout << i++ << 
        }
    }

    return codM;*/
}

/* END MENU MAGIAS */

/* MENU ACOES */
int menuAcoes()
{
    int op;

    cout << "\nMENU DE ACOES";
    cout << "\n1 - Usar Magia";
    cout << "\n2 - Usar Arma";
    cout << "\n3 - Sair do jogo";

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

    cout << "\n\nMENU";
    cout << "\n1 - Como Jogar";
    cout << "\n2 - Jogar";
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
void menuEscolherPersonagem(Personagem *p, int jogador)
{
    int cod;

    cout << "\n\nESCOLHA SEU PERSONAGEM, JOGADOR " << jogador;

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

    cout << "\n\nOpcao escolhida: ";
    cin >> cod;

    while (cod < 1 || cod > 8)
    {
        cout << "\n\nOpcao invalida, insira novamente: ";
        cin >> cod;
    }

    string nome;
    cout << "\nNome: ";
    cin >> nome;

    if (cod == 1)
    {
        p->setPersonagem("Guerreiro", 1, nome, 4000, 30, 100, 20, 80, 20, 20);
    }
    else if (cod == 2)
    {
        p->setPersonagem("Ladrao", 2, nome, 2800, 50, 50, 30, 40, 50, 80);
    }
    else if (cod == 3)
    {
        p->setPersonagem("Mago", 3, nome, 2500, 100, 40, 100, 30, 80, 40);
    }
    else if (cod == 4)
    {
        p->setPersonagem("Paladino", 4, nome, 3200, 80, 60, 50, 60, 60, 60);
    }
    else if (cod == 5)
    {
        p->setPersonagem("Animal", 5, nome, 3200, 30, 80, 20, 80, 20, 50);
    }
    else if (cod == 6)
    {
        p->setPersonagem("Troll", 6, nome, 2800, 20, 100, 20, 80, 20, 20);
    }
    else if (cod == 7)
    {
        p->setPersonagem("Dragao", 7, nome, 3000, 40, 100, 20, 50, 50, 30);
    }
    else if (cod == 8)
    {
        p->setPersonagem("Zumbi", 8, nome, 2500, 20, 40, 20, 40, 80, 50);
    }

    cout << "\nPersonagem criado!\n";
    cout << "\nClasse: " << p->getClasse();
    cout << "\nNome: " << p->getNome();
    cout << "\nVida: " << p->getVida();
    cout << "\nMana: " << p->getMana();
    cout << "\nForca fisica: " << p->getFisica();
    cout << "\nForca magica: " << p->getMagica();
    cout << "\nArmadura: " << p->getResistFisica();
    cout << "\nResistencia magica: " << p->getResistMagica();
    cout << "\nAgilidade: " << p->getAgilidade();

}
/* END MENU ESCOLHER PERSONAGEM */
