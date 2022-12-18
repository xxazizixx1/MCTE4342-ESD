/* By Azizi Bin Mohamad Tambi(1919661)*/

//Defining Pins
#define echoPin 2
#define trigPin 3
#define fsrPin A0
#define ldrPin A1

//Variables
long duration;
int distance;
int fsrVal;
int ldrVal;


//Function Declaration
void ultrasonic();
void fsr();
void ldr();

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(fsrPin, INPUT);
  
}

//Loop overall function
void loop()
{
  ultrasonic();
  fsr();
  ldr();
  delay(10000);
}

/*Function for Ultrasonic Sensor*/
void ultrasonic()
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  // Display the distance on the Serial Monitor
  Serial.print("\nDistance: ");
  Serial.print(distance);
  Serial.println(" cm");
}

/*Function for Force Sensitive Resistor*/
void fsr()
{
  fsrVal = analogRead(fsrPin);
  //Display the FSR value on serial monitor
  Serial.print("FSR reading = ");
  Serial.print(fsrVal);
  
  //Setting Threshold for the FSR
  if (fsrVal < 10) {
    Serial.println(" - No pressure");
  } else if (fsrVal < 200) {
    Serial.println(" - Low Pressure");
  } else if (fsrVal < 500) {
    Serial.println(" - Medium Pressure");
  } else if (fsrVal < 800) {
    Serial.println(" - High Pressure");
  } else {
    Serial.println(" - Very High Pressure");
  }
}

/*Function for Light Dependant Resistor*/
void ldr()
{
  ldrVal = analogRead(ldrPin);
  //Display the LDR value on serial monitor
  Serial.print("LDR reading = ");
  Serial.print(ldrVal);
  
  //Setting threshold for the LDR
  if (ldrVal < 10) {
    Serial.println(" - Very Dark");
  } else if (ldrVal < 200) {
    Serial.println(" - Dark");
  } else if (ldrVal < 500) {
    Serial.println(" - In Between");
  } else if (ldrVal < 800) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very Bright\n");
  }

}
  

