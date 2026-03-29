#include <iostream>
#include <fstream>
#include <locale.h>
#include <cctype>
using namespace std;

string ListaTelefonica(string nome){
    string aux = "", aux2 = "", iniciais = "", primeiroNome = "";
    int ps;
    int posicoes[100];
    int count = 0;

    for(int i = nome.length() - 1; i >= 0; i--){
        if(nome[i] == ' '){
            ps = i;
            break;
        }
        aux += nome[i];
    }

    for(int i = 0; i < nome.length(); i++){
        if(nome[i] == ' '){
            posicoes[count] = i;
            count++;
        }
    }

    for(int i = aux.length() - 1; i >= 0; i--){
        aux2 += toupper(aux[i]);
    }

    for(int i = 0; i < nome.length(); i++){
        if(nome[i] == ' ') break;
        primeiroNome += nome[i];
    }

    for(int i = 0; i < count; i++){
        if(posicoes[i] + 1 < ps && posicoes[i] != (int)primeiroNome.length()-1){
            iniciais += " ";
            iniciais += toupper(nome[posicoes[i] + 1]);
            iniciais += ".";
        }
    }

    aux2.append(", ");
    aux2.append(primeiroNome);
    aux2.append(iniciais);

    return aux2;
}

int main(){
    setlocale(LC_ALL, "");

    ifstream entrada("nomes2.txt");
    ofstream saida("lista2.txt", ios::app);

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