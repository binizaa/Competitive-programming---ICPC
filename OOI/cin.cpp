#include <iostream> // Libreria
using namespace std;

int main() { 

    int n; 
    cin>>n; // Entrada
    cin.ignore(); //Ignorar el salto de linea
    cout<<"Numero: "<<n<<endl;

    string nombre;
    //cin>>nombre;  // Solo guarda la primera palabra
    getline(cin, nombre); // Guarda todo lo ingresado en la linea

    cout<<"Nombre: "<<nombre<<endl;

    return 0; 
}

/*
Compilar
g++ A.cpp -o ./A

Correr el programa
./A

- Remplazar A por el nombre de su programa


---- Entrada y salida desde archivos de textos

cin -> entrada.txt
cout -> salida.txt

./A < entrada.txt > salida.txt
*/