#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void Reduce(int A[], int inicio, int final) {
    if (inicio >= final) {
        return ;
    }

    int izq = inicio;
    int der = final;
    int pivote = A[inicio]; 

    while (izq < der) {
        while (A[der] > pivote && izq < der) {
            der--;
        }
        while (A[izq] <= pivote && izq < der) {
            izq++;
        }
        if (izq < der) {
            swap(A[izq], A[der]);
        }
    }

    A[inicio] = A[der];
    A[der] = pivote;

    Reduce(A, inicio, der - 1);
    Reduce(A, der + 1, final);
}

void QuickSort(int A[], int n) {
    Reduce(A, 0, n - 1);
}

void InterDirIzq(int A[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j > i - 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
            }
        }
    }
}

void imprimirLista(int A[], int tam) {
    cout << "Lista: ( ";
    for (int i = 0; i < tam; i++) {
        if (i == tam - 1) {
            cout << A[i] << " ) ";
        } else {
            cout << A[i] << " , ";
        }
    }
    cout << endl;
}

int main() {
    int resp;
	int resp2=0;
	int tam;
	do{
	
		if(resp2!=0){
			cout << "\nELIJA :";
	        cout << "\n1) Denuevo?";
	        cout << "\n0) Salir";
	        cout << "\nresp: ";
	        cin >> resp2;
		}else{
			resp2=1;
		}
		
	        
	    srand(time(0));
	    
	    cout << "Ingrese la cantidad de términos a evaluar\n";
	    cin >> tam;
	
	    int QUICK[tam];
	    int ORDI[tam];
	    int A[tam];
	    for (int i = 0; i < tam; i++) {
	        A[i] = rand() % tam + 1;
	    }
	
	    imprimirLista(A, tam);
	
	    // Copiamos los datos generados a los arreglos
	    for (int i = 0; i < tam; i++) {
	        QUICK[i] = A[i];
	        ORDI[i] = A[i];
	    }
    
	
		
	    do {
	        cout << "\nELIJA EL METODO DE ORDENAMIENTO:";
	        cout << "\n1) Quicksort";
	        cout << "\n2) Ordenamiento directo por la izquierda";
	        cout << "\n0) Salir";
	        cout << "\nresp: ";
	        cin >> resp;
	
	        if (resp == 1) {
	        	int copia[tam];
				int repeticiones = 1000;
				auto dura1=0;
				  // Repite QuickSort 1000 veces
    			

    			for (int i = 0; i < repeticiones; i++) {
        		
        		for (int j = 0; j < tam; j++) copia[j] = QUICK[j];  // Hacer una copia del arreglo original
        			auto inicio = high_resolution_clock::now();	
        			QuickSort(copia, tam);
        			auto fin = high_resolution_clock::now();
    				auto duracion = duration_cast<microseconds>(fin - inicio).count();
    				dura1+=duracion;
    			}

    			
				imprimirLista(copia, tam);
    			cout << "Tiempo promedio por ejecucion: " << dura1 / repeticiones << " microsegundos" << endl;
	        } else if (resp == 2) {
				int copia[tam];
				auto dura=0;
	        	int repeticiones = 1000;  // Repite  1000 veces
    			auto inicio2 = high_resolution_clock::now();

    			for (int i = 0; i < repeticiones; i++) {
        		
        		for (int j = 0; j < tam; j++) copia[j] = ORDI[j];  // Hacer una copia del arreglo original
        			
					auto inicio2 = high_resolution_clock::now();
        			InterDirIzq(copia, tam);
					auto fin2 = high_resolution_clock::now();
	            	auto duracion2 = duration_cast<microseconds>(fin2 - inicio2).count();
		
					dura+=duracion2;
    			}
	            
	            
	            
	            imprimirLista(copia, tam);
	            cout << "Tiempo de promedio de ejecución: " << dura/repeticiones<< " microsegundos" << endl;
	        } else if (resp == 0) {
	            cout << "Saliendo del programa..." << endl;
	        } else {
	            cout << "Opción inválida. Intente de nuevo." << endl;
	        }
	
	    } while (resp != 0);
	}while(resp2==1);
    return 0;
}
