#include <iostream>

using namespace std;

int main()
{

    char inputEnter;
    int jogadaJogador1;
    int jogadaJogador2;

 
    bool continuarJogar = true;
    char inputJogarNovamente;

    int numeroVitoriasJogador1 = 0;
    int numeroVitoriasJogador2 = 0;

    while (continuarJogar)
    {
        int contadorJogadas = 1;

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

        char grelha[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

        while (true)
        {

            /*******************************************************************
             * JOGADOR 1
             *******************************************************************/
            cout << "________________________________" << endl
                 << endl;
            cout << "Turno Jogador 1:" << endl;

            cout << grelha[0][0] << " | " << grelha[0][1] << " | " << grelha[0][2] << endl;
            cout << "---------" << endl;
            cout << grelha[1][0] << " | " << grelha[1][1] << " | " << grelha[1][2] << endl;
            cout << "---------" << endl;
            cout << grelha[2][0] << " | " << grelha[2][1] << " | " << grelha[2][2] << endl
                 << endl;

            cin >> jogadaJogador1;

            int auxJogadaJogador1 = jogadaJogador1 - 1;
            int i = auxJogadaJogador1 / 3;
            int j = auxJogadaJogador1 % 3;

            while (jogadaJogador1 < 1 || jogadaJogador1 > 9 || grelha[i][j] != ' ')
            {
                cout << "Jogada inválida, escolha uma posição entre 1 e 9" << endl;
                cin >> jogadaJogador1;
                auxJogadaJogador1 = jogadaJogador1 - 1;
                i = auxJogadaJogador1 / 3;
                j = auxJogadaJogador1 % 3;
            }

            grelha[i][j] = '+';

            // Verificar se o Jogador 1 venceu
            // grelha[i][0] == grelha[i][1] == grelha[i][2] == '+'
            // grelha[0][j] == grelha[1][j] == grelha[2][j] == '+'
            // grelha[0][0] == grelha[1][1] == grelha[2][2] == '+'
            // grelha[2][0] == grelha[1][1] == grelha[0][2] == '+'

            if (
                (grelha[i][0] == grelha[i][1] && grelha[i][1] == grelha[i][2] && grelha[i][1] == '+') ||
                (grelha[0][j] == grelha[1][j] && grelha[1][j] == grelha[2][j] && grelha[0][j] == '+') ||
                (grelha[0][0] == grelha[1][1] && grelha[1][1] == grelha[2][2] && grelha[1][1] == '+') ||
                (grelha[2][0] == grelha[1][1] && grelha[1][1] == grelha[0][2] && grelha[1][1] == '+'))
            {
                cout << "Venceu o Jogador 1" << endl;
                numeroVitoriasJogador1++;
                break;
            }

            contadorJogadas += 1;

            if (contadorJogadas > 9)
            {
                cout << "Empataram. Fim do Jogo." << endl;
                break;
            }

            /*******************************************************************
             * JOGADOR 2
             *******************************************************************/
            cout << "________________________________" << endl
                 << endl;
            cout << "Turno Jogador 2:" << endl;

            cout << grelha[0][0] << " | " << grelha[0][1] << " | " << grelha[0][2] << endl;
            cout << "---------" << endl;
            cout << grelha[1][0] << " | " << grelha[1][1] << " | " << grelha[1][2] << endl;
            cout << "---------" << endl;
            cout << grelha[2][0] << " | " << grelha[2][1] << " | " << grelha[2][2] << endl
                 << endl;

            cin >> jogadaJogador2;

            int auxJogadaJogador2 = jogadaJogador2 - 1;
            i = auxJogadaJogador2 / 3;
            j = auxJogadaJogador2 % 3;

            while (jogadaJogador2 < 1 || jogadaJogador2 > 9 || grelha[i][j] != ' ')
            {
                cout << "Jogada inválida, escolha uma posição entre 1 e 9" << endl;
                cin >> jogadaJogador2;
                auxJogadaJogador2 = jogadaJogador2 - 1;
                i = auxJogadaJogador2 / 3;
                j = auxJogadaJogador2 % 3;
            }

            grelha[i][j] = 'O';

            if (
                (grelha[i][0] == grelha[i][1] && grelha[i][1] == grelha[i][2] && grelha[i][1] == 'O') ||
                (grelha[0][j] == grelha[1][j] && grelha[1][j] == grelha[2][j] && grelha[0][j] == 'O') ||
                (grelha[0][0] == grelha[1][1] && grelha[1][1] == grelha[2][2] && grelha[1][1] == 'O') ||
                (grelha[2][0] == grelha[1][1] && grelha[1][1] == grelha[0][2] && grelha[1][1] == 'O'))
            {
                cout << "Venceu o Jogador 2" << endl;
                numeroVitoriasJogador2++;
                break;
            }

            contadorJogadas += 1;

            if (contadorJogadas > 9)
            {
                cout << "Empataram. Fim do Jogo." << endl;
                break;
            }
        }

        cout << endl << endl << "__________________________" << endl;
        cout << "Resultados:" << endl;
        cout << "Jogador 1 -> " << numeroVitoriasJogador1 << " - ";
        cout << numeroVitoriasJogador2 << " <- Jogador 2" << endl << endl; 

        cout << endl << endl << "__________________________" << endl;
        cout << endl << "Quer jogar novamente? [S/n]" << endl;
        cin >> inputJogarNovamente;

        if (tolower(inputJogarNovamente) != 's' ) {
            continuarJogar = false;
        }
    }
}