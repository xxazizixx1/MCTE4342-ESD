/* By Azizi Bin Mohamad Tambi (1919661)*/
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(32, 16, 2); 
#include "Countimer.h" //download at https://github.com/inflop/Countimer
Countimer tdown;
#include <EEPROM.h>

//Assigning pins
#define bt_set 1
#define bt_up 2
#define bt_down 3
#define bt_start 4
#define redLED 5
#define buzzer 6

//Declaring variables
int time_s = 0;  //Time in seconds
int time_m = 0;  //Time in minutes
int time_h = 0;  //Time in hours

int set = 0;
int flag1=0, 
int flag2=0;

int redLED = 5;
int buzzer = 6;

//Functions in the codes
void button_set();
void button_up();
void button_down();
void eeprom_read();
void eeprom_write();
void tdownComplete();
void print_time();
  
void setup() 
{
  Serial.begin (9600);
  pinMode(bt_set,   INPUT_PULLUP);
  pinMode(bt_up,    INPUT_PULLUP);
  pinMode(bt_down,  INPUT_PULLUP);
  pinMode(bt_start, INPUT_PULLUP);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   Welcome To   ");
  lcd.clear();
  
  tdown.setInterval(print_time, 999);  
  eeprom_read();
  delay(1000);
  
}

void loop()
{
  tdown.run();
  button_set();
  button_up();
  button_down();
  
  if(digitalRead (bt_start) == 0)
   { 
     flag2=1; 
     eeprom_read(); 
     digitalWrite(redLED, HIGH); 
     tdown.restart(); 
     tdown.start();
   }
  
  lcd.setCursor(0,0);
	
  if(set==0){
     lcd.print("      Timer     ");
   }
  if(set==1){
     lcd.print("  Set Timer SS  ");
   }
  if(set==2){
     lcd.print("  Set Timer MM  ");
   }
  if(set==3){
     lcd.print("  Set Timer HH  ");
   }

  lcd.setCursor(4,1);
  
  if(time_h<=9){
    lcd.print("0");
  }
  lcd.print(time_h);
  lcd.print(":");
  
  if(time_m<=9){
    lcd.print("0");
  }
  lcd.print(time_m);
  lcd.print(":");
  
  if(time_s<=9){
    lcd.print("0");
  }
  lcd.print(time_s);
  lcd.print("   ");

  if(time_s==0 && time_m==0 && time_h==0 && flag2==1)
  {
    flag2=0;
	tdown.stop(); 
	digitalWrite(redLED, LOW);
	digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(200);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
  }

  if(flag2==1){
    digitalWrite(redLED, HIGH);
  }
  
  else{
    digitalWrite(redLED, LOW);
  }

  delay(1);
}

//Function when button set is pressed (To set time)
void button_set()
{
  
  if(digitalRead (bt_set) == 0){
    if(flag1==0 && flag2==0)
    {
      flag1=1;
      set = set+1;
      
      if(set>3){
        set=0;
      }
      
      delay(100); 
	}
  }
  
  else{
    flag1=0;
  }
  
}

//Function when button up is pressed (To increase the time)
void button_up()
{ 
  if(digitalRead (bt_up) == 0)
  {
    if(set==0){
      tdown.start(); 
      flag2=1;
    }
    if(set==1){
      time_s++;
    }
    if(set==2){
      time_m++;
    }
    if(set==3){
      time_h++;
    }
    if(time_s>59){
      time_s=0;
    }
    if(time_m>59){
      time_m=0;
    }
    if(time_h>99){
      time_h=0;
    }
    if(set>0){
      eeprom_write(); //Write and save to EEPROM
    }
    delay(200); 
  }
}

//Function button down is pressed (To decrease time)
void button_down()
{
  
  if(digitalRead (bt_down) == 0)
  {
	if(set==0){
      tdown.stop(); 
      flag2=0;
    }
	if(set==1){
      time_s--;
    }
	if(set==2){
      time_m--;
    }
	if(set==3){
      time_h--;
    }
	if(time_s<0){
      time_s=59;
    }
	if(time_m<0){
      time_m=59;
    }
	if(time_h<0){
      time_h=99;
    }
	if(set>0){
      eeprom_write(); //Write and save to EEPROM
    }
	delay(200); 
  }

}

//Function to store/write the assigned time in eeprom
void eeprom_write()
{
  EEPROM.write(1, time_s);  
  EEPROM.write(2, time_m);  
  EEPROM.write(3, time_h);  
}

//Function to read data stored in eeprom
void eeprom_read()
{
  time_s =  EEPROM.read(1);
  time_m =  EEPROM.read(2);
  time_h =  EEPROM.read(3);
}

void print_time()
{
  time_s = time_s-1;
  
  if(time_s<0)
  {
    time_s=59; time_m = time_m-1;
  }
  
  if(time_m<0)
  {
    time_m=59; time_h = time_h-1;
  }
}

void tdownComplete()
{
  Serial.print("ok");
}