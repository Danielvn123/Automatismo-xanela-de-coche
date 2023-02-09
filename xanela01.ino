/*
Programa para simular a función dunha fiestra de automóvil, de maneira 
simplificada. O pulsador acciona o motor de subida ao ser premido.Unha
segunda pulsación fai que se acciona o motor de baixada. O percorrido do
motor son 7 segundos.Mentres os motores están activados , deben responder 
ao accionamento do pulsador (responsive).
Entrada: Pulsador (dixital)
Saídas: Relé (2x dixital)
Autor: Daniel Vilas
Data: Febreiro de 2023
*/

#define motorArriba 12
#define motorAbaixo 11
#define pulsador    7

  bool estado =  0;
  int contador = 100; //Contador para o número de impulsos ao motor

void setup() {
  pinMode(motorArriba, OUTPUT);
  pinMode(motorAbaixo, OUTPUT);
  pinMode(pulsador, INPUT);

  Serial.begin(9600);
  int estado;
  
}

void loop() {
  //Lectura do pulsador
  if(digitalRead(pulsador)) {
    estado = !estado;
    contador = 100;
    while(digitalRead(pulsador)) {
      delay(20);
    }
  }
  //Fin de lectura do pulsador
  
  Serial.print("valor do contador: ");
  Serial.println(contador);
  
  //Accionamento dos motores
  if(contador > 0){               //Conta número de impulsos ao motor
    if(estado == 0){
      digitalWrite(motorArriba, HIGH);
      digitalWrite(motorAbaixo, LOW);
      delay(70);
      contador--;
    }
    else{
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, HIGH);
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
}
