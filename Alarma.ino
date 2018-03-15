/*
---------------------------------------------
ALARMA CON REED SWITCH, LED RGB.
---------------------------------------------
Programa que realiza la simulacion de una alarma
con la implementacion de Reed Switch, un led RGB
Alejandro Macario Gomez Ramirez
*/
//#include <ArduinoLowPower.h>//Declaramos la blbioteca que permite al arduino entrar a un modo de ahorro de energia
/*Cabe recarlacar una cosa acerca de esta biblioteca, si tu placa Arduino utiliza arquitectura
avr, la libreria no funcionara. Se necesita que la placa arduino utilice arquitectura samd, nrf52
para que la biblioteca funcione. En mi caso mi placa no es compatible, pero si tu placa posee
arquitectura samd, nrf52; puedes descomentar esta linea y la que esta en seguida del void Loop*/

//--------------------------------------------------
//Declara puertos de entradas y salidas y variables
//--------------------------------------------------
int contacto = 2; //Declaracion del pin que dara electricidad al Reed Switch
int ledRojo = 9;  //Declaracion del pin para encender Led Rojo 
int ledVerde = 10;//Declaracion del pin para encender Led Verde 
int ledAzul = 11; //Declaracion del pin para encender Led Azul

//------------------------------------
//Funcion principal
//------------------------------------
void setup() { //Se ejecuta cuando el arduino inicia
  pinMode(contacto, INPUT); //Cuando el IMAN activa el Reed Switch es la entrada
  pinMode(ledRojo, OUTPUT); //La salida sera el ledRojo
  pinMode(ledVerde, OUTPUT);//La salida sera el ledVerde
  pinMode(ledAzul, OUTPUT); //La salida sera el ledAzul
}

//------------------------------------
//Funcion ciclicla
//------------------------------------
void loop() { //Esta funcion se ciclara cuando el arduino este en funcionamiento
//LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); //Modo de ahorro de energia, el 
                                                  //cual como lo dice su primer 
                                                  //parametro dura 8 segundos 
                                                  //en esta fase en el cual 
                                                  //se apagan los comvertidores 
                                                  //de analogico a digital
                                                  
if (digitalRead(contacto) == LOW) { //Cuando el Reed Switch esta en pasivo
    for (int a = 0; a < 50; a++) { //Realizamos un ciclo para que el led parpadee
      color (255, 0, 0); //Rojo
      delay(50);
      color (0, 0, 0); //Apagado
      delay(50);
    }
  } else {                        //El IMAN ha pasado por el Reed Switch, activandolo.
    color (153,255,0); //Verde
  }

}

//------------------------------------
//Funcion Administradora del Color
//------------------------------------
void color (int rojo, int verde, int azul) { //Declaramos una funcion que se 
                                             //encargara de la administracion 
                                             //del color del LED RGB
  //Escritura de PWM del color Rojo                                           
  analogWrite(ledRojo, 255 - rojo);
  //Escritura de PWM del color Verde
  analogWrite(ledVerde, 255 - verde);
  //Escritura de PWM del color Azul
  analogWrite(ledAzul,  255 -a zul);
}
//FIN DEL PROGRAMA
