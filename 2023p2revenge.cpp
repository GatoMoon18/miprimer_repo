#include <iostream>
using namespace std;
int main() {
    int n1, n2;
    cout << "Ingrese el valor #1: ";
    cin >> n1;
    cout << "Ingrese el valor #2: ";
    cin >> n2;
    // CONTAR CIFRAS
    int aux1 = n1;
    int aux2 = n2;
    int a = 0, b = 0;

    if (aux1 == 0) a = 1;
    if (aux2 == 0) b = 1;

    while (aux1 > 0) {
        aux1 /= 10;
        a++;
    }
    while (aux2 > 0) {
        aux2 /= 10;
        b++;
    }
    // CREAR VECTORES CIFRA
    int cifras_1[10] = {0};
    int cifras_2[10] = {0};
    // INSERTAR CIFRAS EN LOS CONTADORES
    aux1 = n1;
    aux2 = n2;
    while (aux1 > 0) {
        int digito = aux1 % 10;
        cifras_1[digito]++;
        aux1 /= 10;
    }
    while (aux2 > 0) {
        int digito = aux2 % 10;
        cifras_2[digito]++;
        aux2 /= 10;
    }

    // CALCULAR DIFERENCIA
    int diferencia[10] = {0};
    int contador_dif = 0;

    for (int digito = 0; digito <= 9; digito++)  {
        if ((cifras_1[digito] > 0 && cifras_2[digito] == 0) || (cifras_1[digito] == 0 && cifras_2 [digito] > 0)) {
            diferencia[digito] = 1;
            contador_dif++;
        }
    }

    // FORMAR EL NUMERO CON LA DIFERENCIA SIMETRICA
    cout << "El menor numero formado por la diferencia simetrica de los dos numeros es: ";
    if (contador_dif == 0) {
        cout << "0" << endl;
        return 0;
    }
    for (int digito = 0; digito < 10; digito++) {
        if (diferencia[digito] == 1) {
            cout << digito;
        }
    }

    cout << endl;
    return 0;
}