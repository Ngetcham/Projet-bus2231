#include <msp430.h> 
#include <ADC.h>

/**
 * main.c
 */
int main(void)
{
    ADC_init();
       WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
       P1SEL=0;
       P1DIR|= BIT6;

       int valeur=0;//valeur décimale retournée par le capteur infrarouge
       P1DIR &=~ BIT3; // mettre le capteur infrarouge en entrée
       //P1REN|=BIT5;
       //P1OUT|=BIT5;
       while(1){

                   //capteur infrarouge
                   ADC_Demarrer_conversion(0x3);
                   valeur = ADC_Lire_resultat();


       if ( valeur> 400){
           P1OUT|= BIT6;
       }
       else{
           P1OUT &=~BIT6;
       }
   }
       return 0;
}
