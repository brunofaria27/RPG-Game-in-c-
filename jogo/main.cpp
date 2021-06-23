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
void escolherPersonagem(Personagem &p, int jogador);
void usarMagia(char codMagia, Personagem &p2, Personagem &p1);
char menuMagias(Personagem &p);
void usarArma(char codArma, Personagem &p2, Personagem &p1);
char menuArmas(Personagem &p, int bK);
int bulKathos();
/* END FUNÇÕES E PROCEDIMENTOS */

/* --------------------------------------------------------------------------------------------------------- */

/* INT MAIN */
int main()
{
    system("cls");
    int op;
    Personagem p1;
    Personagem p2;

    cout << "\nSeja bem vindo ao Batalha Medieval! :D";

    op = menu();

    while (op != 3)
    {
        if (op == 1)
        {
            cout << "\nBatalha Medieval!\n";
            cout << "\nSOBRE O JOGO:\n";
            cout << "\nJogo RPG por turnos, cada personagem participante executa uma acao por turno sem ser interrompido por outros personagens.\n";
            cout << "Esta acao pode ser um ataque ou o uso de algum item. Dois jogadores batalham para decidir o vencedor, o primeiro jogador a combinar\n";
            cout << "uma sequencia de ataques que faca com que o inimigo fique com a vida zerada, vence o jogo. Lembrando nem sempre o personagem mais forte ganha,\n";
            cout << "use a inteligencia para vencer, nao sao todos que tem uma vitoria por conta da forca.\n\n";
            system("pause");
            system("cls");

            op = menu();
        }
        else if (op == 2)
        {
            escolherPersonagem(p1, 1);

            escolherPersonagem(p2, 2);

            int turno = 1, jogador = 1, acao, op2, bK;

            int vida1 = 1, vida2 = 1, contAcoes;

            while (vida1 > 0 && vida2 > 0)
            {
                cout << "\n\n";
                system("pause");

                cout << "\n\n\t\t\t\tTURNO " << turno;
                turno++;
                contAcoes = 1;

                while (contAcoes <= 2)
                {

                    if (jogador == 1)
                    {
                        bK = bulKathos();
                        cout << "\n\n"
                             << p1.getNome() << ", escolha sua acao. bk = " << bK;

                        if (bK)
                        {
                            cout << "\nVoce recebeu a bencao de Bul-Kathos!\nNesse turno voce tem acesso a Espada Lendaria Voto Solene de Bul-Kathos nas opcoes de Armas!";
                        }
                        cout << "\n\nVida atual: " << p1.getVida();
                        cout << "\nMana atual: " << p1.getMana();
                    }
                    else
                    {
                        bK = bulKathos();
                        cout << "\n\n"
                             << p2.getNome() << ", escolha sua acao.";
                        if (bK)
                        {
                            cout << "\nVoce recebeu a bencao de Bul-Kathos!\nNesse turno voce tem acesso a Espada Lendaria Voto Solene de Bul-Kathos nas opcoes de Armas!";
                        }
                        cout << "\n\nVida atual: " << p2.getVida();
                        cout << "\nMana atual: " << p2.getMana();
                    }

                    acao = menuAcoes();
                    contAcoes++;

                    while (acao == 4)
                    {
                        cout << "\nDeseja sair e perder todo o progresso do jogo?\n(1 - Prosseguir; 2 - Cancelar)\n";
                        cin >> op2;

                        while (op2 > 2 || op2 < 1)
                        {
                            cout << "Opcao invalida, insira novamente: ";
                            cin >> op2;
                        }

                        if (op2 == 1)
                        {
                            cout << "Voce perdeu por W.O!\nVencedor: Jogador";
                            if (jogador == 1)
                            {
                                cout << "2";
                            }
                            else
                            {
                                cout << "1";
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
                        char magia;
                        int diferenca, vidaAntes;

                        if (jogador == 1)
                        {
                            magia = menuMagias(p1);
                            if (magia == 's')
                            {
                                jogador++;
                                turno--;
                            }
                            else
                            {
                                if (magia != 'c' && magia != 'p')
                                {
                                    cout << "\n"
                                         << p2.getNome() << " recebeu um ataque magico de ";
                                    vidaAntes = p2.getVida();

                                    usarMagia(magia, p1, p2);

                                    diferenca = vidaAntes - p2.getVida();
                                    cout << diferenca << " dano!";
                                }
                                else
                                {
                                    cout << "\n"
                                         << p1.getNome() << " curou ";
                                    vidaAntes = p1.getVida();

                                    usarMagia(magia, p1, p2);

                                    diferenca = p1.getVida() - vidaAntes;
                                    cout << diferenca << " pontos de vida!";
                                }
                            }
                        }
                        else
                        {
                            magia = menuMagias(p2);
                            if (magia == 's')
                            {
                                jogador--;
                                turno--;
                            }
                            else
                            {
                                if (magia != 'c' && magia != 'p')
                                {
                                    cout << "\n"
                                         << p1.getNome() << " recebeu um ataque magico de ";
                                    vidaAntes = p1.getVida();

                                    usarMagia(magia, p2, p1);

                                    diferenca = vidaAntes - p1.getVida();
                                    cout << diferenca << " dano!";
                                }
                                else
                                {
                                    cout << "\n"
                                         << p2.getNome() << " curou ";
                                    vidaAntes = p2.getVida();

                                    usarMagia(magia, p2, p1);

                                    diferenca = p1.getVida() - vidaAntes;
                                    cout << diferenca << " pontos de vida!";
                                }
                            }
                        }
                    }
                    else if (acao == 2)
                    {
                        char arma;
                        if (jogador == 1)
                        {
                            p1.recuperarMana(10);
                            arma = menuArmas(p1, bK);

                            if (arma == 's')
                            {
                                jogador--;
                                turno--;
                            }
                            else
                            {
                                usarArma(arma, p1, p2);
                            }
                        }
                        else
                        {
                            p2.recuperarMana(10);
                            arma = menuArmas(p2, bK);

                            if (arma == 's')
                            {
                                jogador++;
                                turno--;
                            }
                            else
                            {
                                usarArma(arma, p1, p2);
                            }
                        }
                    }
                    else
                    {
                        if (jogador == 1)
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

                    vida1 = p1.getVida();
                    vida2 = p2.getVida();
                }
            }
            if (vida1 == 0)
            {
                cout << "\nFIM DE JOGO\n"
                     << p1.getNome()
                     << " morreu! :("
                     << "\n\nVENCEDOR: Jogador 2";
            }
            else if (vida2 == 0)
            {
                cout << "\nFIM DE JOGO\n"
                     << p2.getNome()
                     << " morreu! :("
                     << "\n\nVENCEDOR: Jogador 1";
            }
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

/* ACAO USAR MAGIA */
void usarMagia(char codMagia, Personagem &invocador, Personagem &receptor)
{
    int gastoMana, cura, dano;

    if (codMagia == 'p')
    {
        gastoMana = 12;
        cura = 200;
    }
    else if (codMagia == 'h')
    {
        gastoMana = 12;
        dano = 400;
    }
    else if (codMagia == 'b')
    {
        gastoMana = 14;
        dano = 360;
    }
    else if (codMagia == 'c')
    {
        gastoMana = 16;
        cura = 400;
    }
    else if (codMagia == 'f')
    {
        gastoMana = 14;
        dano = 320;
    }
    else if (codMagia == 'i')
    {
        gastoMana = 12;
        dano = 280;
    }
    else if (codMagia == 't')
    {
        gastoMana = 12;
        dano = 200;
    }

    if (invocador.getMana() < gastoMana)
    {
        cout << "\nVoce nao possui mana suficiente para essa magia! :(";
    }
    else
    {
        if (codMagia != 'p' && codMagia != 'c')
        {
            receptor.receberDanoM(dano, invocador.getMagica());
            invocador.perderMana(gastoMana);
        }
        else
        {
            receptor.receberCura(cura);
            invocador.perderMana(gastoMana);
        }
    }
}
/* END ACAO USAR MAGIA */

/* FUNCAO CALCULAR CHANCE DE BUL-KATHOS */
int bulKathos()
{
    int bK;
    srand(time(0));

    bK = (rand() % 100) + 1;

    if (bK <= 20)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/* END FUNCAO CALCULAR CHANCE DE BUL-KATHOS */

/* ACAO USAR ARMA */
void usarArma(char codArma, Personagem &atacante, Personagem &receptor)
{
    if (codArma == 'g')
    {
        receptor.receberDanoA(100, 300, atacante.getFisica());
    }
    else if (codArma == 't')
    {
        receptor.receberDanoA(220, 400, atacante.getFisica());
    }
    else if (codArma == 'e')
    {
        receptor.receberDanoA(300, 500, atacante.getFisica());
    }
    else if (codArma == 'p')
    {
        receptor.receberDanoA(180, 380, atacante.getFisica());
    }
    else if (codArma == 'c')
    {
        receptor.receberDanoA(50, 200, atacante.getFisica());
    }
    else if (codArma == 'b')
    {
        receptor.receberDanoA(220, 420, atacante.getFisica());
    }
    else if (codArma == 'E')
    {
        receptor.receberDanoA(200, 400, atacante.getFisica());
    }
    else if (codArma == 'K')
    {
        receptor.receberDanoBk(atacante.getFisica());
    }
}
/* END ACAO USAR ARMA */

/* ESCOLHER PERSONAGEM */
void escolherPersonagem(Personagem &p, int jogador)
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
/* END ESCOLHER PERSONAGEM */