/* By Azizi Bin Mohamad Tambi(1919661)*/
//Pin definition
#define ena12 13 		//Enable 1&2 pin 13
#define motor1plus 12	//Input Pin 1 L293D on pin 12 Arduino
#define motor1neg 11	//Input Pin 2 L293D on pin 11 Arduino
#define ena34 10  		//Enable 3&4 pin 10
#define motor2plus 9	//Input Pin 3 L293D on pin 9 Arduino
#define motor2neg 8		//Input Pin 4 L293D on pin 8 Arduino
#define button1 7
#define button2 6

//Variables
int buttonStat1 = 0;
int buttonStat2 = 0;

void button1pressed();
void button2pressed();
void bothpressed();

//Setup function
void setup()
{
  pinMode(ena12, OUTPUT);
  pinMode(motor1plus, OUTPUT);
  pinMode(motor1neg, OUTPUT);
  pinMode(ena34, OUTPUT);
  pinMode(motor2plus, OUTPUT);
  pinMode(motor2neg, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

}

void loop()
{
  button1pressed();
  button2pressed();

}

void button1pressed()
{
  //Read value of push button 1
  buttonStat1 = digitalRead(button1);
  
  //Check if push button is pressed. If pressed, the stat will be HIGH
  if(buttonStat1 == HIGH){
    //Motor 1 Rotate CW
    digitalWrite(ena12, HIGH);
    digitalWrite(motor1plus, LOW);
    digitalWrite(motor1neg, HIGH);
  }else{
    //Motor 1 Rotate CCW
    digitalWrite(ena12, HIGH);
    digitalWrite(motor1plus, HIGH);
    digitalWrite(motor1neg, LOW);  
  } 
}

void button2pressed()
{
  //Read value of push button 2
  buttonStat2 = digitalRead(button2);
  
  //Check if push button is pressed. If pressed, the stat will be HIGH
  if(buttonStat2 == HIGH){
    //Motor 2 Rotate CCW
    digitalWrite(ena34, HIGH);
    digitalWrite(motor2plus, HIGH);
    digitalWrite(motor2neg, LOW);
  }else{
    //Motor 2 Rotate CW
    digitalWrite(ena34, HIGH);
    digitalWrite(motor2plus, LOW);
    digitalWrite(motor2neg, HIGH);
  }
}

void bothpressed()
{
  buttonStat1 = digitalRead(button1); 
  buttonStat2 = digitalRead(button2);

  if (buttonStat1 == HIGH && buttonStat2 == HIGH){
    //both motor stop rotating
    digitalWrite(ena12, LOW);
    digitalWrite(ena34, LOW);
  } 
}