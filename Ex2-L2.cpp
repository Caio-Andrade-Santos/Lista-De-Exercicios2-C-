#include <iostream>
#include <stdlib.h> 
#include <iomanip>
#include <algorithm>
using namespace std;

string palavra;


void VerificaPalavra(string palavra){
	string aux;
	palavra.erase(remove(palavra.begin(), palavra.end(), ' '), palavra.end());
	for( int i = palavra.length() -1; i >= 0 ; i--){
		aux += palavra[i];
	}
	if( palavra == aux){
		cout << "e um palindromo" << endl;
	}
	else{
		cout << "nao e um palindromo " << endl;
	}
}

int main(int argc, char** argv)
{
	cout << "Digite uma palavra para verificar se é um palindromo" << endl;
	getline(cin, palavra);
	VerificaPalavra(palavra);
	return 0;
}