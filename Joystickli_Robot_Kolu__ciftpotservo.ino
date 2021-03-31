#include <Joystick.h>
#include <Servo.h>

Joystick_ Joys;                               //Joystick  olarak tanımladım.                 

#define potOmuz A1                            //Pot1'in A1 de olduğunu belirttim.
#define potDirsek A2                          //Pot2'nin A2 de olduğunu belirttim.

Servo Omuz;                                   //Servo1'i Omuz olarak tanımladım.
Servo Dirsek;                                 //Servo2'yi Dirsek olarak tanımladım

//int motor;                          

void setup() {
  Joys.begin(9600);                               //Joystick kütüphanesini başlat
  Omuz.attach(11);                                            
  Dirsek.attach(10);
  
}

void loop() {
  Joys.setXAxis(analogRead(potOmuz));         //Omuz kontrolü yapacak potun değerini oku
  Joys.sendState();                           //Durumu gönder
  

  Joys.setYAxis(analogRead(potDirsek));       //Dirsek kontrolü yapacak potun değerini oku
  Joys.sendState();                           //Durumu gönder
  
}

void omuzKontrol()
{
  int x = map(potOmuz , 0 , 1023 , 0 , 180);   //potOmuzun değer aralığı 0-180 olacak şekilde ayarla x'e gönder
  Omuz.write(x);                               //x değerini servoya yazdır
  
}

void dirsekKontrol()
{
  int y = map(potDirsek , 0 , 1023 , 0 , 90);  //potDirseğin değer aralığı 0-90 olacak şekilde ayarla y'ye gönder
  Dirsek.write(y);                             //Durumu gönder
  
  
}


// Önceki denemelerim yukarıda temize çekip tekrar yazmaya çalıştım.
/*//Serial.begin(9600);                         
  
  pinMode(potOmuz , INPUT);                   //Potansiyometrelerin giriş olduğunu belirttim.
  pinMode(potDirsek , INPUT);                 //
  Omuz.attach(10);                            // 
  Dirsek.attach(11);                          //
  Omuz.write(0);                              //
  Dirsek.write(0);
 * 
 * 
 * 
 * int x=analogRead(potOmuz);                    //
  Joystick.setXAxis(x);                         //
  Joystick.sendState();                         //
  analogWrite(potOmuz , x);                     //
  int yeni = map(x , 0 , 1023 , 0 , 180);       //
  Omuz.write(yeni);                             //
  delay(15); 
 * 
 * int y=analogRead(potDirsek);
  Joystick.setYAxis(y);
  Joystick.sendState();
  analogWrite(potDirsek , y);
  int  dahayeni = map(y , 0 , 1023 , 0 , 90);
  Dirsek.write(dahayeni);
  Serial.println (dahayeni);*/
