const int LED_PIN = 2;

char modo = '0';
unsigned long t0 = 0;
bool ledState = false;
int pasoDoble = 0;

void setLed(bool estado) {
  ledState = estado;
  digitalWrite(LED_PIN, estado ? HIGH : LOW);
}

void procesarComando(char c) {
  switch (c) {
    case '0':
      modo = '0';
      setLed(false);
      Serial.println("Modo 0: LED apagado");
      break;

    case '1':
      modo = '1';
      setLed(true);
      Serial.println("Modo 1: LED encendido fijo");
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
      setLed(false);
      Serial.println("Modo 4: doble destello");
      break;

    default:
      Serial.print("Comando no valido: ");
      Serial.println(c);
      Serial.println("Use 0, 1, 2, 3 o 4");
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
        setLed(!ledState);
      }
      break;

    case '3':
      if (ahora - t0 >= 150) {
        t0 = ahora;
        setLed(!ledState);
      }
      break;

    case '4':
      switch (pasoDoble) {
        case 0:
          setLed(true);
          pasoDoble = 1;
          t0 = ahora;
          break;

        case 1:
          if (ahora - t0 >= 100) {
            setLed(false);
            pasoDoble = 2;
            t0 = ahora;
          }
          break;

        case 2:
          if (ahora - t0 >= 100) {
            setLed(true);
            pasoDoble = 3;
            t0 = ahora;
          }
          break;

        case 3:
          if (ahora - t0 >= 100) {
            setLed(false);
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
  pinMode(LED_PIN, OUTPUT);
  setLed(false);

  Serial.begin(115200);
  delay(500);

  Serial.println();
  Serial.println("ESP32 listo.");
  Serial.println("Enviar:");
  Serial.println("0 = apagado");
  Serial.println("1 = fijo");
  Serial.println("2 = lento");
  Serial.println("3 = rapido");
  Serial.println("4 = doble destello");
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
