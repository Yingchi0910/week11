#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("s110919017");//請改名
  pinMode(27,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    //顯示在序列視窗
    Serial.println(BTdata);  
    if(BTdata == "yabeLED ON"){
    digitalWrite(27,HIGH);
    }
    else if(BTdata == "yabeLED OFF"){
      digitalWrite(27,LOW);
    }
  }
