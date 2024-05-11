#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>
#include "gameover.h"

SDL_Texture *tex = NULL;
TTF_Font *ubuntu = NULL;
int surX;
int surY;
void init_gameover(SDL_Renderer *renderer)
{
  char *text = "Game Over";
  ubuntu = TTF_OpenFont("res/UbuntuMono-R.ttf", 56);
  SDL_Surface *sur = TTF_RenderText_Blended(ubuntu, text, (SDL_Color){255, 0, 0});
  surX = sur->w;
  surY = sur->h;
  tex = SDL_CreateTextureFromSurface(renderer, sur);
  SDL_FreeSurface(sur);
}

void draw_gameover(SDL_Window *window, SDL_Renderer *renderer)
{
  int *x = malloc(sizeof(int)), *y = malloc(sizeof(int));
  SDL_GetWindowSize(window, x, y);
  SDL_Rect rect = {*x / 2 - surX / 2, *y / 2 - surY / 2, surX, surY};
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, tex, NULL, &rect);
  SDL_RenderPresent(renderer);
  free(x);
  free(y);
}

void destroy_gameover()
{
  SDL_DestroyTexture(tex);
  TTF_CloseFont(ubuntu);
}
