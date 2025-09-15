const int TEMP_SENSOR_PIN = A0; 
const int FAN_PIN = 9;          

const float SERIES_RESISTOR = 10000;    
const float NOMINAL_RESISTANCE = 10000; 
const float NOMINAL_TEMPERATURE = 25;   
const int B_COEFFICIENT = 3900;         

void setup() {
  Serial.begin(9600);
  pinMode(FAN_PIN, OUTPUT);
}

void loop() {
  int adc = analogRead(TEMP_SENSOR_PIN);
  float resistance = SERIES_RESISTOR * (1023.0 / adc - 1.0);

  float steinhart = log(resistance / NOMINAL_RESISTANCE) / B_COEFFICIENT;
  steinhart += 1.0 / (NOMINAL_TEMPERATURE + 273.15);
  float temperatureC = (1.0 / steinhart) - 273.15;

  int fanPWM = 0;
  String fanState = "OFF";

  if (temperatureC >= 30) {
    fanPWM = 255;
    fanState = "100%";
  } else if (temperatureC >= 25) {
    fanPWM = 128;
    fanState = "50%";
  }

  analogWrite(FAN_PIN, fanPWM);

  Serial.print("Temp: ");
  Serial.print(temperatureC);
  Serial.print(" C | Fan: ");
  Serial.println(fanState);

  delay(1000);
}
