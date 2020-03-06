int pwm1 = 3;
int pwm2 = 5;
int pwm3 = 6;
int pwm4 = 9;
int pwm5 = 10;

String prebranPod = "0";
int pretPod = 0;
int stPwmja = 0;
int mocPwmja = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  
pinMode(pwm1,OUTPUT);
pinMode(pwm2,OUTPUT);
pinMode(pwm3,OUTPUT);
pinMode(pwm4,OUTPUT);
pinMode(pwm5,OUTPUT);


}
void serialEvent(){
  
prebranPod = Serial.readString();
}

void loop() {
  // put your main code here, to run repeatedly:
  
prebranPod = Serial.readString();
pretPod = prebranPod.toInt();
Serial.println(prebranPod);

  if(pretPod > 5255){
    //Serial.println("stevilka vecja kot 5255");  
  }
  else if (pretPod < 999){
    //Serial.println("stevilka manjsa kot 1000"); 
  }
  else{
    
    stPwmja = pretPod/1000;
    mocPwmja = pretPod-(stPwmja*1000);

    if(mocPwmja > 255){
      Serial.println("moč pwmja previsoka"); 
    }
      else{

        switch(stPwmja){

          case 1:
          Serial.println(prebranPod);
          analogWrite(pwm1,mocPwmja);
          break;
          
          case 2:
          Serial.println(prebranPod);
          analogWrite(pwm2,mocPwmja);
          break;

          case 3:
          Serial.println(prebranPod);
          analogWrite(pwm3,mocPwmja);
          break;

          case 4:
          Serial.println(prebranPod);
          analogWrite(pwm4,mocPwmja);
          break;

          case 5:
          Serial.println(prebranPod);
          analogWrite(pwm5,mocPwmja);
          break;
        }  
          
     } 
      
  }






}
