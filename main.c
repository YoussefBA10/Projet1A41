#include <stdio.h>
#include <stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include"header.h"
void main() {
int vol=100,done=1;
SDL_Surface *screen=NULL;
SDL_Init(SDL_INIT_VIDEO);
//full screen

if (SDL_Init(SDL_INIT_VIDEO) !=0) {
printf("Erreur : %s \n ",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(1360,760,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


if (screen==NULL)
{
printf("Erreur : %s \n",SDL_GetError());
return 1;
}


while(done){
if (menu(&screen,vol)==1) done=0;
}







}
