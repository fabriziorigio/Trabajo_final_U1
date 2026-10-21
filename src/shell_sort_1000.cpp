#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

int main() {
    int n = 1000, a[1000];
    long long comparaciones = 0, desplazamientos = 0;

    srand(1234);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000;
    }
    auto inicio = steady_clock::now();
    for (int salto=n/2;salto>0;salto=salto/2) {
        for (int i=salto;i<n;i++) {
            int aux=a[i];
            int j=i;
            while(j>=salto) {
                comparaciones++;
               if (a[j-salto]<=aux) {
                    break;
                }
                a[j]=a[j-salto];
                desplazamientos++;
                j=j-salto;
            }
            a[j]=aux;
        }
    }
    auto fin=steady_clock::now();

    double tiempo =
        duration<double, milli>(fin - inicio).count();

    cout << "\n--- SHELLSORT ---\n";
    cout << "Elementos: " << n << endl;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Desplazamientos: " << desplazamientos << endl;
    cout << "Tiempo: " << tiempo << " ms" << endl;

    return 0;
}

