// Kolorowanie.cpp : main project file.

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"

#define POPUALTION
#define CROSS_CHANCE
#define MUTATION_CHANCE
#define STOP_MOMENT

#define NAZWA_PLIKU "myciel4.txt"

using namespace std;



class Grapf
{
public:

	int V = 0;	//ilość wierzchołków w grafie
	int size = 0; //rozmiar tablicy -- o 1 większe niż V żeby indeksować od 1 a nie od 0
	int **tab; //nasz graf

	void pobierz_V_z_pliku(ifstream &file) 
	{
		string buf;
		getline(file, buf);
		V = stoi(buf);
		size = V + 1;
	}
	
	void stwórz_pusty_graf()
	{
		tab = new int*[size];			//Creating 2D graph's array (vertices start from 1 instead of 0 for clarity sake)
		for (int i = 0; i < size; i++)
			tab[i] = new int[size];

		for (int i = 1; i <= size; i++)
			for (int j = 1; j < size; j++)
				tab[j][i] = 0;
	}

	void uzupelnij_graf_danymi(ifstream &file)
	{

		while (!file.eof()) {

			string buf, buf1;
			getline(file, buf, ' ');				//"Grabbing" the edge...
			getline(file, buf1, '\n');

			tab[stoi(buf)][stoi(buf1)] = 1;
			tab[stoi(buf1)][stoi(buf)] = 1;				//...and slapping it into the array
		}
	}

	void wypisz_graf_na_konsole()
	{
		for (int i = 1; i < size; i++) {
			for (int j = 1; j < size; j++) {			//Writing the graph's array onto the console
				cout << tab[i][j];
			}
			cout << '\n';
		}
	}

};



int main()
{
	ifstream file;

	file.open(NAZWA_PLIKU);						//Opening the file

	if (file.is_open()) {

		Grapf graf;

		graf.pobierz_V_z_pliku(file);
		graf.stwórz_pusty_graf();
		graf.uzupelnij_graf_danymi(file);
		graf.wypisz_graf_na_konsole();

		

		

		
	}


	return 0;
}