/* By Azizi Bin Mohamad Tambi(1919661)*/

//Library
#include <LowPower.h> //This library can be downloaded from github

//Defining Pins
#define echo 2
#define trig 3

//Variables
long duration;
int distance;

void ultrasonic();

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //Set pin 4 until pin A5 as OUTPUT to saves power
  for(int i, i >= 4, i++){
    pinMode(i, OUTPUT);
  }
  
}

void loop()
{
  //Calling ultrasonic function to measure distance
  ultrasonic();
  
  //Putting arduino to sleep for 8 seconds
  Serial.println("Arduino: I am going to sleep");
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                 SPI_OFF, USART0_OFF, TWI_OFF);
  Serial.println("Arduino: Waking up");
  Serial.println("");
  delay(2000);

}

void ultrasonic()
{
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  // Display the distance on the Serial Monitor
  Serial.print("\nDistance: ");
  Serial.print(distance);
  Serial.println(" cm");
}