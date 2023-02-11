/*
Programa para simular a función dunha fiestra de automóvil, de maneira 
simplificada. O pulsador acciona o motor de subida ao ser premido.Unha
segunda pulsación fai que se pare o motor de subida; unha terceira 
pulsación fai que se accione o motor de baixada e unha cuarta pulsación fai
que se volva a parar.O percorrido do motor son 7 segundos.

Na segunda parte do problema (práctica 21) temos que forzar que o pulsador
teña tres estado (ARRIBA, PARADA e ABAIXO) e que despois de cada accionamento
do pulsador, pase por 0 ou parada. 

Na terceura parte do problema (Práctica 22) temos que expandir dous novos sensores
dixitais (fins de carreira) que simularemos con pulsadores. Estos sensores sustituen
o control por tempo e fan que ao estaren activados a xanela para na parte superior
ou inferior e permaneza nesa posición ata que se prema no pulsador de accionamento.
O pulsador de accionamento segue a ter a mesma funcionalidade arriba, paro e abaixo.


Entrada: Pulsador (dixital)
Saídas: Relé (2x dixital)

Autor: Daniel Vilas
Data: Febreiro de 2023
*/

#define motorArriba 12
#define motorAbaixo 11
#define pulsador    7
#define fcArriba    8
#define fcAbaixo    9

  int estado =  1;   //Práctica 22; pode tomar valores: 0,1,2,3
  int contador = 0; //Contador para o número de impulsos ao motor

void setup() {
  pinMode(motorArriba, OUTPUT);
  pinMode(motorAbaixo, OUTPUT);
  pinMode(pulsador, INPUT);
  pinMode(fcArriba, INPUT);
  pinMode(fcAbaixo, INPUT);

  Serial.begin(9600);
}

void loop() {
  //Lectura do pulsador
  if(digitalRead(pulsador)) { //Pulsador de accionamento
    estado = (++estado) % 4; //Actualización de `estado´ para estar entre 0 e 3
 //   estado++;  
 //   if(estado > 3) {
 //     estado = 0;
 //  }        
    while(digitalRead(pulsador)) {
      delay(20);
    }
  } 
  
  if(digitalRead(fcArriba)) {  //Fin de carreira posición superior
    if(estado != 2 ) {
      estado = 1;    //Xanela parada arriba
    }
    delay(20);
  }
  
  if(digitalRead(fcAbaixo)) {  //Fin de carreira posición inferior
    if(estado != 0 ) {  
      estado = 3;   //Xanela parada abaixo
    }
    delay(20);
  }
  //Fin de lectura do pulsador
  
  Serial.print("Valor do contador: ");
  Serial.println(contador);
  Serial.print("  |  Estado: ");
  Serial.println(estado);
  
  //Accionamento dos motores
  
    if(estado == 0){
      digitalWrite(motorArriba, HIGH);
      digitalWrite(motorAbaixo, LOW);
      delay(70);
    }
    else if(estado == 2) {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, HIGH);
      delay(70);
    }
    else {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, LOW);
      delay(70);
    }  
  }

