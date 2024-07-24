const int sensorIn = 36 ;
float cutOffLimit = 0.5 ;
//float resistance = 0.066 ;   for 30A
float resistance = 0.185 ;     //for 5A
void setup() {
  // put your setup code here, to run once:
  pinMode(sensorIn , INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc_value = analogRead(sensorIn);
//  Serial.print(adc_value);
  float voltage = (3.3 / 4096 ) * adc_value ;
  float current = (voltage - 2.4
  4) / resistance ;
  Serial.println(current);
  if(current > cutOffLimit ){
    Serial.print("current : ");
    Serial.print(current,2); // print the current with 2 decimal places
    Serial.println("A");
    Serial.println();
  }
  else{
    Serial.println("No Current");
  }
  delay(500);
}
