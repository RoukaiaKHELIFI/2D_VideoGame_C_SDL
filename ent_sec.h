#ifndef entsec_h
#define entsec_h
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>



typedef struct secondaire
{
    SDL_Rect position;
    SDL_Surface *anim[8];
    int vitesse;
    int acceleration;
}secondaire;

void init_sec(secondaire *sec);

void animation_sec(secondaire *sec,int direction,SDL_Surface *ecran);




#endif

