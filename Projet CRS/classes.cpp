#include "classes.h"



Niveau::Niveau()
{
}


Niveau::~Niveau()
{
}

void Niveau::generer(char* choix_niveau) {
	ifstream entree(choix_niveau, ios::in);
	if (!entree)
		cout << "Problème d'ouverture" << endl;
	else {
		char tmp;
		int i = 0;
		while (!entree.eof()) {
			entree.get(tmp);
			if (tmp == '\n') entree.get(tmp);
			ligne[i] = tmp;
			i++;
		}
		entree.close();
	}
}

void Niveau::afficher(SDL_Renderer *rendu) {
	SDL_Rect posFond;
	for (int num_ligne = 0; num_ligne < 20; num_ligne++) {
		for (int num_case = 0; num_case < 20; num_case++) {
			posFond.x = num_case * TAILLE_SPR_X;
			posFond.y = num_ligne * TAILLE_SPR_Y;
			if (ligne[num_ligne * 20 + num_case] == 'm') {
				affichecase(rendu, posFond, image_M);
			}
			if (ligne[num_ligne * 20 + num_case] == 't') {
				affichecase(rendu, posFond, image_T);
			}
			if (ligne[num_ligne * 20 + num_case] == 's') {
				affichecase(rendu, posFond, image_S);
			}
			if (ligne[num_ligne * 20 + num_case] == 'e') {
				affichecase(rendu, posFond, image_E);
			}
			if (ligne[num_ligne * 20 + num_case] == 'f') {
				affichecase(rendu, posFond, image_F);
			}
			if (ligne[num_ligne * 20 + num_case] == 'a') {
				affichecase(rendu, posFond, image_A);
			}
			if (ligne[num_ligne * 20 + num_case] == 'q') {
				affichecase(rendu, posFond, image_Q);
			}
		}
	}
}

void Niveau::affichecase(SDL_Renderer *rendu, SDL_Rect posFond, char* image) {
	SDL_Texture *textureFond = loadImage(rendu, image);
	SDL_QueryTexture(textureFond, NULL, NULL, &posFond.w, &posFond.h);
	SDL_RenderCopy(rendu, textureFond, NULL, &posFond); //on copie la texture dans le rendu
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(textureFond);
}