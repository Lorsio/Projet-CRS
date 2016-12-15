#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H
namespace Var {
	static char niveau_select[] = "niveau/n1.txt";


	//Initialisation de la fenêtre
	static int FPS = 30;
	static char titre_fenetre[11] = "Projet CRS";
	static char image_icone[25] = "images/sprites/ICONE.bmp";
	static const int TAILLE_X = 600;
	static const int TAILLE_Y = 480;

	//Tailles des sprites du fond
	static int TAILLE_SPR_X = 30;
	static int TAILLE_SPR_Y = 24;
	static int NBR_SPR_COTE = 20;

	//Emplacement de départ du sprite du personnage
	static int X_Player = 30;
	static int Y_Player = 0;
	static int CASE_X = 1;
	static int CASE_Y = 1;

	//Variable du score
	static int SCORE = 0;
	static int PAS = 0;

	//Divers : Réglage de bug Python & Fonctionnalité annexes
	static int entre_niveau = 0; //Variable permettant de ne pas revenir à l'accueil une fois un niveau lancer
	static int niveau = 0; //Variable gérant le niveau
	static bool Generer = false; //Variable qui sert pour la gestion de la remise à 0 des personnages
	static bool tuto = false; //Variable pour le tuto
	static bool repet_tuto = false; //Variable pour empêcher le blocage dans la boucle tuto
	static int Cec_obs = 1; //Variable pour gérer l'enchainement des bras du sprite de Cécile en obstacle

	 //Images du jeu - Fenêtre
	static char image_accueil[24] = "images/fond/accueil.png";
	static char image_niveau[28] = "images/fond/fond_niveau.png";
	static char image_pause[22] = "images/fond/pause.png";
	//Images du jeu - Tutoriels
	static char tuto1[22] = "images/fond/tuto1.png";
	//Images du jeu - Sprites personnages
	//Sprites Romain(Normaux)
	static char image_SRL[31] = "images/sprites/SPRROM_LEFT.png";
	static char image_SRR[32] = "images/sprites/SPRROM_RIGHT.png";
	static char image_SRF[32] = "images/sprites/SPRROM_FRONT.png";
	static char image_SRB[31] = "images/sprites/SPRROM_BACK.png";
	//Sprites Romain(Obstacle)
	//Sprites Cécile(Normaux)
	//Sprites Cécile(Obstacle)
	//Sprites Simon(Normaux)
	//Sprites Simon(Obstacle)


	//Images du jeu - Sprites fond
	static char image_E[25] = "images/sol/SPRFOND_E.png"; //Eau
	static char image_M[25] = "images/sol/SPRFOND_M.png"; //Mur
	static char image_P[25] = "images/sol/SPRFOND_P.png"; //Terre
	static char image_F[25] = "images/sol/SPRFOND_F.png"; //Braise/Lave
	static char image_S[25] = "images/sol/SPRFOND_S.png"; //Roche a escaladé
	static char image_A[25] = "images/sol/SPRFOND_A.png"; //Bloc Arrivée
	static char image_Q[25] = "images/sol/SPRFOND_Q.png"; //Bloc tutoriel

	/*
	#Sprites Romain en obstacle
	image_SREL = "images/SPRROME_LEFT.png" #Gauche
	image_SRER = "images/SPRROME_RIGHT.png" #Droit
	image_SREF = "images/SPRROME_FRONT.png" #En face
	image_SREB = "images/SPRROME_BACK.png" #Derrière
	#Sprites Cécile normaux
	image_SCL = "images/SPRCEC_LEFT.png" #Gauche
	image_SCR = "images/SPRCEC_RIGHT.png" #Droit
	image_SCF = "images/SPRCEC_FRONT.png" #En face
	image_SCB = "images/SPRCEC_BACK.png" #Derrière
	#Sprites Cécile en obstacle
	image_SCBO1 = "images/SPRCEC_BACKO1.png" #Un premier bras levé
	image_SCBO2 = "images/SPRCEC_BACKO2.png" #Puis l'autre
	#Sprites Simon normaux
	image_SSL = "images/SPRSIM_LEFT.png" #Gauche
	image_SSR = "images/SPRSIM_RIGHT.png" #Droit
	image_SSF = "images/SPRSIM_FRONT.png" #En face
	image_SSB = "images/SPRSIM_BACK.png" #Derrière
	#Sprites Simon en obstacles
	image_SSLO = "images/SPRSIM_LEFTO.png" #Gauche
	image_SSRO = "images/SPRSIM_RIGHTO.png" #Droit
	image_SSFO = "images/SPRSIM_FRONTO.png" #En face
	image_SSBO = "images/SPRSIM_BACKO.png" #Derrière
	*/
}
#endif