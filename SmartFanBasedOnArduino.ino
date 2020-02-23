/*
 * Smart Fan
 */

//Pins:
const int sensorPin = A0;
const int pwmPin = 5;

//RGB LED:
const int redPin = 10;
const int greenPin = 11;
const int bluePin = 12;

//Variables:
float sensorValue;
float voltageOut;
float temperatureC;
float temperatureF;
float temperatureK;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  voltageOut = (sensorValue * 5000) / 1024;

  temperatureK = voltageOut / 10;
  temperatureC = temperatureK - 273;
  temperatureF = (temperatureC * 1.8) + 32;

  Serial.print("Temperature(ºC): ");
  Serial.println(temperatureC);
  Serial.print("Temperature(ºF): ");
  Serial.println(temperatureF);
  Serial.print("Voltage(mV): ");
  Serial.println(voltageOut);
  Serial.println();

  if (temperatureC < 25) {
    setColor(0, 255, 0); // Green
    analogWrite(pwmPin, 0);
  } else if (temperatureC > 25 && temperatureC <= 30) {
    setColor(0, 0, 255); // Blue
    analogWrite(pwmPin, 255);
    delay(100);
    analogWrite(pwmPin, 100);
  } else if (temperatureC > 30 && temperatureC <= 35) {
    setColor(0, 0, 255); // Blue
    analogWrite(pwmPin, 255);
    delay(100);
    analogWrite(pwmPin, 150);
  } else if (temperatureC > 35 && temperatureC <= 40) {
    setColor(0, 0, 255); // Blue
    analogWrite(pwmPin, 200);
  } else {
    setColor(255, 0, 0); // Red
    analogWrite(pwmPin, 255);
  }
  delay(1000);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
