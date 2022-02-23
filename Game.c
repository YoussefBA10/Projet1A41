#include <stdlib.h>
#include <stdio.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include"header.h"
int game(SDL_Surface *screen)
{
SDL_Surface  *texte =NULL,*fond=NULL;
SDL_Rect position,pos;
SDL_Event event ; 
TTF_Font *police = NULL;
SDL_Color couleurBlanche ={255,255,255};
int continuer = 1;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
screen = SDL_SetVideoMode(1360,760,32,SDL_HWSURFACE | SDL_DOUBLEBUF |SDL_FULLSCREEN);
SDL_WM_SetCaption("Unlifted Curse",NULL);
fond=IMG_Load("Game/Quit/Background.png");
police = TTF_OpenFont("Game/Welcome/font.ttf",50);
texte = TTF_RenderText_Blended(police,"COMMING SOON...",couleurBlanche);
pos.x=0;
pos.y=0;
position.x =400;
position.y =400;
while (continuer == 1)
{
//SDL_FillRect(screen, NULL , SDL_MapRGB(screen->format,255,255,255));
SDL_BlitSurface(fond,NULL,screen,&pos);
SDL_BlitSurface(texte,NULL,screen,&position);
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

}
