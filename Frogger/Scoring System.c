#include "header.h"

//este modulo controla el sistema de puntuacion, hay variables estaticas y funciones para accede a ellas

static int score = 0;//el puntaje total

//este arreglo sirve para detecatr que estuvo en una linea y que no se sume dos veces el puntaje
static int was_in_lane[14][2] = {{65, 0}, {120, 0}, {175, 0}, {230, 0}, {285, 0}, {340, 0}, {395, 0}, {450, 0}, {505, 0}, {560, 0}, {615, 0}, {670, 0}, {725, 0}, {780, 0}};

//parecido al anterior, solo que detecta cuantas veces llego hasta arriba
static int completed_courses[6] = {0, 0, 0, 0, 0, 0};

//nivel de dificultad de la partida, comienza en 0 y su maximo es 2
static int difficulty_level = 0;

void add_points(int points)//agrega puntos
{
    score += points;
}

int get_score(void)//retorna los puntos totales
{
    return score;
}

void reset_score(void)//resetea el score
{
    score = 0;
}

void lane_tracking(int frog_y)//agrega puntos si avanzo una calle para arriba 
{
    for (int i = 0; i < 14; i++)
    {
        if ((was_in_lane[i][0] == frog_y) && !was_in_lane[i][1])
        {
            was_in_lane[i][1] = 1;
            add_points(10);
        }
    }
}

void reset_lane_tracking(char opt)//resetea el arreglo was_in_lane
{
    if (opt)
    {
        add_points(100);
    }
    
    for (int i = 0; i < 14; i++)
    {
        was_in_lane[i][1] = 0;
    }
}


void draw_score(void)//dibuja el score en pantalla
{
    ALLEGRO_FONT *font = al_load_font("font.ttf", 18, 0);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 10, 885, ALLEGRO_ALIGN_LEFT, "Score: %d", get_score());
    
    al_destroy_font(font);
}


void complete_course(int frog_x)//completa un curso, es decir si llego arriba
{
    if (frog_x == 60)
    {
        completed_courses[0] = 1;
    }
    else if (frog_x == 210)
    {
        completed_courses[1] = 1;
    }
    else if (frog_x == 360)
    {
        completed_courses[2] = 1;
    }
    else if (frog_x == 410)
    {
        completed_courses[3] = 1;
    }
    else if(frog_x == 560)
    {
        completed_courses[4] = 1;
    }
    else if (frog_x == 710)
    {
        completed_courses[5] = 1;
    }
}

void reset_courses(void)//resetea el arreglo completed_courses
{
    for (int i = 0; i < 6; i++)
    {
        completed_courses[i] = 0;
        add_points(250);
    }
}

int * get_completed_courses(void)//retorna el arreglo completed_courses
{
    return completed_courses;
}

int completed_all_courses(void)//verifica si completo todos los espacios arriba
{
    int counter = 0;
    for (int i = 0; i < 6; i++)
    {
        if (completed_courses[i])
        {
            counter += 1;
        }
    }
    
    if (counter == 6)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int get_difficulty_level(void)//retorna el nivel de dificultad
{
    return difficulty_level;
}

void difficulty_up(void)//aumenta la dificultad
{
    difficulty_level += 1;
}

void speed_up(Vehicule_Positions *Info)//aumenta la velocidad
{
    Info->Speed1 -= difficulty_level*5000;
    Info->Speed2 -= difficulty_level*5000;
    Info->Speed3 -= difficulty_level*5000;
    Info->Speed4 -= difficulty_level*5000;   
}