#include <stdio.h>
#include <stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include"header.h"
int options(SDL_Surface *screen, int vol ) {
int done=1;
//Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,1024);
SDL_Rect pos,poslogo,posmd,posvol,possg,posrt,posbar,posmod;
//son
//int vol=100;
//Mix_Music *music;
Mix_Chunk *bref;
bref=Mix_LoadWAV("Game/Menu/Bref.wav");
SDL_Surface  *image=NULL,*Option=NULL; //*screen=NULL
//music= Mix_LoadMUS("Game/Menu/background-music.mp3");
//Mix_VolumeMusic(vol);
//Mix_PlayMusic(music,-1);

//SDL_Init(SDL_INIT_VIDEO);
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
image=IMG_Load("Game/Option/Background.png");

    SDL_Event event;
int br;
if (vol==25)
 br=1;
if (vol==50)
 br=2;
if (vol==75)
 br=3;
if (vol==100)
br=4;
    int vl=0,rt=0,md=1,sg=0,t,save,mod=0;
 SDL_Surface *Volume[3],*Mode[3],*Song[3],*Return[3],*bar[4],*Type[1];
    //chargement de bouton et image
    Option=IMG_Load("Game/Option/Option-logo.png");
    Volume[0]=IMG_Load("Game/Option/Volume-normal.png");
    Mode[0]=IMG_Load("Game/Option/Mode-normal.png");

    Return[0]=IMG_Load("Game/Option/Return-normal.png");

    Return[1]=IMG_Load("Game/Option/Return-selected.png");
    Volume[1]=IMG_Load("Game/Option/Volume-selected.png");
    Mode[1]=IMG_Load("Game/Option/Mode-selected.png");
    Volume[2]=IMG_Load("Game/Option/Volume-selected.png");

    Return[2]=IMG_Load("Game/Option/Return-selected.png");
    Mode[2]=IMG_Load("Game/Option/Mode-selected.png");

    bar[0]=IMG_Load("Game/Option/Bar-0.png");
    bar[1]=IMG_Load("Game/Option/Bar-1.png");
    bar[2]=IMG_Load("Game/Option/Bar-2.png");
    bar[3]=IMG_Load("Game/Option/Bar-3.png");
    bar[4]=IMG_Load("Game/Option/Bar-4.png");
    Type[0]=IMG_Load("Game/Option/Full-screen.png");
    Type[1]=IMG_Load("Game/Option/Mini-screen.png");


pos.x=0;
pos.y=0;
poslogo.x=300;
poslogo.y=0;
posrt.x=355;
posrt.y=420;
posvol.x=355;
posvol.y=350;
posmd.x=355;
posmd.y=285;
posbar.x=600;
posbar.y=350;
posmod.x=600;
posmod.y=285;

while (done){
Mix_PlayChannel(-1, bref, 1);
SDL_BlitSurface(image,NULL,screen,&pos);
SDL_BlitSurface(Option,NULL,screen,&poslogo);
SDL_BlitSurface(Mode[md],NULL,screen,&posmd);
SDL_BlitSurface(Volume[vl],NULL,screen,&posvol);
SDL_BlitSurface(Return[rt],NULL,screen,&posrt);
SDL_BlitSurface(bar[br],NULL,screen,&posbar);
SDL_BlitSurface(Type[mod],NULL,screen,&posmod);
Mix_VolumeMusic(vol);
        SDL_Flip(screen);
        t=0;
        if (SDL_WaitEvent(&event))
        {
            switch(event.type)
            {
            /*case SDL_QUIT :
               // if (quit(screen)==1)
                    done=0;
                break;

            //avec clavier */
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {

                case SDLK_UP:
                    if (md==1 && vl==0 && rt==0)
                    {
                        md=1;
                    }
                    if (md==1 && t==0)
                    {
                        rt=1;
                        md=0;
                        vl=0;

                        t=1;

                    }
                    else if(vl==1 && t==0)
                    {

                        {
                            md=1;

                            vl=0;
                            rt=0;
                            t=1;
                        }

                    }
                    else if (rt==1 && t==0)
                    {
                        vl=1;
                        rt=0;
                        md=0;
                        t=1;

                    }
                    break;

                case SDLK_DOWN:
                    if (md==0 && vl==0 && rt==0)
                    {
                        rt=1;
                    }
                    if (md==1 && t==0)
                    {
                            md=0;
                            vl=1;
                            rt=0;
                            t=1;
                    }
                    else if(vl==1 && t==0)
                    {
                        md=0;
                        vl=0;
                        rt=1;
                        t=1;

                    }
                    else if (rt==1 && t==0)
                    {
                        vl=0;
                        rt=0;
                        md=1;
                        t=1;

                    }
                    break;

                    case SDLK_ESCAPE:
                    done=0;
                    SDL_Delay(400);
                    return 1;
                    break;
               case SDLK_RIGHT:
                    if ((br<4) &&(t==0) && (vl==1))
                    {
                                   br=br+1;
                                   vol=vol+25;
                                   t=1;
                                   md=0;
                    }
                    if ((mod==0) && (t==0) && (md==1))
                    {
                        mod=mod+1;
                        screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
                        t=1;
                    }
                    if ((mod==1) && (t==0) && (md=1))
                    {
                        mod=mod-1;
                        screen=SDL_SetVideoMode(1300,760,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
                        t=1;
                        md=0;
                    }

                   break;
            case SDLK_LEFT:
                    if ((br>0) &&(t==0) && (vl==1))
                    {
                                   br=br-1;
                                   vol=vol-25;
                                   t=1;  md=0;
                    }
                    if ((mod==0) && (t==0) && (md==1))
                    {
                        mod=mod+1;
                        screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
                        t=1;
                        md=1;
                    }
                    if ((mod==1) && (t==0) && (md=1))
                    {
                        mod=mod-1;
                        screen=SDL_SetVideoMode(1300,760,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
                        t=1;
                        md=0;
                    }

                   break;


               case SDLK_RETURN:
                    if(rt==1)
                    {
                        SDL_Delay(400);
                        return 1;
                    }


}
    break;
    case SDL_MOUSEMOTION:
                        md=0;
                        sg=0;
                        vl=0;
                        rt=0;
                                   if (event.motion.x>118 && event.motion.y>312 && event.motion.x<900 && event.motion.y<360)
                                    {
                                        md=1;
                                    }

                                    else if (event.motion.x>118 && event.motion.y>362 && event.motion.x<900 && event.motion.y<410)
                                    {
                                        vl=1;
                                    }

                                  else if (event.motion.x>118 && event.motion.y>412 && event.motion.x<900 && event.motion.y<460 )
                                    {
                                        sg=1;
                                    }
                                  else if (event.motion.x>118 && event.motion.y>462 && event.motion.x<900 && event.motion.y<560 )
                                    {
                                        rt=1;
                                    }
    break;
           case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    if(rt==1)
                    {
                        SDL_Delay(400);
                        return 1;
                    }
                }
             break;

}
}
}

SDL_FreeSurface(image);
SDL_FreeSurface(Option);
SDL_FreeSurface(Mode[2]);
SDL_FreeSurface(Song[2]);
SDL_FreeSurface(Return[2]);
SDL_FreeSurface(Mode[0]);
SDL_FreeSurface(Mode[1]);
SDL_FreeSurface(Song[0]);
SDL_FreeSurface(Song[1]);
SDL_FreeSurface(Volume[0]);
SDL_FreeSurface(Return[0]);
SDL_FreeSurface(Return[1]);
Mix_FreeChunk(bref);


return 1;


//SDL_Quit();






}
