// =================================================================
//
// File: main.cpp
// Author: Alan Fernando Razo Peña
// Date: 12 de octubre de 2021
//
// =================================================================
#include <iostream>
#include <string>
#include <vector>
#include "list.h"

using namespace std;

// Con esta función bool, nos sirve para buscar el prefix
// dentro de los inputs
bool buscar(vector<string> &linea, int i, string &ide){
	//Complejidad = O(1)
	size_t found = linea[i].find(ide);

	//Complejidad = O(1)
	return ((found != string::npos));
}


// Se emplea el Bubble Sort para acomodar el vector.
void bubbleSort(vector<string> &order){
	int size = order.size() - 1;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			string Day1=order[j].substr(0,2);
			string Day2=order[j+1].substr(0,2);
			string Month1=order[j].substr(3,2);
			string Month2=order[j+1].substr(3,2);
			if (Month1 == Month2){
				if (Day1 > Day2){
					swap(order, j, j + 1);
				}
			}
			else {
				if (Month1 > Month2){
					swap(order, j, j + 1);
				}
			}
		}
	}
}


// Con esta función se imprime el vector ya ordenado por mes
void printByMonth (vector<string> &pbm){
	//Complejidad = O(1)
	DoubleLinkedList <string> IdentificadorR;
	//Complejidad = O(1)
	DoubleLinkedList <string> IdentificadorM;
	//Complejidad = O(1)
	int size = pbm.size();
	//Complejidad = O(1)
	uint pos = 0;
	//Complejidad = O(1)
	string monthNumber[12] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
	//Complejidad = O(1)
	string monthWrite[12]= {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
	//Complejidad = O(n)
	for (int j = 0; j < size; j++){
		//Complejidad = O(1)
		string month = pbm[j].substr(3, 2);
		//Complejidad = O(1)
		string puntoDeEntrada = pbm [j].substr (15, 1);
		//Complejidad = O(1)
		string Ide = pbm [j].substr (17, 5);
		//Complejidad = O(1)
		if (month == monthNumber[pos]){
			//Complejidad = O(1)
			if (puntoDeEntrada == "M"){
				//Complejidad = O(1)
				IdentificadorM.push_back(Ide);
			}
			else {
				//Complejidad = O(1)
				IdentificadorR.push_back(Ide);
			}
		}
		else {
			//Complejidad = O(1)
			if ((IdentificadorM.empty()) && (IdentificadorR.empty())){
				//Complejidad = O(1)
				pos++;
			}
			else{
				//Complejidad = O(1)
				std::cout << monthWrite[pos] << endl;
				//Complejidad = O(1)
				if (IdentificadorM.empty()!= true){
					//Complejidad = O(1)
					std::cout << "M " << IdentificadorM.length() << ": " << IdentificadorM.toString() <<endl;
				}
				//Complejidad = O(1)
				if (IdentificadorR.empty()!= true){
					//Complejidad = O(1)
					std::cout << "R " << IdentificadorR.length() << ": " << IdentificadorR.toString() <<endl;
				}
				pos++;
				IdentificadorM.clear();
				if ((month == monthNumber[pos])&&(puntoDeEntrada=="M")){
					//Complejidad = O(1)
					IdentificadorM.push_back(Ide);
				}
				IdentificadorR.clear();
				if ((month == monthNumber[pos])&&(puntoDeEntrada=="R")){
					//Complejidad = O(1)
					IdentificadorR.push_back(Ide);
				}
			}
		}
	}
	//Complejidad = O(1)
	std::cout << monthWrite[pos] << endl;
	//Complejidad = O(1)
	if (IdentificadorM.empty()!= true){
		//Complejidad = O(1)
		std::cout << "M " << IdentificadorM.length() << ": " << IdentificadorM.toString() <<endl;
	}
	if (IdentificadorR.empty()!= true){
		//Complejidad = O(1)
		std::cout << "R " << IdentificadorR.length() << ": " << IdentificadorR.toString() <<endl;
	}
	IdentificadorM.clear();
	IdentificadorR.clear();
}



int main(int argc, char* argv[]) {
	//Inicializamos las primeras variables de entrada
	int ships; //Numero de barcos que van a entrar
	string UBI; //Prefijo a buscar
	cin >> ships; cin >> UBI;

	//Entrada de barcos dada por el usuario
	vector <string> FilteredShipsVector; //Vector tipo string que va a almacenar los barcos una vez que se hayan filtrado
	vector <string> entrada(ships); //Vector tipo string de tam anteriormente especificado, almacena las entradas
	string registroBarco;
	for (int i=0; i < ships; i++){	 		//O(n)
		getline(cin, registroBarco); 			//O(1)
		entrada[i]=registroBarco; 				//O(1)
	}

	//Ciclo que guarda en un nuevo vector la informacion de los barcos que cumplen con el prefijo especificado
	//Complejidad = O(n)
	for (int i = 0; i < ships; i++){
		//Complejidad = O(1)
		if (buscar(entrada, i, UBI)==true){
			//Complejidad = O(1)
			FilteredShipsVector.push_back(entrada[i]);
		}
	}

	//Ordenamos por mes y dia
	bubbleSort (FilteredShipsVector);
	int sizeBarcosFiltrados = FilteredShipsVector.size();
	printByMonth (FilteredShipsVector);

	return 0;
}
