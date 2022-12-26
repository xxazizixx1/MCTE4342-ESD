/* By Azizi Bin Mohamad Tambi(1919661)*/

//Defining Pins
#define fsrPin A0
#define ldrPin A1

//Variables
int fsrVal;
int ldrVal;

void setup()
{
  Serial.begin(9600);
  pinMode(fsrPin, INPUT);
  pinMode(ldrPin, INPUT);
}

void loop()
{
  fsrVal = analogRead(fsrPin) / 4; //read FSR value 0-255
  ldrVal = analogRead(ldrPin) / 4; //read LDR value 0-255
  
  Serial.print("FSR value:");
  Serial.print(fsrVal);			//Print FSR value
  Serial.print("\n");
  Serial.print("LDR value:");
  Serial.print(ldrVal);			//Print LDR value
  Serial.print("\n");
  delay(1000);
}