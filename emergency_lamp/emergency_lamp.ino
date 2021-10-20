byte MAINS_LED = 0;//PB0,UC-PHY-PIN 5
byte BATTAEY_LED = 1;//PB1,UC-PHY-PIN 6
byte MOSFET_GATE_PIN = 2;//PB2,UC-PHY-PIN 7

byte MAINS_IN_PIN = 3;//PB3,UC-PHY- 2,ADC4
byte TEST_BUTTON_PIN = 4;//PB4,UC-PHY- 3,ADC3

boolean TEST_STATE = false;

void setup() {
  pinMode(MAINS_IN_PIN, INPUT);
  pinMode(TEST_BUTTON_PIN, INPUT);
  pinMode(MAINS_LED, OUTPUT);
  pinMode(BATTAEY_LED, OUTPUT);
  pinMode(MOSFET_GATE_PIN, OUTPUT);
}

void loop() {

  if (digitalRead(TEST_BUTTON_PIN)) {
    TEST_STATE = true;
  } else {
    TEST_STATE = false;
  }


  if (!TEST_STATE) {
    if (digitalRead(MAINS_IN_PIN)) {
      digitalWrite(MAINS_LED, HIGH);
      digitalWrite(BATTAEY_LED, LOW);
      digitalWrite(MOSFET_GATE_PIN, LOW);
    } else {
      digitalWrite(BATTAEY_LED, HIGH);
      digitalWrite(MOSFET_GATE_PIN, HIGH);
      digitalWrite(MAINS_LED, LOW);
    }
  } else {
    digitalWrite(BATTAEY_LED, HIGH);
    digitalWrite(MOSFET_GATE_PIN, HIGH);
    digitalWrite(MAINS_LED, LOW);
  }

}
