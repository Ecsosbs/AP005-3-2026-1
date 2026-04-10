# 📡 Monitoreo de Potenciómetro con ESP32 y Python

## 🧠 Descripción del proyecto

Este proyecto consiste en la lectura de un potenciómetro usando un ESP32, el envío de los datos al computador mediante comunicación serial, su almacenamiento en un archivo CSV con Python y su visualización en una página web usando Flask.

El sistema integra conceptos de electrónica, programación y desarrollo web.

---

## ⚙️ Tecnologías utilizadas

* ESP32 (Arduino IDE)
* Python 3
* Flask
* Pandas
* Matplotlib
* PySerial
* HTML

---

## 🔄 Funcionamiento del sistema

1. El potenciómetro genera una señal analógica.
2. El ESP32 la convierte a un valor digital (0 - 4095).
3. Los datos se envían por puerto serial al computador.
4. Python recibe los datos y los guarda en un archivo CSV.
5. Flask lee el CSV, genera una gráfica y muestra los datos en una página web.
6. El navegador muestra los resultados en tiempo real.

---

## 📂 Estructura del proyecto

```
mi_proyecto_iot/
│
├── app.py
├── serial_a_csv.py
├── datos_potenciometro.csv
│
├── templates/
│   └── index.html
│
└── static/
    └── grafica_potenciometro.png
```

---

## ▶️ Ejecución del proyecto

1. Conectar el ESP32 al computador.
2. Ejecutar el script de lectura serial:

```
python serial_a_csv.py
```

3. En otra terminal ejecutar el servidor web:

```
python app.py
```

4. Abrir el navegador en:

```
http://127.0.0.1:5000
```

---

## 📊 Resultados

El sistema permite visualizar:

* Lectura en tiempo real del potenciómetro
* Gráfica de las últimas muestras
* Tabla de datos
* Resumen estadístico (mínimo, máximo, promedio)

---

## 🧪 Evidencia

El sistema responde correctamente al movimiento del potenciómetro, actualizando los datos y la gráfica en tiempo real.
![WhatsApp Image 2026-04-10 at 1 18 15 PM](https://github.com/user-attachments/assets/f147da47-5a8a-4c31-8493-f1f07e2255ca)
![Sin título](https://github.com/user-attachments/assets/0c497ba4-ba68-4d57-8d76-2f5aadad1243)
![Sin título2](https://github.com/user-attachments/assets/62df56d5-3ffb-47ad-a857-838b4bcf8913)


## 👨‍💻 Autor

Proyecto realizado por: [Marlon Marquez-Jhon Niño]

