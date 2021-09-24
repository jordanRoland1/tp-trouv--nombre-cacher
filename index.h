#pragma once
#include <string>
#include <time.h>
#include <vector>


class index
{
private:
	int nombreDeTentative = 0;
	int nombreTest;
	int nombreCacher;
	char validation;
	std::string nom;
	clock_t temps;
public: 
	void Generation();
	void Nombre();
	void Noms();
	void PropositionsAffichage();
//	void PetitScore();



};

