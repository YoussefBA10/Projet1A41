#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include <string.h>

int volume ;
int done ;
void menu (SDL_Surface *screen, int volume);
void options(SDL_Surface *screen);

#endif // HEADER_H_INCLUDED

