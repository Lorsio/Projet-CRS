#pragma once
#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <ctime>
#include <cstring>
#include <cmath>
#include <fstream>
#include <SDL.h> 
#include "variables.h"
#include "config_sdl.h"
using namespace std;
using namespace Var;

class Niveau
{
private:

public:
	Niveau();
	~Niveau();
	char ligne[21][21];
	void generer(char* choix_niveau);
	void afficher(SDL_Renderer *rendu);
	void affichecase(SDL_Renderer *rendu, SDL_Rect PosFond, char* image);
};


class Joueur {
private:
	int case_x = 1, case_y = 0;

	SDL_Rect posFond;

public: 
	Joueur();
	~Joueur();

	void deplacer(char* direction, SDL_Renderer *rendu, char ligne[][21]);
	void affichecase(SDL_Renderer *rendu, SDL_Rect posFond, char* image);


};


#endif



