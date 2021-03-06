#include "code.h"

void temp (SDL_Surface *ecran,int *a,int *b,int *c)
{
char ch[10];
TTF_Font *font = NULL;
SDL_Color couleur = {255,0,0};
TTF_Init();
SDL_Surface *e = NULL;
SDL_Rect posnew;
posnew.x=20;
posnew.y=20;
font = TTF_OpenFont("aa.ttf",20);
    int startTicks;



void start();
   startTicks = SDL_GetTicks();
*b=startTicks/1000;
sprintf(ch,"%d",*b);
  e = TTF_RenderText_Blended(font,ch,couleur);
  SDL_BlitSurface(e,NULL,ecran,&posnew);

  TTF_CloseFont(font);
  TTF_Quit();
  SDL_FreeSurface(e);
}
void initialiser_personnage(personnage *p)
{
char load[20];
int i;

p->position.x=10;
p->position.y=550;
p->acceleration=0;
p->vitesse=2;
p->vie=3;
p->score=0;
p->air=0;
p->ground=0;
for(i=0;i<64;i++)
{
sprintf(load,"perso/%d.png",i);
(*p).anim[i]=IMG_Load(load);
}
}
void loadannimation(imgconfig *image2)
{


image2[0].screen=IMG_Load("IMAGE/ANNIMATION/1.jpg");
image2[1].screen=IMG_Load("IMAGE/ANNIMATION/2.jpg");
image2[2].screen=IMG_Load("IMAGE/ANNIMATION/3.jpg");
image2[3].screen=IMG_Load("IMAGE/ANNIMATION/4.jpg");
image2[4].screen=IMG_Load("IMAGE/ANNIMATION/5.jpg");
image2[5].screen=IMG_Load("IMAGE/ANNIMATION/6.jpg");
image2[6].screen=IMG_Load("IMAGE/ANNIMATION/7.jpg");
image2[7].screen=IMG_Load("IMAGE/ANNIMATION/8.jpg");
image2[8].screen=IMG_Load("IMAGE/ANNIMATION/9.jpg");
image2[9].screen=IMG_Load("IMAGE/ANNIMATION/10.jpg");
image2[10].screen=IMG_Load("IMAGE/ANNIMATION/11.jpg");
image2[11].screen=IMG_Load("IMAGE/ANNIMATION/12.jpg");
image2[12].screen=IMG_Load("IMAGE/ANNIMATION/13.jpg");
image2[13].screen=IMG_Load("IMAGE/ANNIMATION/14.jpg");
image2[14].screen=IMG_Load("IMAGE/ANNIMATION/15.jpg");
image2[15].screen=IMG_Load("IMAGE/ANNIMATION/16.jpg");
image2[16].screen=IMG_Load("IMAGE/ANNIMATION/17.jpg");
image2[17].screen=IMG_Load("IMAGE/ANNIMATION/18.jpg");
image2[18].screen=IMG_Load("IMAGE/ANNIMATION/19.jpg");
image2[19].screen=IMG_Load("IMAGE/ANNIMATION/20.jpg");
image2[20].screen=IMG_Load("IMAGE/ANNIMATION/21.jpg");
image2[21].screen=IMG_Load("IMAGE/ANNIMATION/22.jpg");
image2[22].screen=IMG_Load("IMAGE/ANNIMATION/23.jpg");
image2[23].screen=IMG_Load("IMAGE/ANNIMATION/24.jpg");

}
void loadimage(imgconfig *image)
{
image[0].screen=IMG_Load("IMAGE/cursor.png");
image[1].screen=IMG_Load("IMAGE/background.png");
			image[1].position.x=0;
			image[1].position.y=0;
image[2].screen=IMG_Load("IMAGE/new_game.png");
			image[2].position.x=300;
			image[2].position.y=525;
image[3].screen=IMG_Load("IMAGE/new_game2.png");
image[4].screen=IMG_Load("IMAGE/new_game3.png");
image[5].screen=IMG_Load("IMAGE/SETTING1.png");
			image[5].position.x=560;
			image[5].position.y=525;
image[6].screen=IMG_Load("IMAGE/SETTING2.png");
image[7].screen=IMG_Load("IMAGE/SETTING3.png");
image[8].screen=IMG_Load("IMAGE/QUIT1.png");
			image[8].position.x=820;
			image[8].position.y=525;
image[9].screen=IMG_Load("IMAGE/QUIT2.png");
image[10].screen=IMG_Load("IMAGE/QUIT3.png");
image[11].screen=IMG_Load("IMAGE/JOUER.png");
image[12].screen=IMG_Load("IMAGE/BACK.png");
			image[12].position.x=166;
			image[12].position.y=81;
image[13].screen=IMG_Load("IMAGE/NORMAL.png");
			image[13].position.x=621;
			image[13].position.y=532;
image[14].screen=IMG_Load("IMAGE/FULLSCREEN.png");
			image[14].position.x=756;
			image[14].position.y=532;
image[15].screen=IMG_Load("IMAGE/backgroundsetting.png");
			image[15].position.x=0;
			image[15].position.y=0;
image[16].screen=IMG_Load("IMAGE/VOL.png");
			image[16].position.x=1015;
			image[16].position.y=456;
image[17].screen=IMG_Load("IMAGE/zonetxt.png");
			image[17].position.x=400;
			image[17].position.y=500;
image[11].position.x=0;
}



