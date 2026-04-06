#include <WiFi.h>

const char* ssid = "FAMILIA DE SUSY";
const char* password = "Susy7801";

WiFiServer server(3333);
WiFiClient client;

const int LED_PIN = 2;

char modo = '0';
unsigned long t0 = 0;
bool ledState = false;
int pasoDoble = 0;

void setLed(bool estado) {
  ledState = estado;
  digitalWrite(LED_PIN, estado ? HIGH : LOW);
}

void enviarRespuesta(const char* msg) {
  Serial.println(msg);
  if (client && client.connected()) {
    client.println(msg);
  }
}

void procesarComando(char c) {
  switch (c) {
    case '0':
      modo = '0';
      setLed(false);
      enviarRespuesta("Modo 0: LED apagado");
      break;

    case '1':
      modo = '1';
      setLed(true);
      enviarRespuesta("Modo 1: LED encendido fijo");
      break;

    case '2':
      modo = '2';
      t0 = millis();
      enviarRespuesta("Modo 2: parpadeo lento");
      break;

    case '3':
      modo = '3';
      t0 = millis();
      enviarRespuesta("Modo 3: parpadeo rapido");
      break;

    case '4':
      modo = '4';
      t0 = millis();
      pasoDoble = 0;
      setLed(false);
      enviarRespuesta("Modo 4: doble destello");
      break;

    default:
      enviarRespuesta("Comando no valido. Use 0,1,2,3,4");
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

void conectarWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Conectando a WiFi ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi conectada");
  Serial.print("IP del ESP32: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  setLed(false);

  Serial.begin(115200);
  delay(500);

  conectarWiFi();

  server.begin();
  Serial.println("Servidor TCP iniciado en puerto 3333");
}

void loop() {
  if (!client || !client.connected()) {
    WiFiClient nuevoCliente = server.available();
    if (nuevoCliente) {
      client = nuevoCliente;
      Serial.println("Cliente conectado");
      client.println("Conectado al ESP32");
    }
  }

  if (client && client.connected()) {
    while (client.available() > 0) {
      char c = client.read();

      if (c != '\n' && c != '\r') {
        Serial.print("Recibido: ");
        Serial.println(c);
        procesarComando(c);
      }
    }
  }

  actualizarPatron();
}
