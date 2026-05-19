#include <iostream> // Biblioteca para entrada y salida en C++

using namespace std;

void cambiar(int n){ // n recibe una copia del valor enviado desde main
    
    n = 100; // se modifica la copia local, no la variable original
    
    cout << "Dentro de cambiar: n" << n <<endl; //Muestra la copia modificada
}

int main() { // Función principal del programa

    int x = 5; // Variable original
    
    cout << "Antes: x = " << x <<endl;//muestra x antes de llamar la funcion
    
    cambiar(x); //se envia el valor de x. la funcion recibe una copia

    cout << "Despues: x = " << x << endl; // x no cambia porque solo se modifico la copia
    
    return 0; // Finalización exitosa del programa
}