void start(imgconfig *image,int *son ,SDL_Surface *icon)
{
loadimage(image);
SDL_Init(SDL_INIT_VIDEO);
icon=IMG_Load("IMAGE/icon.png");
putenv("SDL_VIDEO_CENTERED=1");
SDL_WM_SetCaption("Corona-Virus", NULL);//nom de fenetre de programme.
SDL_WM_SetIcon(icon, NULL);//icone de programme.
}



void FREEimage(imgconfig *image)
{ int i;
for(i=0;i<20;i++)
SDL_FreeSurface(image[i].screen);
}





void down(int *prec,imgconfig *image,int *entre)
{if((*prec)==0){(*entre)=1;(*prec)=3;}else{(*prec)++;(*entre)++;}if((*entre)==4){(*entre)=1;(*prec)=0;}}





void up(int *prec,imgconfig *image,int *entre)
{if((*prec)==0){(*entre)=3;(*prec)=1;}else{(*prec)++;(*entre)--;}if((*entre)==0){(*entre)=3;(*prec)=1;}}




void jouer(SDL_Surface *ecran,imgconfig *image,Mix_Music *music2,int *captson,Mix_Chunk *clickson,personnage *p)
{

int sc=500,coll;
int continuer=1,resultat=1;
int a;
int temp1=0,temp2=0,temp3=0;
SDL_Event event;
SDL_Rect camera_pos ;
	 camera_pos.x = 0;
        camera_pos.y = 0;


Mix_PlayMusic(music2,-1);
(*captson)=1;
int i=39,k=0;

SDL_BlitSurface(image[11].screen,&camera_pos,ecran,NULL);

SDL_Flip(ecran);

loadfile (p,&camera_pos);


while(continuer)
{
scrolling_me (&event,&camera_pos,p);
SDL_BlitSurface(image[11].screen,&camera_pos,ecran,NULL);
deplacerperso (p,&continuer,&event,&k);
animation_perso(&event,p,camera_pos,ecran,&k);
SDL_BlitSurface(p->anim[k],NULL,ecran,&p->position);
temp (ecran,&temp1,&temp2,&temp3);
insialisation_enigme (p->position,ecran,&sc,&p->vie,&coll);
SDL_Flip(ecran);

SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_KEYDOWN:

		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
		SDL_Delay(200);
		savefile (p,camera_pos);
		continuer=0;
		break;
		}
	}


	if (p->vie==0)
	{
    enigme(image,ecran,&resultat);
if (resultat==0)
{
continuer=0;
p->vie=3;
}
else
{
p->vie=3;
}
	}
}
}







