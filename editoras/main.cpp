#include <iostream>
#include <vector>
#include <string>
#include <limits> // Alteração
#include <sstream>
using namespace std;



void * operator new(size_t size)
{
    cout << "New ("<< size <<")" << endl;
    void * p = malloc(size);
    return p;
}

void operator delete(void * p,size_t size)
{
    (void)size;
    cout << "Delete " << endl;
    free(p);
}

void operator delete(void * p)
{
    cout << "Delete " << endl;
    free(p);
}
void* operator new[](size_t sz)
{
  std::cout<<"New ["<<sz<<"]"<<std::endl;
  void* m = malloc(sz);
  return m;
}

void operator delete[](void* m,size_t size)
{
    (void)size;
  std::cout<<"Delete[]"<<std::endl;
  free(m);
}
void operator delete[](void* m)
{
  std::cout<<"Delete[]"<<std::endl;
  free(m);
}
class Editora {
    protected:
        string          nome;
        int             ano;
        vector<string>  cancoes;

    public:
        Editora() {};

/*
        Editora(const Editora& c)
        {
          std::cout<<"Copy"<<std::endl;
          this->nome =c.nome;
          this->ano  =c.ano;
          for (const std::string &s: c.cancoes)
          {
              this->cancoes.push_back(s);
          }
        }
        */
        Editora(string novoNome, int novoAno, vector<string> novasCancoes)
            : nome(novoNome), ano(novoAno), cancoes(novasCancoes) {}


        void setNome(string novoNome) {
            this->nome = novoNome;
        }

        string getNome() {
            return this->nome;
        }

        void setAno(int novoAno) {
            this->ano = novoAno;
        }

        int getAno() {
            return this->ano;
        }

        void setCancoes(vector<string> novasCancoes) {
            this->cancoes = novasCancoes;
        }

        vector<string> getCancoes() {
            return this->cancoes;
        }

        void adicionarCancao(string novaCancao) {
            this->cancoes.push_back(novaCancao);
        }

        bool removerCancao(string cancao) {
            int tamanho = this->cancoes.size();

            for (int i = 0; i < tamanho; i++) {
                if (this->cancoes[i] == cancao) {
                    this->cancoes.erase(this->cancoes.begin() + i);
                    return true;
                }
            }

            return false;
        }

        string listaCancoes() {
            int tamanho = this->cancoes.size();
            string cancoesString = "";

            for (int i = 0; i < tamanho; i++) {
                cancoesString += this->cancoes[i] + ", ";
            }

            return cancoesString;
        }

};

/*
void menuEditora(vector<Editora> &lista,int index) {
    Editora editora =  lista[index];
    system("clear");
    int input;
    string inputString;
    cout << endl << endl << "Menu da Editora " << editora.getNome() << ": " << endl;
    cout << "Escolha uma das seguintes opções:" << endl;
    cout << "\t[1] - Adicionar uma canção" << endl;
    cout << "\t[2] - Remover uma canção" << endl;
    cout << "\t[3] - Listar as canções" << endl; // alterações
    cout << endl << "\t[0] - Sair do Menu" << endl;
    cin >> input;
    cin.ignore (numeric_limits<streamsize>::max(), '\n');


    switch (input)
{
        case 0:
            break;
        case 1:
            cout << "Por favor, escreva o nome da canção a adicionar:" << endl;
            getline(cin, inputString);
            editora.adicionarCancao(inputString);

            break;
        case 2:
            cout << "Por favor, escreva o nome da canção a remover:" << endl;
            getline(cin, inputString);
            editora.removerCancao(inputString);
            break;

        case 3:
            cout << "Lista de canções da editora " << editora.getNome() << ":" << endl;
            cout << editora.listaCancoes();
            break;
    }

     lista[index] = editora;
}
*/

