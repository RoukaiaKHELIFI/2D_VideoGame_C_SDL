
#include "code.h"
void init_sec(secondaire *sec)
{

char load[20];
int i;

sec->position.x=120;
sec->position.y=480;
sec->acceleration=2;
sec->vitesse=20;
for(i=0;i<8;i++)
{
sprintf(load,"bat%d.png",i);
(*sec).anim[i]=IMG_Load(load);
}

}

void animation_sec(secondaire *sec,int direction,SDL_Surface *ecran)
{
int i;
if(direction==1)
{
for(i=0;i<4;i++)
{
SDL_BlitSurface (sec->anim[i],NULL,ecran,&sec->position);
SDL_Flip(ecran);
}

}
else if (direction==0)
{
for(i=5;i<8;i++)
{
SDL_BlitSurface (sec->anim[i],NULL,ecran,&sec->position);
SDL_Flip(ecran);
}



}





}




















