import socket

IP_ESP32 = "192.168.1.37" 
PUERTO = 3333

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect((IP_ESP32, PUERTO))

print("Conectado al ESP32")

try:
    sock.settimeout(1)

    try:
        data = sock.recv(1024)
        if data:
            print(data.decode(errors="ignore"))
    except:
        pass

    while True:
        cmd = input("Envia 0,1,2,3,4 o q para salir: ")

        if cmd.lower() == 'q':
            break

        if len(cmd) > 0:
            sock.send(cmd[0].encode())
            print("Enviado:", cmd[0])

        try:
            respuesta = sock.recv(1024)
            if respuesta:
                print("ESP32:", respuesta.decode(errors="ignore").strip())
        except:
            pass

finally:
    sock.close()
    print("Conexion cerrada")
