#include "code.h"





// gerer 3 entiers pour l'enigme.
void saisie(double *a, double *b, double *c)
{
  srand(time(0));
	(*a) = -10 + (rand() % 20 );

	(*b) = -10 + (rand() % 20 );

	(*c) = -10 + (rand() % 20 );
}
//resoudre une sollution et retourner une chiffre entre 0 et 3
int resoudre(double a, double b, double c, double *x1, double *x2)
{
	double delta;
	if (a == 0.0)
	{
		if (b == 0.0)
		{
			if (c == 0.0)
			{
				return 3;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			*x1 = -c/b;
			return 1;
		}
	}
	else
	{
		delta = b*b - 4*a*c;
		if (delta < 0)
		{
			return 0;
		}
		else if (delta == 0)
		{
			*x1 = -b / 2*a;
			return 1;
		}
		else
		{
			*x1 = (-b + sqrt(delta)) / 2*a;
			*x2 = (-b - sqrt(delta)) / 2*a;
			return 2;
		}
	}
}

// si la reponse de joueur vrai affichage d'un message bravo
void quiztrue(SDL_Surface *ecran)
{

  TTF_Font *font1=NULL,*font2=NULL;

TTF_Init();
SDL_Surface *bravo,*bravo2;
SDL_Rect bravopos,bravo2pos;
SDL_Color colorbravo={251,181,77};
bravopos.x=500;bravopos.y=-100;
bravo2pos.x=450;bravo2pos.y=900;
font1=TTF_OpenFont("IMAGE/font.ttf",75);
font2=TTF_OpenFont("IMAGE/font.ttf",50);
bravo=TTF_RenderText_Blended(font1,"Bravo",colorbravo);
bravo2=TTF_RenderText_Blended(font2,"Tu as touve la bonne solution",colorbravo);
int i=0,ip=1;
for (ip=0;ip<3000;ip++)
{i++;
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));

  if((i%2==0) && (bravopos.y<300))
bravopos.y++;
if(i%4==0 && bravo2pos.y>380)
bravo2pos.y--;
SDL_BlitSurface(bravo,NULL,ecran,&bravopos);
SDL_BlitSurface(bravo2,NULL,ecran,&bravo2pos);
SDL_Flip(ecran);
}

SDL_FreeSurface(bravo);SDL_FreeSurface(bravo2);TTF_Quit();
}
// si la reponse de joueur vrai affichage d'un message Malheureusement
void quizfalse(SDL_Surface *ecran)
{
  TTF_Font *font1=NULL,*font2=NULL;

TTF_Init();
SDL_Surface *bravo,*bravo2;
SDL_Rect bravopos,bravo2pos;
SDL_Color colorbravo={226,0,0};
bravopos.x=450;bravopos.y=-100;
bravo2pos.x=400;bravo2pos.y=900;
font1=TTF_OpenFont("IMAGE/font.ttf",75);
font2=TTF_OpenFont("IMAGE/font.ttf",50);
bravo=TTF_RenderText_Blended(font1,"Malheureusement",colorbravo);
bravo2=TTF_RenderText_Blended(font2,"Votre sollution est fausse",colorbravo);
int i=0,ip=1;
for (ip=0;ip<3000;ip++)
{i++;
  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));

  if((i%2==0) && (bravopos.y<300))
bravopos.y++;
if(i%4==0 && bravo2pos.y>380)
bravo2pos.y--;
SDL_BlitSurface(bravo,NULL,ecran,&bravopos);
SDL_BlitSurface(bravo2,NULL,ecran,&bravo2pos);
SDL_Flip(ecran);
}

SDL_FreeSurface(bravo);SDL_FreeSurface(bravo2);TTF_Quit();

}





