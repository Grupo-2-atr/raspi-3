/*******************************************************************************
*	port.c 																	   *
*	Este archivo contiene funciones que permiten trabajar con los puertos, 	   *
*	tanto para modificarlos como para leerlos.								   *
*	Grupo 2.																   *
*******************************************************************************/


#include <stdio.h>
#include "port.h"

#define BITSETMASK 1

#ifdef CORRIENDO_TEST //solo si estoy corriendo test
PORT portd;

#else
static PORT portd;

#endif

//Esta funcion se encarga de encender un bit de un puerto.
void bitSet(char port, int bit)
{
	switch (port) 
    {   
    	//Si se recibe una 'a' se desea modificar el puerto A                                       
    	case 'a':
        {
        	//Si el bit esta entre 0 y 7, se enciende ese bit
        	if((0<=bit)&&(bit<=7))
            {
            	portd.ports.a=((BITSETMASK<<bit)|portd.ports.a);
            }
            
            //Si el bit no esta entre 0 y 7, no se realiza ningun cambio
            else
            {
            	printf("No existe el bit %d en el puerto a.\n",bit);
            }                      
            break;
		}
		 
		//Si se recibe una 'b' se desea modificar el puerto B        
		case 'b':
        {
        	//Si el bit esta entre 0 y 7, se enciende ese bit
        	if((0<=bit)&&(bit<=7))
            {
            	portd.ports.b=((BITSETMASK<<bit)|portd.ports.b);
           	} 
           	
           	//Si el bit no esta entre 0 y 7, no se realiza ningun cambio    
           	else
            {
            	printf("No existe el bit %d en el puerto b.\n",bit);
            }      
            break;
        }
        
        //Si se recibe una 'd' se desea modificar el puerto D
        case 'd':
        {
        	//Si el bit esta entre 0 y 15, se enciende ese bit
			if((0<=bit)&&(bit<=15))
            {
            	portd.d=((BITSETMASK<<bit)|portd.d);
            }
            
            //Si el bit no esta entre 0 y 15, no se realiza ningun cambio
            else
            {
            	printf("No existe el bit %d en el puerto d.\n",bit);
            }                  
            break;        
        }
        
        //Si se recibe como puerto cualquier cosa que no sea A, B o D es un error
        default:
        {
        	printf("El puerto %c no existe.\n",port);
            break;
        }
	}     
}

//Esta funcion se encarga de apagar un bit de un puerto.
void bitClr(char port, int bit)
{
	switch (port) 
	{     
		//Si se recibe una 'a' se desea modificar el puerto A                                       
		case 'a':
        {
        	//Si el bit esta entre 0 y 7, se enciende ese bit
        	if((0<=bit)&&(bit<=7))
        	{
				portd.ports.a=(~(BITSETMASK<<bit)&portd.ports.a);
            }
            
            //Si el bit no esta entre 0 y 7, no se realiza ningun cambio
           	else
           	{
            	printf("No existe el bit %d en el puerto a.\n",bit);
            }                      
            break;
        }  
        
        //Si se recibe una 'b' se desea modificar el puerto B       
        case 'b':
        {
        	//Si el bit esta entre 0 y 7, se enciende ese bit
        	if((0<=bit)&&(bit<=7))
            {
            	portd.ports.b=(~(BITSETMASK<<bit)&portd.ports.b);
            } 
            
            //Si el bit no esta entre 0 y 7, no se realiza ningun cambio    
            else
            {
            	printf("No existe el bit %d en el puerto b.\n",bit);
            }      
            break;
       	}
       	
       	//Si se recibe una 'd' se desea modificar el puerto D  
       	case 'd':
        {
        	//Si el bit esta entre 0 y 15, se enciende ese bit
        	if((0<=bit)&&(bit<=15))
            {
            	portd.d=(~(BITSETMASK<<bit)&portd.d);
            }
            
            //Si el bit no esta entre 0 y 15, no se realiza ningun cambio
            else
            {
            	printf("No existe el bit %d en el puerto d.\n",bit);
            }                  
            break;        
       	}
       	
       	//Si se recibe como puerto cualquier cosa que no sea A, B o D es un error
        default:
        {
        	printf("El puerto %c no existe.\n",port);
        	break;
        }
	}     
}

