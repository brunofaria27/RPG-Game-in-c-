#include "jogo.h"

/********************
**** PERSONAGENS ****
********************/

/* FUNÇÃO CONSTRUTORA */
Personagens::Personagens(string nome, int cod, int vida, int mana, int fisica, int magica, int resistFisica,
                         int resistMagica, int agilidade)
{
    this->nome = nome;
    this->cod = cod;
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

/* FUNÇÃO PEGAR VIDA PERSONAGEM */
int Personagens::getVida()
{
    return vida;
}
/* END FUNÇÃO PEGAR VIDA PERSONAGEM */

/* FUNÇÃO RECEBER CODIGO DO PERSONAGEM */
int Personagens::getCod()
{
    return cod;
}
/* END FUNÇÃO RECEBER CODIGO DO PERSONAGEM */

/* --------------------------------------------------------------------------------------------------------- */