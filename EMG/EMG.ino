#include <FlexiTimer2.h>

const int ledPin = 13;  // Pin para el LED
int inByte;             // variable para leer del puerto usb
int outByte = 0;        // variable para enviar al puerto usb

#define FS 256                   // frcuencia de muestreo ADC
#define TIMER2VAL (1024/(FS))                        

// Configuración inicial
void setup() {
    Serial.begin(115200);                 // velocidad de comunicación
    pinMode(ledPin, OUTPUT);              // Pin digital de salida.
    FlexiTimer2::set(TIMER2VAL, flash);   // Iniciar timer
    FlexiTimer2::start(); 
}

// función para ADC y enviar dato
void flash() {
  outByte = analogRead(A0);         // leer dato analógico
  Serial.println(outByte);          // enviar dato
}

void loop() {
  if (Serial.available()) {                 // Pregunta si python envió
        char inByte = Serial.read();        // lee el dato recibido 
        if (inByte == 'H') {
            digitalWrite(ledPin, HIGH);     // enciende el led
            delay(20);
            digitalWrite(ledPin, LOW);      // apaga el led
        }
    }
}  









