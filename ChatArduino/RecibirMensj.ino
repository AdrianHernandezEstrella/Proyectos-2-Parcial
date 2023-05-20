
void RecibirMensj(){
  EnviarMsj = "";
  while(mySerial.available()){
    if(mySerial.available()>0){
      char textRecibidoBt = mySerial.read();
      frase = textRecibidoBt;bandera2 = true;break;
    }else{
    break;
    }
  }
  
if(bandera2 == true){
    EnviarMsj = frase;
    Serial.print(EnviarMsj);
    bandera2 = false;
    }
}
