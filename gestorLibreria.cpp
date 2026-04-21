#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int i;

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

void imprimirArreglo(const vector<int> &n)
{
    for (size_t i = 0; i < n.size(); i++)
        cout << n[i] << " ";
    cout << endl;
}

int main()
{
    int libros, opcion;

    cout << "ingres la cantidad de libros: ";
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
    vector<int> codigosArreglado = codigos;

    cout << "ingrese una opcion del 1 al 4" << endl;
    cout << "1. Buble Sort." << endl;
    cout << "2. Selection Sort." << endl;
    cout << "3. Insertion Sort." << endl;
    cout << "4. Verificacion de Eficiencia." << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        insertionSort(codigosArreglado.data(), codigosArreglado.size());
        cout << "El arreglo ordenado con Insertion sort seria: " << endl;
        imprimirArreglo(codigosArreglado);
        break;
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