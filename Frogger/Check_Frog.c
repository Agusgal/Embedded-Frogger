#include "header.h"

//En este modulo esta todo lo relacionado a las vidas, se creo la variable vidas estática a este archivo y funciones para modificarla

static int vidas = VIDAS; 

void substract_lives(int subs) //resta una cantidad de vidas
{
    vidas -= subs;
}

int get_lives(void)//devuelve cuantas vidas hay
{
    return vidas;
}

void draw_lives(void)//dibuja las vidas en el tablero
{
    ALLEGRO_FONT *font = al_load_font("font.ttf", 18, 0);
    al_draw_textf(font, al_map_rgb(255, 255, 255), 790, 885, ALLEGRO_ALIGN_RIGHT, "Vidas: %d", get_lives());
    
    al_destroy_font(font);
}

void reset_lives(void)//resetea las vidas al valor inicial
{
    vidas = VIDAS;
}


//chequea si la rana murio, recibe la posicion en el tablero, y las psoiciones de los vehiculos y devuelve 0 si murio y 1 si sigue viva
int Check_Frog(int Frog_x, int Frog_y, Vehicule_Positions Positions) 
{
    
    //Basicamente se mete a la posicion d elos autos y compara con la posicion de la rana, sustrae una vida si resulta que la rana se movio hacia un auto y viceversa
    for (int i = 0; i < 16; i++)//Hay un for para cada Linea, ya que cada una es un atributo diferente dentro de la estructura recibida
    {
        if ((Frog_x <= Positions.Lane1[i] + 80 && Frog_x >= Positions.Lane1[i] && Frog_y == 65) || (Frog_x + 30 <= Positions.Lane1[i] + 80 && Frog_x + 30 >= Positions.Lane1[i] && Frog_y == 65))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane2[i] + 30 && Frog_x >= Positions.Lane2[i] && Frog_y == 120) || (Frog_x + 30 <= Positions.Lane2[i] + 30 && Frog_x +30 >= Positions.Lane2[i] && Frog_y == 120))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane3[i] + 30 && Frog_x >= Positions.Lane3[i] && Frog_y == 175) || (Frog_x + 30 <= Positions.Lane3[i] + 30 && Frog_x +30 >= Positions.Lane3[i] && Frog_y == 175))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane4[i] + 80 && Frog_x >= Positions.Lane4[i] && Frog_y == 230) || (Frog_x + 30 <= Positions.Lane4[i] + 80 && Frog_x +30 >= Positions.Lane4[i] && Frog_y == 230))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane5[i] + 80 && Frog_x >= Positions.Lane5[i] && Frog_y == 285) || (Frog_x + 30 <= Positions.Lane5[i] + 80 && Frog_x +30 >= Positions.Lane5[i] && Frog_y == 285))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane6[i] + 30 && Frog_x >= Positions.Lane6[i] && Frog_y == 340) || (Frog_x + 30 <= Positions.Lane6[i] + 30 && Frog_x +30 >= Positions.Lane6[i] && Frog_y == 340))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane7[i] + 30 && Frog_x >= Positions.Lane7[i] && Frog_y == 395) || (Frog_x + 30 <= Positions.Lane7[i] + 30 && Frog_x +30 >= Positions.Lane7[i] && Frog_y == 395))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane8[i] + 30 && Frog_x >= Positions.Lane8[i] && Frog_y == 505) || (Frog_x + 30 <= Positions.Lane8[i] + 30 && Frog_x +30 >= Positions.Lane8[i] && Frog_y == 505))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane9[i] + 30 && Frog_x >= Positions.Lane9[i] && Frog_y == 560) || (Frog_x + 30 <= Positions.Lane9[i] + 30 && Frog_x +30 >= Positions.Lane9[i] && Frog_y == 560))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane10[i] + 30 && Frog_x >= Positions.Lane10[i] && Frog_y == 615) || (Frog_x + 30 <= Positions.Lane10[i] + 30 && Frog_x +30 >= Positions.Lane10[i] && Frog_y == 615))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane11[i] + 30 && Frog_x >= Positions.Lane11[i] && Frog_y == 670) || (Frog_x + 30 <= Positions.Lane11[i] + 30 && Frog_x +30 >= Positions.Lane11[i] && Frog_y == 670))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane12[i] + 80 && Frog_x >= Positions.Lane12[i] && Frog_y == 725) || (Frog_x + 30 <= Positions.Lane12[i] + 80 && Frog_x +30 >= Positions.Lane12[i] && Frog_y == 725))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    for (int i = 0; i < 16; i++)
    {
        if ((Frog_x <= Positions.Lane13[i] + 30 && Frog_x >= Positions.Lane13[i] && Frog_y == 780) || (Frog_x + 30 <= Positions.Lane13[i] + 30 && Frog_x +30 >= Positions.Lane13[i] && Frog_y == 780))
        {
            substract_lives(1);
            return 0;
        }
    }
    
    //Chequea muerte por chocar con carril superior
    if (Frog_y == 10 && (Frog_x == 10 || Frog_x == 110 || Frog_x == 160 || Frog_x == 260 || Frog_x == 310 || Frog_x == 460 || Frog_x == 510 || Frog_x == 610 || Frog_x == 660 || Frog_x == 760))
    {
        substract_lives(1);
        return 0;
    }
    
    int *courses = get_completed_courses();
    
    for (int i = 0; i < 6; i++)
    {
        if (courses[i])
        {
            switch (i)
            {
                case 0:
                    if (Frog_y == 10 && Frog_x == 60)
                    {
                        substract_lives(1);
                        return 0;
                    }
                    break;
                case 1:
                    if (Frog_y == 10 && Frog_x == 210)
                    {
                        substract_lives(1);
                        return 0;
                    }
                    break;
                case 2:
                    if (Frog_y == 10 && Frog_x == 360)
                    {
                        substract_lives(1);
                        return 0;
                    }
                    break;
                case 3:
                    if (Frog_y == 10 && Frog_x == 410)
                    {
                        substract_lives(1);
                        return 0;
                    }
                    break;
                case 4:
                    if (Frog_y == 10 && Frog_x == 560)
                    {
                        substract_lives(1);
                        return 0;
                    }
                    break;
                case 5:
                    if (Frog_y == 10 && Frog_x == 710)
                    {
                        substract_lives(1);
                        return 0;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    
    return 1;
}