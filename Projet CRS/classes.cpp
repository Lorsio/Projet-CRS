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
		int i = 0, j = 0;
		while (!entree.eof()) {
			if (i == 20) {
				i = 0;
				j++;
			}
			entree.get(tmp);
			if (tmp == '\n') entree.get(tmp);
			ligne[j][i] = tmp;
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
			if (ligne[num_ligne][num_case] == 'm') {
				affichecase(rendu, posFond, image_M);
			}
			if (ligne[num_ligne][num_case] == 't') {
				affichecase(rendu, posFond, image_T);
			}
			if (ligne[num_ligne][num_case] == 's') {
				affichecase(rendu, posFond, image_S);
			}
			if (ligne[num_ligne][num_case] == 'e') {
				affichecase(rendu, posFond, image_E);
			}
			if (ligne[num_ligne][num_case] == 'f') {
				affichecase(rendu, posFond, image_F);
			}
			if (ligne[num_ligne][num_case] == 'a') {
				affichecase(rendu, posFond, image_A);
			}
			if (ligne[num_ligne][num_case] == 'q') {
				affichecase(rendu, posFond, image_Q);
			}
		}
	}
}

void Niveau::affichecase(SDL_Renderer *rendu, SDL_Rect posFond, char* image) {
	SDL_Texture *textureFond = loadImage(rendu, image);
	SDL_QueryTexture(textureFond, NULL, NULL, &posFond.w, &posFond.h);
	SDL_RenderCopy(rendu, textureFond, NULL, &posFond); //on copie la texture dans le rendu
	SDL_DestroyTexture(textureFond);
}

Joueur::Joueur() {

}
Joueur::~Joueur() {

}

void Joueur::deplacer(char* direction, SDL_Renderer *rendu, char ligne[][21]) {
	if (strcmp(direction, "right") == 0 && ligne[case_y+1][case_x+1] != 'm') {
		if (case_x < (NBR_SPR_COTE - 1)) {
			case_x++;
			Joueur::affichecase(rendu, posFond, image_SRR);
		}
	}
	if (strcmp(direction, "left") == 0 && ligne[case_y+1][case_x - 1] != 'm') {
		if (case_x > 0) {
			case_x--;
			Joueur::affichecase(rendu, posFond, image_SRL);
		}
	}
	if (strcmp(direction, "up") == 0 && ligne[case_y][case_x] != 'm') {
		if (case_y > 0) {
			case_y--;
			Joueur::affichecase(rendu, posFond, image_SRB);
		}
	}
	if (strcmp(direction, "down") == 0 && ligne[case_y+2][case_x] != 'm') {
		if (case_y < (NBR_SPR_COTE - 1)) {
			case_y++;
			Joueur::affichecase(rendu, posFond, image_SRF);
		}
	}
	// test de fin de jeu
	if (ligne[case_y +1][case_x] != 'a') {
		//return?
		}
	
}

void Joueur::affichecase(SDL_Renderer *rendu, SDL_Rect posFond, char* image) {
	posFond.x = case_x * TAILLE_SPR_X;
	posFond.y = case_y * TAILLE_SPR_Y;
	SDL_Texture *textureFond = loadImage(rendu, image);
	SDL_QueryTexture(textureFond, NULL, NULL, &posFond.w, &posFond.h);
	SDL_RenderCopy(rendu, textureFond, NULL, &posFond); //on copie la texture dans le rendu
	SDL_RenderPresent(rendu);
	SDL_DestroyTexture(textureFond);
}