void setting (SDL_Surface *ecran,imgconfig *image,int *boutonfull,int *captfull,Mix_Chunk *clickson,Mix_Music *music )
{
   FILE* fichier = NULL;
	int continuer=1,x,boutonback=0;
	SDL_Event event;



while(continuer)
{





	SDL_PollEvent(&event);
	switch (event.type)
	{

	case SDL_QUIT:
	continuer=0;
	SDL_Delay(200);
	break;

	case SDL_KEYDOWN:
		{
			Mix_PlayChannel(-1,clickson,0);
		switch (event.key.keysym.sym)
		{
			case SDLK_ESCAPE:
			{
			continuer=0;
			boutonback=1;
			SDL_Delay(200);
			}
			break;
		}

		}
		break;
	case SDL_MOUSEMOTION:
		image[0].position.x = event.motion.x;
		image[0].position.y = event.motion.y;

		if	(event.motion.x> 166 && event.motion.x< 310 && event.motion.y> 81 && event.motion.y< 226 )
			{

			boutonback=1;
			}
			else
			{
				boutonback=0;
			}

	break;

	case SDL_MOUSEBUTTONDOWN:
		Mix_PlayChannel(-1,clickson,0);
		if(event.button.button == SDL_BUTTON_LEFT)
		{

			if(event.button.x> 757 && event.button.x< 830 && event.button.y> 532 && event.button.y< 605 && (*boutonfull)==0 )
			{
				  fichier = fopen("FICHE/mode.txt", "w");(*boutonfull)=1;(*captfull)=1;
				  fclose(fichier);
			}
			else if(event.button.x> 621 && event.button.x< 695 && event.button.y> 532 && event.button.y< 605 && (*boutonfull)==1 )
				  {remove("FICHE/mode.txt");(*boutonfull)=0;(*captfull)=1;}

			else if(event.button.x> 166 && event.button.x< 310 && event.button.y> 81 && event.button.y< 226 )
			{continuer=0;boutonback=1;SDL_Delay(100);}
			else if(event.button.x> 716 && event.button.x< 723 && event.button.y> 462 && event.button.y< 476 )
			{
			image[16].position.x=image[0].position.x-10;
			Mix_VolumeMusic(Mix_VolumeMusic(-1)-32);
			Mix_VolumeMusic(Mix_VolumeMusic(-1)-32);
			Mix_VolumeMusic(Mix_VolumeMusic(-1)-32);
			Mix_VolumeMusic(Mix_VolumeMusic(-1)-32);
			Mix_VolumeMusic(Mix_VolumeMusic(-1)-2400);
			Mix_VolumeChunk(clickson,0);
			}
			else if(event.button.x> 725 && event.button.x< 1036 && event.button.y> 462 && event.button.y< 476 )
			{ x=100 - ((1036 - image[0].position.x)/3.2);
			Mix_VolumeChunk(clickson,x);
			image[16].position.x=image[0].position.x-10;
			Mix_VolumeMusic(Mix_VolumeMusic(-1)-100);
			Mix_VolumeMusic(Mix_VolumeMusic(-1)+x);



			}

		}


	break;

	}

SDL_BlitSurface(image[15].screen,NULL,ecran,&image[15].position);
if(boutonback==1)
SDL_BlitSurface(image[12].screen,NULL,ecran,&image[12].position);

//SDL_BlitSurface(image[12].screen,NULL,ecran,&image[12].position);
if((*boutonfull)==1)
	{SDL_BlitSurface(image[14].screen,NULL,ecran,&image[14].position);}
else if((*boutonfull)==0)
	{SDL_BlitSurface(image[13].screen,NULL,ecran,&image[13].position);}

SDL_BlitSurface(image[16].screen,NULL,ecran,&image[16].position);
SDL_Flip(ecran);





}

}




//******************************************************************
void deplacerperso (personnage *p,int *continuer, SDL_Event *event,int *k)

