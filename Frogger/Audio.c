#include "header.h"

ALLEGRO_SAMPLE *hop, *muerte, *complete, *coin; //crea samples para los efectos de sonido

void play_hop(void)//reproduce sonido de salto
{
    hop = al_load_sample("Hop.wav");
    al_play_sample(hop, 1.0, 0, 1.1, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void play_death(void)//reproduce sonido de muerte
{
    muerte = al_load_sample("Muerte.wav");
    al_play_sample(muerte, 1.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}


void play_complete(void)//reporduce sonido de llegar arriba
{
    complete = al_load_sample("Complete_level.wav");
    al_play_sample(complete, 1.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    
}

void play_coin(void)//reproduce sonido de inicio de juego
{
    coin = al_load_sample("Coin_in.wav");
    al_play_sample(coin, 1.0, 0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    
}

void destroy_samples(void)//destruye los samples de sonido
{
    al_destroy_sample(hop);
    al_destroy_sample(muerte);
    al_destroy_sample(complete);
    al_destroy_sample(coin);
}

