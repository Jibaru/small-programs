#include <iostream>

using namespace std;

// Propiedades del mcd de a y b
// el mcd de a y b pertenece a Z+ - {0}
// si a == b entonces el mcd es a o b
// si a > b y a/b es exacta, el mcd es b
// si a > b, el mcd de a y b se encuentra en el intervalo: <0, b]
// el mcd de n numeros es mcd(n, mcd(n-1, mcd(n-2, ...)))
int mcd(int num1, int num2)
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
        return menor;
    }

    i = menor;

    while (num1 % i != 0 || num2 % i != 0)
    {
        i--;
    }

    return i;
}

int main()
{

    int a = 45;
    int b = 25;

    cout << "El maximo comun divisor de " << a << " y " << b << " es: " << mcd(a, b) << endl;

    return 0;
}