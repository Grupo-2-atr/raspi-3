/*******************************************************************************
* port.h																	   *
* Este archivo contiene lo necesario para poder utilizar port.c 			   *
* Grupo 2																	   *							
*******************************************************************************/

#ifndef _PORT_H_
#define _PORT_H_

#include <stdint.h>

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
typedef struct
{
        uint8_t b;
        uint8_t a; 
} ports_t;

typedef union
{
	uint16_t d;    
	ports_t ports; 
}PORT;

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
/* Funcion bitSet
Se encarga de encender (poner en 1) un bit.
Esta funcion recibe como parametro un char que indica el puerto que se desea 
modificar, y un int con el numero de bit que desea modificar.*/ 
void bitSet(char port, int bit);

/* Funcion bitClr
Se encarga de apagar (poner en 0) un bit.
Esta funcion recibe como parametro un char que indica el puerto que se desea 
modificar, y un int con el numero de bit que desea modificar.*/ 
void bitClr(char port, int bit);

/* Funcion bitGet
Se encarga de averiguar el valor de un bit.
Esta funcion recibe como parametro un char que indica el puerto al que se desea 
ingresar, y un int con el numero de bit que desea saber.
Devuelve el numero que contiene, si la funcion es invocada con un puerto 
inexistente se devuelve un -1.*/ 
int bitGet(char port, int bit);

/* Funcion bitToggle
Se encarga de poner un bit en su estado opuesto.
Esta funcion recibe como parametro un char que indica el puerto que se desea 
modificar, y un int con el numero de bit que desea modificar.*/ 
void bitToggle(char port, int bit);

/* Funcion maskOn
Se encarga de encender (poner en 1) todos los bits que se indiquen en la mascara.
Esta funcion recibe como parametro un char que indica el puerto que se desea 
modificar, y un unsigned int con la mascara.*/ 
void maskOn(char port, unsigned int mask);

/* Funcion maskOff
Se encarga de apagar (poner en 0) todos los bits que se indiquen en la mascara.
Esta funcion recibe como parametro un char que indica el puerto que se desea 
modificar, y un unsigned int con la mascara.*/ 
void maskOff(char port, unsigned int mask);

/* Funcion maskOn
Se encarga de poner todos los bits que indiquen la mascara en su estado opuesto.
Esta funcion recibe como parametro un char que indica el puerto que se desea 
modificar, y un unsigned int con la mascara.*/ 
void maskToggle(char port, unsigned int mask);



/*******************************************************************************
 ******************************************************************************/

#endif // _PORT_H_
