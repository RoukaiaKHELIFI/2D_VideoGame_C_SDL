#include "code.h"


void enigme2(imgenigme *imgenigme,SDL_Surface *ecran,int *resultat)
{
  SDL_Event event;
TTF_Font *font1=NULL;

int rep;

int continuer=1;
int a;

srand(time(0));
a = (rand() % 4 );

SDL_Rect posenigme;
posenigme.x=450;
posenigme.y=0;

int valider=0;






while(continuer)
{
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDL_BlitSurface(imgenigme[a].screen,NULL,ecran,&posenigme);
    SDL_PollEvent(&event);
    switch (event.type)
    {
      case SDL_QUIT:
    	continuer=0;
    	SDL_Delay(200);
    	break;

      case SDL_KEYDOWN:

      switch (event.key.keysym.sym)
      {
        case SDLK_ESCAPE:
        continuer=0;
        SDL_Delay(150);
        break;

      }
      break;
      case SDL_MOUSEBUTTONDOWN:
      if(event.button.button == SDL_BUTTON_LEFT)
        {
          if(event.button.x> 574 && event.button.x< 624 && event.button.y> 138 && event.button.y< 151 )
          {
              rep=1;valider=1;
          }
          if(event.button.x> 574 && event.button.x< 624 && event.button.y> 175 && event.button.y< 188 )
          {
              rep=2;valider=1;
          }




        }
      break;

    }
    if(valider==1)
    {
    if (rep==imgenigme[a].trueRep)
      {
        quiztrue(ecran);(*resultat)=1;continuer=0;
      }
    else
    {quizfalse(ecran);continuer=0;(*resultat)=0;}
    }




SDL_Flip(ecran);

}//while continuer


}