//gerer l'enigme
void enigme(imgconfig *image,SDL_Surface *ecran ,int *resultat)
{

//initialiser les variable
  TTF_Font *font1=NULL,*font2=NULL,*fontsolution=NULL,*fontquestion=NULL,*fontabc=NULL;
  SDL_Color colorCoor={1,254,254},colorrreponse={0,0,0},colorsolution={100,155,200},colorsolutionx={100,50,200},colorquestion={255,250,150},colorabc={50,150,50};
  SDL_Color coloralpha={200,60,100},colorquestion2={145,251,49},colorchoixnormal={237,63,220},colorchoixclic={237,63,100};
  SDL_Color colorchoixclicc={194,193,180};
  SDL_Surface *coordinates,*reponse,*reponse2,*reponse3,*solu,*solutionx1,*solutionx2,*question,*aa,*bb,*cc,*alpha,*question2,*choixrep1,*choixrep2,*choixrep3,*choixrep4;
  SDL_Rect coordinatespos,reponsepos,reponsepos2,reponsepos3,solutionpos,solutionx1pos,solutionx2pos,questionpos;
  SDL_Rect aapos,bbpos,ccpos,alphapos,question2pos,choixrep1pos,choixrep2pos,choixrep3pos,choixrep4pos;
  time_t t;

  SDL_Surface *text1,*text2,*textx1,*textx2;
  SDL_Rect textpos,textx1pos,textx2pos;
  SDL_Color colortext={255,255,255},colortextx={200,0,0};

  textx1pos.x=320;textx1pos.y=500;
  textx2pos.x=725;textx2pos.y=500;
  textpos.x=300;
  textpos.y=450;
  TTF_Init();
  coordinatespos.x=580;reponsepos.x=400;reponsepos2.x=800;reponsepos3.x=600;aapos.x=500;bbpos.x=650;ccpos.x=825;alphapos.x=400;
  coordinatespos.y=1000;reponsepos.y=500;reponsepos2.y=500;reponsepos3.y=450;aapos.y=200;bbpos.y=200;ccpos.y=200;alphapos.y=200;
  question2pos.x=200;question2pos.y=300;
  choixrep1pos.x=50;choixrep1pos.y=350;
  choixrep2pos.x=350;choixrep2pos.y=350;
  choixrep3pos.x=650;choixrep3pos.y=350;
  choixrep4pos.x=900;choixrep4pos.y=350;

  font1=TTF_OpenFont("IMAGE/font.ttf",75);
  font2=TTF_OpenFont("IMAGE/font.ttf",35);
  fontsolution=TTF_OpenFont("IMAGE/font.ttf",30);
  fontquestion=TTF_OpenFont("IMAGE/font.ttf",35);

  fontabc=TTF_OpenFont("IMAGE/font.ttf",44);

  coordinates=TTF_RenderText_Blended(font1,"QuiZ",colorCoor);

  question=TTF_RenderText_Blended(fontquestion,"Resolution d'une equation du second degre dans R",colorquestion);
  questionpos.x=300;questionpos.y=150;
  SDL_Event event;int continuer=1,lch,choix;
char chaine[10]="",chaine2[10]="",chaine3[10]="",chainea[10]="",chaineb[10]="",chainec[10]="",solution[100];


  question2=TTF_RenderText_Blended(fontquestion,"Choisir la bonne reponse :",colorquestion2);
  choixrep1=TTF_RenderText_Blended(fontsolution,"Pas de solution reelle",colorchoixnormal);
  choixrep2=TTF_RenderText_Blended(fontsolution,"Une seule solution",colorchoixnormal);
  choixrep3=TTF_RenderText_Blended(fontsolution,"Deux solutions",colorchoixnormal);
  choixrep4=TTF_RenderText_Blended(fontsolution,"L'ensemble de solutions est R",colorchoixnormal);


int val;
double a, b, c, x1,x2;

alpha=TTF_RenderText_Blended(fontabc,"A =            B =           C =",coloralpha);
text1=TTF_RenderText_Blended(fontsolution,"Ecrire la partie entiere de X':",colortext);
text2=TTF_RenderText_Blended(fontsolution,"Ecrire la partie entiere de X' et X'' :",colortext);
textx1=TTF_RenderText_Blended(fontsolution,"x' =",colortext);
textx2=TTF_RenderText_Blended(fontsolution,"x'' =",colortext);
  solutionpos.x=300;solutionpos.y=600;solutionx1pos.x=575;solutionx1pos.y=600;
  solutionx2pos.x=840;solutionx2pos.y=600;


char chainex1[10],chainex2[10];



int j=0,k,i=0,timechange=75,nc=0;
int timer=0,clic=0,r=0,x,ncc=5,xx1,valider=0,comparer,nc2=0;

  while(continuer)
  {
    if(timer<9000)
    {
      timer++;
    }

    if(timer<3000)
    //appel fonction gerer 3 chiffres aleatoire
    saisie(&a, &b, &c);
    if (timer==3000)
    {
    val = resoudre(a, b, c, &x1, &x2);//appel fonction pour retourner si ilya sollution ou non avec chiffre entre 0 et 3

    switch(val) //d'apres la valeur retourner par la fonction precedent en va trouver une sollution correct
    	{
    		case 0:

        solu=TTF_RenderText_Blended(fontsolution,"Pas de solution reelle",colorsolution);
    			break;
    		case 1:
        gcvt(xx1,6,chainex1);
        xx1 = (int) x1;
        solu=TTF_RenderText_Blended(fontsolution,"Une seule solution: x1 =",colorsolution);
        solutionx1=TTF_RenderText_Blended(fontsolution,chainex1,colorsolutionx);
          break;
    	 	case 2:
        xx1 = (int) x1;
        int xx2 = (int) x2;
        gcvt(xx1,6,chainex1);gcvt(xx2,6,chainex2);

        solu=TTF_RenderText_Blended(fontsolution,"Deux solutions:     x1 =                et            x2 = ",colorsolution);
        solutionx1=TTF_RenderText_Blended(fontsolution,chainex1,colorsolutionx);
        solutionx2=TTF_RenderText_Blended(fontsolution,chainex2,colorsolutionx);
    			break;
    		case 3:
        solu=TTF_RenderText_Blended(fontsolution,"L'ensemble de solutions est R",colorsolution);

    			break;
    	}

    }
    // convertir les trois chifres en  3 chaines pour affiché sur l'enigme
  gcvt(a,6,chainea);
  aa=TTF_RenderText_Blended(fontabc,chainea,colorabc);
  gcvt(b,6,chaineb);
  bb=TTF_RenderText_Blended(fontabc,chaineb,colorabc);
  gcvt(c,6,chainec);
  cc=TTF_RenderText_Blended(fontabc,chainec,colorabc);

//display

  SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,j,50,0));
  if(timer<=475)
  {coordinatespos.y-=2;
    }
    SDL_BlitSurface(coordinates,NULL,ecran,&coordinatespos);


  if(timer>900)
  SDL_BlitSurface(question,NULL,ecran,&questionpos);
  if(timer>1200){SDL_BlitSurface(alpha,NULL,ecran,&alphapos);
  SDL_BlitSurface(aa,NULL,ecran,&aapos);
  SDL_BlitSurface(bb,NULL,ecran,&bbpos);
  SDL_BlitSurface(cc,NULL,ecran,&ccpos);
  }