int bitGet(char port, int bit)
{
        //Zona de variables.
        int rta=0;
        
             
        switch (port) 
        {         
        		//Si se recibe una 'd' se desea modificar el puerto D                                  
                case 'a':
                {
                        if((0<=bit)&&(bit<=7))
                        {
                                rta=((BITSETMASK<<bit)&portd.ports.a);
                                
                        }
                        else
                        {
                                printf("No existe el bit %d en el puerto a.\n",bit);
                                rta=-1;
                        }                      
                        break;
                } 
                
                //Si se recibe una 'd' se desea modificar el puerto D       
                case 'b':
                {
                        if((0<=bit)&&(bit<=7))
                        {
                                rta=((BITSETMASK<<bit)&portd.ports.b);
                        }     
                        else
                        {
                                printf("No existe el bit %d en el puerto b.\n",bit);
                                rta=-1;
                        }      
                        break;
                }
                
                //Si se recibe una 'd' se desea modificar el puerto D 
                case 'd':
                {
                        if((0<=bit)&&(bit<=15))
                        {
                                rta=((BITSETMASK<<bit)&portd.d);
                        }
                        else
                        {
                                printf("No existe el bit %d en el puerto d.\n",bit);
                                rta=-1;
                        }                  
                        break;        
                }
                
                //Si se recibe como puerto cualquier cosa que no sea A, B o D es un error
                default:
                {
                        printf("El puerto %c no existe.\n",port);
                        rta=-1;
                        break;
                }
        } 
        if(rta>0)
        {
                rta=1;
        }
        
        return rta;    
}

void bitToggle(char port, int bit)
{
   

        switch (port) 
        {                                          
                case 'a':
                {
                        if((0<=bit)&&(bit<=7))
                        {
                                portd.ports.a=((BITSETMASK<<bit)^portd.ports.a);
                        }
                        else
                        {
                                printf("No existe el bit %d en el puerto a.\n",bit);
                        }                      
                        break;
                }       
                case 'b':
                {
                        if((0<=bit)&&(bit<=7))
                        {
                                portd.ports.b=((BITSETMASK<<bit)^portd.ports.b);
                        }     
                        else
                        {
                                printf("No existe el bit %d en el puerto b.\n",bit);
                        }      
                        break;
                }
                case 'd':
                {
                        if((0<=bit)&&(bit<=15))
                        {
                                portd.d=((BITSETMASK<<bit)^portd.d);
                        }
                        else
                        {
                                printf("No existe el bit %d en el puerto d.\n",bit);
                        }                  
                        break;        
                }
                default:
                {
                        printf("El puerto %c no existe.\n",port);
                        break;
                }
        }     
}

//robemos
void maskOn(char port, unsigned int mask)
{
        

        switch (port) 
        {                                          
                case 'a':
                {
                                
                                portd.ports.a=(mask|portd.ports.a);
                                break;     
                }       
                case 'b':
                {
                                portd.ports.b=(mask|portd.ports.b);   
                                break;
                }
                case 'd':
                {
                                portd.d=((mask|portd.d));          
                                break;        
                }
                default:
                {
                        printf("El puerto %c no existe.\n",port);
                        break;
                }
        }     
}

void maskOff(char port, unsigned int mask)
{
        

        switch (port) 
        {                                          
                case 'a':
                {
                                
                                portd.ports.a=((~mask)&portd.ports.a);
                                break;     
                }       
                case 'b':
                {
                                portd.ports.b=((~mask)&portd.ports.b);   
                                break;
                }
                case 'd':
                {
                                portd.d=((~mask)&portd.d);          
                                break;        
                }
                default:
                {
                        printf("El puerto %c no existe.\n",port);
                        break;
                }
        }     
}

void maskToggle(char port, unsigned int mask)
{
         
        switch (port) 
        {                                          
                case 'a':
                {
                                
                                portd.ports.a=(mask^portd.ports.a);
                                break;     
                }       
                case 'b':
                {
                                portd.ports.b=(mask^portd.ports.b);   
                                break;
                }
                case 'd':
                {
                                portd.d=(mask^portd.d);          
                                break;        
                }
                default:
                {
                        printf("El puerto %c no existe.\n",port);
                        break;
                }
        }     
}




