#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "Soil Monitor"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi Credentials
char ssid[] = "YourWiFiName";
char pass[] = "YourPassword";

// Pins
#define soilPin A0
#define relayPin D1
#define wifi_led D4

// Variables
int threshold = 600;
bool notificationSent = false;

unsigned long old = 0;
unsigned long current = 0;
int interval = 10;

// Motor Control (Blynk Button V1)
BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(relayPin, value);
  
  if(value == 1)
    Serial.println("Motor ON");
  else
    Serial.println("Motor OFF");
}

void setup() {
  Serial.begin(115200);
  Serial.println("\nConnecting to Blynk...");

  pinMode(relayPin, OUTPUT);
  pinMode(wifi_led, OUTPUT);

  digitalWrite(relayPin, LOW);

  WiFi.begin(ssid, pass);
  wifi_testing();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  Serial.println("Connected to Blynk");
}

void loop() {
  Blynk.run();
  wifi_testing();

  checkSoil();  // continuous check
}


void checkSoil() {

  int moisture = analogRead(soilPin);

  Serial.print("Soil Value: ");
  Serial.println(moisture);

  Blynk.virtualWrite(V0, moisture);

  // Condition: Soil Dry
  if (moisture > threshold) {

    if (!notificationSent) {
      Serial.println("Sending Notification...");

      Blynk.logEvent("soil_low", "Soil moisture is LOW!");

      Serial.println("Notification Sent");

      notificationSent = true;
      delay(3000); // small delay like reference code
    } 
    else {
      Serial.println("Already Sent (Waiting Reset)");
    }

  } 
  else {
    if (notificationSent) {
      Serial.println("Soil Normal → Reset Notification");
    }
    notificationSent = false;
  }

  delay(2000); // stable reading
}

// WiFi Check Function (same as your reference)
void wifi_testing() {
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
    digitalWrite(wifi_led, LOW);
    delay(250);
    digitalWrite(wifi_led, HIGH);

    current = millis();
    if ((current - old) / 1000 > interval)
      ESP.restart();
  }
}