void menuEditora( Editora &editora) {

   // system("clear");
    int input;
    string inputString;
    cout << endl << endl << "Menu da Editora " << editora.getNome() << ": " << endl;
    cout << "Escolha uma das seguintes opções:" << endl;
    cout << "\t[1] - Adicionar uma canção" << endl;
    cout << "\t[2] - Remover uma canção" << endl;
    cout << "\t[3] - Listar as canções" << endl; // alterações
    cout << endl << "\t[0] - Sair do Menu" << endl;
    cin >> input;
    cin.ignore (numeric_limits<streamsize>::max(), '\n');


    switch (input)
{
        case 0:
            break;
        case 1:
            system("clear");
            cout << "Por favor, escreva o nome da canção a adicionar:" << endl;
            getline(cin, inputString);
            editora.adicionarCancao(inputString);

            break;
        case 2:
              system("clear");
            cout << "Por favor, escreva o nome da canção a remover:" << endl;
            getline(cin, inputString);
            editora.removerCancao(inputString);
            break;

        case 3:
            system("clear");
            cout << "Lista de canções da editora " << editora.getNome() << ":" << endl;
            cout << editora.listaCancoes();
            break;
    }


}
int main() {

    vector<Editora> editoras;

    {


    string  nomeSony = "Sony";
    int     anoSony = 1950;
    vector<string> listaCancoes = { "Sete Mares", "Amish Paradise", "Siga a malta" };


    Editora sony(nomeSony, anoSony, listaCancoes);
    editoras.push_back(sony);
    }

     {


    string  nomeSony = "pimba";
    int     anoSony = 2950;
    vector<string> listaCancoes = { "Sete ", "Amish ai", "Siga " };


    Editora sony(nomeSony, anoSony, listaCancoes);
    editoras.push_back(sony);
    }

    bool continuar = true;
    int input;


    while (continuar) {
            
        cout << endl << endl << "Menu das editoras: " << endl;
        cout << "Escolha uma das seguintes opções:" << endl;
        cout << "\t[1] - Adicionar uma editora:" << endl;
        cout << "\t[2] - Remove uma editora:" << endl;
        cout << "\t[3] - Ver uma editora:" << endl;
        cout << "\t[4] - Listar as editoras:" << endl;
        cout << endl << "\t[0] - Sair" << endl;



        cin >> input;

        switch (input)
        {
        case 0:
            {
                continuar=false;
                break;
            }
            case 1:
            {
                 system("clear");
                string nomeNovaEditora;
                int anoNovaEditora;
                vector<string> listaCancoesNovaEditora = {};

                cout << "Adicione o nome da editora:" << endl;
                cin >> nomeNovaEditora;

                cout << "Adicione o ano de fundação da editora:" << endl;
                cin >> anoNovaEditora;

                cout << "Adicione a lista de canções separadas por vírgulas:" << endl;

                string inputString;
                getline(cin, inputString);
                cout << inputString << endl;
                cin.ignore (numeric_limits<streamsize>::max(), '\n');


                stringstream streamMusicas(inputString);

                while(streamMusicas.good()) {
                    string token;
                    getline(streamMusicas, token, ',');
                    listaCancoesNovaEditora.push_back(token);
                }


                Editora novaEditora(nomeNovaEditora, anoNovaEditora, listaCancoesNovaEditora);

                editoras.push_back(novaEditora);

                break;
            }

            case 2:
            {
                 system("clear");
                cout << "Por favor, escreva o nome da editora a remover:" << endl;
                string inputString;
                getline(cin, inputString);
                cin.ignore ();
               

                for (int i = 0; i < (int)editoras.size(); i++) {
                    Editora item = editoras[i];

                    if (item.getNome() == inputString) {
                        editoras.erase(editoras.begin() + i);
                        break;
                    }
                }

                break;
            }

            case 3:
            {
                system("clear");
                cout << "Por favor, escreva o nome da editora a ver:" << endl;
                string inputString;
                cin.ignore ();
                getline(cin, inputString);



                bool existe = false;

                for (int i = 0; i < (int)editoras.size(); i++)
                {
                    Editora item = editoras[i];

                    if (item.getNome() == inputString)
                    {
                        existe = true;
                       // menuEditora(editoras,i);
                        menuEditora(item);
                        editoras[i]=item;

                        break;
                    }
                }

                if (!existe)
                {
                  cout << "A editora (" << inputString << ")não existe!" << endl;
                }

                break;
            }
        }
    }

    return 0;
}
