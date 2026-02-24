#include <Arduino.h>
#include <WiFi.h>
#include <WiFiManager.h>
#include <ArduinoOTA.h>

#define LED_PIN 12   // Built-in LED ESP32-C3 biasanya GPIO8

WiFiManager wm;

/* ===============================
   MORSE CONFIG
================================= */
const int dotTime = 200;
const int dashTime = dotTime * 3;
const int symbolSpace = dotTime;
const int letterSpace = dotTime * 3;
const int wordSpace = dotTime * 7;

// Morse pattern untuk SOS (... --- ...)
const char* morsePattern = "...---...";
int morseIndex = 0;

unsigned long previousMillis = 0;
bool ledState = false;
int currentDelay = dotTime;

/* ===============================
   OTA SETUP
================================= */
void setupOTA() {
  ArduinoOTA.setHostname("ESP32C3-SOS");

  ArduinoOTA.onStart([]() {
    Serial.println("Start OTA Update");
  });

  ArduinoOTA.onEnd([]() {
    Serial.println("\nOTA Finished");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress * 100) / total);
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]\n", error);
  });

  ArduinoOTA.begin();
}

/* ===============================
   NON-BLOCKING MORSE
================================= */
void handleMorse() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= currentDelay) {
    previousMillis = currentMillis;

    if (ledState) {
      digitalWrite(LED_PIN, LOW);
      ledState = false;
      currentDelay = symbolSpace;
    } else {
      char symbol = morsePattern[morseIndex];

      if (symbol == '.') {
        digitalWrite(LED_PIN, HIGH);
        currentDelay = dotTime;
      } 
      else if (symbol == '-') {
        digitalWrite(LED_PIN, HIGH);
        currentDelay = dashTime;
      }

      ledState = true;
      morseIndex++;

      if (morseIndex >= strlen(morsePattern)) {
        morseIndex = 0;
        currentDelay = wordSpace;
      }
    }
  }
}

/* ===============================
   SETUP
================================= */
void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\nBooting...");
  Serial.println("Reset reason: " + String(esp_reset_reason()));

  pinMode(LED_PIN, OUTPUT);

  wm.setConfigPortalTimeout(180);

  Serial.println("Connecting to WiFi...");

  if (!wm.autoConnect("ESP32C3-Setup")) {
    Serial.println("WiFi failed. Starting config portal.");
    wm.startConfigPortal("ESP32C3-Setup");
  }

  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  setupOTA();
}

/* ===============================
   LOOP
================================= */
void loop() {
  ArduinoOTA.handle();
  handleMorse();
}