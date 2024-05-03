#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "mainscreen.h"

#define BUFFER 255

SDL_Texture *texture;
SDL_Surface *surfaceScreen = NULL;
TTF_Font *ubuntu2 = NULL;
char text[BUFFER];

void getFileLine(int ligne)
{
  FILE *textfile = fopen("res/scripts.txt", "r");
  for (int i = 0; i < ligne; i++)
  {
    fgets(text, BUFFER, textfile);
  }

  fclose(textfile);
}

void init_screen(SDL_Renderer *renderer)
{
  ubuntu2 = TTF_OpenFont("res/UbuntuMono-R.ttf", 56);
  surfaceScreen = TTF_RenderText_Blended_Wrapped(ubuntu2, text, (SDL_Color){255, 0, 0}, 0);

  texture = SDL_CreateTextureFromSurface(renderer, surfaceScreen);
  SDL_FreeSurface(surfaceScreen);
}

void draw_screen(SDL_Window *window, SDL_Renderer *renderer)
{
  int *x = malloc(sizeof(int)), *y = malloc(sizeof(int));
  SDL_GetWindowSize(window, x, y);
  SDL_Rect rect = {5, 5, (*x) - 10, (*y) - 100};
  surfaceScreen = TTF_RenderText_Blended_Wrapped(ubuntu2, text, (SDL_Color){255, 0, 0}, *x);

  texture = SDL_CreateTextureFromSurface(renderer, surfaceScreen);
  SDL_FreeSurface(surfaceScreen);
  SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
  SDL_RenderDrawRect(renderer, &rect);
  rect.w = *x;
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}
void changeText(int ligne)
{
  getFileLine(ligne);
}
void destroy_sreen()
{
}