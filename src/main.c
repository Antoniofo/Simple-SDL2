#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "healthbar.h"
#include "gameover.h"
#include "inventory.h"

#define width 800
#define height 600

int main(int argc, char *argv[])
{
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO) < 0)
  {
    fprintf(stderr, "ERR SDL INIT %s", SDL_GetError());
    return 1;
  }
  if (IMG_Init(IMG_INIT_PNG) == 0)
  {
    fprintf(stderr, "ERR SDL INIT %s", SDL_GetError());
    return 1;
  }
  TTF_Init();

  window = SDL_CreateWindow("Smoll project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    fprintf(stderr, "ERR SDL WINDOW %s", SDL_GetError());
    return 1;
  }
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL)
  {
    fprintf(stderr, "ERR SDL Renderer %s", SDL_GetError());
    return 1;
  }

  init_healthbar(renderer);
  init_gameover(renderer);
  init_inventory(renderer);
  SDL_bool alive = SDL_TRUE;
  // SDL_bool alive = SDL_FALSE;
  SDL_Event e;
  SDL_bool quit = SDL_FALSE;
  while (quit == SDL_FALSE)
  {

    while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
        quit = SDL_TRUE;

      if (e.type == SDL_KEYDOWN)
      {
        switch (e.key.keysym.sym)
        {
        case SDLK_d:
        {
          int curr_hp = remove_hp(4);
          if (curr_hp == 0)
          {
            alive = SDL_FALSE;
          }
          break;
        }
        case SDLK_r:
        {
          if (alive == SDL_FALSE)
          {
            alive = SDL_TRUE;
            reset_health();
            reset_inventory();
            // Become alive agai
          }
          break;
        }
        case SDLK_a:
          add_item(WRENCH);
          break;
        case SDLK_b:
          add_item(SWORD);
          break;
        case SDLK_1:
          remove_item(2);
          break;
        case SDLK_2:
          remove_item(1);
          break;
        case SDLK_3:
          remove_item(0);
          break;
        }
      }
      if (alive == SDL_TRUE)
      {

        draw_inventory(window, renderer);
        draw_healthbar(window, renderer);
        draw_items(window, renderer);
        SDL_RenderPresent(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
      }
      else
      {
        draw_gameover(window, renderer);
      }
    }
  }
  destroy_inventory();
  destroy_healthbar();
  destroy_gameover();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
