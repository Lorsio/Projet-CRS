
//Initialisation de la fen�tre
int FPS = 30;
char titre_fenetre[11] = "Projet CRS";
char lien_icone[21] = "images/sprites/ICONE";
const int TAILLE_X = 600;
const int TAILLE_Y = 480;

//Tailles des sprites du fond
int TAILLE_SPR_X = 30;
int TAILLE_SPR_Y = 24;
int NBR_SPR_COTE = 20;

//Emplacement de d�part du sprite du personnage
int X_Player = 30;
int Y_Player = 0;
int CASE_X = 1;
int CASE_Y = 1;

//Variable du score
int SCORE = 0;
int PAS = 0;

//Divers : R�glage de bug Python & Fonctionnalit� annexes
int entre_niveau = 0; //Variable permettant de ne pas revenir � l'accueil une fois un niveau lancer
int niveau = 0; //Variable g�rant le niveau
bool Generer = false; //Variable qui sert pour la gestion de la remise � 0 des personnages
bool tuto = false; //Variable pour le tuto
bool repet_tuto = false; //Variable pour emp�cher le blocage dans la boucle tuto
int Cec_obs = 1; //Variable pour g�rer l'enchainement des bras du sprite de C�cile en obstacle

//Images du jeu - Fen�tre
char image_accueil[24] = "images/fond/accueil.png";
char image_niveau[28] = "images/fond/fond_niveau.png";
char image_pause[22] = "images/fond/pause.png";
//Images du jeu - Tutoriels
char tuto1[22] = "images/fond/tuto1.png";
//Images du jeu - Sprites personnages
//Sprites Romain(Normaux)
char image_SRL[31]="images/sprites/SPRROM_LEFT.png";
char image_SRR[32]="images/sprites/SPRROM_RIGHT.png";
char image_SRF[32]="images/sprites/SPRROM_FRONT.png";
char image_SRB[31]="images/sprites/SPRROM_BACK.png";
//Sprites Romain(Obstacle)
//Sprites C�cile(Normaux)
//Sprites C�cile(Obstacle)
//Sprites Simon(Normaux)
//Sprites Simon(Obstacle)


//Images du jeu - Sprites fond
char image_E[25]="images/sol/SPRFOND_E.png" ; //Eau
char image_M[25]="images/sol/SPRFOND_M.png" ; //Mur
char image_P[25]="images/sol/SPRFOND_P.png" ; //Terre
char image_F[25]="images/sol/SPRFOND_F.png" ; //Braise/Lave
char image_S[25]="images/sol/SPRFOND_S.png" ; //Roche a escalad�
char image_A[25]="images/sol/SPRFOND_A.png" ; //Bloc Arriv�e
char image_Q[25]="images/sol/SPRFOND_Q.png" ; //Bloc tutoriel

/*
#Sprites Romain en obstacle
image_SREL = "images/SPRROME_LEFT.png" #Gauche
image_SRER = "images/SPRROME_RIGHT.png" #Droit
image_SREF = "images/SPRROME_FRONT.png" #En face
image_SREB = "images/SPRROME_BACK.png" #Derri�re
#Sprites C�cile normaux
image_SCL = "images/SPRCEC_LEFT.png" #Gauche
image_SCR = "images/SPRCEC_RIGHT.png" #Droit
image_SCF = "images/SPRCEC_FRONT.png" #En face
image_SCB = "images/SPRCEC_BACK.png" #Derri�re
#Sprites C�cile en obstacle
image_SCBO1 = "images/SPRCEC_BACKO1.png" #Un premier bras lev�
image_SCBO2 = "images/SPRCEC_BACKO2.png" #Puis l'autre
#Sprites Simon normaux
image_SSL = "images/SPRSIM_LEFT.png" #Gauche
image_SSR = "images/SPRSIM_RIGHT.png" #Droit
image_SSF = "images/SPRSIM_FRONT.png" #En face
image_SSB = "images/SPRSIM_BACK.png" #Derri�re
#Sprites Simon en obstacles
image_SSLO = "images/SPRSIM_LEFTO.png" #Gauche
image_SSRO = "images/SPRSIM_RIGHTO.png" #Droit
image_SSFO = "images/SPRSIM_FRONTO.png" #En face
image_SSBO = "images/SPRSIM_BACKO.png" #Derri�re
*/