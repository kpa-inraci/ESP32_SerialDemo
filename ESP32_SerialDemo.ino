
// ESP32 Serial Demo - Universel pour GitHub

const int ledPin = 2;         // LED intégrée
const int buttonPin = 0;      // Bouton (GPIO0 ou autre selon votre carte)
bool ledState = false;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.println("[ESP32] Démarrage du système...");
}

void loop() {
  static unsigned long lastTime = 0;
  unsigned long now = millis();

  // Toutes les 2 secondes
  if (now - lastTime >= 2000) {
    lastTime = now;

    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    
    bool buttonPressed = digitalRead(buttonPin) == LOW;

    Serial.print("[ESP32] LED: ");
    Serial.print(ledState ? "ON" : "OFF");
    Serial.print(" | Bouton appuyé: ");
    Serial.println(buttonPressed ? "OUI" : "NON");
  }
}
