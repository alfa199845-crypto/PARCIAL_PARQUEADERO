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
