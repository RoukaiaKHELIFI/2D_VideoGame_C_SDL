#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include <string.h>
#include <math.h>
#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES //evite les inclustions infinies.
#define JumpLimit 360
#define Personnage_Default_Y 550
#define Gravity -20
typedef struct imgconfig
{
SDL_Surface *screen;
SDL_Rect position;

}imgconfig;
typedef struct imgenigme
{
  SDL_Surface *screen;
  int trueRep;//si  1 cas1 sinon si 2 cas2
}imgenigme;

// structure perso
typedef struct personnage
{   
    SDL_Rect position;
    SDL_Surface *anim[64];
	int vie;
	int score;
	int vitesse;
	int acceleration;
	int air;
	int ground;
}personnage;
typedef struct secondaire
{
    SDL_Rect position;
    SDL_Surface *anim[8];
    int vitesse;
    int acceleration;
}secondaire;

//load
void loadannimation(imgconfig *image2);
void loadimage(imgconfig *image);
void loadmusic(Mix_Music *music);
void initialiser_personnage(personnage *p);
void jump( personnage *p);
//*void anim_perso(SDL_Event *event,personnage *p, int a,SDL_Rect camera_pos,SDL_Surface *ecran) ;
void temp (SDL_Surface *ecran,int *a,int *b,int *c);
//star
void start(imgconfig *image,int *son,SDL_Surface *icon);
void deplacerperso (personnage *p,int *continuer, SDL_Event *event,int *information);
//jeu
void jouer(SDL_Surface *ecran,imgconfig *image,Mix_Music *music2,int *captson,Mix_Chunk *clickson,personnage *p);



//setting
void setting(SDL_Surface *ecran,imgconfig *image,int *boutonfull,int *captfull,Mix_Chunk *clickson,Mix_Music *music);


// up-down
void down(int *prec,imgconfig *image,int *entre);
void up(int *prec,imgconfig *image,int *entre);


//quiz
void saisie (double *a, double *b, double *c);
int atoi(const char *string);
int resoudre (double a, double b, double c, double *x1, double *x2);
void affiche (int v, double x1, double x2);
void quiztrue(SDL_Surface *ecran);
void quizfalse(SDL_Surface *ecran);
void enigme(imgconfig *image,SDL_Surface *ecran,int *resultat );
void enigme2(imgenigme *imgenigme,SDL_Surface *ecran,int *resultat);



//free
void FREEimage(imgconfig *image);
void FREEmusic(Mix_Music *music);

void savefile (personnage *p,SDL_Rect camera_pos);
void loadfile (personnage *p,SDL_Rect *camera_pos);


//********************** coll
int col(SDL_Rect pos1,SDL_Rect pos2);
void insialisation_enigme (SDL_Rect pos,SDL_Surface *ecran ,int *sc,int *vi,int *coll);
int score(int s);
void affichage_s(SDL_Surface *ecran,int sco);
//int vie(int v);
void affichage_v(SDL_Surface *ecranv,int viee);
void affichage_go(SDL_Surface *ecran);

//************************ent sec



void init_sec(secondaire *sec);

void animation_perso(SDL_Event *event,personnage *p, SDL_Rect camera_pos, SDL_Surface *ecran,int *k);

void scrolling_me (SDL_Event *event,SDL_Rect *camera_pos,personnage *p);


#define  L_F	1280
#define  H_F	720

#endif