if(comparer==1)
    if (clic==2)
  {
    SDL_BlitSurface(text1,NULL,ecran,&textpos);
    SDL_BlitSurface(image[17].screen,NULL,ecran,&image[17].position);
    SDL_BlitSurface(textx1,NULL,ecran,&textx1pos);
    SDL_BlitSurface(reponse,NULL,ecran,&image[17].position);}
if(comparer==2)
    if (clic==3)
  {
    SDL_BlitSurface(text2,NULL,ecran,&textpos);
    SDL_BlitSurface(image[17].screen,NULL,ecran,&image[17].position);
    SDL_BlitSurface(image[17].screen,NULL,ecran,&reponsepos2);;
  //if(timer>=900)
    SDL_BlitSurface(textx1,NULL,ecran,&textx1pos);
    SDL_BlitSurface(textx2,NULL,ecran,&textx2pos);
    SDL_BlitSurface(reponse,NULL,ecran,&image[17].position);
    SDL_BlitSurface(reponse2,NULL,ecran,&reponsepos2);
  }



  //SDL_BlitSurface(reponse3,NULL,ecran,&reponsepos3);
  if(timer>3000)
  {SDL_BlitSurface(question2,NULL,ecran,&question2pos);
    SDL_BlitSurface(choixrep1,NULL,ecran,&choixrep1pos);
    SDL_BlitSurface(choixrep2,NULL,ecran,&choixrep2pos);
    SDL_BlitSurface(choixrep3,NULL,ecran,&choixrep3pos);
    SDL_BlitSurface(choixrep4,NULL,ecran,&choixrep4pos);
  }
  if(r==1 && timer >3050)
  {
    switch (val) {
    case 0:
    SDL_BlitSurface(solu,NULL,ecran,&solutionpos);
    break;
    case 1:
    SDL_BlitSurface(solu,NULL,ecran,&solutionpos);
    SDL_BlitSurface(solutionx1,NULL,ecran,&solutionx1pos);
    break;
    case 2:
    SDL_BlitSurface(solu,NULL,ecran,&solutionpos);
    SDL_BlitSurface(solutionx1,NULL,ecran,&solutionx1pos);
    SDL_BlitSurface(solutionx2,NULL,ecran,&solutionx2pos);
    break;
    case 3:
    SDL_BlitSurface(solu,NULL,ecran,&solutionpos);
    break;
                }
  }



    SDL_PollEvent(&event);
    switch (event.type)
    {
      case SDL_KEYDOWN:

      switch (event.key.keysym.sym)
      {

        case SDLK_ESCAPE:
          SDL_Delay(200);
          continuer=0;
        break;

        case SDLK_r:
        r=1;
        break;
        case  SDLK_KP0  :
        if(nc<ncc && choix==1)
        {
        SDL_Delay(200);
        strcat(chaine,"0");
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        nc++;
        }
        else if (nc<ncc && choix==2)
        {
          SDL_Delay(200);
          strcat(chaine2,"0");
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        nc++;
        }

        break;
        case  SDLK_KP1  :
        if(nc<ncc && choix==1)
        {
        SDL_Delay(200);
        strcat(chaine,"1");
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        nc++;
        }
        else if (nc<ncc && choix==2)
        {
          SDL_Delay(200);
          strcat(chaine2,"1");
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        nc++;
        }

        break;
        case  SDLK_KP2  :
        if(nc<ncc && choix==1)
        {
        SDL_Delay(200);
        strcat(chaine,"2");
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        nc++;
        }
        else if (nc<ncc && choix==2)
        {
        SDL_Delay(200);
        strcat(chaine2,"2");
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        nc++;
        }

        break;
        case  SDLK_KP3  :
        if(nc<ncc && choix==1)
        {
        SDL_Delay(200);
        strcat(chaine,"3");
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        nc++;
        }
        else if (nc<ncc && choix==2)
        {
          SDL_Delay(200);
          strcat(chaine2,"3");
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        nc++;
        }

        break;
        case  SDLK_KP4  :
        if(nc<ncc && choix==1)
        {
        SDL_Delay(200);
        strcat(chaine,"4");
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        nc++;
        }
        else if (nc<ncc && choix==2)
        {
          SDL_Delay(200);
          strcat(chaine2,"4");
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        nc++;
        }


        break;
        case  SDLK_KP5  :
        if(nc<ncc && choix==1)
        {
        SDL_Delay(200);
        strcat(chaine,"5");
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        nc++;
        }
        else if (nc<ncc && choix==2)
        {
          SDL_Delay(200);
          strcat(chaine2,"5");
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        nc++;
        }

        break;
        case  SDLK_KP6  :
        if(nc<ncc && choix==1)
        {
        SDL_Delay(200);
        strcat(chaine,"6");
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        nc++;
        }
        else if (nc<ncc && choix==2)
        {
          SDL_Delay(200);
          strcat(chaine2,"6");
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        nc++;
        }

        break;
        case  SDLK_KP7  :
        if(nc<ncc && choix==1)
        {
        SDL_Delay(200);
        strcat(chaine,"7");
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        nc++;
        }
        else if (nc<ncc && choix==2)
        {
          SDL_Delay(200);
          strcat(chaine2,"7");
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        nc++;
        }

        break;
        case  SDLK_KP8  :
        if(nc<ncc && choix==1)
        {
        SDL_Delay(200);
        strcat(chaine,"8");
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        nc++;
        }
        else if (nc<ncc && choix==2)
        {
          SDL_Delay(200);
          strcat(chaine2,"8");
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        nc++;
        }

        break;

        case  SDLK_KP9  :
        if(nc<ncc && choix==1)
        {
        SDL_Delay(200);
        strcat(chaine,"9");
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        nc++;
        }
        else if (nc<ncc && choix==2)
        {
          SDL_Delay(200);
          strcat(chaine2,"9");
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        nc++;
        }
        break;

        case SDLK_KP_MINUS:
        if(nc==0 && choix==1)
        {
        SDL_Delay(200);
        strcat(chaine,"-");
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        nc++;
        }
        else if (nc==0 && choix==2)
        {
          SDL_Delay(200);
          strcat(chaine2,"-");
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        nc++;
        }



        break;
        case  SDLK_BACKSPACE:
        SDL_Delay(200);
        if (choix==1)
        {

          x = atoi(chaine);
          x=x/10;
          gcvt(x,10,chaine);
          if (strcmp(chaine,"0")==0)
          {
            strcpy(chaine,"");
          }
        reponse=TTF_RenderText_Blended(font2,chaine,colorrreponse);
        if(nc>0)
        nc--;
        }
        else if (choix==2)
        {
          x = atoi(chaine2);
          x=x/10;
          gcvt(x,10,chaine2);
          if (strcmp(chaine2,"0")==0)
          {
            strcpy(chaine2,"");
          }
        reponse2=TTF_RenderText_Blended(font2,chaine2,colorrreponse);
        if(nc>0)
        nc--;
        }

        break;
        case SDLK_KP_ENTER:
        if(comparer==1)
          {
            if(strcmp(chaine,chainex1)==0)
            {quiztrue(ecran);(*resultat)=1;}
            else if(!strcmp(chaine,chainex1))
            {quizfalse(ecran);(*resultat)=0;}
            continuer=0;
          }

          else if(comparer==2)
          {
            if((strcmp(chaine,chainex1)==0 && strcmp(chaine2,chainex2)==0 ) || (strcmp(chaine2,chainex1)==0 && strcmp(chaine,chainex2)==0) )
            {quiztrue(ecran);(*resultat)=1;}
            else
            {quizfalse(ecran);(*resultat)=0;}
            continuer=0;
          }
        break;
      }
      case SDL_MOUSEMOTION:

      if(timer > 3000 && clic!=1 && event.motion.x> 50 && event.motion.x< 270 && event.motion.y> 350 && event.motion.y< 375)
      choixrep1=TTF_RenderText_Blended(fontsolution,"Pas de solution reelle",colorchoixclic);
      else if(timer > 3000 && clic!=2 && event.motion.x> 350 && event.motion.x< 530 && event.motion.y> 350 && event.motion.y< 375)
      choixrep2=TTF_RenderText_Blended(fontsolution,"Une seule solution",colorchoixclic);
      else if(timer > 3000 && clic!=3 && event.motion.x> 650 && event.motion.x< 820 && event.motion.y> 350 && event.motion.y< 375)
      choixrep3=TTF_RenderText_Blended(fontsolution,"Deux solutions",colorchoixclic);
      else if(timer > 3000 && clic!=4 && event.motion.x> 900 && event.motion.x< 1200 && event.motion.y> 350 && event.motion.y< 375)
      choixrep4=TTF_RenderText_Blended(fontsolution,"L'ensemble de solutions est R",colorchoixclic);
      else
      {
        if(clic !=1)
        choixrep1=TTF_RenderText_Blended(fontsolution,"Pas de solution reelle",colorchoixnormal);
      if(clic !=2)
      choixrep2=TTF_RenderText_Blended(fontsolution,"Une seule solution",colorchoixnormal);
      if(clic!=3)
      choixrep3=TTF_RenderText_Blended(fontsolution,"Deux solutions",colorchoixnormal);
      if(clic!=4)
      choixrep4=TTF_RenderText_Blended(fontsolution,"L'ensemble de solutions est R",colorchoixnormal);
    }
      break;


	    case SDL_MOUSEBUTTONDOWN:
      if(timer > 3000 && event.button.x> 50 && event.button.x< 270 && event.button.y> 350 && event.button.y< 375)
      {choixrep1=TTF_RenderText_Blended(fontsolution,"Pas de solution reelle",colorchoixclicc);
      clic=1;valider=1;}
      else if(timer > 3000 && event.button.x> 350 && event.button.x< 530 && event.button.y> 350 && event.button.y< 375)
      {choixrep2=TTF_RenderText_Blended(fontsolution,"Une seule solution",colorchoixclicc);
      clic=2;valider=1;}
      else if(timer > 3000 && event.button.x> 650 && event.button.x< 820 && event.button.y> 350 && event.button.y< 375)
      {choixrep3=TTF_RenderText_Blended(fontsolution,"Deux solutions",colorchoixclicc);
      clic=3;valider=1;}
      else if(timer > 3000 && event.button.x> 900 && event.button.x< 1200 && event.button.y> 350 && event.button.y< 375)
      {choixrep4=TTF_RenderText_Blended(fontsolution,"L'ensemble de solutions est R",colorchoixclicc);
      clic=4;valider=1;}
      if( (comparer==1 || comparer==2) && event.button.x>400 && event.button.x<550 && event.button.y>500 && event.button.y<525 )
      {choix=1;
        nc=strlen(chaine);
      }
      if(comparer==2 && event.button.x>800 && event.button.x<950 && event.button.y>500 && event.button.y<525)
      {choix=2;
        nc=strlen(chaine2);
      }



      break;
    }
