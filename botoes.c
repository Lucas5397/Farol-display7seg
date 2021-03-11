/*
 * File:   botao.c
 * Author: 20185315
 *
 * Created on 5 de Março de 2021, 14:20
 */


#include <xc.h>

void botao_init (void)  
{
    TRISDbits.TRISD0 = 1;
}

int botao_ped (void)
{
    return (PORTDbits.RD0);
}
