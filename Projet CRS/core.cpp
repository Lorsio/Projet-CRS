#include <iostream>
#include <ctime>
#include <cstring>
#include <cmath>
#include <fstream>
#include <SDL.h> 
#include <SDL_ttf.h> //pour le texte
#include "classes.h"
#include "config_sdl.h"
using namespace std;


//Fonction ; Re-d�finir les variables en fonction des classes
/* void Reset(Personnage);
void Reset_Pas(Pas);
void Mouvement(Personnage, MVT); */
void afficheFond(char lien[], SDL_Renderer *rendu);


//PARTIE INITIALISATION : Fen�tre, icone, nom, r�p�tition

//PARTIE PRINCIAPLE : Main
int main(int argn, char* argv[]) {
	//Ouverture de la SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Echec � l�ouverture";
		return 1;
	}
	//Cr�ation de la fen�tre
	SDL_Window* win = SDL_CreateWindow(titre_fenetre, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TAILLE_X, TAILLE_Y, SDL_WINDOW_SHOWN);
	if (win == NULL)
		cout << "erreur ouverture fenetre";
	//Cr�ation d'un rendu
	SDL_Renderer *rendu = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	//Application d'une icone
	SDL_Surface* icone = SDL_LoadBMP(image_icone);
	SDL_SetWindowIcon(win, icone);
	SDL_FreeSurface(icone);


	bool continuer = true, choix_niveau = false, continuer_niveau = false, continuer_jeu = false;
	SDL_Event event;//gestion des �v�nements souris/clavier, 
	while (continuer) {
		//char image_accueil[24] = "images/fond/accueil.png";
		//on cr�e une texture � partir de l'image, de sa couleur, et de la fonte
		afficheFond(image_accueil, rendu);

		SDL_WaitEvent(&event);//attente d�un �v�nement
		switch (event.type) //test du type d��v�nement
		{
		case SDL_QUIT: //clic sur la croix de fermeture
					   //on peut enlever SDL_Delay
			continuer = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				continuer = false;
			}
			if (event.key.keysym.sym == SDLK_RETURN) {
				continuer_niveau = true;
			}
			break;
		}
		while (continuer_niveau) {
			afficheFond(image_niveau, rendu);
			SDL_WaitEvent(&event);
			switch (event.type) {
			case SDL_QUIT:
				continuer_niveau = false;
				continuer = false;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					choix_niveau = false;
					continuer_niveau = false;
				}
				if (event.key.keysym.sym == SDLK_RETURN) { // a modif, pour test l�;
					choix_niveau = true;
					continuer_jeu = true;
					continuer_niveau = false;
				}
				break;
			}
		}
		if (choix_niveau) {
			Niveau niveau;
			niveau.generer("niveaux/n0");
			niveau.afficher(rendu);
		}

			/*if (G�n�rer == False){
			// Cr�ation des persos...
			}
			else {
			// Reset des persos...
			}
			Perso = Romain; //perso par d�faut */


		while (continuer_jeu) {
			SDL_WaitEvent(&event);
			switch (event.type) {
			case SDL_QUIT:
				continuer_jeu = false;
				continuer = false;
				break;
			}
		}
	}
	SDL_Quit();
	return 0;
}


void afficheFond(char lien[], SDL_Renderer *rendu) {
	SDL_Rect posFond;
	posFond.x = 0;
	posFond.y = 0;
	//on cr�e une texture � partir de l'image, de sa couleur, et de la fonte
	SDL_Texture *textureFond = loadImage(rendu, lien);
	SDL_QueryTexture(textureFond, NULL, NULL, &posFond.w, &posFond.h);
	SDL_RenderCopy(rendu, textureFond, NULL, &posFond); //on copie la texture dans le rendu
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(textureFond);
}
