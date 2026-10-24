#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

void insercion(int a[], int n, long long &comparaciones, long long &movimientos) {

    for (int i = 1; i < n; i++) {

        int aux = a[i];
        int j = i - 1;

        while (j >= 0) {

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

        a[j + 1] = aux;
        movimientos++;
    }
}

void generarDatos(int a[], int n, int patron) {

    if (patron == 1) {
        // Aleatorio
        for (int i = 0; i < n; i++) {
            a[i] = rand() % 100000;
        }
    }
    else if (patron == 2) {
        // Ascendente
        for (int i = 0; i < n; i++) {
            a[i] = i;
        }
    }
    else if (patron == 3) {
        // Descendente
        for (int i = 0; i < n; i++) {
            a[i] = n - i;
        }
    }
}

bool estaOrdenado(int a[], int n) {

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }

    return true;
}

int main() {

    srand(time(0));

    int tamanos[] = {1000, 10000, 100000};
    int cantidadTamanos = 3;
    int repeticiones = 30;

    cout << "ALGORITMO: INSERCION\n";
    cout << "========================================\n";

    for (int t = 0; t < cantidadTamanos; t++) {

        int n = tamanos[t];

        for (int patron = 1; patron <= 3; patron++) {

            double sumaTiempo = 0;
            double sumaComparaciones = 0;
            double sumaMovimientos = 0;

            for (int r = 0; r < repeticiones; r++) {

                int *a = new int[n];

                generarDatos(a, n, patron);

                long long comparaciones = 0;
                long long movimientos = 0;

                auto inicio = steady_clock::now();

                insercion(a, n, comparaciones, movimientos);

                auto fin = steady_clock::now();

                double tiempo = duration<double, milli>(fin - inicio).count();

                sumaTiempo += tiempo;
                sumaComparaciones += comparaciones;
                sumaMovimientos += movimientos;

                if (!estaOrdenado(a, n)) {
                    cout << "ERROR: el arreglo no fue ordenado.\n";
                }

                delete[] a;
            }

            cout << "\n";

            if (patron == 1)
                cout << "Patron: Aleatorio\n";
            else if (patron == 2)
                cout << "Patron: Ascendente\n";
            else
                cout << "Patron: Descendente\n";

            cout << "n: " << n << "\n";
            cout << "Repeticiones: " << repeticiones << "\n";
            cout << "Tiempo promedio: "
                 << sumaTiempo / repeticiones << " ms\n";

            cout << "Comparaciones promedio: "
                 << sumaComparaciones / repeticiones << "\n";

            cout << "Movimientos promedio: "
                 << sumaMovimientos / repeticiones << "\n";

            cout << "----------------------------------------\n";
        }
    }

    return 0;
}