//tester la reponse de joueur avec la reponse correct
if(valider==1)
    {

      if((clic-1)==val)
      {
        switch (clic) {
          case 1:
          quiztrue(ecran);
          (*resultat)=1;
          continuer=0;

          break;
          case 2:
          comparer=1;

          break;
          case 3:
          comparer=2;
          break;
          case 4:
          quiztrue(ecran);
          (*resultat)=1;
          continuer=0;
          break;
        }
      }
      else
      {
        quizfalse(ecran);
        (*resultat)=0;
        continuer=0;
      }



    }


i++;
if (i==10)
{
  if (j==150)
    timechange=1;

  if(j==0)
  timechange=0;

if(timechange==0)
j++;
if(timechange==1)
j--;
i=0;
}





SDL_Flip(ecran);

}//while continuer.

//liberer tous les variable ...
SDL_FreeSurface(coordinates);SDL_FreeSurface(reponse);if (comparer==2)SDL_FreeSurface(reponse2);SDL_FreeSurface(reponse3);/*SDL_FreeSurface(solu);SDL_FreeSurface(solutionx1);
SDL_FreeSurface(solutionx2);*/SDL_FreeSurface(question);SDL_FreeSurface(aa);SDL_FreeSurface(bb);SDL_FreeSurface(cc);SDL_FreeSurface(alpha);
SDL_FreeSurface(question2);SDL_FreeSurface(choixrep1);SDL_FreeSurface(choixrep2);SDL_FreeSurface(choixrep3);SDL_FreeSurface(choixrep4);
TTF_Quit();

//la fonction enigme retourner 1 si la reponse de joueur correct si non retourner 0

}
