/*
 * File:   main.c
 * Author: 20185315
 *
 * Created on 10 de Março de 2021, 16:08
 */


#include <xc.h>
#include "config.h"
#include "delay.h"
#include "botoes.h"
#include "display7seg.h"
#include "Semaforo.h"

void main(void) 
{
    char estado = 0;
    int cont = 0;
    semaforo_init();
    disp7seg_init();
    botao_init();
    
    while(1)
    {
        switch (estado)
        {
            case 0:
                    disp7seg(17);
                    verde();
                    vermelho_ped();
                    
                    if( botao_ped() == 1 )
                        estado=1;
                    
                    break;
            case 1:
                    cont = 3;
                    if( botao_ped() == 0 )
                        estado = 2;
                    
                    break;
            case 2:
                   disp7seg(cont);
                   delay(1000);
                   cont--;
                   if(cont == 0)
                   {
                       disp7seg(0);
                       delay(1000);
                       cont = 3;
                       estado = 3;
                   }
                   else
                       estado = 2;
                   
                   break;
            case 3:
                    amarelo();
                    disp7seg(cont);
                    delay(1000);
                    cont--;
                    
                    if(cont == 0)
                    {
                        disp7seg(0);
                        delay(1000);
                        cont = 4;
                        estado = 4;
                    }
                    else
                        estado = 3;
                    
                    break;
            case 4:
                    vermelho();
                    verde_ped();
                    disp7seg(cont);
                    delay(1000);
                    cont--;
                    
                    if(cont == 0)
                    {
                        disp7seg(0);
                        delay(1000);
                        estado = 0;
                    }
                    else 
                        estado = 4;
                    
                    break;
        }
    }
}
