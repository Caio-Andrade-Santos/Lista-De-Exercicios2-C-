#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

string ListaTelefonica(string nome){
    string aux = "", aux2 = "";
    int ps;

    for(int i = nome.length() - 1; i >= 0; i--){
        if(nome[i] == ' '){
            ps = i;
            break;
        }
        aux += nome[i];
    }

    for(int i = aux.length() - 1; i >= 0; i--){
        aux2 += aux[i];
    }

    aux2.append(", ");
    nome.erase(ps);
    nome.insert(0, aux2);

    return nome;
}

int main(){
    setlocale(LC_ALL, "");

    ifstream entrada("nomes.txt");
    ofstream saida("lista1.txt", ios::app);

    string nome;

    if (entrada.is_open() && saida.is_open()) {
        while (getline(entrada, nome)) {
            string resultado = ListaTelefonica(nome);
            saida << resultado << endl;
        }
        entrada.close();
        saida.close();
    } else {
        cout << "Erro ao abrir arquivo";
    }

    return 0;
}