const int leds[] = {13, 12, 14, 27, 26, 25, 33, 32, 4};
const int NUM_LEDS = 9;

char modo = '0';
unsigned long t0 = 0;
bool ledState = false;
int pasoDoble = 0;

void setLeds(bool estado) {
  ledState = estado;
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(leds[i], estado ? HIGH : LOW);
  }
}

void procesarComando(char c) {
  switch (c) {
    case '0':
      modo = '0';
      setLeds(false);
      Serial.println("Modo 0: LEDs apagados");
      break;

    case '1':
      modo = '1';
      setLeds(true);
      Serial.println("Modo 1: LEDs encendidos");
      break;

    case '2':
      modo = '2';
      t0 = millis();
      Serial.println("Modo 2: parpadeo lento");
      break;

    case '3':
      modo = '3';
      t0 = millis();
      Serial.println("Modo 3: parpadeo rapido");
      break;

    case '4':
      modo = '4';
      t0 = millis();
      pasoDoble = 0;
      setLeds(false);
      Serial.println("Modo 4: doble destello");
      break;

    default:
      Serial.println("Comando no valido");
      break;
  }
}

void actualizarPatron() {
  unsigned long ahora = millis();

  switch (modo) {
    case '0':
      break;

    case '1':
      break;

    case '2':
      if (ahora - t0 >= 500) {
        t0 = ahora;
        setLeds(!ledState);
      }
      break;

    case '3':
      if (ahora - t0 >= 150) {
        t0 = ahora;
        setLeds(!ledState);
      }
      break;

    case '4':
      switch (pasoDoble) {
        case 0:
          setLeds(true);
          pasoDoble = 1;
          t0 = ahora;
          break;

        case 1:
          if (ahora - t0 >= 100) {
            setLeds(false);
            pasoDoble = 2;
            t0 = ahora;
          }
          break;

        case 2:
          if (ahora - t0 >= 100) {
            setLeds(true);
            pasoDoble = 3;
            t0 = ahora;
          }
          break;

        case 3:
          if (ahora - t0 >= 100) {
            setLeds(false);
            pasoDoble = 4;
            t0 = ahora;
          }
          break;

        case 4:
          if (ahora - t0 >= 700) {
            pasoDoble = 0;
            t0 = ahora;
          }
          break;
      }
      break;
  }
}

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }

  setLeds(false);

  Serial.begin(115200);
  delay(500);

  Serial.println("ESP32 listo con 9 LEDs");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c != '\n' && c != '\r') {
      procesarComando(c);
    }
  }

  actualizarPatron();
}
