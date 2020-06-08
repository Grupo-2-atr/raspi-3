#include <stdio.h>
#include <stdlib.h>
#include "port.h"
#include <unistd.h>

// Microsegundos a milisegundos
#define USEC2MS(n) ((n)*1000)

char D0[] = "17";
char D1[] = "4";
char D2[] = "18";
char D3[] = "23";
char D4[] = "24";
char D5[] = "25";
char D6[] = "22";
char D7[] = "27";

//Esta funcion se encarga de imprimir el puerto
void print_port(void);

char* leds(int bit);

void export_p(char * a);
void unexport_p(char * a);
void led_on_off(char * a, char * on);

int main(void) {
    //Zona de variables
    char c;
    int bit, n;

	for (n = 7; n >= 0; --n)
	{
		export_p(leds(n));
	}
	
    //Esto se repetira siempre que no se ingrese una 'q', en ese caso terminara el programa
    do {
        c = getchar();
        switch (c) {
                //Si se recibe una 't', se debe cambiar de estado todas las LED
            case 't':
            {
                maskToggle('a', 0xFF);
                print_port();
                break;
            }

                //Si se recibe una 'c', se debe apagar todas las LED
            case 'c':
            {
                maskOff('a', 0xFF);
                print_port();
                break;
            }

                //Si se recibe una 's', se debe encender todas las LED	
            case 's':
            {
                maskOn('a', 0xFF);
                print_port();
                break;
            }

                //Si se recibe un numero (del 0 al 7) se debe encender esa LED
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            {
                bit=((int)c)-48;
                bitSet('a', bit);
                print_port();
                break;
            }

                //Mientras haya espacios o enter o en el caso de la 'q' el programa no hace nada
            case '\n':
            case ' ':
            case 'q':
            {
                break;
            }

                //Si se recibe cualquier cosa distinta a los casos anteriores, es un caracter invalido	
            default:
            {
                printf("Caracter inválido.\n");
                break;
            }
        }
    } while (c != 'q');

	for (n = 7; n >= 0; --n)
	{
		unexport_p(leds(n));
	}
    return 0;
}

//Esta función se encarga de imprimir el puerto	

void print_port(void) {
    //Zona de variables
    int n;

    //Imprime desde el b7 hasta el b0
    for (n = 7; n >= 0; --n) 
    {
        if(bitGet('a',n)==1)
        {
        	led_on_off(leds(n), "1");
       	}
       	else
       	{
       		led_on_off(leds(n),"0");
       	}
        printf("%d ", bitGet('a', n));
    }
    printf("\n");
}

char* leds(int bit)
{
    char * pin;
    switch(bit)
    {
        case 0:
        {
            pin=D0;
            break;
        }
        case 1:
        {
            pin=D1;
            break;
        }
        case 2:
        {
            pin=D2;
            break;
        }
        case 3:
        {
            pin=D3;
            break;
        }
        case 4:
        {
            pin=D4;
            break;
        }
        case 5:
        {
            pin=D5;
            break;
        }
        case 6:
        {
            pin=D6;
            break;
        }
        case 7:
        {
            pin=D7;
            break;
        }
    }
    return pin;
}

void export_p(char * a) {
    FILE * handle_pins;
    int pin;
    if ((handle_pins = fopen("/sys/class/gpio/export", "w")) == NULL) {
        printf("Cannot open EXPORT File. Try again later.\n");
        exit(1);
    }
    pin = fputs(a, handle_pins);

    if (pin == -1) {
        printf("Cannot EXPORT PIN . Try again later.\n");
        exit(1);
    } else
        printf("EXPORT File opened succesfully\n");
    fclose(handle_pins);
            
	/*// Delay de 100 ms
	usleep(USEC2MS(100));*/
}

void unexport_p(char * a) {
    FILE * handle_pins;
    int pin;
    if ((handle_pins = fopen("/sys/class/gpio/unexport", "w")) == NULL) {
        printf("Cannot open UNEXPORT File. Try again later.\n");
        exit(1);
    }

    pin = fputs(a, handle_pins);

    if (pin == -1) {
        printf("Cannot UNEXPORT PIN . Try again later.\n");
        exit(1);
    } else
        printf("UNEXPORT File opened succesfully\n");
    fclose(handle_pins);
}

