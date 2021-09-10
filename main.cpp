#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

	int main()
{
		std::ofstream myfile;
		myfile.open("score.txt", std::ios::app);




		clock_t temps;																				// stock le temps que le programme est lancer 
	srand(time(NULL));
	int nombreCacher = rand()%100;																			  // stock la valeurs à trouvée
	int nombreDeTentative = 0;																				 // stock le nombre de tentative
	int nombreTest;				// stock le nombre qui est tester
	std::string nom;
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
		else if (nombreTest == nombreCacher){
			temps = clock();
			nombreDeTentative += 1;
			std::cout << "Tu as trouvee le nombre cacher ! " << std::endl;
			std::cout << "voici ton nombre de tentative ! =  " << nombreDeTentative <<std::endl;
			std::cout << "voici ton temps en secondes :  " << (double)temps / CLOCKS_PER_SEC << std::endl;	// transforme le temps en ticks en secondes.
			break;																								// break les thread
		}
	} while (true);
	
	std::cout << "Quelle est votre nom ? " << std::endl;
	std::cin >> nom;

	myfile << (double)temps / CLOCKS_PER_SEC << " "<< nom;
	myfile.close();









	return 0;
}