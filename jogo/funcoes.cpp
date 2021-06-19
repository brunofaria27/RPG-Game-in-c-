#include "jogo.h"

/********************
**** PERSONAGENS ****
********************/

/* FUNÇÃO CONSTRUTORA */
Personagem::Personagem(string classe, int cod, string nome, int vida, int mana, int fisica, int magica, int resistFisica,
                       int resistMagica, int agilidade)
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
    const static int vidaMax = vida;
}
/* END FUNÇÃO CONSTRUTORA */

/* FUNÇÃO DESTRUTORA */
Personagem::~Personagem() {}
/* END FUNÇÃO DESTRUTORA */

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

/* END FUNÇÕES QUE RETORNAM ATRIBUTOS */

/* --------------------------------------------------------------------------------------------------------- */

/********************
****** MAGIAS *******
********************/

/* FUNÇÃO CONSTRUTORA */
Magia::Magia(string nome, int cod, int gastoMana, int curaOuDano)
{
    this->nome = nome;
    this->cod = cod;
    this->gastoMana = gastoMana;
    this->curaOuDano = curaOuDano;
}
/* END FUNÇÃO CONSTRUTORA */

/* FUNÇÃO RECEBER CODIGO DA MAGIA */
int Magia::getCodM()
{
    return cod;
}
/* END FUNÇÃO RECEBER CODIGO DA MAGIA */

/* --------------------------------------------------------------------------------------------------------- */
