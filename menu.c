#include "header.h"

void menu (SDL_Surface *screen, int vol){
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen=NULL;
screen=SDL_SetVideoMode(1920,1080,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Unlifted Curse",NULL);

SDL_Surface *background=NULL;
background=IMG_Load("Menu/backgroundMenu.png");
SDL_Rect background_pos;
background_pos.x=0;
background_pos.y=0;


//introduction musique
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,1024);//1 -> mono ** 2 -> sterio
    Mix_Music *music;
    music= Mix_LoadMUS("Menu/Immortal.mp3");
    Mix_VolumeMusic(volume);
    Mix_PlayMusic(music,-1);//-1 play till the program ends ** n number of times


 SDL_Surface *playgame[3],*story[3],*option[3],*exit[3];

    SDL_Rect pos;
    pos.x=0;    //position blit
    pos.y=0;

    SDL_Event event;
    int ng=1,op=0,ex=0,st=0,t,save;
    //chargement de bouton et image
    playgame[0]=IMG_Load("Menu/play-normal.png");
    story[0]=IMG_Load("Menu/story-normal.png");
    option[0]=IMG_Load("Menu/option-normal.png");
    option[2]=IMG_Load("Menu/option-selected.png");
    option[1]=IMG_Load("Menu/option-selected.png");;
    exit[0]=IMG_Load("Menu/exit-normal.png");
    playgame[1]=IMG_Load("Menu/play-selected.png");
    playgame[2]=IMG_Load("Menu/play-selected.png");
    exit[1]=IMG_Load("Menu/exit-selected.png");
    exit[2]=IMG_Load("Menu/exit-selected.png");
    story[1]=IMG_Load("Menu/story-selected.png");
    story[2]=IMG_Load("Menu/story-selected.png");



 int done=1;
    while (done)
    {

        //affichage des images
        SDL_BlitSurface(background,NULL,screen,&pos);
        SDL_BlitSurface(option[op],NULL,screen,&pos);
        SDL_BlitSurface(story[st],NULL,screen,&pos);
        SDL_BlitSurface(playgame[ng],NULL,screen,&pos);
        SDL_BlitSurface(exit[ex],NULL,screen,&pos);
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

            //avec clavier
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

                        t=1;

                    }
                    break;

                case SDLK_DOWN:
                    if (ng==0 && op==0 && ex==0 && lg==0)
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



                case SDLK_RETURN:
                    if (ng==1)
                    {
                        SDL_BlitSurface(playgame[2],NULL,screen,&pos);
                        SDL_Flip(screen);
                        SDL_Delay(100);

                      level_one();
                        //return PLAY_GAME;
                    }


                    else if (ex==1)
                    {
                        SDL_BlitSurface(exit[2],NULL,screen,&pos);
                        SDL_Flip(screen);
                        SDL_Delay(100);

                        if (quit(screen)==1)
                            done = 0;

                    }
                     if (op==1)
                      options(screen);
                    break;

                      if (st==1)
                      story(screen);
                    break;


}
    break;
}
}
}
SDL_FreeSurface(background);
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

}
