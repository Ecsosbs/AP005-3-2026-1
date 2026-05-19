#include <iostream> // Biblioteca para entrada y salida en C++

using namespace std;

int main() { // Función principal del programa

    int x = 25; // Variable entera con valor inicial 25

    int* p = &x; // p guarda la dirección de x

    cout << "x = " << x << endl; // Muestra el valor directo de x

    cout << "&x = " << &x << endl; // Muestra la dirección de x

    cout << "p = " << p << endl; // Muestra la dirección guardada en p

    cout << "*p = " << *p << endl; // Muestra el contenido apuntado por p

    return 0; // Finalización exitosa del programa
}
