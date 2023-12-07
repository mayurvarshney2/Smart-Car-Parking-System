#include <Servo.h> //includes the servo library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

Servo myservo1;
Servo myservo2;

#define ir_enter1 2
#define ir_enter2 4

#define ir_exit1 7
#define ir_exit2 8

#define ir_car1 9
#define ir_car2 10


int S1=0, S2=0;
int slot = 2;  

void setup(){
Serial.begin(9600);

pinMode(ir_enter1,INPUT);
pinMode(ir_enter2,INPUT);

pinMode(ir_exit1,INPUT);
pinMode(ir_exit2,INPUT);

pinMode(ir_car1, INPUT);
pinMode(ir_car2, INPUT);

  
myservo1.attach(3);
myservo2.attach(5);
myservo1.write(0);
myservo2.write(0);

lcd.init();
lcd.clear();         
lcd.backlight();
//lcd.begin(20, 4);  
lcd.setCursor (2,0);
lcd.print("Car  parking");
lcd.setCursor (5,1);
lcd.print("System");
delay (2000);
lcd.clear();

Read_Sensor();
 
}

void loop(){
/////////////////SLOTS////////////////////////////////////////////////
  Read_Sensor();
slot =2;
int total = S1+S2;
slot = slot-total;

lcd.setCursor (0,0);
lcd.print("   Have Slot: "); 
lcd.print(slot);  
//!!!!!!!!!!!!!!!!!slot1!!!!!!!!!!!!!!!!!!!!!!!!!!
lcd.setCursor (0,1);
if(S1==1)
{
  slot=slot-1;
  lcd.print("S1:Fill ");
}
else
{
  slot=slot+1;
  lcd.print("S1:Empty");
}
//!!!!!!!!!!!!!!!!!!slot2!!!!!!!!!!!!!!!!!!!!!!!!!!
lcd.setCursor (9,1);
if(S2==1)
{
  slot=slot-1;
  lcd.print("S2:Fill ");
}
else
{
  slot=slot+1;
  lcd.print("S2:Empty");
}
  

//////////////////////gate///////////////////////


//////////////////////ENTRY/////////////////////////////////
  int IRenter1=digitalRead(ir_enter1);
  if(IRenter1 == 0)
  {
    myservo1.write(90);
  }
  int IRenter2=digitalRead(ir_enter2);
  if(IRenter2 == 0 && IRenter1 !=0)
  {
    myservo1.write(0);
  }
  


////////////////////////////EXIT//////////////////////////////////
  
  int IRexit1=digitalRead(ir_exit1);
  if(IRexit1 == 0)
  {
    myservo2.write(90);
  }
  int IRexit2=digitalRead(ir_exit2);
  if(IRexit2 == 0 && IRexit1 !=0)
  {
    myservo2.write(0);
  }
}

void Read_Sensor(){
S1=0, S2=0;

if(digitalRead(ir_car1) == 0){S1=1;}
if(digitalRead(ir_car2) == 0){S2=1;} 
}
