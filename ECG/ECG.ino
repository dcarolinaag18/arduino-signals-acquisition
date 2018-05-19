#include <FlexiTimer2.h>

const int buzPin = 9;         // Pin para el Buzzer
int inByte;                   // variable para leer del puerto usb
int outByte = 0;               // variable para enviar al puerto usb

#define FS 256                    // frcuencia de muestreo ADC
#define TIMER2VAL (1024/(FS))                      

// Configuración inicial
void setup() {
    Serial.begin(115200);                 // velocidad de comunicación
    pinMode(buzPin, OUTPUT);              // Pin digital de salida.
    FlexiTimer2::set(TIMER2VAL, flash);   // Iniciar timer
    FlexiTimer2::start(); 
}

// función para ADC y enviar dato
void flash() {
  outByte = analogRead(A0);         // leer dato analógico
  Serial.println(outByte);          // enviar dato
}

// función principal
void loop() {
  if (Serial.available()) {           // Pregunta si python envió algún dato
        char inByte = Serial.read();  // lee el dato recibido 
        if (inByte == 'H') {
            tone(buzPin, 1000);       // Manda señal al Buzzer
            delay(10);
            noTone(buzPin);           // Desactiva el Buzzer
        }
    }
}  









