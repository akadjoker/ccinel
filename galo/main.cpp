#include <iostream>

using namespace std;

int i;
int j;

bool posJogo(int numeroVitoriasJogador1, int numeroVitoriasJogador2)
{
    char inputJogarNovamente;

    cout << endl
         << endl
         << "__________________________" << endl;
    cout << "Resultados:" << endl;
    cout << "Jogador 1 -> " << numeroVitoriasJogador1 << " - ";
    cout << numeroVitoriasJogador2 << " <- Jogador 2" << endl
         << endl;

    cout << endl
         << endl
         << "__________________________" << endl;
    cout << endl
         << "Quer jogar novamente? [S/n]" << endl;
    cin >> inputJogarNovamente;

    if (tolower(inputJogarNovamente) != 's')
    {
        return false;
    }

    return true;
}

void turnoJogador(int jogadorActual, char** grelha)
{
    /*******************************************************************
     * JOGADOR X
     *******************************************************************/
  
    int jogadaJogador;
    
   

    cout << "________________________________" << endl
         << endl;
    cout << "Turno Jogador " << jogadorActual << ": " << endl;

    cout << grelha[0][0] << " | " << grelha[0][1] << " | " << grelha[0][2] << endl;
    cout << "---------" << endl;
    cout << grelha[1][0] << " | " << grelha[1][1] << " | " << grelha[1][2] << endl;
    cout << "---------" << endl;
    cout << grelha[2][0] << " | " << grelha[2][1] << " | " << grelha[2][2] << endl
         << endl;

    cin >> jogadaJogador;

    int auxJogadaJogador = jogadaJogador - 1;
    i = auxJogadaJogador / 3;
    j = auxJogadaJogador % 3;

    while (jogadaJogador < 1 || jogadaJogador > 9 || grelha[i][j] != ' ')
    {
        cout << "Jogada inválida, escolha uma posição entre 1 e 9" << endl;
        cin >> jogadaJogador;
        auxJogadaJogador = jogadaJogador - 1;
        i = auxJogadaJogador / 3;
        j = auxJogadaJogador % 3;
    }

    // if (jogadorActual == 1) {
    //     grelha[i][j] = '+';
    // } else {
    //     grelha[i][j] = 'O';
    // }

    grelha[i][j] = (jogadorActual == 1 ? '+' : 'O');

 

    ///return grelha;
}

bool verificarVitoria(int jogadorActual, char** grelha) {
    // Verificar se o Jogador 1 venceu
    // grelha[i][0] == grelha[i][1] == grelha[i][2] == '+'
    // grelha[0][j] == grelha[1][j] == grelha[2][j] == '+'
    // grelha[0][0] == grelha[1][1] == grelha[2][2] == '+'
    // grelha[2][0] == grelha[1][1] == grelha[0][2] == '+'

    if (
        (grelha[i][0] == grelha[i][1] && grelha[i][1] == grelha[i][2] && grelha[i][1] != ' ') ||
        (grelha[0][j] == grelha[1][j] && grelha[1][j] == grelha[2][j] && grelha[0][j] != ' ') ||
        (grelha[0][0] == grelha[1][1] && grelha[1][1] == grelha[2][2] && grelha[1][1] != ' ') ||
        (grelha[2][0] == grelha[1][1] && grelha[1][1] == grelha[0][2] && grelha[1][1] != ' '))
    {
        cout << "Venceu o Jogador " << jogadorActual << endl;
        
        return true;
    }

    return false;
}

int main()
{

    char inputEnter;
  //  int jogadaJogador1;
 //   int jogadaJogador2;

  //  bool possivelJogar = true;
    bool continuarJogar = true;
    // char inputJogarNovamente;

    int numeroVitoriasJogador1 = 0;
    int numeroVitoriasJogador2 = 0;

    while (continuarJogar)
    {
        int contadorJogadas = 0;

        cout << "Regras do jogo:" << endl;
        cout << "Jogador 1 - +" << endl;
        cout << "Jogador 2 - O" << endl;
        cout << "Escolha a posição de jogo" << endl
             << endl;

        cout << "1 | 2 | 3" << endl;
        cout << "---------" << endl;
        cout << "4 | 5 | 6" << endl;
        cout << "---------" << endl;
        cout << "7 | 8 | 9" << endl
             << endl;

        cout << "Clique no ponto e enter para começar a jogar e divirta-se..." << endl
             << endl
             << endl;

        cin >> inputEnter;

        char** grelha=(char**)malloc(4*sizeof(char**));//[4][4] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        grelha[0]=(char*)malloc(4*sizeof(char));
        grelha[1]=(char*)malloc(4*sizeof(char));
        grelha[2]=(char*)malloc(4*sizeof(char));
     
         grelha[0][0] = grelha[0][1] = grelha[0][2] = ' ';
         grelha[1][0] = grelha[1][1] = grelha[1][2] = ' ';
         grelha[2][0] = grelha[2][1] = grelha[2][2] = ' ';
         
    // grelha[0][j] == grelha[1][j] == grelha[2][j] == '+'
    // grelha[0][0] == grelha[1][1] == grelha[2][2] == '+'
    // grelha[2][0] == grelha[1][1] == grelha[0][2] == '+'
        
        int jogadorActual;

        while (true)
        {
            jogadorActual = contadorJogadas % 2 + 1;
            turnoJogador((contadorJogadas % 2 + 1),grelha);
            if (verificarVitoria(jogadorActual, grelha)) {
                if (jogadorActual == 1) {
                    numeroVitoriasJogador1++;
                } else {
                    numeroVitoriasJogador2++;
                }

                break;
            }    

            contadorJogadas += 1;

            if (contadorJogadas > 8)
            {
                cout << "Empataram. Fim do Jogo." << endl;
                break;
            }
        }

        continuarJogar = posJogo(numeroVitoriasJogador1, numeroVitoriasJogador2);
    }
}

