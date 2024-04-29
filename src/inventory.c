#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture *invtex;

void draw_inventory(SDL_Window *window, SDL_Renderer *renderer)
{
  int *x = malloc(sizeof(int)), *y = malloc(sizeof(int));
  SDL_GetWindowSize(window, x, y);
  SDL_Rect slot = {*x - 66, *y - 66, 64, 64};

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  SDL_RenderCopy(renderer, invtex, NULL, &slot);
  for (int i = 0; i < 3; i++)
  {
    SDL_RenderCopy(renderer, invtex, NULL, &slot);
    slot.x -= 74;
  }
}
void init_inventory(SDL_Renderer *renderer)
{
  SDL_Surface *surface = IMG_Load("res/invslot.png");
  invtex = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
}
void destroy_inventory()
{
  SDL_DestroyTexture(invtex);
}