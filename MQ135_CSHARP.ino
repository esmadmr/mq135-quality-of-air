//hava kalitesi olcumu
int sensorValue;
int digitalValue;
//millis fonksiyon sabitleri
unsigned long currentMillis_MQ135;
unsigned long previousMillis_MQ135; 
unsigned long MQ135_Scan_Time = 500;
void setup()
{
  Serial.begin(9600); 
  pinMode(13, OUTPUT); //dijital pin seçtim
  pinMode(2, INPUT);
}

void loop()
{
  previousMillis_MQ135 = millis();
  if (previousMillis_MQ135 - currentMillis_MQ135 >= MQ135_Scan_Time )
  { 
      int sensorValue = analogRead(0); 
      int digitalValue = digitalRead(2);
      if (sensorValue > 400)
      {
        digitalWrite(13, HIGH);
      }
      else
      {
        digitalWrite(13, LOW);
      }
      float payload_alti;
      Serial.print("P6,");
      Serial.println(sensorValue, DEC); 
      currentMillis_MQ135 =  previousMillis_MQ135;
  }
  
}