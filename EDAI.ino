#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "iPhone";
const char* password = "12345678";

const long channelID = 2304180;
const char* apiKey = "PJQC54XJX1364MJC";

const int MQ135Pin = A0; // Analog input pin for MQ135 sensor

// Calibration parameters (you need to calibrate for your specific sensor)
const float R0 = 10000; // Resistance at clean air
const float ppmR0 = 282; // CO2 ppm at R0
const float ppmLPG_R0 = 50; // CO ppm at R0

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
  ThingSpeak.begin(client);
}

void loop() {
  // Read the analog value from the MQ135 sensor
  int sensorValue = analogRead(MQ135Pin);

  // Calculate resistance and ppm values
  float Rs = (1023.0 / sensorValue - 1) * R0;
  float ppmCO2 = ppmR0 * pow((Rs / R0), -2.77);
  float ppmCO = ppmLPG_R0 * pow((Rs / R0), -2.3);

  // Display values on the serial monitor
  Serial.print("\nCO2 (ppm): ");
  Serial.println(ppmCO2);
  Serial.print("CO (ppm): ");
  Serial.print(ppmCO);
  // Determine air quality (customize these thresholds as needed)
  String airQuality = (ppmCO2 < 350 && ppmCO < 10) ? "Good" : "Bad";

  ThingSpeak.setField(1, ppmCO2);
  ThingSpeak.setField(2, ppmCO);
  //ThingSpeak.setField(3, airQuality);
  
  int httpCode = ThingSpeak.writeFields(channelID, apiKey);

  Serial.print("\nAir Quality: ");
  Serial.print(airQuality);
  Serial.print("\nData sent to ThingSpeak\n");

  delay(15000); // Update ThingSpeak every minute
}


#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// Replace with your network credentials
const char* ssid = "iPhone";
const char* password = "12345678";

// Replace with your ThingSpeak channel information
const long channelID = 2304180;
const char* apiKey = "PJQC54XJX1364MJC";

// Pin connected to DHT11 sensor data pin
const int dhtPin = D2;

// Initialize DHT sensor
DHT dht(dhtPin, DHT11);

// Initialize WiFi client
WiFiClient client;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);

  // Give the sensor time to stabilize
  delay(2000);
}

void loop() {
  // Read temperature and humidity from DHT11
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Display data on the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, \nHumidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Update ThingSpeak fields 3 and 4
  ThingSpeak.setField(3, temperature);
  ThingSpeak.setField(4, humidity);
  int response = ThingSpeak.writeFields(channelID, apiKey);

  if (response == 200) {
    Serial.println("Data sent to ThingSpeak successfully.");
  } else {
    Serial.println("Error sending data to ThingSpeak. Check your settings.");
  }
  delay(15000);
}

#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "iPhone";
const char* password = "12345678";

const long channelID = 2304180;
const char* apiKey = "PJQC54XJX1364MJC";

const int soundSensorPin = D5; 

WiFiClient client;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  ThingSpeak.begin(client);
}

void loop() {
  int soundValue = digitalRead(soundSensorPin);

  Serial.print("Raw Sound Value: ");
  Serial.println(soundValue); // Print raw sensor value

  ThingSpeak.writeField(channelID, 5, soundValue, apiKey);

  delay(1000); 
}









