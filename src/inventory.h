typedef enum
{
  SWORD = 1,
  WRENCH
} Item;
void draw_inventory(SDL_Window *window, SDL_Renderer *renderer);
void init_inventory(SDL_Renderer *renderer);
void destroy_inventory();
void add_item(Item item);
void draw_items(SDL_Window *window, SDL_Renderer *renderer);
void remove_item(int index);
void reset_inventory();