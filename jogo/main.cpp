#include "jogo.h"

using namespace std;

/* FUNÇÕES E PROCEDIMENTOS */
int menu();
int menuAcoes();
void escolherPersonagem(Personagem &p, int jogador);
int usarMagia(char codMagia, Personagem &p2, Personagem &p1);
char menuMagias(Personagem &p);
int usarArma(char codArma, Personagem &p2, Personagem &p1);
char menuArmas(Personagem &p, int bK);
int bulKathos();
string getMagia(char magia);
string getArma(char arma);
/* END FUNÇÕES E PROCEDIMENTOS */

/* --------------------------------------------------------------------------------------------------------- */

bool salvar = false;
ofstream arq;
string nomeArquivo;

/* INT MAIN */
int main()
{
    system("cls");
    int op;
    Personagem p1;
    Personagem p2;

    cout << "\nSeja bem vindo ao Batalha Medieval! :D";

    op = menu();

    while (op != 3)
    {
        if (op == 1)
        {
            cout << "\nBatalha Medieval!\n";
            cout << "\nSOBRE O JOGO:\n";
            cout << "\nJogo RPG por turnos, cada personagem participante executa uma acao por turno sem ser interrompido por outros personagens.\n";
            cout << "Esta acao pode ser um ataque ou o uso de algum item. Dois jogadores batalham para decidir o vencedor, o primeiro jogador a combinar\n";
            cout << "uma sequencia de ataques que faca com que o inimigo fique com a vida zerada, vence o jogo. Lembrando nem sempre o personagem mais forte ganha,\n";
            cout << "use a inteligencia para vencer, nao sao todos que tem uma vitoria por conta da forca.\n\n";
            cout << "\nCOMO JOGAR:\n";
            cout << "COMO FUNCIONA O DANO? Todo dano magico e calculado com base na resistencia fisica ou magica do receptor e a forca fisica ou magica do invocador\n";
            cout << "caso o receptor tenha 50 de resistencia fisica, o dano fisico e abaixado 50%, porem no caso do dano com arma, pode ocorrer do invocador causar dano critico\n";
            cout << "a chance disto acontecer e de 30%, por isso voce tem que ter sorte de nao acontecer com voce, ha uma arma lendaria que a chance de ser dropada e 20%. A utilizar\n";
            cout << "as armas um campeao utiliza da sua energia e com passar das utilizacoes fica com pouca energia, podendo nao utilizar mais a sua arma em tal rodada,\n";
            cout << "por isso a energia deve ser respeitada e usada com sabedoria, voce pode acabar por ficar sem energia e nao poder atacar de forma boa seu inimigo, entao fique esperto,\n";
            cout << "porem quando voce nao utiliza arma em uma rodada voce recupera 10 de energia, podendo assim poder utilizar a sua arma de forma melhor\n";
            cout << "Para utilizar as magias, cada campeao inicia com uma quantidade de mana, porem quando utilizada alguma magia, essa mana vai se esgotando e para recupera-la\n";
            cout << "voce deve nao utilizar uma magia em 1 turno (Recuperando 10 de mana).\n";
            cout << "BOM JOGO!\n";
            system("pause");
            system("cls");

            op = menu();
        }
        else if (op == 2)
        {
            int opS;
            cout << "\nDeseja que todo o progresso do jogo seja registrado em um arquivo de texto?\n\n1 - Sim\n2 - Nao";
            cout << "\n\nOpcao escolhida: ";
            cin >> opS;

            while (opS > 2 || opS < 1)
            {
                cout << "\n\nOpcao invalida, insira novamente: ";
                cin >> opS;
            }

            while (opS == 1)
            {
                salvar = true;

                string txt;

                cout << "\nInsira um nome para o arquivo de texto (sem espacos): ";
                cin >> txt;

                nomeArquivo = txt + ".txt";

                arq.open(nomeArquivo, ios::app);

                if (!(arq.is_open()))
                {
                    cout << "\nAlgo deu errado, tentar novamente?\n\n1 - Sim, quero ativar o modo salvar\n2 - Nao, nao quero salvar";
                    cout << "\nOpcao escolhida: ";
                    cin >> opS;

                    while (opS > 2 || opS < 1)
                    {
                        cout << "Opcao invalida, insira novamente: ";
                        cin >> opS;
                    }
                }
                else
                {
                    arq << "REGISTRO DE BATALHA\n\n";
                    arq.close();
                    opS = 0;
                }
            }

            if (opS == 2)
            {
                salvar = false;
            }

            escolherPersonagem(p1, 1);

            escolherPersonagem(p2, 2);

            if (salvar)
            {
                arq.open(nomeArquivo, ios::app);

                arq << "* * * * ATRIBUTOS JOGADOR 1 * * * *";
                arq << "\n\nClasse: " << p1.getClasse();
                arq << "\nNome: " << p1.getNome();
                arq << "\nVida Maxima: " << p1.getVidaMax();
                arq << "\nMana Maxima: " << p1.getManaMax();
                arq << "\nEnergia Maxima: " << p1.getEnergiaMax();
                arq << "\nForca fisica: " << p1.getFisica();
                arq << "\nForca magica: " << p1.getMagica();
                arq << "\nArmadura: " << p1.getResistFisica();
                arq << "\nResistencia magica: " << p1.getResistMagica();
                arq << "\nAgilidade: " << p1.getAgilidade();

                arq << "\n\n* * * * ATRIBUTOS JOGADOR 2 * * * *";
                arq << "\n\nClasse: " << p2.getClasse();
                arq << "\nNome: " << p2.getNome();
                arq << "\nVida Maxima: " << p2.getVidaMax();
                arq << "\nMana Maxima: " << p2.getManaMax();
                arq << "\nEnergia Maxima: " << p2.getEnergiaMax();
                arq << "\nForca fisica: " << p2.getFisica();
                arq << "\nForca magica: " << p2.getMagica();
                arq << "\nArmadura: " << p2.getResistFisica();
                arq << "\nResistencia magica: " << p2.getResistMagica();
                arq << "\nAgilidade: " << p2.getAgilidade();

                arq.close();
            }

            int turno = 1, jogador = 1, acao, op2, bK;

            int vida1 = 1, vida2 = 1, contAcoes;

            while (vida1 > 0 && vida2 > 0)
            {
                cout << "\n\n";
                system("pause");
                system("cls");

                cout << "\n\n* * * * TURNO " << turno << " * * * *";
                if (salvar)
                {
                    arq.open(nomeArquivo, ios::app);
                    arq << "\n\n* * * * TURNO " << turno << " * * * *";
                    arq.close();
                }
                turno++;
                contAcoes = 1;

                while (contAcoes <= 2 && vida1 > 0 && vida2 > 0)
                {

                    if (jogador == 1)
                    {
                        bK = bulKathos();
                        cout << "\n\n"
                             << p1.getNome() << ", escolha sua acao.";

                        if (salvar)
                        {
                            arq.open(nomeArquivo, ios::app);
                            arq << "\n\nVez de agir: "
                                << p1.getNome();

                            arq << "\nVida atual: " << p1.getVida() << "/" << p1.getVidaMax();
                            arq << "\nMana atual: " << p1.getMana() << "/" << p1.getManaMax();
                            arq << "\nEnergia atual: " << p1.getEnergia() << "/" << p1.getEnergiaMax();

                            arq.close();
                        }

                        if (bK)
                        {
                            cout << "\n\n* * * * Voce recebeu a bencao de Bul-Kathos! * * * *\nNesse turno voce tem acesso a Espada Lendaria Voto Solene de Bul-Kathos nas opcoes de Armas!";

                            if (salvar)
                            {
                                arq.open(nomeArquivo, ios::app);
                                arq << "\n\n* * * * " << p1.getNome() << " recebeu a bencao de Bul-Kathos! * * * *\nNesse turno voce tem acesso a Espada Lendaria Voto Solene de Bul-Kathos nas opcoes de Armas!";

                                arq.close();
                            }
                        }
                        cout << "\n\nVida atual: " << p1.getVida() << "/" << p1.getVidaMax();
                        cout << "\nMana atual: " << p1.getMana() << "/" << p1.getManaMax();
                        cout << "\nEnergia atual: " << p1.getEnergia() << "/" << p1.getEnergiaMax();
                    }
                    else
                    {
                        bK = bulKathos();
                        cout << "\n\n"
                             << p2.getNome() << ", escolha sua acao.";

                        if (salvar)
                        {
                            arq.open(nomeArquivo, ios::app);
                            arq << "\n\nVez de agir: "
                                << p2.getNome();

                            arq << "\nVida atual: " << p2.getVida() << "/" << p2.getVidaMax();
                            arq << "\nMana atual: " << p2.getMana() << "/" << p2.getManaMax();
                            arq << "\nEnergia atual: " << p2.getEnergia() << "/" << p2.getEnergiaMax();

                            arq.close();
                        }
                        if (bK)
                        {
                            cout << "\n\n* * * * Voce recebeu a bencao de Bul-Kathos! * * * *\nNesse turno voce tem acesso a Espada Lendaria Voto Solene de Bul-Kathos nas opcoes de Armas!";
                            if (salvar)
                            {
                                arq.open(nomeArquivo, ios::app);
                                arq << "\n\n* * * * " << p2.getNome() << " recebeu a bencao de Bul-Kathos! * * * *\nNesse turno voce tem acesso a Espada Lendaria Voto Solene de Bul-Kathos nas opcoes de Armas!";

                                arq.close();
                            }
                        }
                        cout << "\n\nVida atual: " << p2.getVida() << "/" << p2.getVidaMax();
                        cout << "\nMana atual: " << p2.getMana() << "/" << p2.getManaMax();
                        cout << "\nEnergia atual: " << p2.getEnergia() << "/" << p2.getEnergiaMax();
                    }

                    acao = menuAcoes();
                    contAcoes++;

                    while (acao == 4)
                    {
                        cout << "\nDeseja sair e perder todo o progresso do jogo?\n\n1 - Prosseguir\n2 - Cancelar\n";
                        cout << "\nOpcao escolhida: ";
                        cin >> op2;

                        while (op2 > 2 || op2 < 1)
                        {
                            cout << "\n\nOpcao invalida, insira novamente: ";
                            cin >> op2;
                        }

                        if (op2 == 1)
                        {
                            cout << "\n\n* * * * FIM DE JOGO * * * *\n\nVoce perdeu por W.O!\nVencedor: ";
                            cout << "\n\n* * * * * * * *";

                            if (jogador == 1)
                            {
                                cout << p2.getNome();
                            }
                            else
                            {
                                cout << p1.getNome();
                            }

                            if (salvar)
                            {
                                arq.open(nomeArquivo, ios::app);
                                if (jogador == 1)
                                {
                                    arq << "\n\n* * * * FIM DE JOGO * * * *\n\n" << p1.getNome();
                                }
                                else
                                {
                                    arq << p2.getNome();
                                }

                                arq << " abandonou o jogo e perdeu por W.O!\nVencedor: ";

                                if (jogador == 1)
                                {
                                    arq << p2.getNome();
                                }
                                else
                                {
                                    arq << p1.getNome();
                                }
                                arq.close();
                            }

                            return 0;
                        }
                        else
                        {
                            acao = menuAcoes();
                        }
                    }

                    int diferenca = 0, vidaAntes = 0, verifica = 0;

                    if (acao == 1)
                    {
                        char magia;

                        if (jogador == 1)
                        {

                            magia = menuMagias(p1);
                            if (magia == 's')
                            {
                                acao = 10;
                            }
                            else
                            {
                                if (magia != 'c' && magia != 'p')
                                {
                                    vidaAntes = p2.getVida();
                                    verifica = usarMagia(magia, p1, p2);

                                    if (verifica)
                                    {
                                        diferenca = vidaAntes - p2.getVida();
                                        cout << "\n\n"
                                             << p1.getNome() << " usou a magia " << getMagia(magia) << " e "
                                             << p2.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p1.getNome() << " usou a magia " << getMagia(magia) << " e "
                                                << p2.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                            arq.close();
                                        }
                                    }
                                    else
                                    {
                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p1.getNome() << "tentou usar a magia " << getMagia(magia) << " mas nao possui mana suficiente.";
                                            arq.close();
                                        }
                                        acao = 10;
                                    }
                                }
                                else
                                {
                                    vidaAntes = p1.getVida();
                                    verifica = usarMagia(magia, p1, p2);

                                    if (verifica)
                                    {
                                        diferenca = p1.getVida() - vidaAntes;
                                        cout << "\n\n"
                                             << p1.getNome() << " usou a magia " << getMagia(magia)
                                             << " e curou " << diferenca << " de vida!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p1.getNome() << " usou a magia " << getMagia(magia)
                                                << " e curou " << diferenca << " de vida!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                            arq.close();
                                        }
                                    }
                                    else
                                    {
                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p1.getNome() << "tentou usar a magia " << getMagia(magia) << " mas nao possui mana suficiente.";
                                            arq.close();
                                        }
                                        acao = 10;
                                    }
                                }
                            }
                        }
                        else
                        {
                            magia = menuMagias(p2);

                            if (magia == 's')
                            {
                                acao = 10;
                            }
                            else
                            {
                                if (magia != 'c' && magia != 'p')
                                {
                                    vidaAntes = p1.getVida();
                                    verifica = usarMagia(magia, p2, p1);

                                    if (verifica)
                                    {
                                        diferenca = vidaAntes - p1.getVida();

                                        cout << "\n\n"
                                             << p2.getNome() << " usou a magia " << getMagia(magia) << " e "
                                             << p1.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p2.getNome() << " usou a magia " << getMagia(magia) << " e "
                                                << p1.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                            arq.close();
                                        }
                                    }
                                    else
                                    {
                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p2.getNome() << " tentou usar a magia " << getMagia(magia) << " mas nao possui mana suficiente.";
                                            arq.close();
                                        }
                                        acao = 10;
                                    }
                                }
                                else
                                {
                                    vidaAntes = p2.getVida();
                                    verifica = usarMagia(magia, p2, p1);

                                    if (verifica)
                                    {
                                        diferenca = p2.getVida() - vidaAntes;
                                        cout << "\n\n"
                                             << p2.getNome() << " usou a magia " << getMagia(magia)
                                             << " e curou " << diferenca << " de vida!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p2.getNome() << " usou a magia " << getMagia(magia)
                                                << " e curou " << diferenca << " de vida!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                            arq.close();
                                        }
                                    }
                                    else
                                    {
                                        if (salvar)
                                        {
                                            arq.open(nomeArquivo, ios::app);
                                            arq << "\n\n"
                                                << p2.getNome() << " tentou usar a magia " << getMagia(magia) << " mas nao possui mana suficiente.";
                                            arq.close();
                                        }
                                        acao = 10;
                                    }
                                }
                            }
                        }
                    }
                    else if (acao == 2)
                    {
                        char arma;

                        if (jogador == 1)
                        {
                            arma = menuArmas(p1, bK);

                            if (arma == 's')
                            {
                                acao = 10;
                            }
                            else
                            {
                                vidaAntes = p2.getVida();
                                verifica = usarArma(arma, p1, p2);
                                cout << "\nverifica = " << verifica;

                                if (verifica == 1)
                                {
                                    diferenca = vidaAntes - p2.getVida();
                                    cout << "\n\n"
                                         << p1.getNome() << " usou a arma " << getArma(arma) << " e "
                                         << p2.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";

                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p1.getNome() << " usou a arma " << getArma(arma) << " e "
                                            << p2.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                        arq.close();
                                    }
                                }
                                else if (verifica == 0)
                                {
                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p1.getNome() << " tentou usar a arma " << getArma(arma) << " mas nao possui energia suficiente.";
                                        arq.close();
                                    }
                                    acao = 10;
                                }
                                else if (verifica == -1)
                                {
                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p1.getNome() << " tentou usar a arma " << getArma(arma) << " mas " << p2.getNome() << " desviou e nao recebeu dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                        arq.close();
                                    }
                                }
                            }
                        }
                        else
                        {
                            arma = menuArmas(p2, bK);

                            if (arma == 's')
                            {
                                acao = 10;
                            }
                            else
                            {
                                vidaAntes = p1.getVida();
                                verifica = usarArma(arma, p2, p1);
                                cout << "\nverifica = " << verifica;

                                if (verifica == 1)
                                {
                                    diferenca = vidaAntes - p1.getVida();
                                    cout << "\n\n"
                                         << p2.getNome() << " usou a arma " << getArma(arma) << " e "
                                         << p1.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p2.getNome() << " usou a arma " << getArma(arma) << " e "
                                            << p1.getNome() << " recebeu " << diferenca << " de dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                        arq.close();
                                    }
                                }
                                else if (verifica == 0)
                                {
                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p2.getNome() << " tentou usar a arma " << getArma(arma) << " mas nao possui energia suficiente.";
                                        arq.close();
                                    }
                                    acao = 10;
                                }
                                else if (verifica == -1)
                                {
                                    if (salvar)
                                    {
                                        arq.open(nomeArquivo, ios::app);
                                        arq << "\n\n"
                                            << p2.getNome() << " tentou usar a arma " << getArma(arma) << " mas " << p1.getNome() << " desviou e nao recebeu dano!\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
                                        arq.close();
                                    }
                                }
                            }
                        }
                    }
                    else if (acao == 3)
                    {
                        acao = 10;
                        cout << "\n* * * * ATRIBUTOS JOGADOR ";
                        if (jogador == 1)
                        {
                            cout << "1 * * * *";
                            p1.printAtributos();
                        }
                        else
                        {
                            cout << "2 * * * *";
                            p2.printAtributos();
                        }
                    }
                    if (acao != 10)
                    {
                        if (jogador == 1)
                        {
                            if (acao == 1)
                            {
                                p1.recuperarEnergia(10);
                            }
                            else if (acao == 2)
                            {
                                p1.recuperarMana(10);
                            }

                            jogador++;
                        }
                        else
                        {
                            if (acao == 1)
                            {
                                p2.recuperarEnergia(10);
                            }
                            else if (acao == 2)
                            {
                                p2.recuperarMana(10);
                            }
                            jogador--;
                        }
                    }
                    else
                    {
                        contAcoes--;
                    }

                    vida1 = p1.getVida();
                    vida2 = p2.getVida();

                    if (contAcoes == 3)
                    {
                        cout << "\nFIM DO TURNO " << turno - 1 << "\n\nVida de " << p1.getNome() << ": " << vida1 << "/" << p1.getVidaMax() << "\nVida de " << p2.getNome() << ": " << vida2 << "/" << p2.getVidaMax();
                        if (salvar)
                        {
                            arq.open(nomeArquivo, ios::app);

                            arq << "\nFIM DO TURNO " << turno - 1 << "\n\nVida de " << p1.getNome() << ": " << vida1 << "/" << p1.getVidaMax() << "\nVida de " << p2.getNome() << ": " << vida2 << "/" << p2.getVidaMax();

                            arq.close();
                        }
                    }
                }
            }
            if (vida1 == 0)
            {
                cout << "\n\n* * * * FIM DE JOGO * * * *\n"
                     << p1.getNome()
                     << " morreu! :("
                     << "\n\nVENCEDOR: Jogador 2, " << p2.getNome();

                if (salvar)
                {
                    arq.open(nomeArquivo, ios::app);

                    arq << "\n\n* * * * FIM DE JOGO * * * *\n"
                        << p1.getNome()
                        << " morreu! :("
                        << "\n\nVENCEDOR: Jogador 2, " << p2.getNome();

                    arq.close();
                }
            }
            else if (vida2 == 0)
            {
                cout << "\n\n* * * * FIM DE JOGO * * * *\n"
                     << p2.getNome()
                     << " morreu! :("
                     << "\n\nVENCEDOR: Jogador 1, " << p1.getNome();

                if (salvar)
                {
                    arq.open(nomeArquivo, ios::app);

                    cout << "\n\n* * * * FIM DE JOGO * * * *\n"
                         << p2.getNome()
                         << " morreu! :("
                         << "\n\nVENCEDOR: Jogador 1, " << p1.getNome();

                    arq.close();
                }
            }

            op = menu();
        }
    }

    cout << "\nObrigado por jogar, volte sempre! :D";

    return 0;
}
/* END INT MAIN */

/* --------------------------------------------------------------------------------------------------------- */