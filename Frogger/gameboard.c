#include "header.h"


//Dibuja el tablero de juego
int draw_gameboard(ALLEGRO_DISPLAY *display)
{
    ALLEGRO_BITMAP *segmented_lines, *Lanes, *Mid_lane, *Bottom_Lane, *Lane_Detail;
    
    segmented_lines = al_create_bitmap(20, 5);
    Lanes = al_create_bitmap(800, 55);
    Mid_lane = al_create_bitmap(800, 60);
    Bottom_Lane = al_create_bitmap(800, 45);
    Lane_Detail = al_create_bitmap(800, 10);
    
    
    al_clear_to_color(al_map_rgb(211, 211, 211)); //Set Background to gray
    
    if(!segmented_lines)
    {
        printf("Failed to create segmented lines bitmap!\n");
        return -1;
    }
    
    if(!Lanes)
    {
        printf("Failed to create lanes bitmap!\n");
        return -1;
    }
    
    if (!Mid_lane)
    {
        printf("Failed to create Mid Lane bitmap!\n");
        return -1;
    }
    
    if (!Bottom_Lane)
    {
        printf("Failed to create Bottom Lane bitmap!\n");
        return -1;
    }
    
    if (!Lane_Detail)
    {
        printf("Failed to create Lane Detail bitmap\n");
        return -1;
    }
    
    al_set_target_bitmap(segmented_lines);
    al_clear_to_color(al_map_rgb(255, 255, 255));
    
    al_set_target_bitmap(Mid_lane);
    al_clear_to_color(al_map_rgb(148, 0, 211));
    
    al_set_target_bitmap(Lanes);
    al_clear_to_color(al_map_rgb(148,0,211));
    
    al_set_target_bitmap(Bottom_Lane);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    
    al_set_target_bitmap(Lane_Detail);
    al_clear_to_color(al_map_rgb(139,0,139));
    
    
    al_set_target_bitmap(al_get_backbuffer(display)); //Importante setea la pantalla como lugar a dibujar
    
    
    
    
    
    //First 6 lanes
    for (int i = 105; i < 381; i += 55)
    {
        for (int j = 0; j < 801; j += 30)
        {
            al_draw_bitmap(segmented_lines, j, i, 0);
        }
    }
    
    //Second 5 lines
    for (int i = 545; i < 766; i += 55)
    {
        for (int j = 0; j < 801; j += 30)
        {
            al_draw_bitmap(segmented_lines, j, i, 0);
        }
    }
    
    //al_draw_bitmap(Lanes, 0, 0, 0);
    al_draw_bitmap(Mid_lane, 0, 435, 0);
    al_draw_bitmap(Lanes, 0, 820, 0);
    al_draw_bitmap(Lane_Detail, 0, 820, 0);
    al_draw_bitmap(Lane_Detail, 0, 485, 0);
    
    Draw_Circles(); //Draws circles
    Draw_Top(); //Draws Top of the gameboard
    
    al_draw_bitmap(Bottom_Lane, 0, 875, 0);
    draw_score();
    draw_lives();
    
    
    //Dibuja la rana arriba cuando llega a ganar los puntos
    int *courses = get_completed_courses();
    
    for (int i = 0; i < 6; i++)
    {
        if (courses[i])
        {
            switch (i)
            {
                case 0:
                    draw_frog(display, 60, 10);
                    break;
                case 1:
                    draw_frog(display, 210, 10);
                    break;
                case 2:
                    draw_frog(display, 360, 10);
                    break;
                case 3:
                    draw_frog(display, 410, 10);
                    break;
                case 4:
                    draw_frog(display, 560, 10);
                    break;
                case 5:
                    draw_frog(display, 710, 10);
                    break;
                default:
                    break;
            }
        }
    }
    
    
    //destruye bitmaps
    al_destroy_bitmap(Lane_Detail);
    al_destroy_bitmap(Bottom_Lane);
    al_destroy_bitmap(Mid_lane);
    al_destroy_bitmap(segmented_lines);
    al_destroy_bitmap(Lanes);
}

void Draw_Circles(void)
{
    //Dibuja circulos de decoracion en el medio
    for (int j = 0; j < 2 ; j++)
    {
        for (int i = 10; i < 801; i+= 20)
        {
            al_draw_filled_circle(i, 446 + j*30, 3, al_map_rgb(0, 0, 255));
            al_draw_filled_circle(i, 446 + j*30, 2, al_map_rgb(255, 0, 0));
        }
    }
    
    for (int i = 20; i < 781; i += 20 )
    {
        al_draw_filled_circle(i, 461, 3, al_map_rgb(0, 0, 255));
        al_draw_filled_circle(i, 461, 2, al_map_rgb(255, 0, 0));
    }
    
    //Dibuja circuos de decoracion abajo
    for (int j = 0; j < 2 ; j++)
    {
        for (int i = 10; i < 801; i+= 20)
        {
            al_draw_filled_circle(i, 838 + j*30, 3, al_map_rgb(0, 0, 255));
            al_draw_filled_circle(i, 838 + j*30, 2, al_map_rgb(255, 0, 0));
        }
    }
    
    for (int i = 20; i < 781; i += 20 )
    {
        al_draw_filled_circle(i, 853, 3, al_map_rgb(0, 0, 255));
        al_draw_filled_circle(i, 853, 2, al_map_rgb(255, 0, 0));
    }
}

//Dibuja parte de arriab de tablero
void Draw_Top(void)
{
    al_draw_filled_rectangle(0, 0, 800, 9, al_map_rgb(50, 205, 50));
    al_draw_filled_rectangle(0, 0, 50, 55, al_map_rgb(50, 205, 50));
    
    al_draw_filled_rectangle(100, 0, 200, 55, al_map_rgb(50, 205, 50));
    
    al_draw_filled_rectangle(250, 0, 350, 55, al_map_rgb(50, 205, 50));
    
    al_draw_filled_rectangle(450, 0, 550, 55, al_map_rgb(50, 205, 50));
    
    al_draw_filled_rectangle(600, 0, 700, 55, al_map_rgb(50, 205, 50));
    
    al_draw_filled_rectangle(750, 0, 800, 55, al_map_rgb(50, 205, 50));
    
}