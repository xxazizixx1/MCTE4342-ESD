/* By Azizi Bin Mohamad Tambi(1919661)*/

const int buzzer = 3;
const int buzzer2 = 5;
const int buzzer3 = 6;

const int button = 13;
const int button2 = 12;
const int button3 = 11;
const int button4 = 10;
const int button5 = 9;
const int maxFrequency = 1024;
int interval = 50;
int frequency = 500;
int k = 100;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
}

void loop()
{
  buttonControl();
  //For buzzer 1
  if (digitalRead(button3) == HIGH)
  {
    toneControl(3, frequency - 100, k);
    delay(50);
  }
  if (digitalRead(button4) == HIGH)
  {
    toneControl(5, frequency, k);
    delay(50);
  }
  if (digitalRead(button5) == HIGH)
  {
    toneControl(6, frequency + 100, k);
    delay(50);
  }
}

void buttonControl()
{
  //Increase Frequency
  if(digitalRead(button) == HIGH && frequency < maxFrequency)
  {
   	frequency = frequency + interval;
    Serial.println(frequency);
  }
  //Decrease frequency
  if(digitalRead(button2) == HIGH && frequency > 0)
  {
    frequency = frequency + interval;
    Serial.println(frequency);
  } 
}

void toneControl(const int buzzerNo, int frequency, int k)
{
  tone(buzzerNo, frequency, k);
  delay(100);
}