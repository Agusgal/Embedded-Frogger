#include "header.h"

uint16_t matriz [16] = {0,18500,5,1,4680,32904,664,2345,0,44367,1,565,1,264,555,0}; //Matriz compatible con rasp que dice donde estan los autos inicialmente 

//teclas
enum MYKEYS 
{
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

//
const int FROG_SIZE = 30;


int main(void)
{
  //se inician y rpotegen los modulos de allegro
  ALLEGRO_EVENT_QUEUE *event_queue = NULL;
  ALLEGRO_DISPLAY *display = NULL;
  ALLEGRO_TIMER *timer;
  
  if(!al_init())//inicio allegro
  {
      printf("Could not initialize Allegro!\n");
      return -1;
  }
  
  
  display = al_create_display(SCREEN_W, SCREEN_H);
  if(!display)//inicio display
  {
      printf("Could not initialize Display!.\n");
      return -1;
  }
  
  event_queue = al_create_event_queue();
  if(!event_queue)//inicio cola de eventos
  {
      printf("Could not initialize event queue!.\n");
      al_destroy_display(display);
      return -1;
  }
  
  timer = al_create_timer(1/FPS);
  if(!timer)//inicio timer IMPORTANTE FUNCIONA  A 60 FPS
  {
      printf("Failed to create timer!\n");
      al_destroy_event_queue(event_queue);
      al_destroy_display(display);
      return -1;
  }
  
  if(!al_install_keyboard())//Inicio teclado
  {
      printf("Failed to initialize the keyboard!\n");
      return -1;
  }
  
  al_install_mouse();
  al_init_image_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  
  
  if(!al_install_audio())//Inicio audio
  {
      printf("failed to initialize audio!\n");
      return -1;
  }
  
  if(!al_init_acodec_addon())//se usa en audio
  {
      printf("failed to initialize audio codecs!\n");
      return -1;
  }
  
  
  if (!al_reserve_samples(4))//reservo espacio para los efectos de sonido
  {
      printf("failed to reserve samples!\n");
      return -1;
  }
  
  //Solo estético, pone nombre a la ventana abierta
  al_set_window_title(display, "Frogger");
  
  //Registro eventos de todo tipo
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_mouse_event_source());
  
  //Comienzo el timer del juego
  al_start_timer(timer);
  
  run_game(event_queue, display, matriz); //empieza el juego

                
  Terminate_Threads();//termino threads
  
  //libero memoria
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);
  al_destroy_timer(timer);
          
    return 0;
}

