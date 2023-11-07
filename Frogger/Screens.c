#include "header.h"

//Aca esta todo lo relacionado con las pantallas, principal, pausa y game over.

//pantalla de fin de jeugo, retorna -2 si quiere cerrar el juego, -1 si quiere ir a la pantalla principal y 1 si quiere reiniciar directamente
int game_over_screen(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue) 
{
    //creo una imagen, fuentes y cursor
    ALLEGRO_BITMAP * pepe = al_load_bitmap("pepe.png");
    ALLEGRO_FONT *font = al_load_font("font.ttf", 36, 0);
    ALLEGRO_FONT *font_game_over = al_load_font("font.ttf", 65, 0);
    
    ALLEGRO_BITMAP * cursorimagen = al_load_bitmap("cursor.jpg"); 
    ALLEGRO_MOUSE_CURSOR * cursor = al_create_mouse_cursor(cursorimagen,20, 20);
    
    int salida = 0;
    
    while (!salida)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        
        int x, y;
        
        if(event.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            x = event.mouse.x;
            y = event.mouse.y;
        }
        
        //si quiere salir directamnete puede hacerlo con esc o apretando el boton rojo
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            salida = -2;
        }
        
        if (event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            salida = -2;
        }
        
        al_clear_to_color(al_map_rgb(211, 211, 211));
        al_draw_bitmap(pepe, SCREEN_W / 2, SCREEN_H / 2, 0 );
        al_draw_text(font_game_over, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H / 2 - 300, ALLEGRO_ALIGN_CENTER, "GAME OVER");
        
        //Controla el restart
        if(x >= 290 && x <= 515 && y >= 315 && y <= 360)
        {
            al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H / 2 - 150, ALLEGRO_ALIGN_CENTER, "Restart?");
            if(event.mouse.button & 1)
            {
                salida = 1;
            }
        }
        else
        {
            al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2 - 150, ALLEGRO_ALIGN_CENTER, "Restart?");
        }
        
        //Controla exit
        if(x >= 180 && x <= 630 && y >= 416 && y <= 455)
        {
            al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H / 2 - 50, ALLEGRO_ALIGN_CENTER, "Exit to main menu");
            if(event.mouse.button & 1)
            {
                salida = -1;
            }
        }
        else
        {
            al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2 - 50, ALLEGRO_ALIGN_CENTER, "Exit to main menu");
        }
        
        
        al_flip_display();
    }
    
    al_destroy_font(font);
    al_destroy_font(font_game_over);
    al_destroy_bitmap(cursorimagen);
    
    return salida;
}

//Menu de pausa, devuelve -2 si quiere salir directamente, -1 si quiere ir  al menu ppal y 1 si quiere continuar
int pause_menu(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue)
{
    ALLEGRO_BITMAP * cursorimagen = al_load_bitmap("cursor.jpg"); 
    ALLEGRO_MOUSE_CURSOR * cursor = al_create_mouse_cursor(cursorimagen,20, 20);
  
    int salida = 0;
    
    ALLEGRO_BITMAP * pausa = al_load_bitmap("ranapiensa.jpg");
    ALLEGRO_BITMAP * pausa1 = al_load_bitmap("ranapiensaContinue.jpg");
    ALLEGRO_BITMAP * pausa2 = al_load_bitmap("ranapiensaExit.jpg");
    
    while (!salida)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        
        al_clear_to_color(al_map_rgb(211, 211, 211));
        int x, y;
        if(events.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            x = events.mouse.x;
            y = events.mouse.y;
        }
        
        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            salida = -2;
        }
        
        if (events.type == ALLEGRO_EVENT_KEY_UP && events.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            salida = -2;
        }
        
        if(x > 30 && x < 230 && y > 60 && y < 120) //continuar
        {
            al_draw_bitmap(pausa1, 0, 0, 0);
            if(events.mouse.button & 1)
            {
                salida = 1;
            }
        }
        else if(x > 30 && x < 145 && y > 165 && y < 225) //salir menu principal
        {
            al_draw_bitmap(pausa2, 0, 0, 0);
            if(events.mouse.button & 1)
            {
                salida = -1;
            }
        }
        else
        {
            al_draw_bitmap(pausa, 0, 0, 0);
        }
        
        al_flip_display();
    }
    
    al_destroy_bitmap(pausa);
    al_destroy_bitmap(pausa1);
    al_destroy_bitmap(pausa2);
    al_destroy_bitmap(cursorimagen);
    
    return salida;
}

// tira 1 si se apreta juego nuevo, -1 si quiere salir
int menu(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_DISPLAY *display)
{
    ALLEGRO_BITMAP * cursorimagen = al_load_bitmap("cursor.jpg"); 
    
    ALLEGRO_MOUSE_CURSOR * cursor = al_create_mouse_cursor(cursorimagen, 20, 20);
    
    ALLEGRO_FONT *font = al_load_font("font.ttf", 45, 0);
    
    int salida = 0;
    
    ALLEGRO_BITMAP *menu = al_load_bitmap("nuevomenu.png");
    
    while (!salida)
    {
        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue, &events);
        
        al_clear_to_color(al_map_rgb(211, 211, 211));
        int x, y;
        
        if (events.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            x = events.mouse.x;
            y = events.mouse.y;
        }
        
        if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            salida = -1;
        }
        
        al_draw_bitmap(menu, 100, 100, 0);
        
        
        if(x >= 229 && y >= 305 && x <= 576 && y <=356)
        {
            al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W / 2, 300, ALLEGRO_ALIGN_CENTER, "New Game");
            if(events.mouse.button & 1)
            {
                play_coin();
                salida = 1;
            }
        }
        else
        {
            al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 300, ALLEGRO_ALIGN_CENTER, "New Game");
        }
        
        if(x >= 341 && y >= 409 && x <= 467 && y <= 456)
        {
            al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W / 2, 400, ALLEGRO_ALIGN_CENTER, "Exit");
            if(events.mouse.button & 1)
            {
                salida = -1;
            }
        }
        else
        {
            al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 400, ALLEGRO_ALIGN_CENTER, "Exit");
        }
        
        al_flip_display();
    }
    
    al_destroy_bitmap(menu);
    al_destroy_font(font);
    al_destroy_bitmap(cursorimagen);
    
    return salida;
}


//resetea el juego, recibe punteros a posicion d ela rana, game_runnign que controla el loop general del juego, la matriz inciial y puntero a las posiciones de los vehiculos
void reset_game(int *redraw, int *frog_x, int *frog_y, char *keys, int *game_running, uint16_t *matriz, Vehicule_Positions *Positions)
{
    Positions->Game_State = 1;
    *game_running = 1;
    
    *frog_x = 360;
    *frog_y = 835;
    
    for(int i = 0; i < 4; i++)
    {
        keys[i] = 0;
    }
    
    *redraw = 1;
    
    *Positions = Read_Decimal_Gameboard(matriz);
    reset_courses();
    reset_lane_tracking(0);
    
    reset_score();
    reset_lives();
}