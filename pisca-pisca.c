/* Teste para preparar o ambiente e programar PCIs
 * 
 * Descrição
 * Ao ligar o circuito o led segue piscando. Enquanto o botão permancer 
 * pressionado o led piscara mais rapidamente.
 * 
 * Created on 28 de Dezembro de 2021, 22:05
 * Teste Pisca - Pisca
 * Author: Natan
 * (Linux) MAPLAB X IDE-v5.50 - Compilador XC8-v1.36
 */

// Configurações do PIC16F628A que usei
#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = OFF         // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 4000000      // Frequencia 4MHz interna do PIC 16F628A

//Função principal
void main(void){
    TRISBbits.TRISB0 = 0;      //Pino b0 configurado como (output)
    TRISBbits.TRISB3 = 1;      //Pino b3 configurado como (output)
    while(1){
        //Enquanto o botão não estiver pressionado
        PORTBbits.RB0 = 1;      //Liga o led
        __delay_ms(1000);       //Delay de 1000 ms
        PORTBbits.RB0 = 0;      //Desliga o led
        __delay_ms(1000);       //Delay de 1000 ms
        while(PORTBbits.RB3 == 1){
        //Enquanto o botão estiver pressionado
            PORTBbits.RB0 = 1;      //Liga o led
            __delay_ms(100);        //Delay de 1000 ms
            PORTBbits.RB0 = 0;      //Desliga o led
            __delay_ms(100);        //Delay de 1000 ms
        }    
    }
}
//Nota: Gravei no PCI o equivalente .hex deste cÓdigo compilado no MPLABX IDE + XC8
