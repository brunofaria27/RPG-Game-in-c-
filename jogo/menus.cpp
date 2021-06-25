#include "jogo.h"

using namespace std;

/* MENU PRINCIPAL*/
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
        cout << "\nOpcao invalida, insira novamente: ";
        cin >> op;
    }

    return op;
}
/* END MENU PRINCIPAL */

/* MENU ACOES */
int menuAcoes()
{
    int op;

    cout << "\n\n1 - Usar Magia";
    cout << "\n2 - Usar Arma";
    cout << "\n3 - Exibir atributos do personagem";
    cout << "\n4 - Sair do jogo";

    cout << "\n\nOpcao escolhida: ";
    cin >> op;

    while (op < 1 || op > 4)
    {
        cout << "\nOpcao invalida, insira novamente: ";
        cin >> op;
    }

    return op;
}
/* END MENU ACOES */

/* MENU MAGIAS */
char menuMagias(Personagem &p)
{
    cout << "\n\nMagias disnponiveis para " << p.getClasse();

    int i = 1, codM = 1, codP = p.getCodP();
    char Magia[7];

    cout << "\n\n0 - Retornar ao menu de acoes";
    Magia[0] = 's';

    if (codP == 3 || codP == 4)
    {
        cout << "\n\n" << i << " - Pocao de vida\nRestaura 200 pontos de vida\nGasta 12 pontos de mana";
        Magia[i++] = 'p';
    }
    if (codP == 7)
    {
        cout << "\n\n" << i << " - Halito de Fogo\nCausa 400 de dano\nGasta 12 pontos de mana";
        Magia[i++] = 'h';
    }
    if (codP == 3 || codP == 5)
    {
        cout << "\n\n" << i << " - Bio\nCausa 360 de dano\nGasta 14 pontos de mana";
        Magia[i++] = 'b';
    }
    if (codP == 3)
    {
        cout << "\n\n" << i << " - Cura\nRestaura 400 pontos de vida\nGasta 16 pontos de mana";
        Magia[i++] = 'c';
    }
    if (codP == 3 || codP == 4)
    {
        cout << "\n\n" << i << " - Flama Gelada\nCausa 320 de dano\nGasta 14 pontos de mana";
        Magia[i++] = 'f';
    }
    if (codP == 2 || codP == 3 || codP == 6 || codP == 8)
    {
        cout << "\n\n" << i << " - Intoxicacao\nCausa 280 de dano\nGasta 12 pontos de mana";
        Magia[i++] = 'i';
    }
    if (codP == 1 || codP == 2 || codP == 3 || codP == 4)
    {
        cout << "\n\n" << i << " - Tempestade\nCausa 200 de dano\nGasta 12 pontos de mana";
        Magia[i] = 't';
    }

    cout << "\n\nOpcao escolhida: ";
    cin >> codM;

    while (codM < 0 || codM > i)
    {
        cout << "\nOpcao invalida, insira novamente: ";
        cin >> codM;
    }

    return Magia[codM];
}
/* END MENU MAGIAS */

/* MENU ARMAS */
char menuArmas(Personagem &p, int bK)
{
    cout << "\nArmas disnponiveis para " << p.getClasse();

    int i = 1, codA = 1, codP = p.getCodP();
    char Arma[8];

    cout << "\n\n0 - Retornar ao menu de acoes";
    Arma[0] = 's';

    if (codP == 5 || codP == 7 || codP == 8)
    {
        cout << "\n\n" << i << " - Garra Letal\nCausa 100 a 300 de dano\nGasta 10 pontos de energia";
        Arma[i++] = 'g';
    }
    if (codP == 4 || codP == 3)
    {
        cout << "\n\n" << i << " - Tridente Sagrado\nCausa 220 a 420 de dano\nGasta 14 pontos de energia";
        Arma[i++] = 't';
    }
    if (codP == 1)
    {
        cout << "\n\n" << i << " - Espada Barroca\nCausa 300 a 500 de dano\nGasta 16 pontos de energia";
        Arma[i++] = 'e';
    }
    if (codP == 1 || codP == 2 || codP == 6 || codP == 8)
    {
        cout << "\n\n" << i << " - Porrete\nCausa 180 a 380 de dano\nGasta 12 pontos de energia";
        Arma[i++] = 'p';
    }
    if (codP == 2 || codP == 3 || codP == 6 || codP == 8)
    {
        cout << "\n\n" << i << " - Cajado\nCausa 50 a 200 de dano\nGasta 8 pontos de energia";
        Arma[i++] = 'c';
    }
    if (codP == 2 || codP == 4)
    {
        cout << "\n\n" << i << " - Besta\nCausa 220 a 420 de dano\nGasta 14 pontos de energia";
        Arma[i++] = 'b';
    }
    if (codP == 2)
    {
        cout << "\n\n" << i << " - Esfera de Ataque\nCausa 200 a 400 de dano\nGasta 12 pontos de energia";
        Arma[i++] = 'E';
    }

    if(bK){
        cout << "\n\n" << i << " - Espada Lendaria Voto Solene de Bul-Kathos\nCausa 500 a 900 de dano\nDobra o dano se o acerto for critico (chance de 15%)\nNao gasta pontos de energia";
        Arma[i] = 'K';
    }

    cout << "\n\nOpcao escolhida: ";
    cin >> codA;

    while (codA < 0 || codA > i)
    {
        cout << "Opcao invalida, insira novamente: ";
        cin >> codA;
    }

    return Arma[codA];
}
/* END MENU ARMAS */