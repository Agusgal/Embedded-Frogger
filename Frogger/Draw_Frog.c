#include "header.h"

//Dibuja a la rana, recibe display y su posicion
void draw_frog(ALLEGRO_DISPLAY *display, int frog_x, int frog_y)
{
    
    al_set_target_bitmap(al_get_backbuffer(display));
    
    //cuerpo
    al_draw_filled_rounded_rectangle(frog_x + 5, frog_y + 3, frog_x + 25, frog_y + 30, 5, 7, al_map_rgb(34, 139, 34));
    
    al_draw_filled_rounded_rectangle(frog_x + 8, frog_y + 7, frog_x + 22, frog_y + 25, 3, 7, al_map_rgb(255,255,102));
    
    
    //patas
    al_draw_filled_rectangle(frog_x, frog_y, frog_x + 5, frog_y + 13, al_map_rgb(34, 139, 34)); 
    
    al_draw_filled_rectangle(frog_x + 25, frog_y, frog_x + 30, frog_y + 13, al_map_rgb(34,139,34));
    
    al_draw_filled_rectangle(frog_x, frog_y + 17, frog_x + 5, frog_y + 30, al_map_rgb(34, 139, 34));
    
    al_draw_filled_rectangle(frog_x + 25, frog_y + 17, frog_x + 30, frog_y + 30, al_map_rgb(34, 139, 34));
    
    
    //ojos
    
    al_draw_filled_circle(frog_x + 10, frog_y + 7, 4, al_map_rgb(0, 191, 255));
    
    al_draw_filled_circle(frog_x + 20, frog_y + 7, 4, al_map_rgb(0, 191, 255));
   
    
    al_set_target_bitmap(al_get_backbuffer(display));
    
}
