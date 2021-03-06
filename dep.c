


void deplacerperso (personnage *p,int *continuer, SDL_Event *event)

{
    SDL_PollEvent(*event);
    switch(event->type)
    {
        case SDL_QUIT:
            (*continuer)=0;
            break;
        case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
        {
            case SDLK_UP:
               if (p->position.y!=450)
                 { p->position.y-=p->vitesse;}
                break;
       
            case SDLK_RIGHT:
                p->position.x+=p->vitesse+p->acceleration*0.3;
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
            case SDL_KEYUP :
           if(event->key.keysym.sym==SDLK_UP)
              {
                jump(p);
              }
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
}
/*
void jump (personnage *p)
{ 
  
while( p->position.y!= p->sol) 
 p->position.y+=p->vitesse;
;}
*/
void animation_perso(SDL_Event *event,personnage *p, SDL_Rect camera_pos, SDL_Surface *ecran,int *k)
{

switch(event->type)
{
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
               
        }
        
            case SDL_KEYUP :
           if((event->key.keysym.sym==SDLK_RIGHT)&&(*k>0)&&(*k<9)&&( p->acceleration !=0))
            {
(*k)++;
}
else 
{
(*k)=0;
}
  
       if((event->key.keysym.sym==SDLK_LEFT)&&(*k>10)&&(*k<19)&&( p->acceleration !=0))
             {
(*k)++;
}
else 
{
(*k)=10;
}
            break;

    }
}

SDL_BlitSurface(p->anim[k],NULL,ecran,&p->position);
}


