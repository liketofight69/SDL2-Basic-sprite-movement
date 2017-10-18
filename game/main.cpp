#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include <map>

#define img "sprite.png"
#define img2 "front.png"
//#define front "front.png"
#define SHAPE_SIZE 20

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
//#define SPRITE_SIZE 32

enum {
    DISPLAY_WIDTH  = 480
    , DISPLAY_HEIGHT = 320
    , UPDATE_INTERVAL = 1000/60
    , HERO_SPEED = 2
};
class Sprite {
public:
    int x, y ;
    Sprite() :x(0), y(0) {}
} ;
void onQuit();
    void onKeyDown( SDL_Event* event );
    void onKeyUp( SDL_Event* event );
int running;
std::map<int,int> keys;
int speed = 2;
int main(int argc, char ** argv)
{
    SDL_Rect SrcR;
  SDL_Rect DestR;

  SrcR.x = 0;
  SrcR.y = 0;
  SrcR.w = SHAPE_SIZE;
  SrcR.h = SHAPE_SIZE;

  DestR.x = 640 / 2 - SHAPE_SIZE / 2;
  DestR.y = 580 / 2 - SHAPE_SIZE / 2;
  DestR.w = SHAPE_SIZE;
  DestR.h = SHAPE_SIZE;
  //test


 //test
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window * window = SDL_CreateWindow("SDL2 Sprite Sheets",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
        SCREEN_HEIGHT, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Renderer * ren = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * image = IMG_Load(img);
    SDL_Surface * front_face = IMG_Load(img2);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
        image);
    SDL_Texture * front_text = SDL_CreateTextureFromSurface(renderer,
        front_face);
    SDL_Texture * f_text = SDL_CreateTextureFromSurface(ren,
        front_face);
    /*SrcR.x = 0;
    SrcR.y = 0;
    DestR.x = 0;
    DestR.y = 0;
    //image->h = 5;
    //image->w = 5;
    //test
    //

     if ( keys[SDLK_LEFT] ) {
        DestR.x -= speed ;
    } else if ( keys[SDLK_RIGHT] ) {
        DestR.x += speed ;
    } else if ( keys[SDLK_UP] ) {
       DestR.y -= speed ;
    } else if ( keys[SDLK_DOWN] ) {
        DestR.y += speed ;
    }
  */



    //test

    SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
    SDL_RenderClear(renderer);




    while (!quit)
    {
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:    onQuit();            break;
                case SDL_KEYDOWN: onKeyDown( &event );

                 break ;
                case SDL_KEYUP:   onKeyUp( &event );   break ;
                case SDL_MOUSEBUTTONDOWN:
                case SDL_MOUSEBUTTONUP:
                case SDL_MOUSEMOTION:
                    break ;
            }
        }
   //test

    //DestR.x = 10;
    //DestR.y = 10;

    //test
    //

     if ( keys[SDLK_LEFT] ) {
            SrcR.x = 45;
          SrcR.y = 2;

        DestR.x -= speed ;
    } else if ( keys[SDLK_RIGHT] ) {
         SrcR.x = 65;
          SrcR.y = 2;

        DestR.x += speed ;

    } else if ( keys[SDLK_UP] ) {

        //SDL_RenderClear(renderer);
        //SDL_RenderCopy(renderer, texture,&SrcR, &DestR );
        //SDL_RenderPresent(renderer);


        SrcR.x = 0;
          SrcR.y = 0;
       DestR.y -= speed ;
    } else if ( keys[SDLK_DOWN] ) {//testing rendering when down pressed
        //SDL_DestroyTexture(texture);

          SrcR.x = 25;
          SrcR.y = 2;

          /*SDL_FreeSurface(image);

        //SDL_FreeSurface(front_face);
        SDL_DestroyTexture(texture);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, front_text,&SrcR, &DestR );
        SDL_RenderPresent(renderer);*/

        DestR.y += speed ;
        //SDL_RenderCopy(renderer, front_text,&SrcR, &DestR );
       /*SDL_DestroyRenderer(renderer);


         SDL_RenderClear(ren);

        SDL_RenderCopy(ren, f_text,&SrcR, &DestR );
        SDL_RenderPresent(ren);
        SDL_SetRenderDrawColor(ren, 168, 230, 255, 255);
        SDL_RenderClear(ren);*/


       /*if ( keys[SDLK_RIGHT] ) {
        DestR.x += speed ;
        }*/



    }


    //test
    /* collide with edges of screen */
    if ( DestR.x < 0 ) {
      DestR.x = 0;
    }
    else if ( DestR.x > SCREEN_WIDTH-SHAPE_SIZE ) {
      DestR.x = SCREEN_WIDTH-SHAPE_SIZE;
    }
    if ( DestR.y < 0 ) {
      DestR.y = 0;
    }
    else if ( DestR.y > SCREEN_HEIGHT-SHAPE_SIZE ) {
      DestR.y = SCREEN_HEIGHT-SHAPE_SIZE;
    }





//test
        //Uint32 ticks = SDL_GetTicks();
        //Uint32 sprite = (ticks / 100) % 4;
        //SDL_Rect srcrect = { sprite * 32, 0, 32, 64 };//sprite
        //SDL_Rect dstrect = { 10, 10, 32, 64 };

        SDL_PollEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture,&SrcR, &DestR );
        SDL_RenderPresent(renderer);



    }

    SDL_DestroyTexture(texture);

    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
void onQuit() {
    running = 0 ;
}
void onKeyDown( SDL_Event* evt ) {
    keys[ evt->key.keysym.sym ] = 1 ;
}

void onKeyUp( SDL_Event* evt ) {
    keys[ evt->key.keysym.sym ] = 0 ;
}

