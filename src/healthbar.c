#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int hp = 200;
int lives = 3;
SDL_Texture *bartex;
SDL_Texture *hearttex;
void init_healthbar(SDL_Renderer *renderer)
{
  SDL_Surface *barsur = IMG_Load("res/healthbar.png");
  SDL_Surface *heartsur = IMG_Load("res/heart.png");
  bartex = SDL_CreateTextureFromSurface(renderer, barsur);
  hearttex = SDL_CreateTextureFromSurface(renderer, heartsur);
  SDL_FreeSurface(barsur);
  SDL_FreeSurface(heartsur);
}
void destroy_healthbar()
{
  SDL_DestroyTexture(bartex);
  SDL_DestroyTexture(hearttex);
}
void draw_healthbar(SDL_Window *window, SDL_Renderer *renderer)
{
  int *heigh = malloc(sizeof(int));
  SDL_GetWindowSize(window, NULL, heigh);
  SDL_Rect rect = {3, *heigh - 27, 204, 22};
  SDL_Rect rect2 = {5, *heigh - 25, hp, 18};
  SDL_Rect heart = {10, *heigh - 80, 50, 50};

  // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  // SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  SDL_RenderCopy(renderer, bartex, NULL, &rect);
  for (int i = 0; i < lives; i++)
  {
    SDL_RenderCopy(renderer, hearttex, NULL, &heart);
    heart.x += 60;
  }

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(renderer, &rect2);
}

int remove_hp(int hp_taken)
{
  if (hp_taken > hp)
  {
    hp = 0;
  }
  else
  {
    hp -= hp_taken;
  }
  if (hp == 0 && lives > 1)
  {
    hp = 200;
    lives--;
  }
  return hp;
}
void reset_health()
{
  hp = 200;
  lives = 3;
}