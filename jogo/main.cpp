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
void menuEscolherPersonagem(Personagem &p, int jogador);
void usarMagia(int codMagia, Personagem &p2, Personagem &p1);
int menuMagias(Personagem &p);
int menuArmas(Personagem &p);
/* END FUNÇÕES E PROCEDIMENTOS */

/* --------------------------------------------------------------------------------------------------------- */

/* INT MAIN */
int main()
{
    int op;
    Personagem p1;
    Personagem p2;

    cout << "\nSeja bem vindo ao Batalha Medieval! :D";

    op = menu();

    while (op != 3)
    {
        if (op == 1)
        {
            cout << "\nExplicacao de como jogar\n";
            system("pause");
            system("cls");

            op = menu();
        }
        else if (op == 2)
        {
            menuEscolherPersonagem(p1, 1);

            menuEscolherPersonagem(p2, 2);

            int turno = 1, jogador = 1, acao, op2;

            int vida1 = p1.getVida(), vida2 = p2.getVida();

            while (vida1 > 0 && vida2 > 0)
            {
                cout << "\n\nTURNO " << turno;

                if (jogador == 1)
                {
                    cout << "\n\n"
                         << p1.getNome() << ", escolha sua acao.";
                    cout << "\n\nVida atual: " << p1.getVida();
                }
                else
                {
                    cout << "\n\n"
                         << p2.getNome() << ", escolha sua acao.";
                    cout << "\n\nVida atual: " << p2.getVida();
                }

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
                        cout << "Parabens! Voce perdeu por W.O!\nVencedor: ";
                        if (jogador == 1)
                        {
                            cout << jogador + 1;
                        }
                        else
                        {
                            cout << jogador - 1;
                        }
                        return 0;
                    }
                    else
                    {
                        acao = menuAcoes();
                    }
                }

                if (acao == 1)
                {
                    int codMagia;

                    if (jogador == 1)
                    {
                        codMagia = menuMagias(p1);
                        if (codMagia == 0)
                        {
                            jogador--;
                            turno--;
                        }
                        else
                        {
                            usarMagia(codMagia, p2, p1);
                        }
                    }
                    else
                    {
                        codMagia = menuMagias(p2);
                        if (codMagia == 0)
                        {
                            jogador++;
                            turno--;
                        }
                        else
                        {
                            usarMagia(codMagia, p1, p2);
                        }
                    }
                }
                else if (acao == 2)
                {
                }
                else
                {
                    if (jogador == 2)
                    {
                        p1.printAtributos();
                        jogador--;
                        turno--;
                    }
                    else
                    {
                        p2.printAtributos();
                        jogador++;
                        turno--;
                    }
                }

                if (jogador == 1)
                {
                    jogador++;
                }
                else
                {
                    jogador--;
                }
            }
            turno++;
        }
    }

    cout << "\nObrigado por jogar, volte sempre! :D";

    return 0;
}
/* END INT MAIN */

/* --------------------------------------------------------------------------------------------------------- */

/*************************************************************************************************************
********* FUNÇÕES E PROCEDIMENTOS ****************************************************************************
*************************************************************************************************************/

/* MENU MAGIAS */
int menuMagias(Personagem &p)
{
    cout << "\nMagias disnponiveis para " << p.getClasse();

    int i = 1, codM = 1, codP = p.getCodP();

    cout << "\n\n0 - Retornar ao menu de acoes";

    if (codP == 4 || codP == 5)
    {
        cout << i++ << "\n- Pocao de vida\nRestaura 200 pontos de vida\nGasta 12 pontos de mana";
    }
    if (codP == 7)
    {
        cout << i++ << "\n\n- Halito de Fogo\nCausa 400 de dano\nGasta 12 pontos de mana";
    }
    if (codP == 3 || codP == 5)
    {
        cout << i++ << "\n\n- Bio\nCausa 360 de dano\nGasta 14 pontos de mana";
    }
    if (codP == 3)
    {
        cout << i++ << "\n\n- Cura\nRestaura 400 pontos de vida\nGasta 16 pontos de mana";
    }
    if (codP == 3 || codP == 4)
    {
        cout << i++ << "\n\n- Flama Gelada\nCausa 320 de dano\nGasta 14 pontos de mana";
    }
    if (codP == 2 || codP == 3 || codP == 6 || codP == 8)
    {
        cout << i++ << "\n\n- Intoxicacao\nCausa 280 de dano\nGasta 12 pontos de mana";
    }
    if (codP == 1 || codP == 2 || codP == 3 || codP == 4)
    {
        cout << i++ << "\n\n- Tempestade\nCausa 200 de dano\nGasta 12 pontos de mana";
    }

    cout << "\n\nOpcao escolhida: ";
    cin >> codM;

    while (codM < 1 || codM > i)
    {
        cout << "\n\nOpcao invalida, insira novamente: ";
        cin >> codM;
    }

    return codM;
}
/* END MENU MAGIAS */

