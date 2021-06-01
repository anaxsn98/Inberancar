

const int control= 9;//para controlar el ventilador
const int pulsador = 4;//boton ventilador
int sensor = A0;//Pin 2 para el valor del sensor DHT11
const int bomba = 13; //Pin 13 para la bomba
const int rele = 2; //Pin 13 para la bomba
const int ventilador = 3; //Pin 13 para la bomba
int pin[7]={5,6,7,8,10,11,12};//luces

void setup() {
  Serial.begin(9600);
  //control ventilador
  pinMode(control,OUTPUT);
  //boton
  pinMode(pulsador,INPUT);
  //sensor humedad
 pinMode(sensor, INPUT);
 // usamos el pin 2 como salida, para activar y desactivar el rel
  pinMode(rele, OUTPUT);
  
  //leds
  for(int i=0; i < 4; i++){
     pinMode(pin[i],OUTPUT);
  }
}

void loop() {
  //VENTILADOR
  if(digitalRead(pulsador)== HIGH){
     digitalWrite(control,LOW);
     for(int i=0; i < 4; i++){
         digitalWrite(pin[i],LOW);
      }
  }else{
     digitalWrite(control,HIGH);
     for(int i=0; i < 4; i++){
         digitalWrite(pin[i],HIGH);
      }
  }

//SENSOR HUMEDAD
   if(digitalRead(sensor)==LOW){
    Serial.print("HUMEDO ");
//iniciarbomba agua-rele
    digitalWrite(rele, HIGH);   // encendemos el rele osea la bomba
    
   }else{
    digitalWrite(rele, LOW);
   }
  
}
