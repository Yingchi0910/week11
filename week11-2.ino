#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("s110919017");//請改名
  pinMode(27,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
}
int a=0,b=0;

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    //顯示在序列視窗
    Serial.println(BTdata);  
    if(BTdata == "P1 gets one point"){
      a+=1;
      if(a==1){
        digitalWrite(12,HIGH);
      }
      else if(a==2){
        digitalWrite(14,HIGH);
      }
    }
    else if(BTdata == "P2 gets one point"){
      b+=1;
      if(b==1){
        digitalWrite(27,HIGH);
      }
      else if(b==2){
        digitalWrite(25,HIGH);
      }
    }
    if(BTdata=="restart"){
      digitalWrite(25,LOW);
      digitalWrite(27,LOW);
      digitalWrite(12,LOW);
      digitalWrite(14,LOW);
    }
  }

  delay(1);
}
