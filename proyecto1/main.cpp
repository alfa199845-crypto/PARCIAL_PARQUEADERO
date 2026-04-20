#include <iostream>
using namespace std;
void cerrarParqueadero();
void abrirParqueadero();
void   buscarVehiculo();
void mostrarHistorial();
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
        cout << "5. Buscar vehiculo\n";
        cout << "6. Ver historial\n";
        cout << "7. Cerrar parqueadero\n";
        cout << "8. Abrir parqueadero\n";
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

                case 5:
    buscarVehiculo();
    break;

    case 6:
    mostrarHistorial();
    break;

    case 7:
    cerrarParqueadero();
    break;

case 8:
    abrirParqueadero();
    break;

            default:
                cout << "Opcion invalida\n";
        }

    } while(opcion != 4);

    return 0;
}
