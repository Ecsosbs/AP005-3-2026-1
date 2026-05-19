#include <iostream> // Biblioteca para entrada y salida en C++

using namespace std;

int main() { // Función principal del programa

    int x = 5; // Variable entera con valor inicial 5
    
    int *p = &x;
    
    *p = 40; //desreferenciacion de puntero: aqui el * dorma parte de la declaracion

    cout << "x = " << x << endl; // Muestra el valor final de x
    
    return 0; // Finalización exitosa del programa
}
