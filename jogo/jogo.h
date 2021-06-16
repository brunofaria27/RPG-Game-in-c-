#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

/* CLASSE PERSONGEM */
class Personagens
{
private:
    string nome;
    int cod;
    int vida;
    int mana;
    int fisica;
    int magica;
    int resistFisica;
    int resistMagica;
    int agilidade;
    //MagiaDano *MagiaDano;
    //MagiaCura *MagiaCura;
    //Arma *arma;

public:
    Personagens(string nome, int cod, int vida, int mana, int fisica, int magica, int resistFisica,
                int resistMagica, int agilidade);
    int getVida();
    int getCod();
    ~Personagens();
};
/* END CLASSE PERSONAGEM */