/* ACAO USAR MAGIA */
void usarMagia(int codMagia, Personagem &invocador, Personagem &receptor)
{
    if (codMagia == 1)
    {
        if (invocador.getMana() < 12)
        {
            cout << "\nVoce nao possui mana suficiente para essa magia! :(";
        }
        else
        {
            invocador.receberCura(200);
            invocador.perderMana(12);
        }
    }
    else if (codMagia == 2)
    {
        if (invocador.getMana() < 12)
        {
            cout << "\nVoce nao possui mana suficiente para essa magia! :(";
        }
        else
        {
            receptor.receberDanoM(400, invocador.getMagica());
            invocador.perderMana(12);
        }
    }
    else if (codMagia == 3)
    {
        if (invocador.getMana() < 14)
        {
            cout << "\nVoce nao possui mana suficiente para essa magia! :(";
        }
        else
        {
            receptor.receberDanoM(360, invocador.getMagica());
            invocador.perderMana(14);
        }
    }
    else if (codMagia == 4)
    {
        if (invocador.getMana() < 16)
        {
            cout << "\nVoce nao possui mana suficiente para essa magia! :(";
        }
        else
        {
            receptor.receberCura(400);
            invocador.perderMana(16);
        }
    }
    else if (codMagia == 5)
    {
        if (invocador.getMana() < 14)
        {
            cout << "\nVoce nao possui mana suficiente para essa magia! :(";
        }
        else
        {
            receptor.receberDanoM(320, invocador.getMagica());
            invocador.perderMana(14);
        }
    }
    else if (codMagia == 6)
    {
        if (invocador.getMana() < 12)
        {
            cout << "\nVoce nao possui mana suficiente para essa magia! :(";
        }
        else
        {
            receptor.receberDanoM(280, invocador.getMagica());
            invocador.perderMana(12);
        }
    }
    else if (codMagia == 7)
    {
        if (invocador.getMana() < 12)
        {
            cout << "\nVoce nao possui mana suficiente para essa magia! :(";
        }
        else
        {
            receptor.receberDanoM(200, invocador.getMagica());
            invocador.perderMana(12);
        }
    }
}
/* END ACAO USAR MAGIA */

/* MENU ACOES */
int menuAcoes()
{
    int op;

    cout << "\n\n1 - Usar Magia";
    cout << "\n2 - Usar Arma";
    cout << "\n3 - Exibir atributos atuais";
    cout << "\n4 - Sair do jogo";

    cout << "\n\nOpcao escolhida: ";
    cin >> op;

    while (op < 1 || op > 4)
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
void menuEscolherPersonagem(Personagem &p, int jogador)
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

    system("cls");

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
        p.setPersonagem("Guerreiro", 1, nome, 4000, 30, 100, 20, 80, 20, 20);
    }
    else if (cod == 2)
    {
        p.setPersonagem("Ladrao", 2, nome, 2800, 50, 50, 30, 40, 50, 80);
    }
    else if (cod == 3)
    {
        p.setPersonagem("Mago", 3, nome, 2500, 100, 40, 100, 30, 80, 40);
    }
    else if (cod == 4)
    {
        p.setPersonagem("Paladino", 4, nome, 3200, 80, 60, 50, 60, 60, 60);
    }
    else if (cod == 5)
    {
        p.setPersonagem("Animal", 5, nome, 3200, 30, 80, 20, 80, 20, 50);
    }
    else if (cod == 6)
    {
        p.setPersonagem("Troll", 6, nome, 2800, 20, 100, 20, 80, 20, 20);
    }
    else if (cod == 7)
    {
        p.setPersonagem("Dragao", 7, nome, 3000, 40, 100, 20, 50, 50, 30);
    }
    else if (cod == 8)
    {
        p.setPersonagem("Zumbi", 8, nome, 2500, 20, 40, 20, 40, 80, 50);
    }

    cout << "\nPersonagem criado!\n";

    p.printAtributos();
}
/* END MENU ESCOLHER PERSONAGEM */
