#ifndef HEADER_H
#define HEADER_H



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h> 
#include <pthread.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define FPS 60.0
#define SCREEN_W 800
#define SCREEN_H 920
#define VIDAS 3


extern uint16_t matriz[16];



typedef struct Vehicules
{
    int Flag;
    int Game_State;
    int Speed1;
    int Speed2;
    int Speed3;
    int Speed4;
    
    int Lane1[16];
    int Lane2[16];
    int Lane3[16];
    int Lane4[16];
    int Lane5[16];
    int Lane6[16];
    int Lane7[16];
    int Lane8[16];
    int Lane9[16];
    int Lane10[16];
    int Lane11[16];
    int Lane12[16];
    int Lane13[16];
    
}Vehicule_Positions;


Vehicule_Positions Read_Decimal_Gameboard(uint16_t *Decimal_Gameboard);
int Dibujar_Vehiculos(Vehicule_Positions Positions, int Lane, ALLEGRO_DISPLAY *display);

void Initiate_Threads(void *Info);
void Terminate_Threads(void);
void resume_threads(Vehicule_Positions *Positions);
void pause_threads(Vehicule_Positions *Positions);


int pause_menu(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue);
int menu (ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_DISPLAY *display);
int game_over_screen(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue);
void reset_game(int *redraw, int *frog_x, int *frog_y, char *keys, int *game_running, uint16_t *matriz, Vehicule_Positions *Positions);


void Draw_Top(void);
void Draw_Circles(void);
int draw_gameboard(ALLEGRO_DISPLAY *display);
void draw_frog(ALLEGRO_DISPLAY *display, int frog_x, int frog_y);

void run_game(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_DISPLAY *display, uint16_t *matriz);


void draw_score(void);
void lane_tracking(int frog_y);
void add_points(int points);
int get_score(void);
void reset_score(void);
void reset_lane_tracking(char opt);
void reset_courses(void);
void complete_course(int frog_x);
int * get_completed_courses(void);
int completed_all_courses(void);
int get_difficulty_level(void);
void difficulty_up(void);
void speed_up(Vehicule_Positions *Info);


int Check_Frog(int Frog_x, int Frog_y, Vehicule_Positions Positions);
void substract_lives(int subs);
int get_lives(void);
void draw_lives(void);
void reset_lives(void);

void play_hop(void);
void play_death(void);
void play_complete(void);
void play_coin(void);
void destroy_samples(void);

#endif 