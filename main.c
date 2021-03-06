#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
int col(SDL_Rect pos1,SDL_Rect pos2)
{
if((pos1.x+pos1.w<pos2.x) || (pos1.x>pos2.x+pos2.w) || (pos1.y+pos1.h<pos2.y) || (pos1.y>pos2.y+pos2.h))
//s'il ya une collision collision=1 si non collision =0
return 0;
else
return 1;
}
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

int main(int argc, char argv[])
{
int game = 1;


SDL_Event event;
SDL_Surface *screen = NULL,*perso1 = NULL,*perso2 = NULL,*perso3 = NULL,*background= NULL,*perso4 = NULL;

SDL_Rect positionperso1,positionperso2,posbackground;

SDL_Init(SDL_INIT_VIDEO);
background = IMG_Load("background.png");
perso1= IMG_Load("ennemi1.png");
perso2= IMG_Load("en1.png");

perso3= IMG_Load("en4.png");
perso4 = IMG_Load("ennemi5.png");

screen = SDL_SetVideoMode(700,460,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
posbackground.x = 0;
posbackground.y = 0;
positionperso1.x = 0;
positionperso1.y = 185;


positionperso2.x=420;
positionperso2.y=185;



if (screen == NULL)
{
printf("Erreur Loading imahe background\n");
return EXIT_FAILURE;
}

SDL_EnableKeyRepeat(20,20);

while(game)
{
	
  SDL_FillRect(screen,0,SDL_MapRGB(screen->format,255,255,255));
  SDL_BlitSurface(background,NULL,screen,&posbackground);
  SDL_BlitSurface(perso1,NULL,screen,&positionperso1);
  SDL_BlitSurface(perso2,NULL,screen,&positionperso2);

while(SDL_PollEvent(&event)){
switch(event.type)
{

case SDL_QUIT:
game = 0;
break;
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{

case SDLK_RIGHT:
positionperso1.x+=5;
break;
case SDLK_LEFT:
positionperso1.x-=5;
break;

}

break;
}
}

int x1 = positionperso1.x;


if(x1==300)
{
    perso2 = perso3;
    
     SDL_BlitSurface(perso2,NULL,screen,&positionperso2);
     SDL_Delay(100);
}

else if(x1==500)
{

    perso2 = perso1;

    SDL_BlitSurface(perso2,NULL,screen,&positionperso2);
     SDL_Delay(100);
}

/*
if(positionperso1.x = 400)
{	
	perso2 = perso4;
	SDL_BlitSurface(perso2,NULL,screen,&positionperso2);
     SDL_Delay(100);

}
*/
if(col(positionperso1,positionperso2)==1)
{
    affichage_go(screen);
}

//if(((positionperso1.x+positionperso1.w<posisitionperso2.x) || (positionperso1.x>positionperso2.x+positionperso2.w) || (positionperso1.y+positionperso1.h<positionperso2.y) || (positionperso1.y>positionperso2.y+positioperso2.h)))

SDL_Flip(screen);

}

SDL_FreeSurface(background);
SDL_FreeSurface(perso1);
SDL_FreeSurface(perso2);

SDL_Quit();

return EXIT_SUCCESS;

}
