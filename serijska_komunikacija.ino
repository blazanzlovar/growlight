void setup() {
  pinMode(3,OUTPUT); 
  pinMode(5,OUTPUT); 
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);      //DOLOČANJE PINOV  pinMode(št . pina , način(INPUT ali OUTPUT));

Serial.begin(9600);        //zacetek komunikacije

}
String prebran_podatek;
int  pretvorjen_podatek=0;
int st_PWM;
int moc_PWM;
void loop() {
           
  pretvorjen_podatek=prebran_podatek.toInt(); //zdaj imamo int
  Serial.println(prebran_podatek);
 if (pretvorjen_podatek>5255){
 // Serial.println("Error");
  }
  else if(pretvorjen_podatek<1000){
   //Serial.println("Napaka");                            //podatek mora biti med 1000 in 5255
   }
  else{
  st_PWM=pretvorjen_podatek/1000;
   // Serial.println(st_PWM);

    moc_PWM= (pretvorjen_podatek-(st_PWM*1000));
    
    //Serial.println(moc_PWM);
    if (moc_PWM>255){
      //Serial.println("error");
      
      }
      else{
        //Serial.println(st_PWM);
          //Serial.println(moc_PWM);
           
      }
    }
   switch(st_PWM){
    case 1:    
      Serial.println("3");
      analogWrite(3,moc_PWM);
      break;
    case 2:    
    Serial.println("5");
      analogWrite(5,moc_PWM);
      break;
    case 3: 
      Serial.println("6");
        analogWrite(6,moc_PWM);
      break;
    case 4:  
     Serial.println("9");
       analogWrite(9,moc_PWM);
      break;
       case 5:    
      Serial.println("10");
        analogWrite(10,moc_PWM);
      break;
  }
  delay(1000); 
}
void serialEvent() {
    prebran_podatek = Serial.readString(); 
  }
 
