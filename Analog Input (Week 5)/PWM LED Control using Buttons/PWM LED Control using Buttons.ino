/* By Azizi Bin Mohamad Tambi(1919661)*/

const int led = 9;
const int button = 6;
const int button2 = 5;
const int maxBrightness = 255;

int brightness = maxBrightness;
int i = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
}

void loop()
{
  buttonControl();
  analogWrite(led, map(brightness, 0, maxBrightness, 0, 255));
}

void buttonControl()
{
  if(digitalRead(button) == HIGH && brightness < maxBrightness)
  {
   	brightness = brightness + i;
    Serial.println(brightness);
  }
  if(digitalRead(button2) == HIGH && brightness > 0)
  {
    brightness = brightness - i;
    Serial.println(brightness);
  } 
}
