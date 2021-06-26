#include "jogo.h"

using namespace std;

/*************************************************************************************************************
********* FUNÇÕES E PROCEDIMENTOS ****************************************************************************
*************************************************************************************************************/

/* ACAO USAR MAGIA */
int usarMagia(char codMagia, Personagem &invocador, Personagem &receptor)
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
        cout << "\nVoce nao possui mana suficiente para essa magia! :(\nEscolha outra acao.";
        return 0;
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
            invocador.receberCura(cura);
            invocador.perderMana(gastoMana);
        }
        return 1;
    }
}
/* END ACAO USAR MAGIA */

/* FUNCAO CALCULAR CHANCE DE BUL-KATHOS */
int bulKathos()
{
    int bK;
    srand(time(0));

    bK = (rand() % 100) + 1;

    if (bK <= 10)
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
int usarArma(char codArma, Personagem &atacante, Personagem &receptor)
{
    int danoMin, danoMax, gastoEnergia;

    if (codArma == 'g')
    {
        danoMin = 100;
        danoMax = 300;
        gastoEnergia = 10;
    }
    else if (codArma == 't')
    {
        danoMin = 220;
        danoMax = 400;
        gastoEnergia = 14;
    }
    else if (codArma == 'e')
    {
        danoMin = 300;
        danoMax = 500;
        gastoEnergia = 16;
    }
    else if (codArma == 'p')
    {
        danoMin = 180;
        danoMax = 380;
        gastoEnergia = 12;
    }
    else if (codArma == 'c')
    {
        danoMin = 50;
        danoMax = 200;
        gastoEnergia = 8;
    }
    else if (codArma == 'b')
    {
        danoMin = 220;
        danoMax = 420;
        gastoEnergia = 14;
    }
    else if (codArma == 'E')
    {
        danoMin = 200;
        danoMax = 400;
        gastoEnergia = 12;
    }
    else if (codArma = 'K')
    {
        gastoEnergia = 0;
    }

    if (atacante.getEnergia() < gastoEnergia)
    {
        cout << "\nVoce nao possui energia suficiente para usar essa arma! :(\nEscolha outra acao.";
        return 0;
    }

    if (receptor.getEnergia() >= 10)
    {
        if (receptor.desviar())
        {
            receptor.perderEnergia(10);
            atacante.perderEnergia(gastoEnergia);
            return -1;
        }
    }

    if (codArma == 'K')
    {
        receptor.receberDanoBk(atacante.getFisica());
    }
    else
    {
        receptor.receberDanoA(danoMin, danoMax, atacante.getFisica());
        atacante.perderEnergia(gastoEnergia);
    }
    return 1;
}
/* END ACAO USAR ARMA */

/* ESCOLHER PERSONAGEM */
void escolherPersonagem(Personagem &p, int jogador)
{
    int cod;

    cout << "\n\n";
    system("pause");
    system("cls");

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
        p.setPersonagem("Guerreiro", 1, nome, 4000, 30, 100, 20, 80, 20, 20, 80);
    }
    else if (cod == 2)
    {
        p.setPersonagem("Ladrao", 2, nome, 2800, 50, 50, 30, 40, 50, 80, 50);
    }
    else if (cod == 3)
    {
        p.setPersonagem("Mago", 3, nome, 2500, 100, 40, 100, 30, 80, 40, 20);
    }
    else if (cod == 4)
    {
        p.setPersonagem("Paladino", 4, nome, 3200, 80, 60, 50, 60, 60, 60, 30);
    }
    else if (cod == 5)
    {
        p.setPersonagem("Animal", 5, nome, 3200, 30, 80, 20, 80, 20, 50, 70);
    }
    else if (cod == 6)
    {
        p.setPersonagem("Troll", 6, nome, 2800, 20, 100, 20, 80, 20, 20, 80);
    }
    else if (cod == 7)
    {
        p.setPersonagem("Dragao", 7, nome, 3000, 40, 100, 20, 50, 50, 30, 100);
    }
    else if (cod == 8)
    {
        p.setPersonagem("Zumbi", 8, nome, 2500, 20, 40, 20, 40, 80, 50, 50);
    }

    cout << "\nPersonagem criado!\n";

    p.printAtributos();
}
/* END ESCOLHER PERSONAGEM */

/* FUNÇÃO RETORNAR NOME DA MAGIA */
string getMagia(char magia)
{
    if (magia == 'p')
    {
        return "Pocao de Vida";
    }
    else if (magia == 'h')
    {
        return "Halito de Fogo";
    }
    else if (magia == 'b')
    {
        return "Bio";
    }
    else if (magia == 'c')
    {
        return "Cura";
    }
    else if (magia == 'f')
    {
        return "Flama Gelada";
    }
    else if (magia == 'i')
    {
        return "Intoxicacao";
    }
    else if (magia == 't')
    {
        return "Tempestade";
    }
}
/* FUNÇÃO RETORNAR NOME DA MAGIA */

/* FUNÇÃO RETORNAR NOME DA ARMA */
string getArma(char arma)
{
    if (arma == 'g')
    {
        return "Garra Letal";
    }
    else if (arma == 't')
    {
        return "Tridente Sagrado";
    }
    else if (arma == 'e')
    {
        return "Espada Barroca";
    }
    else if (arma == 'p')
    {
        return "Porrete";
    }
    else if (arma == 'c')
    {
        return "Cajado";
    }
    else if (arma == 'b')
    {
        return "Besta";
    }
    else if (arma == 'E')
    {
        return "Esfera de Ataque";
    }
    else if (arma = 'K')
    {
        return "Espada Lendaria Voto Solene de Bul-Kathos";
    }
}
/* FUNÇÃO RETORNAR NOME DA ARMA */