void led_on_off(char * a, char * on) {
    FILE * handle_value;
    FILE * handle_direction;
    FILE * handle_low;

    int direction, low, value;
    
   	if(a==D0)
	{
		handle_direction = fopen("/sys/class/gpio/gpio17/direction", "w");
	}
    else if(a==D1)
	{
		handle_direction = fopen("/sys/class/gpio/gpio4/direction", "w");
	}
	else if(a==D2)
	{
		handle_direction = fopen("/sys/class/gpio/gpio18/direction", "w");
	}    
	else if(a==D3)
	{
		handle_direction = fopen("/sys/class/gpio/gpio23/direction", "w");
	}
	else if(a==D4)
	{
		handle_direction = fopen("/sys/class/gpio/gpio24/direction", "w");
	}
	else if(a==D5)
	{
		handle_direction = fopen("/sys/class/gpio/gpio25/direction", "w");
	}
	else if(a==D6)
	{
		handle_direction = fopen("/sys/class/gpio/gpio22/direction", "w");
	}
	else if(a==D7)
	{
		handle_direction = fopen("/sys/class/gpio/gpio27/direction", "w");
	}    

    if (handle_direction == NULL) {
        printf("Cannot open DIRECTION File. Try again later.\n");
        exit(1);
    }
    if ((direction = fputs("out", handle_direction)) == -1) {
        printf("Cannot open DIRECTION pin. Try again later.\n");
        exit(1);
    }

	fclose(handle_direction);
	
	if(a==D0)
	{
		handle_low = fopen("/sys/class/gpio/gpio17/active_low", "w");
	}
    else if(a==D1)
	{
		handle_low = fopen("/sys/class/gpio/gpio4/active_low", "w");
	}
	else if(a==D2)
	{
		handle_low = fopen("/sys/class/gpio/gpio18/active_low", "w");
	}    
	else if(a==D3)
	{
		handle_low = fopen("/sys/class/gpio/gpio23/active_low", "w");
	}
	else if(a==D4)
	{
		handle_low = fopen("/sys/class/gpio/gpio24/active_low", "w");
	}
	else if(a==D5)
	{
		handle_low = fopen("/sys/class/gpio/gpio25/active_low", "w");
	}
	else if(a==D6)
	{
		handle_low = fopen("/sys/class/gpio/gpio22/active_low", "w");
	}
	else if(a==D7)
	{
		handle_low = fopen("/sys/class/gpio/gpio27/active_low", "w");
	}
	
    if (handle_low == NULL) {
        printf("Cannot open ACTIVE_LOW File. Try again later.\n");
        exit(1);
    }
    if ((low = fputs("0", handle_low)) == -1) {
        printf("Cannot open ACTIVE_LOW pin. Try again later.\n");
        exit(1);
    }
	
	fclose(handle_low);
	
	if(a==D0)
	{
		handle_value = fopen("/sys/class/gpio/gpio17/value", "w");
	}
    else if(a==D1)
	{
		handle_value = fopen("/sys/class/gpio/gpio4/value", "w");
	}
	else if(a==D2)
	{
		handle_value = fopen("/sys/class/gpio/gpio18/value", "w");
	}    
	else if(a==D3)
	{
		handle_value = fopen("/sys/class/gpio/gpio23/value", "w");
	}
	else if(a==D4)
	{
		handle_value = fopen("/sys/class/gpio/gpio24/value", "w");
	}
	else if(a==D5)
	{
		handle_value = fopen("/sys/class/gpio/gpio25/value", "w");
	}
	else if(a==D6)
	{
		handle_value = fopen("/sys/class/gpio/gpio22/value", "w");
	}
	else if(a==D7)
	{
		handle_value = fopen("/sys/class/gpio/gpio27/value", "w");
	}
	
    if (handle_value == NULL) {
        printf("Cannot open VALUE File. Try again later.\n");
        exit(1);
    }
    if ((value = fputs(on, handle_value)) == -1) {
        printf("Cannot open VALUE pin. Try again later.\n");
        exit(1);
    }

    fclose(handle_value);
}

