#include "header.h"

//Este modulo contiene todo lo referido al dibujo en pantalla d elos vehiculos

//dibuja los vehiculos, recibe sus posiciones, la linea donde dibuajrlos y el display
int Dibujar_Vehiculos(Vehicule_Positions Positions, int Lane, ALLEGRO_DISPLAY *display)
{
    ALLEGRO_BITMAP *Car; 
    ALLEGRO_BITMAP *Truck;
    
    Car = al_create_bitmap(30, 30);
    
    if(!Car)//protejo en caso de error
    {
        printf("Failed to create Car bitmap!\n");
        return -1;
    }
    
    al_set_target_bitmap(Car);
    al_clear_to_color(al_map_rgb(0, 0, 255));
    
    Truck = al_create_bitmap(80, 30);
    
    if (!Truck)//protejo en caso de error
    {
        printf("Failed to create Truck bitmap!\n");
        return -1;
    }
    
    al_set_target_bitmap(Truck);
    al_clear_to_color(al_map_rgb(255, 0, 0));
            
    al_set_target_bitmap(al_get_backbuffer(display));
    
    //Con esto los dibujo
    switch (Lane){
        case 1:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane1[i] != -111)
                {
                    al_draw_bitmap(Truck, Positions.Lane1[i], 65, 0);
                }    
            }
            break;
        case 2:
            for(int i = 0; i < 16; i++)
            {
                if(Positions.Lane2[i] != -111)
                {
                    al_draw_bitmap(Car, Positions.Lane2[i], 120, 0);
                }
            }       
            break;
        case 3:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane3[i] != -111)
                {
                    al_draw_bitmap(Car, Positions.Lane3[i], 175, 0);
                }    
            }       
            break;
        case 4:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane4[i] != -111)
                {
                    al_draw_bitmap(Truck, Positions.Lane4[i], 230, 0);
                }
            }       
            break;    
        case 5:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane5[i] != -111)
                {
                    al_draw_bitmap(Truck, Positions.Lane5[i], 285, 0);
                }    
            }       
            break;
        case 6:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane6[i] != -111)
                {
                    al_draw_bitmap(Car, Positions.Lane6[i], 340, 0);
                }    
            }       
            break;    
        case 7:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane7[i] != -111)
                {
                    al_draw_bitmap(Car, Positions.Lane7[i], 395, 0);
                   
                } 
            }       
            break;    
        case 8:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane8[i] != -111)
                {
                    al_draw_bitmap(Car, Positions.Lane8[i], 505, 0);
                }    
            }       
            break;   
        case 9:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane9[i] != -111)
                {
                    al_draw_bitmap(Car, Positions.Lane9[i], 560, 0);
                }    
            }       
            break;    
        case 10:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane10[i] != -111)
                {
                    al_draw_bitmap(Car, Positions.Lane10[i], 615, 0);
                }    
            }       
            break; 
        case 11:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane11[i] != -111)
                {
                    al_draw_bitmap(Car, Positions.Lane11[i], 670, 0);
                }    
            }       
            break;    
        case 12:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane12[i] != -111)
                {
                    al_draw_bitmap(Truck, Positions.Lane12[i], 725, 0);
                }  
            }       
            break;    
        case 13:
            for(int i = 0; i < 16; i++)
            {
                if (Positions.Lane13[i] != -111)
                {
                    al_draw_bitmap(Car, Positions.Lane13[i], 780, 0);    
                }      
            }       
            break;    
        default:
            break;
    }
    
    al_destroy_bitmap(Car);
    al_destroy_bitmap(Truck);
}

//Lee y traduce la matriz inicial a una estructura utilizable
Vehicule_Positions Read_Decimal_Gameboard(uint16_t *Decimal_Gameboard)
{
    Vehicule_Positions Cars;
    Cars.Flag = 1;
    Cars.Game_State = 1;
    
    //Esta es la velocidad con la que se mueven los vehiculos
    Cars.Speed1 = 35000;
    Cars.Speed2 = 20000;
    Cars.Speed3 = 25000;
    Cars.Speed4 = 20000;
           
    
    for(int y = 1; y < 8; y++)
    {
        int mask = 32768;   //10000000000000000
        for(int x = 0; x < 16; x++)
        {
            switch (y){
                case 1:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane1[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane1[x] = -111;
                    }
                    break;
                case 2:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane2[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane2[x] = -111;
                    }
                    break;
                case 3:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane3[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane3[x] = -111;
                    }
                    break;
                case 4:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane4[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane4[x] = -111;
                    }
                    break;
                case 5:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane5[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane5[x] = -111;
                    }
                    break;
                case 6:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane6[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane6[x] = -111;
                    }
                    break;
                case 7:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane7[x] = 10 + 50*1;
                    }
                    else
                    {
                        Cars.Lane7[x] = -111;
                    }
                    break;
                default:
                    break;
            }
            mask = mask >> 1;
        }
    }
    
    for (int y = 9; y < 15; y++)
    {
        int mask = 32768;   //10000000000000000
        for(int x = 0; x < 16; x++)
        {
            switch (y){
                case 9:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane8[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane8[x] = -111;
                    }
                    break;
                case 10:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane9[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane9[x] = -111;
                    }
                    break;    
                case 11:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane10[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane10[x] = -111;
                    }
                    break;    
                case 12:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane11[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane11[x] = -111;
                    }
                    break;
                case 13:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane12[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane12[x] = -111;
                    }
                    break;   
                case 14:
                    if((Decimal_Gameboard[y] & mask) != 0)
                    {
                        Cars.Lane13[x] = 10 + 50*x;
                    }
                    else
                    {
                        Cars.Lane13[x] = -111;
                    }
                    break;   
                default:
                    break;
            }
            mask = mask >> 1;
        }
    }

    return Cars;
}


