#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

String frase;
String EnviarMsj;
boolean flag = false;
boolean bandera2 = false;
char PackageMsj;

void setup() {
  Serial.begin(9600);
  Serial.println("LISTO CHAT");
  Serial.println("Puede enviar Mensaje....");
  mySerial.begin(9600);

}

void loop() {
  RecibirMensj();
  EnviarMensj();

}
