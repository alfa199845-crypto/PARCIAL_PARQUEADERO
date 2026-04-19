#include <iostream>
using namespace std;

void mostrarmapa();
void inicializarParqueadero();
void ingresarvehiculo();
void registrarSalida();

int main() {

    int opcion;

    inicializarParqueadero();
    
 do {
        cout << "\n_rovky parqueadero_\n";
        cout << "1. Muestra mapa\n";
        cout << "2. Ingresa el vehiculo\n";
        cout << "3. vehiculo se retira\n";
        cout << "4. Salir del menu\n";
        cout << "Opcion: ";

        if(!(cin >> opcion)) {
            cin.clear();                
            cin.ignore(1000, '\n');     
            cout << "Entrada invalida\n";
            continue;                   
        }

        switch(opcion) {

            case 1:
                mostrarmapa();
                break;

            case 2:
                ingresarvehiculo();
                break;

            case 3:
                registrarSalida();
                break;

            case 4:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while(opcion != 4);

    return 0;
}
