#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include <string.h>

/*int vol ;
int done ;*/
int menu(SDL_Surface *screen,int vol);
int options(SDL_Surface *screen,int vol);
int Story(SDL_Surface *screen);
int quit(SDL_Surface *screen);
int welcome(SDL_Surface *screen);

#endif // HEADER_H_INCLUDED
