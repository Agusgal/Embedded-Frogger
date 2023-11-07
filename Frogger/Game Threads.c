#include "header.h"

//Modulo de Threads, aca se especifica que hace cada una, se usan para controlar los vehiculos ya que se mueven con diferentes velocidades

pthread_t t1,t2,t3,t4;

void *thread1(void *Info)  //Esta controla a los camiones
{
    while (((Vehicule_Positions*)Info)->Game_State)//Loop de juego, mientars siga el juego sigue
    {    
        
        while (((Vehicule_Positions*)Info)->Flag)//Loop de pausa mientras siga se mueven los autos, en cuanto no se quedan parados
        {
            usleep (((Vehicule_Positions*)Info)->Speed1);//usleep controla el delay para aparentar que los vehiculos se mueven a diferentes velocidades
            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane1[i] != -111 && ((Vehicule_Positions*)Info)->Lane1[i] == -80)//Con esto detecto si el vehiculo llego a la horilla de la pantalla y lo muevo al otro aldo
                {
                    ((Vehicule_Positions*)Info)->Lane1[i] = SCREEN_W;
                }
                else if(((Vehicule_Positions*)Info)->Lane1[i] != -111)//Muevo el vehiculo
                {
                    ((Vehicule_Positions*)Info)->Lane1[i] -= 1;
                }
            }
            
            //Se repiten los comentarios anteriores para las distintas lineas
            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane4[i] != -111 && ((Vehicule_Positions*)Info)->Lane4[i] == -80)
                {
                    ((Vehicule_Positions*)Info)->Lane4[i] = SCREEN_W;
                }
                else if(((Vehicule_Positions*)Info)->Lane4[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane4[i] -= 1;
                }
            }

            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane5[i] != -111 && ((Vehicule_Positions*)Info)->Lane5[i] == -80)
                {
                    ((Vehicule_Positions*)Info)->Lane5[i] = SCREEN_W;
                }
                else if(((Vehicule_Positions*)Info)->Lane5[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane5[i] -= 1;
                }
            }

             for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane12[i] != -111 && ((Vehicule_Positions*)Info)->Lane12[i] == -80)
                {
                    ((Vehicule_Positions*)Info)->Lane12[i] = SCREEN_W;
                }
                else if(((Vehicule_Positions*)Info)->Lane12[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane12[i] -= 1;
                }
            }
        }
    }    
}

void *thread2(void *Info)  //controla los carriles 13, 11 y 3
{
    while (((Vehicule_Positions*)Info)->Game_State)
    {
        while (((Vehicule_Positions*)Info)->Flag)
        {
            usleep (((Vehicule_Positions*)Info)->Speed2);

            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane13[i] != -111 && ((Vehicule_Positions*)Info)->Lane13[i] == SCREEN_W)
                {
                    ((Vehicule_Positions*)Info)->Lane13[i] = -50;
                }
                else if(((Vehicule_Positions*)Info)->Lane13[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane13[i] += 1;
                }
            }

            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane11[i] != -111 && ((Vehicule_Positions*)Info)->Lane11[i] == SCREEN_W)
                {
                    ((Vehicule_Positions*)Info)->Lane11[i] = -50;
                }
                else if(((Vehicule_Positions*)Info)->Lane11[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane11[i] += 1;
                }
            }
            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane3[i] != -111 && ((Vehicule_Positions*)Info)->Lane3[i] == SCREEN_W)
                {
                    ((Vehicule_Positions*)Info)->Lane3[i] = -50;
                }
                else if(((Vehicule_Positions*)Info)->Lane3[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane3[i] += 1;
                }
            }
        }
    }    
}

void *thread3(void *Info)  //controla los carriles 3, 7 y 2
{
    while(((Vehicule_Positions*)Info)->Game_State)
    {
        while (((Vehicule_Positions*)Info)->Flag)
        {
            usleep (((Vehicule_Positions*)Info)->Speed3);
            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane7[i] != -111 && ((Vehicule_Positions*)Info)->Lane7[i] == SCREEN_W)
                {
                    ((Vehicule_Positions*)Info)->Lane7[i] = -50;
                }
                else if(((Vehicule_Positions*)Info)->Lane7[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane7[i] += 1;
                }
            }

            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane2[i] != -111 && ((Vehicule_Positions*)Info)->Lane2[i] == SCREEN_W)
                {
                    ((Vehicule_Positions*)Info)->Lane2[i] = -50;
                }
                else if(((Vehicule_Positions*)Info)->Lane2[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane2[i] += 1;
                }
            }

            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane10[i] != -111 && ((Vehicule_Positions*)Info)->Lane10[i] == SCREEN_W)
                {
                    ((Vehicule_Positions*)Info)->Lane10[i] = -50;
                }
                else if(((Vehicule_Positions*)Info)->Lane10[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane10[i] += 1;
                }
            }
        }
    }    
}

void *thread4(void *Info)  //controla los carriles 6, 8 y 9
{
    while (((Vehicule_Positions*)Info)->Game_State)
    {
        while (((Vehicule_Positions*)Info)->Flag)
        {
            usleep (((Vehicule_Positions*)Info)->Speed4);

            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane6[i] != -111 && ((Vehicule_Positions*)Info)->Lane6[i] == -50)
                {
                    ((Vehicule_Positions*)Info)->Lane6[i] = SCREEN_W;
                }
                else if(((Vehicule_Positions*)Info)->Lane6[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane6[i] -= 1;
                }
            } 

            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane8[i] != -111 && ((Vehicule_Positions*)Info)->Lane8[i] == -50)
                {
                    ((Vehicule_Positions*)Info)->Lane8[i] = SCREEN_W;
                }
                else if(((Vehicule_Positions*)Info)->Lane8[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane8[i] -= 1;
                }
            }
            for (int i = 0; i < 16; i++)
            {
                if (((Vehicule_Positions*)Info)->Lane9[i] != -111 && ((Vehicule_Positions*)Info)->Lane9[i] == -50)
                {
                    ((Vehicule_Positions*)Info)->Lane9[i] = SCREEN_W;
                }
                else if(((Vehicule_Positions*)Info)->Lane9[i] != -111)
                {
                    ((Vehicule_Positions*)Info)->Lane9[i] -= 1;
                }
            }
        }
    }    
}

void pause_threads(Vehicule_Positions *Positions)//pausa las threads
{
    Positions->Flag = 0;
}

void resume_threads(Vehicule_Positions *Positions)//reanuda las threads
{
    Positions->Flag = 1;
}

void Initiate_Threads(void *Positions)//inicia los hilos de procesamiento
{
    pthread_create(&t1, 0, thread1, Positions);
    pthread_create(&t2, 0, thread2, Positions);
    pthread_create(&t3, 0, thread3, Positions);
    pthread_create(&t4, 0, thread4, Positions);
}

void Terminate_Threads(void)//termina los threads
{
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    pthread_join(thread3, 0);
    pthread_join(thread4, 0);
}

 