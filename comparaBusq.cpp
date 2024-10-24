#include <iostream>
#include <chrono>
#include <windows.h>

using namespace std;

// Prototipos
int SecuencialOrd(int[], int, int, int&);
int Binaria(int[], int, int, int&);
void tiempoSecuencial(int[], int, int);
void tiempoBinaria(int[], int, int);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n, op, dato;

    cout << "Digite la cantidad:\n"; 
    cin >> n;
    int numeros[n];

    // Generar números aleatorios sin repetición
    for (int i = 0; i < n; i++) {
        numeros[i] = i + 1; 
    }

    cout << endl;

    cout << "Arreglo:\n";
    for (int i = 0; i < n; i++) {
        cout << numeros[i] << " ";
    }

    do {
        cout << "\n\n\nBienvenido a la comparacion de dos metodos de ordenamiento y busqueda"
             << "\n1. Búsqueda Secuencial."
             << "\n2. Búsqueda Binaria."
             << "\n0. Salir.\nDigite una opción: \n";

        cin >> op;

        switch (op) {
            case 1:
                cout << "\nDigite el número a buscar: "; 
                cin >> dato;
                tiempoSecuencial(numeros, n, dato);                
                break;
            case 2:
                cout << "\nDigite el número a buscar: "; 
                cin >> dato;
                tiempoBinaria(numeros, n, dato);
                break;
        }
    } while (op != 0);

    return 0;
}

// Búsqueda Secuencial
int SecuencialOrd(int A[], int n, int dato, int& comparaciones) {
    int i = 0;
    comparaciones = 0; 

    while (i < n && A[i] < dato) {
        comparaciones++; 
        i++;
    }
    
    comparaciones++; 
    if (i >= n || A[i] > dato) {
        return -i;
    } else {
        return i;
    }
}

void tiempoSecuencial(int A[], int n, int dato) {
    const int repeticiones = 100000;  
    int comparaciones = 0;
    int resultado = -1;

    auto inicio = chrono::high_resolution_clock::now();

    for (int i = 0; i < repeticiones; i++) {
        int tempComparaciones = 0;
        resultado = SecuencialOrd(A, n, dato, tempComparaciones);
        comparaciones = tempComparaciones;  
    }

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duracion = fin - inicio;  

    cout << "\nEl tiempo total de ejecución para " << repeticiones << " repeticiones de la Búsqueda Secuencial fue de: "
         << duracion.count() << " milisegundos." << endl;
    cout << "El tiempo promedio por ejecución fue de: " << duracion.count() / repeticiones << " milisegundos." << endl;

    if (resultado >= 0)
        cout << "Número encontrado en la posición: " << resultado << endl;
    else
        cout << "Número no encontrado. " << resultado << endl;

    cout << "Número de comparaciones en la última búsqueda: " << comparaciones << endl;
}

// Búsqueda Binaria
int Binaria(int A[], int n, int dato, int& comparaciones) {
    int izq = 0;
    int der = n - 1; 
    int pos = -1;
    comparaciones = 0; 

    while (izq <= der) {
        comparaciones++; 
        int m = (izq + der) / 2;
        if (A[m] == dato) {
            return m; 
        } else if (dato > A[m]) {
            izq = m + 1;
        } else {
            der = m - 1;
        }
    }

    return -izq;
}

void tiempoBinaria(int A[], int n, int dato) {
    const int repeticiones = 100000;
    int comparaciones_totales = 0;
    
    int resultado = Binaria(A, n, dato, comparaciones_totales);
    
    auto inicio = chrono::high_resolution_clock::now();
    int comparaciones = 0;

    for (int i = 0; i < repeticiones; i++) {
        resultado = Binaria(A, n, dato, comparaciones);
    }

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duracion = fin - inicio;

    cout << "\nEl tiempo total de ejecución para " << repeticiones << " repeticiones de la Búsqueda Binaria fue de: " << duracion.count() << " milisegundos." << endl;
    cout << "El tiempo promedio por ejecución fue de: " << duracion.count() / repeticiones << " milisegundos." << endl;
    cout << "Número total de comparaciones en la última búsqueda: " << comparaciones << endl; 
}
