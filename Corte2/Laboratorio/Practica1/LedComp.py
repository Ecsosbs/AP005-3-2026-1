import serial
import serial.tools.list_ports
import time

puerto = "COM3"  # Ajustar según tu equipo
baudrate = 115200

print("Puertos disponibles:")
for p in serial.tools.list_ports.comports():
    print(" ", p.device, "-", p.description)

ser = None

try:
    ser = serial.Serial(puerto, baudrate, timeout=1)
    time.sleep(2)
    print(f"Conectado en {puerto}")

    while True:
        cmd = input("Envia 0,1,2,3,4 o q para salir: ")

        if cmd.lower() == 'q':
            break

        if len(cmd) > 0:
            ser.write(cmd[0].encode())
            print("Enviado:", cmd[0])

except serial.SerialException as e:
    print("No se pudo abrir el puerto.")
    print("Posibles causas:")
    print("- El puerto está ocupado por Arduino IDE u otro programa")
    print("- El puerto no es el correcto")
    print("- El ESP32 fue desconectado")
    print()
    print("Detalle del error:")
    print(e)

finally:
    if ser is not None and ser.is_open:
        ser.close()
        print("Puerto cerrado")
