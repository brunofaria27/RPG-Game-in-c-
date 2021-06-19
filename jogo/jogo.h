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
    int resistFisica;
    int resistMagica;
    int agilidade;

public:
    Personagem(string classe, int cod, string nome, int vida, int mana, int fisica, int magica, int resistFisica,
               int resistMagica, int agilidade);
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
    ~Personagem();
};
/* END CLASSE PERSONAGEM */

/* CLASSE MAGIA*/
class Magia : public Personagem
{
private:
    string nome;
    int cod;
    int gastoMana;
    int curaOuDano;

public:
    Magia(string nome, int cod, int gastoMana, int curaOuDano);
    int getCodM();
    void receberDano(int dano);
    void receberCura(int cura);
    ~Magia();
};
/* END CLASSE MAGIA*/
