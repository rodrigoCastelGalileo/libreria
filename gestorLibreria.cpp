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

void selectionSort(int arr[], int n)
{
    int intercambios = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            intercambios++;
        }
    }

    cout << "Para ordenar " << n
         << " elementos, se realizaron "
         << intercambios
         << " intercambios de posicion." << endl;
}

void busquedaBinaria(int lista[], int size, int buscar)
{
    int bajo = 0;
    int alto = size - 1;

    while (bajo <= alto)
    {
        int mitad = (bajo + alto) / 2;

        if (lista[mitad] == buscar)
        {
            cout << "El libro SI existe en el inventario." << endl;
            cout << "Se encuentra en el indice: " << mitad << endl;
            return;
        }
        else if (lista[mitad] < buscar)
        {
            bajo = mitad + 1;
        }
        else
        {
            alto = mitad - 1;
        }
    }

    cout << "El libro NO esta en el inventario." << endl;
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
    {
        vector<int> codigosArreglado = codigos;
        selectionSort(codigosArreglado.data(), codigosArreglado.size());
        cout << "El arreglo ordenado con Selection sort seria: " << endl;
        imprimirArreglo(codigosArreglado);
        break;
    }
    case 3:
    {
        vector<int> codigosArreglado = codigos;
        insertionSort(codigosArreglado.data(), codigosArreglado.size());
        cout << "El arreglo ordenado con Insertion sort seria: " << endl;
        imprimirArreglo(codigosArreglado);
        break;
    }
    case 4:
    {
        int buscar, tipoOrden;

        cout << "Seleccione el metodo de ordenamiento:" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cin >> tipoOrden;

        vector<int> codigosOrdenados = codigos;

        switch (tipoOrden)
        {
        case 1:
            bubleSort(codigosOrdenados.data(), codigosOrdenados.size());
            break;
        case 2:
            selectionSort(codigosOrdenados.data(), codigosOrdenados.size());
            break;
        case 3:
            insertionSort(codigosOrdenados.data(), codigosOrdenados.size());
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
        }

        cout << "Arreglo ordenado: " << endl;
        imprimirArreglo(codigosOrdenados);

        cout << "Ingrese el codigo del libro a buscar: ";
        cin >> buscar;

        busquedaBinaria(codigosOrdenados.data(), codigosOrdenados.size(), buscar);

        break;
    }
    default:
        cout << "Opcion invalida." << endl;
        break;
    }

    pause();
    return 0;
}