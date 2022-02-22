#include <stdio.h>
#include <stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include"header.h"
int menu(SDL_Surface *screen,int vol) {
int done=1;

int br;
if (vol==25)
 br=1;
if (vol==50)
 br=2;
if (vol==75)
 br=3;
if (vol==100)
br=4;
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,1024);
SDL_Rect pos,poslogo,posng,posop,posst,posex;
//son
//int vol=100;
Mix_Music *music;
Mix_Chunk *bref;
bref=Mix_LoadWAV("Game/Menu/Bref.mp3");
SDL_Surface *image=NULL,*logo=NULL; //screen
music= Mix_LoadMUS("Game/Menu/background-music.mp3");
Mix_VolumeMusic(vol);
Mix_PlayMusic(music,-1);

SDL_Init(SDL_INIT_VIDEO);
//full screen

if (SDL_Init(SDL_INIT_VIDEO) !=0) {
printf("Erreur : %s \n ",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(1360,760,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);


if (screen==NULL)
{
printf("Erreur : %s \n",SDL_GetError());
return 1;
}
image=IMG_Load("Game/Menu/background.png");

    SDL_Event event;
    int ng=1,op=0,ex=0,st=0,t,save;
 SDL_Surface *playgame[3],*story[3],*option[3],*exit[3];
    //chargement de bouton et image
    logo=IMG_Load("Game/Menu/LOGO.png");
    playgame[0]=IMG_Load("Game/Menu/play-normal.png");
    story[0]=IMG_Load("Game/Menu/story-normal.png");
    option[0]=IMG_Load("Game/Menu/option-normal.png");
    option[2]=IMG_Load("Game/Menu/option-clicked.png");
    option[1]=IMG_Load("Game/Menu/option-selected.png");;
    exit[0]=IMG_Load("Game/Menu/exit-normal.png");
    playgame[1]=IMG_Load("Game/Menu/play-selected.png");
    playgame[2]=IMG_Load("Game/Menu/play-clicked.png");
    exit[1]=IMG_Load("Game/Menu/exit-selected.png");
    exit[2]=IMG_Load("Game/Menu/exit-clicked.png");
    story[1]=IMG_Load("Game/Menu/story-selected.png");
    story[2]=IMG_Load("Game/Menu/story-clicked.png");


pos.x=0;
pos.y=0;
poslogo.x=300;
poslogo.y=0;
posex.x=570;
posex.y=480;
posst.x=570;
posst.y=420;
posop.x=570;
posop.y=350;
posng.x=555;
posng.y=285;

while (done){
Mix_PlayChannel(-1, bref, 1);
SDL_BlitSurface(image,NULL,screen,&pos);
SDL_BlitSurface(logo,NULL,screen,&poslogo);
        SDL_BlitSurface(option[op],NULL,screen,&posop);
        SDL_BlitSurface(story[st],NULL,screen,&posst);
        SDL_BlitSurface(playgame[ng],NULL,screen,&posng);
        SDL_BlitSurface(exit[ex],NULL,screen,&posex);
        SDL_Flip(screen);
        t=0;
        if (SDL_WaitEvent(&event))
        {
            switch(event.type)
            {
           /* case SDL_QUIT :
                if (quit(screen)==1)
                    return 1;
                break;
*/
            //avec clavier */
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {

                case SDLK_UP:
                    if (ng==1 && op==0 && ex==0 && st==0)
                    {
                        ng=1;
                    }
                    if (ng==1 && t==0)
                    {
                        ex=1;
                        ng=0;
                        op=0;
                        st=0;
                        t=1;

                    }
                    else if(op==1 && t==0)
                    {

                        {
                            ng=1;
                            st=0;
                            op=0;
                            ex=0;
                            t=1;

                        }

                    }
                    else if (ex==1 && t==0)
                    {
                        op=0;
                        ex=0;
                        ng=0;
                        st=1;
                        t=1;

                    }
                    else if (st==1 && t==0)
                    {
                        ng=0;
                        op=1;
                        ex=0;
                        st=0;
                        t=1;

                    }
                    break;

                case SDLK_DOWN:
                    if (ng==0 && op==0 && ex==0 && st==0)
                    {
                        ex=1;
                    }
                    if (ng==1 && t==0)
                    {
                            ng=0;
                            st=0;
                            op=1;
                            ex=0;
                            t=1;
                    }
                    else if(op==1 && t==0)
                    {
                        ng=0;
                        op=0;
                        ex=0;
                        st=1;
                        t=1;

                    }
                    else if (ex==1 && t==0)
                    {
                        op=0;
                        ex=0;
                        ng=1;
                        ex=0;
                        t=1;

                    }
                    else if (st==1 && t==0)
                    {
                        ng=0;
                        st=0;
                        op=0;
                        ex=1;
                        t=1;

                    }
                    break;

                    case SDLK_ESCAPE:
                if (quit(screen)==1)
                    return 1;
                    break;


               case SDLK_RETURN:
                   /* if (ng==1)
                    {
                        SDL_BlitSurface(playgame[2],NULL,screen,&pos);
                        SDL_Flip(screen);
                        SDL_Delay(100);

                    //  level_one();
                        //return PLAY_GAME; 
                    }*/


                    if (ex==1)
                    {
                        SDL_BlitSurface(exit[2],NULL,screen,&pos);
                        SDL_Flip(screen);
                        SDL_Delay(100);

                if (quit(screen)==1)
                    return 1;

                    }
                     if (op==1)
                      {
                      if (options(&screen,vol)==1)
                        t=0;
                   
                      }
                      if (st==1)
                       {
                      if (Story(&screen)==1)
                        t=0;
                       }
                    break;


}
    break;
    case SDL_MOUSEMOTION:
                        ng=0;
                        st=0;
                        op=0;
                        ex=0;
                                   if (event.motion.x>118 && event.motion.y>312 && event.motion.x<900 && event.motion.y<360)
                                    {
                                        ng=1;
                                    }

                                    else if (event.motion.x>118 && event.motion.y>362 && event.motion.x<900 && event.motion.y<410)
                                    {
                                        op=1;
                                    }

                                  else if (event.motion.x>118 && event.motion.y>412 && event.motion.x<900 && event.motion.y<460 )
                                    {
                                        st=1;
                                    }
                                  else if (event.motion.x>118 && event.motion.y>462 && event.motion.x<900 && event.motion.y<560 )
                                    {
                                        ex=1;
                                    }

}
}
}

SDL_FreeSurface(image);
SDL_FreeSurface(logo);
SDL_FreeSurface(playgame[2]);
SDL_FreeSurface(story[2]);
SDL_FreeSurface(exit[2]);
SDL_FreeSurface(playgame[0]);
SDL_FreeSurface(playgame[1]);
SDL_FreeSurface(story[0]);
SDL_FreeSurface(story[1]);
SDL_FreeSurface(option[0]);
SDL_FreeSurface(exit[0]);
SDL_FreeSurface(exit[1]);
Mix_FreeChunk(bref);


//SDL_Quit();


return 0; 




}
