#define BLYNK_TEMPLATE_ID   "*************"
#define BLYNK_TEMPLATE_NAME "Energy Monitoring and Theft Detection System"
#define BLYNK_AUTH_TOKEN    "********************************"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// WiFi
char ssid[] = "YOUR WIFI";
char pass[] = "YOUR WIFI PASSWORD";

BlynkTimer timer;

// Pins
#define VOLTAGE_PIN 34
#define CURRENT_PIN 35

#define GREEN_LED 25
#define RED_LED   26
#define BUZZER    27

// Variables
float voltage = 0;
float current = 0;
float power   = 0;

float theftThreshold = 5.0;

bool alertSent = false;

// Smooth values
float smoothV = 0;
float smoothI = 0;
float smoothP = 0;

// 🎬 Welcome Animation
void showWelcome() {
  for (int x = -120; x < 20; x += 5) {
    display.clearDisplay();
    display.setTextSize(1);

    display.setCursor(x, 20);
    display.println("WELCOME TEAM");

    display.setCursor(x, 35);
    display.println("NEURO VOLT");

    display.display();
    delay(150);
  }
}

// 📡 MAIN FUNCTION
void sendData() {

  // -------- VOLTAGE --------
  float sumV = 0;
  for (int i = 0; i < 100; i++) {
    float val = analogRead(VOLTAGE_PIN) - 2048;
    sumV += val * val;
    delayMicroseconds(200);
  }

  float Vrms = sqrt(sumV / 100.0);

  // FIXED CALIBRATION
  voltage = Vrms * 1.6;
  if (voltage < 50) voltage = 0;

  // -------- CURRENT --------
  float sumI = 0;
  for (int i = 0; i < 100; i++) {
    float val = analogRead(CURRENT_PIN) - 2048;   // IMPORTANT
    sumI += val * val;
    delayMicroseconds(200);
  }

  float Irms = sqrt(sumI / 100.0);

  // FIXED CALIBRATION
  current = Irms * 0.02;
  if (current < 0.1) current = 0;

  // -------- POWER --------
  power = voltage * current;

  // -------- SMOOTH --------
  smoothV = 0.8 * smoothV + 0.2 * voltage;
  smoothI = 0.8 * smoothI + 0.2 * current;
  smoothP = 0.8 * smoothP + 0.2 * power;

  // -------- SERIAL --------
  Serial.print("V: "); Serial.println(smoothV);
  Serial.print("I: "); Serial.println(smoothI);
  Serial.print("P: "); Serial.println(smoothP);

  // -------- OLED --------
  display.clearDisplay();
  display.setTextSize(1);

  display.setCursor(0, 0);
  display.print("Voltage: ");
  display.print(smoothV, 1);

  display.setCursor(0, 20);
  display.print("Current: ");
  display.print(smoothI, 2);

  display.setCursor(0, 40);
  display.print("Power: ");
  display.print(smoothP, 1);

  // -------- BLYNK --------
  Blynk.virtualWrite(V0, smoothV);
  Blynk.virtualWrite(V1, smoothI);
  Blynk.virtualWrite(V2, smoothP);

  // -------- THEFT --------
  if (smoothI > theftThreshold) {

    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BUZZER, HIGH);

    display.setCursor(0, 55);
    display.print("THEFT ALERT!");

    if (!alertSent) {
      Blynk.logEvent("theft_alert", "⚠ Theft Detected!");
      alertSent = true;
    }

    Blynk.virtualWrite(V3, 1);

  } else {

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);

    alertSent = false;
    Blynk.virtualWrite(V3, 0);
  }

  display.display();
}

// ⚙ SETUP
void setup() {

  Serial.begin(115200);
  Wire.begin(21, 22);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  // OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found!");
    while (1);
  }

  display.setTextColor(WHITE);
  showWelcome();

  // WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  Serial.print("Connecting WiFi");
  int retry = 0;

  while (WiFi.status() != WL_CONNECTED && retry < 20) {
    delay(500);
    Serial.print(".");
    retry++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Connected!");
  } else {
    Serial.println("\nWiFi Failed!");
  }

  // Blynk
  Blynk.config(BLYNK_AUTH_TOKEN);
  Blynk.connect(5000);

  // Timer
  timer.setInterval(1000L, sendData);
}

// LOOP
void loop() {
  if (Blynk.connected()) {
    Blynk.run();
  }
  timer.run();
}
