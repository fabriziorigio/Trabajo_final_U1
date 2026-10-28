#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include <cstdio>

using namespace std;
using namespace chrono;

void insercion(int a[], int n, long long &comparaciones, long long &movimientos){
    for (int i=1;i<n;i++){
        int aux=a[i];
        int j=i-1;
        while (j >= 0){
            comparaciones++;
            if (a[j] > aux) {
                a[j + 1] = a[j];
                movimientos++;
                j--;
            }
            else {
                break;
            }
        }
        a[j+1] = aux;
        movimientos++;
    }
}
void shellsort(int a[], int n, long long &comparaciones, long long &movimientos){
    for (int gap = n / 2; gap > 0; gap = gap / 2){
        for (int i = gap; i < n; i++){
            int aux = a[i];
            int j = i - gap;
            while (j>= 0){
                comparaciones++;
                if (a[j] > aux) {
                    a[j + gap] = a[j];
                    movimientos++;
                    j = j - gap;
                }
                else {
                    break;
                }
            }
            a[j + gap] = aux;
            movimientos++;
        }
    }
}
void generarDatos(int a[], int n, int patron){
    if (patron == 1) {
        for (int i = 0; i < n; i++){
            a[i] = rand() % 100000;
        }
    }
    else if (patron == 2) {
        for (int i = 0; i < n; i++){
            a[i] = i;
        }
    }
    else if (patron == 3) {
        for (int i = 0; i < n; i++){
            a[i]=n-i;
        }
    }
}
void copiarArreglo(int origen[], int destino[], int n){

    for (int i = 0; i < n; i++){
        destino[i] = origen[i];
    }
}
bool estaOrdenado(int a[], int n){


    for (int i=0;i<n-1;i++){

        if (a[i] > a[i + 1]){
            return false;
        }
    }
    return true;
}
string obtenerCommitHash(){

    FILE* pipe = _popen("git rev-parse HEAD", "r");

    if (!pipe) {
        return "no_disponible";
    }

    char buffer[128];
    string resultado;

    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        resultado += buffer;
    }

    _pclose(pipe);

    while (!resultado.empty() &&
          (resultado.back() == '\n' || resultado.back() == '\r')) {
        resultado.pop_back();
    }

    return resultado;
}
int main() {

    string commitHash=obtenerCommitHash();

    ofstream archivo("resultados.csv");

    if (!archivo){
        cout << "No se pudo crear el archivo CSV.\n";
        return 1;
    }

    archivo << "algoritmo,patron,n,repeticion,semilla,tiempo,comparaciones,movimientos,commit_hash\n";
    
    int tamanos[] = {100, 1000,10000};
	int cantidadTamanos = 3;
	int repeticiones = 30;

	for (int t = 0; t < cantidadTamanos; t++){

    int n = tamanos[t];

    for (int patron = 1; patron <= 3; patron++){

        cout << "Procesando n = " << n
             << ", patron = " << patron << "\n";

        for (int r = 0; r < repeticiones; r++){
        	unsigned int semilla = 12345 + r;
    		srand(semilla);

            int *original = new int[n];
			int *a = new int[n];

			generarDatos(original, n, patron);

			copiarArreglo(original, a, n);

			long long comparaciones = 0;
			long long movimientos = 0;

			auto inicio = steady_clock::now();

			insercion(a, n, comparaciones, movimientos);
			if (!estaOrdenado(a, n)) {
    		cout << "ERROR: Insercion no ordeno correctamente.\n";
			}

			auto fin = steady_clock::now();

			double tiempo =
    		duration<double, milli>(fin - inicio).count();

			archivo << "Insercion," << patron << ","
        	<< n << "," << r + 1 << ","
        	<< semilla << ","
        	<< tiempo << ","
        	<< comparaciones << ","
        	<< movimientos << ","
        	<< commitHash << "\n";


			copiarArreglo(original, a, n);

			comparaciones = 0;
			movimientos = 0;

			inicio = steady_clock::now();

			shellsort(a, n, comparaciones, movimientos);
			if (!estaOrdenado(a, n)){
    		cout << "ERROR: Shellsort no ordeno correctamente.\n";
			}
			fin=steady_clock::now();

			tiempo=duration<double, milli>(fin - inicio).count();

			archivo << "Shellsort," << patron << ","
        	<< n << "," << r + 1 << ","
        	<< semilla << ","
        	<< tiempo << ","
        	<< comparaciones << ","
        	<< movimientos << ","
        	<< commitHash << "\n";

			delete[] original;
			delete[] a;

        	}
    	}
	}
	archivo.close();

    return 0;
}