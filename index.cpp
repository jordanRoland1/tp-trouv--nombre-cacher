#include "index.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
std::fstream fichier("score.txt");
vector<std::string> tableau1;
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

	myfile << (double)temps / CLOCKS_PER_SEC << " " << nom << std::endl;

	myfile.close();
}

//void index::PetitScore()
//{
//	while (std::getline(fichier, ligne))
//	{
//		tableau1.push_back(ligne);
//	}
	
//	for (int i = 0; i < tableau1.size(); i++)
//	{
//		cout << "Le " << i << " du jeu est " << tableau1[i] << endl;
//	}
//}




void index::PropositionsAffichage()
{
// cette boucle s'arrête dès qu'une erreur de lecture survient 
	while (std::getline(fichier, ligne))
	{
			tableau1.push_back(ligne);
	}
	std::cout << "Voulez-vous afficher toutes les statistique du jeu ? Y or N" << std::endl;
	std::cin >> validation;
	if (validation == 'Y')
	{
		std::cout << " affichage des 3 premiers du jeu" << std::endl;
		for (int i = 0; i < tableau1.size() ; i++)
		{
			cout << "Le " << i << " du jeu est " << tableau1[i] << endl;
		}
	}
	if (validation == 'N')
	{
		std::cout << "Vous avez pas voulu afficher toutes les statistique du jeu" << std::endl;
	}
	fichier.close();
}