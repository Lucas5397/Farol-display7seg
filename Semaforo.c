/*
 * File:   semaforo.c
 * Author: 20185315
 *
 * Created on 5 de Fevereiro de 2021, 17:35
 */


#include <xc.h>
#include "config.h"
#include "delay.h"  

void semaforo_init (void)
{
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD0 = 1;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD2 = 0; 
    TRISDbits.TRISD3 = 0;
    PORTDbits.RD2 = 0;
    PORTDbits.RD7 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD5 = 0;
    PORTDbits.RD3 = 0;       
}
void verde (void)
{
     PORTDbits.RD6 = 0;
     PORTDbits.RD7 = 0;  
     PORTDbits.RD5 = 1;
}
void amarelo (void)
{
    PORTDbits.RD5 = 0;
    PORTDbits.RD7 = 0;  
    PORTDbits.RD6 = 1;
}
void vermelho (void)
{
    PORTDbits.RD5 = 0;
    PORTDbits.RD6 = 0;  
    PORTDbits.RD7 = 1;
}
void verde_ped (void)
{
    PORTDbits.RD3 = 0;
    PORTDbits.RD2 = 1;
}
void vermelho_ped (void)
{
    PORTDbits.RD2 = 0;
    PORTDbits.RD3 = 1;
}

    
   
