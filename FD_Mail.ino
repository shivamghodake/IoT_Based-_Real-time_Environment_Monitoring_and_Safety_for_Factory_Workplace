// API - api-F3F49AAE2A904002AF45B55564CAECCA

// username - shivam.ghodake22@vit.edu
// fgotoTC3RYcR2HLH

// SMTP Server:  mail.smtp2go.com

// SMTP Port: 2525

// encode
// c2hpdmFtLmdob2Rha2UyMkB2aXQuZWR1 : username
// ZmdvdG9UQzNSWWNSMkhMSA==  : PAss
// LPG, propane, hydrogen, methane, and smoke

#include <ESP8266WiFi.h>
const char* ssid = "iPhone";
const char* password = "12345678";
const char* server = "mail.smtp2go.com";
const int flame = D0;
const int buzz = D1;
WiFiClient client;

int previousFlameState = -1;

void setup() {
  pinMode(flame, INPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(115200);
  connectToWiFi();
}

void loop() {
  int currentFlameState = digitalRead(flame);
  if (currentFlameState != previousFlameState) {
    if (currentFlameState == LOW) {
      digitalWrite(buzz, HIGH);
      sendEmail();
      Serial.println("Mail sent to:   shivam.ghodake22@gmail.com");
    } else {
      digitalWrite(buzz, LOW);
    }
    previousFlameState = currentFlameState;
  }
  delay(100);
}

void connectToWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
void sendEmail() {
  if (client.connect(server, 2525)) {
    Serial.println("Connected to server");
    if (!emailResp()) return;
    client.println("EHLO www.example.com");
    if (!emailResp()) return;
    client.println("AUTH LOGIN");
    if (!emailResp()) return;
    client.println("c2hpdmFtLmdob2Rha2UyMkB2aXQuZWR1"); // SMTP Username (base64 encoded)
    if (!emailResp()) return;
    client.println("ZmdvdG9UQzNSWWNSMkhMSA=="); // SMTP Password (base64 encoded)
    if (!emailResp()) return;
    client.println("MAIL From: ghodakeshivam23@gmail.com");
    if (!emailResp()) return;
    client.println("RCPT To: shivam.ghodake22@gmail.com");
    if (!emailResp()) return;
    client.println("DATA");
    if (!emailResp()) return;
    client.println("To: shivam.ghodake22@gmail.com");
    client.println("From: ghodakeshivam23@gmail.com");
    client.println("Subject: Fire Alarm\r\n");
    client.println("Attention: Fire Detected.\n");
    client.println(".");
    if (!emailResp()) return;
    client.println("QUIT");
    emailResp();

    client.stop();
    Serial.println("Email sent");
  } else {
    Serial.println("Connection failed");
  }
}

boolean emailResp() {
  int loopCount = 0;
  while (!client.available()) {
    delay(1);
    if (++loopCount > 20000) {
      client.stop();
      Serial.println("\nTimeout");
      return false;
    }
  }

  while (client.available()) {
    char readByte = client.read();
    Serial.write(readByte);
  }
  return true;
}


#include <ESP8266WiFi.h>
const char* ssid = "Adi";
const char* password = "Adi4998";
const char* server = "mail.smtp2go.com";
const int gasSensorPin = A0; 
const int buzz = D1;
WiFiClient client;

int previousGasState = -1;

void setup() {
  pinMode(gasSensorPin, INPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(115200);
  connectToWiFi();
}

void loop() {
  int currentGasState = analogRead(gasSensorPin);

  // You may need to adjust the threshold value for gas detection based on your sensor
  if (currentGasState > 400) {
    digitalWrite(buzz, HIGH);
    sendGasAlertEmail();
    Serial.println("Gas leak detected! Email sent.");
    delay(5000); // Wait for a few seconds to prevent continuous alerts
  } else {
    digitalWrite(buzz, LOW);
  }

  delay(1000); // Adjust the delay as needed to control sensor reading frequency
}

void connectToWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void sendGasAlertEmail() {
  if (client.connect(server, 2525)) {
    Serial.println("Connected to server");
    if (!emailResp()) return;
    client.println("EHLO www.example.com");
    if (!emailResp()) return;
    client.println("AUTH LOGIN");
    if (!emailResp()) return;
    client.println("c2hpdmFtLmdob2Rha2UyMkB2aXQuZWR1"); // SMTP Username (base64 encoded)
    if (!emailResp()) return;
    client.println("ZmdvdG9UQzNSWWNSMkhMSA=="); // SMTP Password (base64 encoded)
    if (!emailResp()) return;
    client.println("MAIL From: ghodakeshivam23@gmail.com");
    if (!emailResp()) return;
    client.println("RCPT To: shivam.ghodake22@gmail.com");
    if (!emailResp()) return;
    client.println("DATA");
    if (!emailResp()) return;
    client.println("To: shivam.ghodake22@gmail.com");
    client.println("From: ghodakeshivam23@gmail.com");
    client.println("Subject: Gas Leakage Alert\r\n");
    client.println("Attention: Gas Leakage Detected.\n");
    client.println(".");
    if (!emailResp()) return;
    client.println("QUIT");
    emailResp();

    client.stop();
    Serial.println("Email sent");
  } else {
    Serial.println("Connection failed");
  }
}

boolean emailResp() {
  int loopCount = 0;
  while (!client.available()) {
    delay(1);
    if (++loopCount > 20000) {
      client.stop();
      Serial.println("\nTimeout");
      return false;
    }
  }

  while (client.available()) {
    char readByte = client.read();
    Serial.write(readByte);
  }
  return true;
}






