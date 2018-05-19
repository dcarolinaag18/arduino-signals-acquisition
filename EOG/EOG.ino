#include <FlexiTimer2.h>

const int ledPin1 = 13;  // Pin 1 para el LED
const int ledPin2 = 12   // Pin 2 para el LED 
int inByte;             // variable para leer del puerto usb
int outByte = 0;        // variable para enviar al puerto usb

#define FS 256                   // frcuencia de muestreo ADC
#define TIMER2VAL (1024/(FS))                        

// Configuración inicial
void setup() {
    Serial.begin(115200);                 // velocidad de comunicación
    pinMode(ledPin1, OUTPUT);              // Pin 1 digital de salida.
    pinMode(ledPin2, OUTPUT);              // Pin 2 digital de salida.
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
        if (inByte == 'R') {
            digitalWrite(ledPin1, HIGH);     // enciende el led Rojo
            delay(100);
            digitalWrite(ledPin1, LOW);      // apaga el led Rojo
        }
        else if (inByte == 'A'){
            digitalWrite(ledPin2, HIGH);     // enciende el led Azul
            delay(100);
            digitalWrite(ledPin2, LOW);      // apaga el led Azul
        }
        }
    }
}  









