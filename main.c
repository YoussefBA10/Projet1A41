#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"

int main(int argc,char *argv[]) {


int vol=100;
    SDL_Init(SDL_INIT_VIDEO);
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,1024);//1 -> mono ** 2 -> sterio
Mix_Music *music;
music= Mix_LoadMUS("menu/background.mp3");
Mix_VolumeMusic(vol);
Mix_PlayMusic(music,-1);//-1 play till the program ends ** n number of times


//fenetre principale
SDL_Surface *screen ;
screen=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Unlifted Curse",NULL);
iscntrl(screen);


return 0 ;
}
