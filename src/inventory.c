#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "inventory.h"

#define SLOT_OFFSET 69
#define SLOT_DIMENSION 64
#define SLOT_SPACE_BETWEEN 74

SDL_Texture *invtex;
SDL_Texture *itemtex;
Item items[3] = {};

void draw_inventory(SDL_Window *window, SDL_Renderer *renderer)
{
  int *x = malloc(sizeof(int)), *y = malloc(sizeof(int));
  SDL_GetWindowSize(window, x, y);
  SDL_Rect slot = {*x - SLOT_OFFSET, *y - SLOT_OFFSET, SLOT_DIMENSION, SLOT_DIMENSION};

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  SDL_RenderCopy(renderer, invtex, NULL, &slot);
  for (int i = 0; i < 3; i++)
  {
    SDL_RenderCopy(renderer, invtex, NULL, &slot);
    slot.x -= SLOT_SPACE_BETWEEN;
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
  SDL_DestroyTexture(itemtex);
}
void add_item(Item item)
{
  if (items[0] == 0)
  {
    items[0] = item;
  }
  else if (items[1] == 0)
  {
    items[1] = item;
  }
  else if (items[2] == 0)
  {
    items[2] = item;
  }
  else
  {
    printf("Inventory Full\n");
  }
}
void draw_items(SDL_Window *window, SDL_Renderer *renderer)
{
  int *x = malloc(sizeof(int)), *y = malloc(sizeof(int));
  SDL_GetWindowSize(window, x, y);
  SDL_Rect rect = {*x - SLOT_OFFSET, *y - SLOT_OFFSET, SLOT_DIMENSION, SLOT_DIMENSION};

  for (int i = 0; i < 3; i++)
  {
    if (items[i] != 0)
    {
      switch (items[i])
      {
      case WRENCH:
      {
        SDL_Surface *itemsurWrench = IMG_Load("res/wrench.png");
        itemtex = SDL_CreateTextureFromSurface(renderer, itemsurWrench);

        SDL_FreeSurface(itemsurWrench);
        SDL_RenderCopy(renderer, itemtex, NULL, &rect);
        break;
      }
      case SWORD:
      {
        SDL_Surface *itemsurSword = IMG_Load("res/sword.png");
        itemtex = SDL_CreateTextureFromSurface(renderer, itemsurSword);

        SDL_FreeSurface(itemsurSword);
        SDL_RenderCopy(renderer, itemtex, NULL, &rect);
        break;
      }
      }
    }
    rect.x -= SLOT_SPACE_BETWEEN;
  }
}
void remove_item(int index)
{
  if (index >= 0 && index < 3)
  {
    if (items[index] == 0)
    {
      return;
    }
    else
    {
      items[index] = 0;
    }
  }
}
void reset_inventory()
{
  for (int i = 0; i < 3; i++)
  {
    items[i] = 0;
  }
}