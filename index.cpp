#include "index.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
std::fstream fichier("score.txt");
vector<float> tempsDeFin;
vector<std::string> nomsFin;
std::string ligne;
void index::Generation()
{
	srand(time(NULL));
	nombreCacher = rand() % 100;
}

void index::Nombre()
{
	std::cout << nombreCacher << std::endl;
	std::cout << "veillez trouvez le nombre cacher ! " << std::endl;
	do																								     // boucle le temps qu'il n'est pas stopper / break
	{
		std::cin >> nombreTest;
		if (nombreTest > nombreCacher)																	// regarde si le nombre tester est plus grands
		{
			std::cout << "C'est moins ! " << std::endl;
			nombreDeTentative += 1;																		// nombre de tentative + 1
		}
		else if (nombreTest < nombreCacher)															   // regarde si le nombre tester est plus petit 
		{
			std::cout << "C'est plus ! " << std::endl;
			nombreDeTentative += 1;																	// nombre de tentative + 1
		}
		else if (nombreTest == nombreCacher) {
			temps = clock();
			nombreDeTentative += 1;
			std::cout << "Tu as trouvee le nombre cacher ! " << std::endl;
			std::cout << "voici ton nombre de tentative ! =  " << nombreDeTentative << std::endl;
			std::cout << "voici ton temps en secondes :  " << (double)temps / CLOCKS_PER_SEC << std::endl;	// transforme le temps en ticks en secondes.
			break;																								// break les thread
		}
	} while (true);
}

void index::Noms()
{
	std::ofstream myfile;
	myfile.open("score.txt", std::ios::app);

	std::cout << "Quelle est votre nom ? " << std::endl;
	std::cin >> nom;
	double temps1 = (double)temps / CLOCKS_PER_SEC;
	myfile << std::endl << (double)temps / CLOCKS_PER_SEC << " " << nom;
	tempsDeFin.push_back(temps1);
	nomsFin.push_back(nom);
	myfile.close();
}

void index::tableau()
{
	float temp;
	string nomJoueurs;
	while (!fichier.eof())
	{
		fichier >> temp >> nomJoueurs;
		tempsDeFin.push_back(temp);
		nomsFin.push_back(nomJoueurs);
	}

}
void index::PetitScore()
{
		cout << "Le premier du jeu est " << nomsFin[0] << " avec comme temps : " << tempsDeFin[0] << endl;
}

void index::trie()
{
	int passage = 0;
	bool permutation = true;
	int en_cours;
	while (permutation == true)
	{
		permutation = false;
		passage++;
		for (en_cours = 0; en_cours<tempsDeFin.size() - passage; en_cours++)
		{
			if (tempsDeFin[en_cours]>tempsDeFin[en_cours + 1])
			{
				permutation = true;
				float temp = tempsDeFin[en_cours];
				tempsDeFin[en_cours] = tempsDeFin[en_cours + 1];
				tempsDeFin[en_cours + 1] = temp;
				string temp1 = nomsFin[en_cours];
				nomsFin[en_cours] = nomsFin[en_cours + 1];
				nomsFin[en_cours + 1] = temp1;
			}
		}
	}
}


void index::PropositionsAffichage()
{
	std::cout << "Voulez-vous afficher toutes les statistique du jeu ? Y or N" << std::endl;
	std::cin >> validation;	// demande
	if (validation == 'Y' || validation == 'y')        // validation de d'afficher             
	{
		std::cout << " affichage des statistiques du jeu" << std::endl; //
		for (int i = 0; i < tempsDeFin.size(); i++)	// affichage de tout les valeur du tableau
		{
			cout << "Le " << i << " du jeu est " << nomsFin[i] << " avec comme temps : " << tempsDeFin[i] << endl;
		}
	}
	if (validation == 'N' || validation == 'n') //validation de ne pas afficher. 
	{
		std::cout << "Vous avez pas voulu afficher toutes les statistique du jeu" << std::endl; //
	}
	fichier.close();
}
