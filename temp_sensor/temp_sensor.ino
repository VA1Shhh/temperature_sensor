//program of a temperature sensor

#define LED 13
#define TEMP A0

//Initiallizing the values for LED to blink 500 milliseconds
unsigned long CurrentMillis1 = 0;
unsigned long PrevBlinkMillis1 = 0;
const unsigned long BlinkPeriod1 = 500;


//Initiallizing the values for LED to blink 250 milliseconds
unsigned long CurrentMillis2 = 0;
unsigned long PrevBlinkMillis2 = 0;
const unsigned long BlinkPeriod2 = 250;

//Setting up the input and output pins
void setup()
{
  pinMode(TEMP, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

//Function to blink LED for 500 milliseconds
void blinkLed()
{
  if(CurrentMillis1 - PrevBlinkMillis1 >= BlinkPeriod1)
  {
    PrevBlinkMillis1 = CurrentMillis1;
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}

//Function to blink LED for 250 milliseconds
void blink_Led()
{
  if(CurrentMillis2 - PrevBlinkMillis2 >= BlinkPeriod2)
  {
    PrevBlinkMillis2 = CurrentMillis2;
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}

void loop()
{
  int value=analogRead(TEMP);
  double volts,temp;
  //Calculate the analog voltage value that LM35 generates
  volts=0.0048828125*value; 

  //To calculte the temperature from analog value
  temp = (volts-0.5)*100; 
  
  //Printing the degree of temperature on the monitor
  Serial.print("TEMPERATURE: ");
  Serial.print(temp);
  Serial.print("\n");

  CurrentMillis1 = millis();
  CurrentMillis2 = millis();

  if(temp>=30)
  {
    blinkLed();
  }
  else
  {
    blink_Led();
  }
}