//funcion general del juego
void run_game(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_DISPLAY *display, uint16_t *matriz)
{
    int enter_menu = 1;//variable que controla si entrar o no en el menu ppal
    int back_to_menu = 0;//variable que controla si entrar nuevamente al menu ppal
    
    int game_running = 1;//variable que controla el loop general del juego
    char key[4] = {0, 0, 0, 0};//teclas
    
    //posicion de la rana
    int frog_x = 360;
    int frog_y = 835;
    
    int redraw = 1;//variable que controla cuando dibujar en pantalla
    
    //punteros a datos que se usan para resetear el juego
    int *frog_xP = &frog_x;
    int *frog_yP = &frog_y;
    int *redrawP = &redraw;
    int *game_runningP = &game_running;
    
    //estructura con datos sobre vehiculos y threads
    Vehicule_Positions Positions = Read_Decimal_Gameboard(matriz);
    Vehicule_Positions *PositionsP = &Positions;
    
  
    Initiate_Threads(PositionsP); //Inicia threads de vehiculos
    pause_threads(PositionsP); //Las pausa para que luego se resuman cuando el jugador comienza el juego
    
    
    while(game_running)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        
        if(enter_menu)
        {
            if(menu(event_queue, display) == -1)//entro al menu ppal
            {
                game_running = 0;
            }
            resume_threads(PositionsP);
            enter_menu = 0;
            back_to_menu = 0;
        }
        
        if(event.type == ALLEGRO_EVENT_TIMER) 
        {
            if(key[KEY_UP] && frog_y >= 50.0) 
            {
                frog_y -= 55.0;
                lane_tracking(frog_y); //anota puntos cuando sube por primera vez a la linea
                play_hop();
                key[KEY_UP] = 0;
            }

            if(key[KEY_DOWN] && frog_y <= SCREEN_H - 45.0 - FROG_SIZE - 50.0) 
            {
               frog_y += 55.0;
               play_hop(); //efecto de salto
               key[KEY_DOWN] = 0;
            }

            if(key[KEY_LEFT] && frog_x >= 50.0) 
            {
               frog_x -= 50.0;
               play_hop();//efecto de salto
               key[KEY_LEFT] = 0;

            }

            if(key[KEY_RIGHT] && frog_x <= SCREEN_W - FROG_SIZE - 50.0) 
            {
               frog_x += 50.0;
               play_hop();//efecto de salto
               key[KEY_RIGHT] = 0;
            }
            
            if (!Check_Frog(frog_x, frog_y, Positions) && get_lives()) //chequeo si la rana murio y si le quedan vidas
            {
                play_death();//efecto de muerte
                frog_x = 360;
                frog_y = 835;
                reset_lane_tracking(0);
            }
            else if(!get_lives())//Si no le quedan vidas...
            {
                play_death();
                Positions.Flag = 0;
                game_running = 0;
                
                int var = game_over_screen(display, event_queue);//pantalla de fin de juego
                
                if (var == 1)//Si quiere seguir jugando...
                {
                    reset_game(redrawP, frog_xP, frog_yP, key, game_runningP, matriz, PositionsP);
                    resume_threads(PositionsP);
                    play_coin();
                }
                else if(var == -1) //Si quiere salir...
                {
                    reset_game(redrawP, frog_xP, frog_yP, key, game_runningP, matriz, PositionsP);
                    enter_menu = 1;
                    back_to_menu = 1;
                }
            }
            
            //Este if detecta que llego arriba y consiguió los puntos sin morir
            if (frog_y == 10)
            {
                complete_course(frog_x);
                play_complete();
                if (completed_all_courses())
                {
                    if ((get_difficulty_level() != 2))
                    {
                        difficulty_up();
                        speed_up(PositionsP);
                    }
                    reset_courses();
                }
                
                frog_x = 360;
                frog_y = 835;
                reset_lane_tracking(1);     
            }
        
            redraw = 1;
        }
        else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //cierra la ventana
        {
            Positions.Flag = 0;
            Positions.Game_State = 0;
            game_running = 0;
        }
        else if(event.type == ALLEGRO_EVENT_KEY_DOWN) //Registra tecla para abajo
        {
         switch(event.keyboard.keycode) 
         {
            case ALLEGRO_KEY_UP:
               key[KEY_UP] = 1;
               break;

            case ALLEGRO_KEY_DOWN:
               key[KEY_DOWN] = 1;
               break;

            case ALLEGRO_KEY_LEFT: 
               key[KEY_LEFT] = 1;
               break;

            case ALLEGRO_KEY_RIGHT:
               key[KEY_RIGHT] = 1;
               break;
         }
        }
        else if(event.type == ALLEGRO_EVENT_KEY_UP) //Registra tecla para arriba
        {
            switch(event.keyboard.keycode) 
            {
               case ALLEGRO_KEY_UP:
                  key[KEY_UP] = 0;
                  break;

               case ALLEGRO_KEY_DOWN:
                  key[KEY_DOWN] = 0;
                  break;

               case ALLEGRO_KEY_LEFT: 
                  key[KEY_LEFT] = 0;
                  break;

               case ALLEGRO_KEY_RIGHT:
                  key[KEY_RIGHT] = 0;
                  break;

               case ALLEGRO_KEY_ESCAPE: //cierra la ventana
                   Positions.Flag = 0;
                   Positions.Game_State = 0;
                   game_running = 0;
                  break;
               
               case ALLEGRO_KEY_ENTER: //pausa el juego
               {    
                  pause_threads(PositionsP);//pausa threads
                  
                  int opt = pause_menu(display, event_queue);
                    
                  if (opt == -1) //Si quiere volver al menu ppal...
                  {
                      reset_game(redrawP, frog_xP, frog_yP, key, game_runningP, matriz, PositionsP);
                      enter_menu = 1;
                      back_to_menu = 1;
                      
                  }
                  else if(opt == -2)//Si quiere cerrar el juego...
                  {
                    Positions.Flag = 0;
                    game_running = 0;
                  }
                  else
                  {
                      resume_threads(PositionsP);//Si no entra a ninguna de las anteriores resume el juego
                  }
                  break;
               }
            }
        }
        
        //Aca entra cuando hay que dibujar en pantalla TODO
        if(redraw && al_is_event_queue_empty(event_queue) && game_running && !back_to_menu) 
        {
           
           
           redraw = 0;//vuelve a 0 la variable
         
           draw_gameboard(display);//dibujo tablero
           
           for (int i = 0; i < 14; i++) //dibuja vehiculos
           {
               Dibujar_Vehiculos(Positions, i, display);
           }
          
           draw_frog(display, frog_x, frog_y);//dibuja rana
           
           
           al_flip_display();//da vuelta el display

        }
    }
}
