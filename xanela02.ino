/*
Programa para simular a función dunha fiestra de automóvil, de maneira 
simplificada. O pulsador acciona o motor de subida ao ser premido.Unha
segunda pulsación fai que se pare o motor de subida; unha terceira 
pulsación fai que se accione o motor de baixada e unha cuarta pulsación fai
que se volva a parar.O percorrido do motor son 7 segundos.

Na segunda parte do problema (práctica 21) temos que forzar que o pulsador
teña tres estado (ARRIBA, PARADA e ABAIXO) e que despois de cada accionamento
do pulsador, pase por 0 ou parada.

Entrada: Pulsador (dixital)
Saídas: Relé (2x dixital)

Autor: Daniel Vilas
Data: Febreiro de 2023
*/

#define motorArriba 12
#define motorAbaixo 11
#define pulsador    7

  int estado =  1;   //Práctica 21; pode tomar valores: 0,1,2,3
  int contador = 0; //Contador para o número de impulsos ao motor

void setup() {
  pinMode(motorArriba, OUTPUT);
  pinMode(motorAbaixo, OUTPUT);
  pinMode(pulsador, INPUT);

  Serial.begin(9600);
}

void loop() {
  //Lectura do pulsador
  if(digitalRead(pulsador)) {
    estado = (++estado) % 4; //Actualización de `estado´ para estar entre 0 e 2
 //   estado++;  
 //   if(estado > 3) {
 //     estado = 0;
 //  }        
    contador = 100;
    while(digitalRead(pulsador)) {
      delay(20);
    }
  }
  //Fin de lectura do pulsador
  
  Serial.print("Valor do contador: ");
  Serial.println(contador);
  Serial.print("  |  Estado: ");
  Serial.println(estado);
  
  //Accionamento dos motores
  if(contador > 0){               //Conta número de impulsos ao motor
    if(estado == 0){
      digitalWrite(motorArriba, HIGH);
      digitalWrite(motorAbaixo, LOW);
      delay(70);
      contador--;
    }
    else if(estado == 2) {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, HIGH);
      delay(70);
      contador--;
    }
    else {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, LOW);
      delay(70);
      contador--;
    }
  }
  else{               //Se non está o motor accionado, lee botón 10 veces/s 
    digitalWrite(motorArriba, LOW);
    digitalWrite(motorAbaixo, LOW);
    delay(100);
  }
  //Fin de accionamento dos motores
  //delay(80);
}

