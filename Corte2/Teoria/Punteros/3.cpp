#include <iostream> // Biblioteca para entrada y salida en C++

using namespace std;

int main() { // Función principal del programa

    int x = 25; // Variable entera con valor inicial 25
    int *p = &x;

    cout << "x = " << x << endl; // Muestra el valor directo de x

    cout << "*p = " << *p << endl; // Muestra la dirección de x

    *p = 99; /*modifica x indirecramente mediante pintero p */
    
    cout << "x =" << x << endl;/*muestra x despues de la modificacion indirecta*/
    
    return 0; // Finalización exitosa del programa
}
