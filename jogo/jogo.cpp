#include "jogo.h"

Personagens::Personagens(string nome, int cod, int vida, int fisica, int magica, int resistFisica,
                         int resistMagica, int agilidade)
{
    this->nome = nome;
    this->cod = cod;
    this->vida = vida;
    this->fisica = fisica;
    this->magica = magica;
    this->resistFisica = resistFisica;
    this->resistMagica = resistMagica;
    this->agilidade = agilidade;
}