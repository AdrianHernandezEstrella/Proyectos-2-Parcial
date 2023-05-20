void EnviarMensj(){
  int i = 0;
    while(Serial.available()){
    if(Serial.available()>0){
      String textRecibido = Serial.readString(); 
      if(textRecibido.length() == 2){
                flag == false;
                Serial.println("--- Asistente *** Escriba el Mensaje....");
           }else{
                EnviarMsj = "PC: "+textRecibido;flag = true;
           }
        }
     }
         
  if(flag == true){
      Serial.print("*"+EnviarMsj);
      flag = false;
      int CantCadena = EnviarMsj.length();
      while(i <= CantCadena){
        PackageMsj = EnviarMsj[i];
        mySerial.write(PackageMsj);
        i++;
      }
    
  }
}
