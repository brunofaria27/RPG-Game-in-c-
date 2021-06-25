#include "jogo.h"

using namespace std;

/********************
**** PERSONAGENS ****
********************/

/* FUNÇÃO CONSTRUTORA */
Personagem::Personagem(){};
/* END FUNÇÃO CONSTRUTORA */

/* FUNÇÃO DESTRUTORA */
Personagem::~Personagem() {}
/* END FUNÇÃO DESTRUTORA */

void Personagem::setPersonagem(string classe, int cod, string nome, int vida, int mana, int fisica, int magica, float resistFisica,
                               float resistMagica, int agilidade, int energia)
{
    this->classe = classe;
    this->cod = cod;
    this->nome = nome;
    this->vida = vida;
    this->mana = mana;
    this->fisica = fisica;
    this->magica = magica;
    this->resistFisica = resistFisica;
    this->resistMagica = resistMagica;
    this->agilidade = agilidade;
    this->manaMax = mana;
    this->vidaMax = vida;
    this->energia = energia;
    this->energiaMax = energia;
}

/* FUNÇÕES QUE RETORNAM ATRIBUTOS */
string Personagem::getClasse()
{
    return classe;
}
string Personagem::getNome()
{
    return nome;
}
int Personagem::getVida()
{
    return vida;
}
int Personagem::getCodP()
{
    return cod;
}
int Personagem::getMana()
{
    return mana;
}
int Personagem::getFisica()
{
    return fisica;
}
int Personagem::getMagica()
{
    return magica;
}
int Personagem::getResistFisica()
{
    return resistFisica;
}
int Personagem::getResistMagica()
{
    return resistMagica;
}
int Personagem::getAgilidade()
{
    return agilidade;
}
int Personagem::getEnergia()
{
    return energia;
}
int Personagem::getVidaMax()
{
    return vidaMax;
}
int Personagem::getEnergiaMax()
{
    return energiaMax;
}
int Personagem::getManaMax()
{
    return manaMax;
}
/* END FUNÇÕES QUE RETORNAM ATRIBUTOS */

/* FUNÇÃO IMPRIMIR ATRIBUTOS */
void Personagem::printAtributos()
{
    cout << "\nClasse: " << classe;
    cout << "\nNome: " << nome;
    cout << "\nVida Maxima: " << vidaMax;
    cout << "\nMana Maxima: " << manaMax;
    cout << "\nEnergia Maxima: " << energia;
    cout << "\nForca fisica: " << fisica;
    cout << "\nForca magica: " << magica;
    cout << "\nArmadura: " << resistFisica;
    cout << "\nResistencia magica: " << resistMagica;
    cout << "\nAgilidade: " << agilidade;
}
/* END FUNÇÃO IMPRIMIR ATRIBUTOS */

/* --------------------------------------------------------------------------------------------------------- */

/********************
****** MAGIAS *******
********************/
void Personagem::perderMana(int gastoMana)
{
    this->mana = mana - gastoMana;
}

void Personagem::recuperarMana(int recupera)
{
    this->mana = mana + recupera;

    if (mana > manaMax)
    {
        this->mana = manaMax;
    }
}

void Personagem::receberCura(int cura)
{
    this->vida = vida + cura;

    if (vida > vidaMax)
    {
        this->vida = vidaMax;
    }
}

void Personagem::receberDanoM(int dano, float forcaMagica)
{
    dano = dano + (dano * (forcaMagica / 100));

    dano = dano - (dano * (resistMagica / 100));

    this->vida = vida - dano;

    if (vida < 0)
    {
        this->vida = 0;
    }
}

/* --------------------------------------------------------------------------------------------------------- */

/********************
****** Armas *******
********************/

void Personagem::receberDanoA(int danoMin, int danoMax, float forcaFisica)
{
    srand(time(0));

    int diferenca = danoMax - danoMin;
    int dano = (rand() % diferenca) + 1 + danoMin;

    dano = dano + (dano * (forcaFisica / 100));

    dano = dano - (dano * (resistFisica / 100));

    this->vida = vida - dano;

    if (vida < 0)
    {
        this->vida = 0;
    }
}

void Personagem::receberDanoBk(float forcaFisica)
{
    srand(time(0));

    int critico, dano = (rand() % 400) + 1 + 500;

    critico = (rand() % 100) + 1;

    if (critico <= 15)
    {
        cout << "\nAcerto critico!";
        dano = dano * 2;
    }

    dano = dano + (dano * (forcaFisica / 100));

    dano = dano - (dano * (resistFisica / 100));

    this->vida = vida - dano;

    if (vida < 0)
    {
        this->vida = 0;
    }
}

void Personagem::recuperarEnergia(int recupera)
{
    this->energia = energia + recupera;

    if (energia > energiaMax)
    {
        this->energia = energiaMax;
    }
}

void Personagem::perderEnergia(int gastoEnergia)
{
    this->energia = energia - gastoEnergia;
}

/* --------------------------------------------------------------------------------------------------------- */

/******************************
****** Outros atributos *******
******************************/

int Personagem::desviar()
{
    srand(time(0));

    int chance = (rand() % 100) + 1;

    if (chance <= agilidade)
    {
        cout << nome << " desviou do ataque e nao recebeu dano!";
        return 1;
    }

    return 0;
}

/* --------------------------------------------------------------------------------------------------------- */