
int analogPin = A0;// function generator connected to analog pin A0
int temp=A1;                  
int val = 0;  // variable to store the value read
int tempRead=0;
int i=0;
int highs=0;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(temp, INPUT);
  Serial.begin(9600);           //  setup serial, usually 9600 Bauds
}



void loop()
{
  i++;
  tempRead=map(((analogRead(temp) - 20) * 3.04), 0, 1023, -40, 125);
  val = analogRead(analogPin);  // read the input pin
  if (val>400 || val<-400) //turning internal LED when the heartbeat reaches peacks or valleys
     digitalWrite(13, HIGH);
  else
     digitalWrite(13, LOW);
  if(digitalRead(13==HIGH))
  {
    highs++;
  }
   Serial.println(highs);
   delay(50);
   Serial.println(tempRead);
}

