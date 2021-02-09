#include <iostream>

using namespace std;

// Propiedades del mcm de a y b
// el mcm de a y b pertenece a Z+
// si a == b, entonces el mcm de a y b es a o b
// si a > b y a/b es exacta, entonces el mcm de a y b es a
// si a > b, el mcm de a y b se encuentra en el intervalo: [a, infinito>
// el mcm de n numeros es mcm(n, mcm(n-1, mcm(n-2, ...)))
int mcm(int num1, int num2)
{

    int mayor, menor, i;

    if (num1 == num2)
    {
        return num1;
    }

    if (num1 > num2)
    {
        mayor = num1;
        menor = num2;
    }
    else
    {
        mayor = num2;
        menor = num1;
    }

    if (mayor % menor == 0)
    {
        return mayor;
    }

    i = mayor;

    while (i % num1 != 0 || i % num2 != 0)
    {
        i++;
    }

    return i;
}

int main()
{

    int a = 45;
    int b = 25;

    cout << "El minimo comun multiplo de " << a << " y " << b << " es: " << mcm(a, b) << endl;

    return 0;
}