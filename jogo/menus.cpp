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
        cout << "Opcao invalida, insira novamente: ";
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
        cout << "Opcao invalida, insira novamente: ";
        cin >> op;
    }

    return op;
}
/* END MENU ACOES */

/* MENU MAGIAS */
char menuMagias(Personagem &p)
{
    cout << "\nMagias disnponiveis para " << p.getClasse();

    int i = 1, codM = 1, codP = p.getCodP();
    char Magia[6];

    cout << "\n\n0 - Retornar ao menu de acoes\n\n";
    Magia[0] = 's';

    if (codP == 3 || codP == 4)
    {
        cout << i << " - Pocao de vida\nRestaura 200 pontos de vida\nGasta 12 pontos de mana\n\n";
        Magia[i++] = 'p';
    }
    if (codP == 7)
    {
        cout << i << " - Halito de Fogo\nCausa 400 de dano\nGasta 12 pontos de mana\n\n";
        Magia[i++] = 'h';
    }
    if (codP == 3 || codP == 5)
    {
        cout << i << " - Bio\nCausa 360 de dano\nGasta 14 pontos de mana\n\n";
        Magia[i++] = 'b';
    }
    if (codP == 3)
    {
        cout << i << " - Cura\nRestaura 400 pontos de vida\nGasta 16 pontos de mana\n\n";
        Magia[i++] = 'c';
    }
    if (codP == 3 || codP == 4)
    {
        cout << i << " - Flama Gelada\nCausa 320 de dano\nGasta 14 pontos de mana\n\n";
        Magia[i++] = 'f';
    }
    if (codP == 2 || codP == 3 || codP == 6 || codP == 8)
    {
        cout << i << " - Intoxicacao\nCausa 280 de dano\nGasta 12 pontos de mana\n\n";
        Magia[i++] = 'i';
    }
    if (codP == 1 || codP == 2 || codP == 3 || codP == 4)
    {
        cout << i << " - Tempestade\nCausa 200 de dano\nGasta 12 pontos de mana\n\n";
        Magia[i] = 't';
    }

    cout << "Opcao escolhida: ";
    cin >> codM;

    while (codM < 0 || codM > i)
    {
        cout << "\n\nOpcao invalida, insira novamente: ";
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
    char Arma[7];

    cout << "\n\n0 - Retornar ao menu de acoes\n\n";
    Arma[0] = 's';

    if (codP == 3 || codP == 4)
    {
        cout << i << " - Garra Letal\nCausa 100 a 300 de dano\n\n";
        Arma[i++] = 'g';
    }
    if (codP == 7)
    {
        cout << i << " - Tridednte Sagrado\nCausa 220 a 420 de dano\n\n";
        Arma[i++] = 't';
    }
    if (codP == 3 || codP == 5)
    {
        cout << i << " - Espada Barroca\nCausa 300 a 500 de dano\n\n";
        Arma[i++] = 'e';
    }
    if (codP == 3)
    {
        cout << i << " - Porrete\nCausa 180 a 380 de dano\n\n";
        Arma[i++] = 'p';
    }
    if (codP == 3 || codP == 4)
    {
        cout << i << " - Cajado\nCausa 50 a 200 de dano\n\n";
        Arma[i++] = 'c';
    }
    if (codP == 2 || codP == 3 || codP == 6 || codP == 8)
    {
        cout << i << " - Besta\nCausa 220 a 420 de dano\n\n";
        Arma[i++] = 'b';
    }
    if (codP == 1 || codP == 2 || codP == 3 || codP == 4)
    {
        cout << i << " - Esfera de Ataque\nCausa 200 a 400 de dano\n\n";
        Arma[i++] = 'E';
    }

    if(bK){
        cout << i << " - Espada Lendaria Voto Solene de Bul-Kathos\nCausa 500 a 900 de dano\nDobra o dano se o acerto for critico (chance de 30%)\n\n";
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