#include "jogo.h"

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

int Personagens::getVida()
{
    return vida;
}

int Personagens::getCod()
{
    return cod;
}
