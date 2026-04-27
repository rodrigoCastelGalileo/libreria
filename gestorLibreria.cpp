
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    int libros, opcion;

    cout << "ingres la cantidad de libros: ";
    cin >> libros;

    vector<int> codigos(libros);

    srand(time(0));
    for (int i = 0; i < libros; i++){
        codigos[i] = (rand() % 9000) + 1000;
        for (int j = 0; j < i; j++) {
            if (codigos[i] == codigos[j]) {
                codigos[i] = rand() % 9000 + 1000;
                j = -1;
            }
        }
    }

    cout << "Codigos generados: " << endl;
    for (int i = 0; i < codigos[i]; i++){
        cout << codigos[i] << endl;
    }

    cout << "ingrese una opcion del 1 al 4" << endl;
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
    /* code */
        break;
    case 4:
    /* code */
        break;
    default:
        break;
    }

}
