// =================================================================
//
// File: main.cpp
// Author: Alan Fernando Razo Peña
// Date: 10 de septiembre de 2021
//
// =================================================================
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "header.h"

using namespace std;

int main(int argc, char* argv[]) {
	// se inicializan las variables
	int n;
	string prefix, line;
	// Se crean vectores para la lista general y la acomodada
	vector<string> ships;
	vector<string> ordenar;
	//Ciclo for que guarda las lineas en un vector
	cin>>n>>prefix;
	for (int i=0; i<n; i++){
		getline(cin, line);
		ships.push_back(line); //O(n)
	}
	//Ciclo for que busca las lineas igual al prefix
	for (int i=0; i<n; i++){
		size_t found = ships[i].find(prefix);
		if (found != string::npos){
			ordenar.push_back(ships[i]); //O(n)
		}
	}
	//Algoritmo bubbleSort para comparar y ordenar los valores del vector
	string m1, m2, d1, d2;
	for (int i=ordenar.size()-1; i>0; i--){
		for(int j=0; j<i; j++){
			//substr substrae la posicion y cuantos valores de la linea
			m1 = ordenar[j].substr(3, 2);
			d1 = ordenar[j].substr(0, 2);

			m2 = ordenar[j+1].substr(3, 2);
			d2 = ordenar[j+1].substr(0, 2);
			//compara y voltea
			if (m1 == m2) {
					if (d1 > d2) {
							swap(ordenar, j, j+1);
						}
					}
			else {
				if (m1 > m2) {
					swap(ordenar, j, j+1);
				}
			}
		}
	}
	//Despliega los valores ordenados
	for (int i = 0; i < ordenar.size(); i++) {
			cout << ordenar[i] << "\n";
	}

	return 0;
}
