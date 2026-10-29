# Comparación experimental de algoritmos de ordenamiento

 Descripción del proyecto:
 Este proyecto busca realizar una comparacion experimental entre los algoritmos de ordenamiento Insercion y Shellsort.
 El objetivo es analizar el rendimiento eficiencia de estos algoritmos en el que consideraremos los diferentes tamaños y patrones de entrada. Se registro 3 metricas: tiempo, comparaciones y movimientos.
 Los experimentos se realizaron con los tamaños de entrada de 100, 1000 y 10000 elementos, usando los patrones aleatorio, ascendente y descendente, cada combinacion fue ejecutada 30 veces. utilizando los mismos datos de entrada para ambos algoritmos con el fin de realizar una comparacion justa.

Mi nombre es Fabrizio Rigio Apaza Vizcarra, soy estudiante de la ESIS de la UNJBG.

Algoritmos que se seleccionaron:
Los algorimos que seleccione para el proyecto son:
Insercion:
El algoritmo de insercion ordena los elementos recorriendo el arreglo y colocando cada elemento en su posicion correspondiente dentro de la parte previamente ordenada.

Shellsort:
Shellsort es una mejora del metodo insercion que utiliza intervalos conocidos como gaps o saltos, que tienen como utilidad comparar y desplazar elementos que se encuentran a mayor distancia. El intervalo se reduce progresivamente hasta llegar a uno.

Requisitos para la compilacion y ejecucion:
Para ejecutar el proyecto se requiere:
- Sistema operativo Windows
- Compilador compatible con C++
- Dev-C++ con MinGW o un compilador equivalente.
- Git para obtner el commit_hash usado en el experimento.
   
El codigo utiliza caracteristicas estandar de las librerias de C++:
<iostream>
<fstream>
<cstdlib>
<ctime>
<chrono>
<string>
<cstdio>

El programa principal para reproducir el experimento es:
src/benchmark.cpp, en Dev-C++ se puede abrir el archivo compilarlo y ejecutarlo, aunque tammbien puede compilarse mediante un compilador C++ desde la terminal: g++ src/benchmark.cpp -o benchmark.exe y se ejecuta: ./benchmark.exe
despues el programa generara el archivo resultados.csv.

**Reproduccion de los experimentos:**
El benchmark evalua los dos algoritmos utilizados:
Tamaños de entrada
n = 100
n = 1000
n = 10000
Patrones de entrada:
Patron 1 aleatorio: Los elementos se generan mediante valores pseudoaleatorios.
Patron 2 ascendente: Los elementos se generan previamente ordenados de menor a mayor.
Patron 3 descendente: Se generan los datos de mayor a menor.

Numeros de repeticiones:
Cada combinacion de algorimo, tamaño y patron se ejecuta 30 repeticiones y en total se obtienen: 2 algoritmos × 3 tamaños × 3 patrones × 30 repeticiones = 540 ejecuciones.
Para garantizar que se reproduzcan datos aleatorios se utilizan semillas controladas:
unsigned int semilla = 12345 + r;
srand(semilla);
Ademas, ambos algoritmos reciben exactamente el mismo arreglo original en cada repeticion. Para esto, el benchmark genera un arreglo original y despues realiza una copara antes de ejecutar cada algoritmo.
Las metricas registradas son:

Tiempo de ejecución en milisegundos.
Número de comparaciones.
Número de movimientos.

Archivos de resultados
El archivo: results/resultados.csv, contiene los resultados individuales de las 540 ejecuciones. Cada regsitro incluye:
- algoritmo
- patron
- n
- repeticion
- semilla
- tiempo
- comparaciones
- movimientos
- commit_hash

El archivo: results/promedios_resultados.csv, contiene los promedios obtenidos para cada combinacion de algoritmo, patron y tamaño.

Resultados:

Los resultados muestran que Shellsort presentó un mejor rendimiento general que Inserción, especialmente cuando aumentó el tamaño de la entrada.
En el patrón descendente con 10000 elementos, Inserción alcanzó aproximadamente: 49 995 000 comparaciones y
50 004 999 movimientos. Mientras que Shellsort realizo aproxidamente: 172 578 comparaciones y 182 565 movimientos.

En cuanto a el tiempo de ejecucion, Shellsort present una ventaja obvia para entradas grandes. Para 10000 elementos y patrón aleatorio, Inserción obtuvo aproximadamente 69.16 ms, mientras que Shellsort obtuvo aproximadamente 2.33 ms.
El metodo de insercion mostro un comportamiento favorable cuando los datos estaban ordenados de forma ascendente, esto porque necesita pocas operaciones.

Coclusiones:

Los experimentos muestran que Shellsort presenta un mejor rendimiento general que el algoritmo de Inserción bajo las condiciones evaluadas.
Inserción puede ser conveniente para conjuntos pequeños o datos que ya se encuentran ordenados. Sin embargo, cuando aumenta el tamaño de la entrada o los datos presentan un orden desfavorable, el número de comparaciones y movimientos aumenta considerablemente.

Shellsort logró reducir significativamente la cantidad de operaciones necesarias en comparación con Inserción y presentó un mejor comportamiento para los tamaños de entrada mayores.
Por lo tanto, los resultados experimentales permiten comprobar que el rendimiento de un algoritmo de ordenamiento depende tanto del tamaño de la entrada como del patrón inicial de los datos.

 Articulo cientifico:

 El archivo se encuentra en la carpeta docs/, contiene la metodologia experimental, tablas, graficos, discusion y conclusiones de los resultados.

 Video de demostracion del proyecto en youtube:
 Link del video: https://youtu.be/FPdMO-engR8?si=LWeXmuUZllS-9O_W

 Version final del commit hash:
 1968e35.
 Este commit contiene la versión actualizada del código, los resultados experimentales y el artículo del proyecto.
 

 
