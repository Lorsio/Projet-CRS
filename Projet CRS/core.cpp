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


//Fonction ; Re-définir les variables en fonction des classes
/* void Reset(Personnage);
void Reset_Pas(Pas);
void Mouvement(Personnage, MVT); */
void afficheFond(char lien[], SDL_Renderer *rendu);


//PARTIE INITIALISATION : Fenêtre, icone, nom, répétition

//PARTIE PRINCIAPLE : Main
int main(int argn, char* argv[]) {
	//Ouverture de la SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cout << "Echec à l’ouverture";
		return 1;
	}
	//Création de la fenêtre
	SDL_Window* win = SDL_CreateWindow(titre_fenetre, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, TAILLE_X, TAILLE_Y, SDL_WINDOW_SHOWN);
	if (win == NULL)
		cout << "erreur ouverture fenetre";
	//Création d'un rendu
	SDL_Renderer *rendu = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	//Application d'une icone
	SDL_Surface* icone = SDL_LoadBMP(image_icone);
	SDL_SetWindowIcon(win, icone);
	SDL_FreeSurface(icone);


	bool continuer = true, choix_niveau = false, continuer_niveau = false, continuer_jeu = false;
	SDL_Event event;//gestion des évènements souris/clavier, 
	while (continuer) {
		//char image_accueil[24] = "images/fond/accueil.png";
		//on crée une texture à partir de l'image, de sa couleur, et de la fonte
		afficheFond(image_accueil, rendu);

		SDL_WaitEvent(&event);//attente d’un évènement
		switch (event.type) //test du type d’évènement
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
				if (event.key.keysym.sym == SDLK_RETURN) { // a modif, pour test là;
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

			/*if (Générer == False){
			// Création des persos...
			}
			else {
			// Reset des persos...
			}
			Perso = Romain; //perso par défaut */


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
	//on crée une texture à partir de l'image, de sa couleur, et de la fonte
	SDL_Texture *textureFond = loadImage(rendu, lien);
	SDL_QueryTexture(textureFond, NULL, NULL, &posFond.w, &posFond.h);
	SDL_RenderCopy(rendu, textureFond, NULL, &posFond); //on copie la texture dans le rendu
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(textureFond);
}
