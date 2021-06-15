#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

class ataque
{
protected:
    string nome;
    int dano;
    int cod;
};

class magia : public ataque
{
protected:
    int cura;
    int gastoMana;
};

class Personagens
{
protected:
    string nome;
    int cod;
    int vida;
    int mana;
    int fisica;
    int magica;
    int resistFisica;
    int resistMagica;
    int agilidade;
    ataque *magia;
};