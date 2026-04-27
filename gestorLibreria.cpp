#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void pause()
{
    cout << "\n\nPresiona ENTER para salir...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void insertionSort(int arr[], int n)
{
    int cambios = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        int posicionOriginal = i;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            cambios++;
        }

        arr[j + 1] = key;

        if (j + 1 != posicionOriginal)
        {
            cambios++;
        }
    }
    cout << "Se contabilizaron " << cambios << " cambios de posicion." << endl;
}

void bubleSort(int arr[], int n)
{
    int cambios = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                cambios++;
            }
        }
    }

    cout << "Para ordenar " << n << " elementos, se realizaron "
         << cambios << " intercambios de posicion." << endl;
}

void imprimirArreglo(const vector<int> &n)
{
    for (size_t i = 0; i < n.size(); i++)
        cout << n[i] << " ";
    cout << endl;
}

int main()
{
    int libros, opcion;

    cout << "Ingrese la cantidad de libros: ";
    cin >> libros;

    vector<int> codigos(libros);

    srand(time(0));
    for (int i = 0; i < libros; i++)
    {
        codigos[i] = (rand() % 9000) + 1000;
        for (int j = 0; j < i; j++)
        {
            if (codigos[i] == codigos[j])
            {
                codigos[i] = rand() % 9000 + 1000;
                j = -1;
            }
        }
    }

    cout << "Codigos generados: " << endl;
    imprimirArreglo(codigos);

    cout << "ingrese una opcion del 1 al 4" << endl;
    cout << "1. Buble Sort." << endl;
    cout << "2. Selection Sort." << endl;
    cout << "3. Insertion Sort." << endl;
    cout << "4. Busqueda de un Libro." << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
    {
        vector<int> codigosArreglado = codigos;
        bubleSort(codigosArreglado.data(), codigosArreglado.size());
        cout << "El arreglo ordenado con Buble sort seria: " << endl;
        imprimirArreglo(codigosArreglado);
        break;
    }
    case 2:
        /* code */
        break;
    case 3:
    {
        vector<int> codigosArreglado = codigos;
        insertionSort(codigosArreglado.data(), codigosArreglado.size());
        cout << "El arreglo ordenado con Insertion sort seria: " << endl;
        imprimirArreglo(codigosArreglado);
        break;
    }
    case 4:
        /* code */
        break;
    default:
        cout << "Opcion invalida." << endl;
        break;
    }

    pause();
    return 0;
}