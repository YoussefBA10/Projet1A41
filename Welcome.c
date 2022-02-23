#include <stdlib.h>
#include <stdio.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include"header.h"
int welcome(SDL_Surface *screen)
{
SDL_Surface  *texte = NULL, *texte1=NULL , *fond = NULL, *image=NULL, *r=NULL ;
SDL_Rect position,poslogo,posr;
SDL_Event event ; 
TTF_Font *police = NULL ,*police1=NULL;
SDL_Color couleurBlanche ={255,255,255};
int continuer = 1;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
screen = SDL_SetVideoMode(1360,760,32,SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN);
SDL_WM_SetCaption("Unlifted Curse",NULL);
r=IMG_Load("Game/Welcome/r.png");
image=IMG_Load("Game/Welcome/logo.jpg");
fond = IMG_Load("Game/Quit/Background.png");
police = TTF_OpenFont("Game/Welcome/font1.ttf",50);
police1= TTF_OpenFont("Game/Welcome/font.ttf",30);
texte = TTF_RenderText_Blended(police,"PRESENTED BY THE SIX GATES GROUP",couleurBlanche);
texte1 = TTF_RenderText_Blended(police1,"Press enter to continue!",couleurBlanche);
position.x =0;
position.y =0;
poslogo.x=530;
poslogo.y=130;
posr.x=1070;
posr.y=420;
while (continuer == 1 )
{
//SDL_FillRect(screen, NULL , SDL_MapRGB(screen->format,255,255,255));
SDL_BlitSurface(r,NULL,screen,&posr);
SDL_BlitSurface(fond,NULL,screen,&position);
position.x = 270;
position.y = 420; //position texte par rapport a l image //
SDL_BlitSurface(texte,NULL,screen,&position);
position.x =500;
position.y =600;
SDL_BlitSurface(texte1,NULL,screen,&position);
SDL_BlitSurface(image,NULL,screen,&poslogo);
SDL_Flip(screen);
SDL_WaitEvent(&event);

 switch(event.type)
            {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
              case SDLK_RETURN:
                SDL_Delay(400);
                return 1;
               break;
}
break;
}
}
TTF_CloseFont(police);
TTF_Quit();

SDL_FreeSurface(texte);
SDL_Quit();
}
