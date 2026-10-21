#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

int main() {
    int n = 10000;
    vector<int> a(n);
    srand(1234);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000;
    }
    long long comparaciones = 0;
    long long desplazamientos = 0;

    auto inicio = steady_clock::now();

    for (int i=1;i<n;i++) {
        int aux=a[i];
        int j=i-1;
        while (j >= 0) {
            comparaciones++;
            if (a[j] > aux) {
                a[j + 1] = a[j];
                desplazamientos++;
                j--;
            } else {
                break;
            }
        }
        a[j + 1] = aux;
    }
    auto fin = steady_clock::now();

    double tiempo =
        duration<double, milli>(fin - inicio).count();

    cout << "\n--- INSERTION SORT ---\n";
    cout << "Elementos: " << n << endl;
    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Desplazamientos: " << desplazamientos << endl;
    cout << "Tiempo: " << tiempo << " ms" << endl;
    return 0;
}

