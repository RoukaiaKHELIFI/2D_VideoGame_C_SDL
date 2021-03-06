
#include "code.h"
/**
 * @file score_collision.c
*/

/**
 * @brief to detect collision
 * @return 1 if there's collision and 0 and there isn't
*/

int col(SDL_Rect pos1,SDL_Rect pos2)
{
if((pos1.x+pos1.w<pos2.x) || (pos1.x>pos2.x+pos2.w) || (pos1.y+pos1.h<pos2.y) || (pos1.y>pos2.y+pos2.h))
//s'il ya une collision collision=1 si non collision =0
return 0;
else
return 1;
}

/**
 * @brief to display the score
 * @return nothing
*/

void insialisation_enigme (SDL_Rect pos,SDL_Surface *ecran ,int *sc,int *vi,int *coll)
{

char ch[10];

SDL_Rect pos1;
pos1.x=50;
pos1.y=550;


affichage_s(ecran,*sc);
affichage_v(ecran,*vi);


if(col(pos,pos1)==1 && (*coll)!=1)
{
  
if(*vi>0)
*vi -=1; 
*coll=1;

}

if(col(pos,pos1)==0 && (*coll) !=0)
{
  (*coll)=0;
}
  
if((*vi)==0)
{
	(*sc) = 0;
	affichage_go(ecran);
	//game = 0;
	//SDL_Delay(2000);
}





}
void affichage_s(SDL_Surface *ecran,int sc)
{
char ch[10];


SDL_Surface *e = NULL;
SDL_Rect pos;
TTF_Font *font = NULL;
SDL_Color couleur = {255,0,0};
TTF_Init();

font = TTF_OpenFont("aa.ttf",20);
pos.x = 0;
pos.y = 0;
//convertir le score int -> char
//puis afficher

sprintf(ch,"%d",sc);
e = TTF_RenderText_Blended(font,ch,couleur);
SDL_BlitSurface(e,NULL,ecran,&pos);
TTF_CloseFont(font);
TTF_Quit();
SDL_FreeSurface(e);
}

/**
 * @brief to display vie
 *return nothing
*/

void affichage_v(SDL_Surface *ecran,int vi)
{
  char ch[10];


  SDL_Surface *e = NULL;
  SDL_Rect pos;
  TTF_Font *font = NULL;
  SDL_Color couleur = {255,0,0};
  TTF_Init();

  font = TTF_OpenFont("aa.ttf",20);
  pos.x = 100;
  pos.y = 0;
  //convertir le score int -> char
  //puis afficher

  sprintf(ch,"%d",vi);
  e = TTF_RenderText_Blended(font,ch,couleur);
  SDL_BlitSurface(e,NULL,ecran,&pos);
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_FreeSurface(e);
}
/**
 * @brief to display game over
 * @return nothing
*/

void affichage_go(SDL_Surface *ecran)
{

SDL_Surface *e = NULL;
SDL_Rect pos;
TTF_Font *font = NULL;
SDL_Color couleur = {255,0,0};
TTF_Init();

font = TTF_OpenFont("aa.ttf",20);
pos.x = 150;
pos.y = 0;
//convertir le score int -> char
//puis afficher


e = TTF_RenderText_Blended(font,"GAME OVER !",couleur);
SDL_BlitSurface(e,NULL,ecran,&pos);
TTF_CloseFont(font);
TTF_Quit();
SDL_FreeSurface(e);
}




