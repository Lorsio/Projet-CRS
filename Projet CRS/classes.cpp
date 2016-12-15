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
		char tmp[3];
		int i = 0;
		while (!entree.eof()) {
			entree.getline(tmp, 1);
			ligne[i] = tmp[0];
			i++;
		}
		entree.close();
	}
}

void Niveau::afficher(SDL_Renderer *rendu) {
	int x = 0, y = 0;

	SDL_Rect posFond;
	//on crée une texture à partir de l'image, de sa couleur, et de la fonte


	for (int num_ligne = 0; num_ligne < 20; num_ligne++) {
		for (int num_case = 0; num_case < 20; num_case++) {
			posFond.x = num_case * TAILLE_SPR_X;
			posFond.y = num_ligne * TAILLE_SPR_Y;
			if (ligne[num_ligne * 20 + num_case] == 'm') {
				SDL_Texture *textureFond = loadImage(rendu, image_M);
				SDL_QueryTexture(textureFond, NULL, NULL, &posFond.w, &posFond.h);
				SDL_RenderCopy(rendu, textureFond, NULL, &posFond); //on copie la texture dans le rendu
				SDL_RenderPresent(rendu);
				SDL_DestroyTexture(textureFond);
			}
		}
	}
}