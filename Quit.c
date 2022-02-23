#include <stdlib.h>
#include <stdio.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
int quit(SDL_Surface *screen)
{
SDL_Surface  *texte = NULL , *fond = NULL ;
SDL_Rect position,posy,posn;
SDL_Event event ; 
TTF_Font *police = NULL ;
SDL_Color couleurBlanche ={255,255,255};
int continuer = 1;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
//screen = SDL_SetVideoMode(1360,760,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
SDL_WM_SetCaption("Unlifted Curse",NULL);

fond = IMG_Load("Game/Quit/Background.png");
police = TTF_OpenFont("Game/Story/font.ttf",60);
int y=1,n=0,t;
SDL_Surface *yes[1],*no[1];
yes[0]= IMG_Load("Game/Quit/yes.png");
yes[1]= IMG_Load("Game/Quit/yes-selected.png");
no[0]= IMG_Load("Game/Quit/no.png");
no[1]= IMG_Load("Game/Quit/no-selected.png");
texte = TTF_RenderText_Blended(police,"Are you sure you want  to quit the game ?",couleurBlanche);

while (continuer == 1 )
{
SDL_FillRect(screen, NULL , SDL_MapRGB(screen->format,255,255,255));
position.x =0;
position.y =0;
posy.x=400;
posy.y=400;
posn.x=700;
posn.y=400;
SDL_BlitSurface(fond,NULL,screen,&position);
SDL_BlitSurface(yes[y],NULL,screen,&posy);
SDL_BlitSurface(no[n],NULL,screen,&posn);
position.x = 100;
position.y = 200; //position texte par rapport a l image //
SDL_BlitSurface(texte,NULL,screen,&position);
SDL_Flip(screen);
SDL_WaitEvent(&event);
t=0;
 switch(event.type)
            {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
              case SDLK_RIGHT:
                if (y==1 && t==0) 
                    {
                       y=0;
                       n=1;
                       t=1;
                    }
                if (n==1 && t==0) 
                    {
                       y=1;
                       n=0;
                       t=1;
                    }
              break;
              case SDLK_LEFT:
                if (y==1 && t==0) 
                    {
                       y=0;
                       n=1;
                       t=1;
                    }
                if (n==1 && t==0) 
                    {
                       y=1;
                       n=0;
                       t=1;
                    }
              break;
               case SDLK_ESCAPE:
                 {SDL_Delay(400);
                 return 1;}
               break;
               case SDLK_RETURN:
                 if (y==1) 
                 {SDL_Delay(400); 
                  return 1;}
                 if (n==1) return 1;
               break;
                }
            }
}
TTF_CloseFont(police);
TTF_Quit();

SDL_FreeSurface(texte);
SDL_Quit();
}
