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
	char ligne[500];
public:
	Niveau();
	~Niveau();

	void generer(char* choix_niveau);
	void afficher(SDL_Renderer *rendu);
	void affichecase(SDL_Renderer *rendu, SDL_Rect PosFond, char* image);
};

/*
class Joueur {

};
*/

#endif



