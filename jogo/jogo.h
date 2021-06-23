#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

/* CLASSE PERSONGEM */
class Personagem
{
protected:
    string classe;
    int cod;
    string nome;
    int vida;
    int mana;
    int fisica;
    int magica;
    float resistFisica;
    float resistMagica;
    int agilidade;
    int manaMax;
    int vidaMax;

public:
    Personagem();
    void setPersonagem(string classe, int cod, string nome, int vida, int mana, int fisica, int magica, float resistFisica,
               float resistMagica, int agilidade);

    string getClasse();
    int getVida();
    int getCodP();
    string getNome();
    int getMana();
    int getFisica();
    int getMagica();
    int getResistFisica();
    int getResistMagica();
    int getAgilidade();

    void printAtributos();

    void perderMana(int gastoMana);
    void recuperarMana(int gastoMana);
    void receberCura(int cura);
    void receberDanoM(int dano, float forcaMagica);
    void receberDanoA(int danoMin, int danoMax, float forcaFisica);
    void receberDanoBk(float forcaFisica);

    ~Personagem();
};
/* END CLASSE PERSONAGEM */

