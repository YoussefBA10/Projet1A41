#include "header.h"
void options(SDL_Surface *screen)
{

                        SDL_Surface *background;
                        background =IMG_Load("option/background.png");

                        SDL_Surface *audio[3],*controls[3],*video[3];

                        SDL_Rect pos;
                        pos.x=0;    //position blit
                        pos.y=0;

                        SDL_Event event;
                        int au=1,cn=0,vd=0,t,lg,save;
                        //chargement d'image
                        audio[0]=IMG_Load("option/audio-normal.png");
                        controls[0]=IMG_Load("option/controls-normal.png");
                        controls[2]=IMG_Load("option/controls-clicked.png");
                        controls[1]=IMG_Load("option/controls-selected.png");
                        video[0]=IMG_Load("option/video-normal.png");
                        audio[1]=IMG_Load("option/audio-selected.png");
                        audio[2]=IMG_Load("option/audio-clicked.png");
                        video[1]=IMG_Load("option/video-selected.png");
                        video[2]=IMG_Load("option/video-clicked.png");

                         int done=1;
                        while (done)
                        {

                            //affichage des images
                            SDL_BlitSurface(background,NULL,screen,&pos);
                            SDL_BlitSurface(controls[cn],NULL,screen,&pos);
                            //SDL_BlitSurface(loadgame[lg],NULL,screen,&pos);
                            SDL_BlitSurface(audio[au],NULL,screen,&pos);
                            SDL_BlitSurface(video[vd],NULL,screen,&pos);
                            SDL_Flip(screen);
                            t=0;
                            if (SDL_WaitEvent(&event))
                            {
                                switch(event.type)
                                {
                                case SDL_QUIT :
                                    if (quit(screen)==1)
                                        done=0;
                                    break;
                          

