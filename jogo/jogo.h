#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

class Ataque
{
protected:
    string nome;
    int dano;
    int cod;

public:
    void ataque(string nome, int dano, int cod);
};

class Magia : public Ataque
{
protected:
    int cura;
    int gastoMana;
};

class Arma : public Ataque
{
public:
    void bulKathos();
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
    Magia *magia;
    Arma *arma;

public:
    Personagens(string nome, int cod, int vida, int fisica, int magica, int resistFisica,
                int resistMagica, int agilidade);
    void setAtaque(int codArma);
    ~Personagens();
};

class Guerreiro : public Personagens
{
public:
    Guerreiro();
};

class Ladrap : public Personagens
{
};

class Mago : public Personagens
{
};

class Paladino : public Personagens
{
};

class Animal : public Personagens
{
};

class Troll : public Personagens
{
};

class Dragao : public Personagens
{
};

class Zumbi : public Personagens
{
};
