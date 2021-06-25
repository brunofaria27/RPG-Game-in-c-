#include <cstdlib>
#include <string.h>
#include <iostream>
#include <ctime>
#include <ctype.h>
#include <fstream>

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
    int energia;
    int manaMax;
    int vidaMax;
    int energiaMax;
    
public:
    Personagem();
    void setPersonagem(string classe, int cod, string nome, int vida, int mana, int fisica, int magica, float resistFisica,
               float resistMagica, int agilidade, int energia);

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
    int getEnergia();
    int getVidaMax();
    int getManaMax();
    int getEnergiaMax();

    void printAtributos();

    void perderMana(int gastoMana);
    void recuperarMana(int gastoMana);
    void receberCura(int cura);
    void receberDanoM(int dano, float forcaMagica);
    void receberDanoA(int danoMin, int danoMax, float forcaFisica);
    void receberDanoBk(float forcaFisica);
    void recuperarEnergia(int recupera);
    void perderEnergia(int gastoEnergia);
    int desviar();

    ~Personagem();
};
/* END CLASSE PERSONAGEM */