{
    SDL_PollEvent(event);
    switch(event->type)
    {
        case SDL_QUIT:
            (*continuer)=0;
            break;
//*****************************************deplacement souris 
 case SDL_MOUSEBUTTONDOWN :
            if(event->button.button==SDL_BUTTON_LEFT)
            {
                if(event->button.x>p->position.x)
                {
		if (p->position.x>=640)
   			{

			}
		else
		       {
	         p->position.x+=p->vitesse+p->acceleration*0.3;
		       }
		}

if(event->button.x<p->position.x)
                {
                                  p->position.x=p->position.x-5;
   
                
            	}






	    }
break;
//********************************************************
        case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
        {
            case SDLK_UP:
     
p->air=1;

                break;
       
            case SDLK_RIGHT:
if (p->position.x<640)
{
                p->position.x+=p->vitesse+p->acceleration*0.3;
}
                break;
            case SDLK_LEFT:
                p->position.x-=p->vitesse+p->acceleration*0.3;
                break;
                case SDLK_SPACE:
             p->acceleration = 9;
                p->position.x+=p->vitesse+p->acceleration*0.3;
                break;
        }
            break;
        
           if(event->key.keysym.sym==SDLK_RIGHT)
             {while ( p->acceleration !=0)
              { p->acceleration--;
              p->position.x+=p->vitesse+p->acceleration*0.3; }
              }
       if(event->key.keysym.sym==SDLK_SPACE)
             {while ( p->acceleration !=0)
              { p->acceleration--;
              p->position.x+=p->vitesse+p->acceleration*0.3; }
              } 
            break;

    }
jump(p);

}


//*****************************************
void animation_perso(SDL_Event *event,personnage *p, SDL_Rect camera_pos, SDL_Surface *ecran,int *k)
{

switch(event->type)
{
//*******************************************************************

case SDL_MOUSEBUTTONDOWN :
            if(event->button.button==SDL_BUTTON_LEFT)
            {
                if(event->button.x>p->position.x)
                {
if((*k>=0)&&(*k<9))
{
(*k)++;
}
else 
{
(*k)=0;
}
		}
		else
		{
if((*k>=10)&&(*k<19))
{
(*k)++;
}
else 
{
(*k)=10;
}
   
		}
	   }
break;


//*******************************************************************
   case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
        {

       
            case SDLK_RIGHT:
                if((*k>=0)&&(*k<9))
{
(*k)++;
}
else 
{
(*k)=0;
}
                break;
            case SDLK_LEFT:
                if((*k>=10)&&(*k<19))
{
(*k)++;
}
else 
{
(*k)=10;
}
   
       	break;         
          default : *k=39;     
        }
        
            
}

}

//****************************************************
void scrolling_me (SDL_Event *event,SDL_Rect *camera_pos,personnage *p)
{
switch(event->type)
			{


//********************
case SDL_MOUSEBUTTONDOWN :
            if(event->button.button==SDL_BUTTON_LEFT)
            {
                if(event->button.x>p->position.x)
                {
		if (p->position.x>=640)
   			{
camera_pos->x+=5;
			}
		}
	}
break;
//******************
case SDL_KEYDOWN:

		switch (event->key.keysym.sym)
		{
		
            case SDLK_RIGHT:
		if (p->position.x>=640)
{
camera_pos->x+=5;
}
	   break;
		}
break;

			}
}



//**************************************************save file 
void savefile (personnage *p,SDL_Rect camera_pos)
{
FILE* f=NULL;
f=fopen("saveall.txt","a+");


if(f!=NULL)
{
fprintf(f,"%d %d %d %d %d %d",p->position.x,p->position.y,p->vie,p->score,camera_pos.x,camera_pos.y);
fclose(f);
}
else
{
printf("ivaliiiiiiiiiid file \n ");
}

}


void loadfile (personnage *p,SDL_Rect *camera_pos)
{
int a,b,c,d,e,g;
FILE* f=NULL;
f=fopen("saveall.txt","r");
if(f!=NULL)
{
fscanf(f,"%d %d %d %d %d %d",&a,&b,&c,&d,&e,&g);
p->position.x=a;
p->position.y=b;
p->vie=c;
p->score=d;
camera_pos->x=e;
camera_pos->y=g;
}

}



//***************************************************************************jump
void jump( personnage *p)
{
        if(p->air && p->position.y > JumpLimit && !p->ground)
            p->position.y += Gravity;
        if(p->position.y <= JumpLimit )
           p->ground = 1;
        if(p->position.y < Personnage_Default_Y && p->ground )
            p->position.y -= Gravity;
        if(p->position.y == Personnage_Default_Y)
        {
            p->ground = 0;
            p->air = 0;
        }
}


