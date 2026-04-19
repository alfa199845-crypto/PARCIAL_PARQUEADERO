#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// mapa de 16x16
// e es entrada, s es la salida , p es cada parqueadero y . indcia el camino :3
char mapa[16][16] = {
{'E','.','.','.','.','.','.','.','.','.','.','.','.','.','.','S'},
{'.','P','P','P','.','P','P','P','.','P','P','P','.','P','P','.'},
{'.','P','P','P','.','P','P','P','.','P','P','P','.','P','P','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','P','P','P','.','P','P','P','.','P','P','P','.','P','P','.'},
{'.','P','P','P','.','P','P','P','.','P','P','P','.','P','P','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','P','P','P','.','P','P','P','.','P','P','P','.','P','P','.'},
{'.','P','P','P','.','P','P','P','.','P','P','P','.','P','P','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','P','P','P','.','P','P','P','.','P','P','P','.','P','P','.'},
{'.','P','P','P','.','P','P','P','.','P','P','P','.','P','P','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','P','P','P','.','P','P','P','.','P','P','P','.','P','P','.'},
{'.','P','P','P','.','P','P','P','.','P','P','P','.','P','P','.'},
{'E','.','.','.','.','.','.','.','.','.','.','.','.','.','.','S'}
};

// funcion q muestra el mapa
void mostrarmapa() {
    cout << "\nMAPA PARQUEADERO\n\n";

    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}

// Datos del vehiculo
struct Vehiculo {
    string placa;
    time_t horaEntrada;
    bool ocupado;
};

// matriz de vehículos 16x16
Vehiculo parqueadero[16][16];

void inicializarParqueadero() {
    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            parqueadero[i][j].ocupado = false;
            parqueadero[i][j].placa = "";
        }
    }
}

void ingresarvehiculo() {
    string placa;
    cout << "ingrese la placa: ";
    cin >> placa;

    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {

            //verifica si la posicion de la maitriz es una p osea un parqueadero  y si no esta ocupado
            if(mapa[i][j] == 'P' && parqueadero[i][j].ocupado == false) {

                mapa[i][j] = 'X'; // marcar ocupado

                parqueadero[i][j].ocupado = true;
                parqueadero[i][j].placa = placa;
                parqueadero[i][j].horaEntrada = time(0);

                cout << "vehiculo se parqueo en [" << i << "][" << j << "]\n";
                return;
            }
        }
    }

    cout << "no hay espacios disponibles\n";
}

void registrarSalida() {
    string placa;
    cout << "Ingrese la placa a retirar: ";
    cin >> placa;

    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {

            if(parqueadero[i][j].ocupado == true &&
               parqueadero[i][j].placa == placa) {

                // cuanto tiempo esta
                time_t horaSalida = time(0);
                double segundos = difftime(horaSalida, parqueadero[i][j].horaEntrada);
                double horas = segundos / 3600.0;

                // valor a pagar
                double tarifa = 2000;
                double pago = horas * tarifa;

                cout << "Tiempo: " << horas << " horas\n";
                cout << "Total a pagar: $" << pago << endl;

                // libera el espacio que estaba ocupado
                parqueadero[i][j].ocupado = false;
                parqueadero[i][j].placa = "";
                mapa[i][j] = 'P';

                cout << "Vehiculo retirado correctamente\n";
                return;
            }
        }
    }

    cout << "Vehiculo no encontrado\n";
}
