#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

int resaltarI = -1;
int resaltarJ = -1;

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

int numeroParqueo[16][16];


void mostrarFactura(string placa, int numero, double horas, double pago) {
    cout << "\n===== FACTURA =====\n";
    cout << "Placa: " << placa << endl;
    cout << "Parqueadero: #" << numero << endl;
    cout << "Tiempo: " << horas << " horas\n";
    cout << "Tarifa: $2000 por hora\n";
    cout << "Total a pagar: $" << pago << endl;
    cout << "===================\n";
}

// funcion q muestra el mapa
void mostrarmapa() {
    cout << "\nMAPA PARQUEADERO\n\n";

    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {

             if(i == resaltarI && j == resaltarJ) {
            cout << "\033[32m" << setw(4) << numeroParqueo[i][j] << "\033[0m";
        }
          else if(mapa[i][j] == 'P') {
    cout << setw(4) << numeroParqueo[i][j];
}
else if(mapa[i][j] == 'X') {
    cout << setw(4) << "X";
}
else {
    cout << setw(4) << mapa[i][j];
}
        }
        cout << endl;
    }
}

struct Registro {
    string placa;
    time_t entrada;
    time_t salida;
    double pago;
    bool activo; // true = esta en el parqueadero y  false = ya se fue xd 
};


Registro historial[200];
int totalRegistros = 0;

// Datos del vehiculo
struct Vehiculo {
    string placa;
    time_t horaEntrada;
    bool ocupado;
};

// matriz de vehículos 16x16
Vehiculo parqueadero[16][16];



void inicializarParqueadero() {

    
    int contador = 1;

for(int i = 0; i < 16; i++) {
    for(int j = 0; j < 16; j++) {

        parqueadero[i][j].ocupado = false;
        parqueadero[i][j].placa = "";

        if(mapa[i][j] == 'P') {
            numeroParqueo[i][j] = contador;
            contador++;
        } else {
            numeroParqueo[i][j] = 0;
        }
    }
}
}

void ocuparEspacio(Vehiculo* v, string placa) {
    v->ocupado = true;
    v->placa = placa;
    v->horaEntrada = time(0);
}

bool placaExiste(string placa) {
    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            if(parqueadero[i][j].ocupado == true &&
               parqueadero[i][j].placa == placa) {
                return true;
            }
        }
    }
    return false;
}

void ingresarvehiculo() {
    string placa;
    cout << "ingrese la placa: ";
    cin >> placa;

    if(placaExiste(placa)) {
        cout << "Ese vehiculo ya esta en el parqueadero\n";
        return;
    }

    int numero;
    cout << "Ingrese el numero del parqueadero: ";
    cin >> numero;

    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {

            if(numeroParqueo[i][j] == numero) {

                if(parqueadero[i][j].ocupado == false) {

                    mapa[i][j] = 'X';
                    ocuparEspacio(&parqueadero[i][j], placa);
                    historial[totalRegistros].placa = placa;
                   historial[totalRegistros].entrada = time(0);
                    historial[totalRegistros].activo = true;
                    totalRegistros++;

                    cout << "vehiculo parqueado en puesto #" << numero << endl;
                    return;

                } else {
                    cout << "Ese parqueadero ya esta ocupado\n";
                    return;
                }
            }
        }
    }

    cout << "Numero de parqueadero invalido\n";
}


void buscarVehiculo() {
    string placa;
    cout << "Ingrese placa a buscar: ";
    cin >> placa;

    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {

            if(parqueadero[i][j].ocupado &&
               parqueadero[i][j].placa == placa) {

                cout << "Vehiculo en parqueadero #" 
                     << numeroParqueo[i][j] << endl;

                // activar resaltado
                resaltarI = i;
                resaltarJ = j;

                mostrarmapa();

                // desactivar resaltado
                resaltarI = -1;
                resaltarJ = -1;

                return;
            }
        }
    }

    cout << "Vehiculo no encontrado\n";
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

                mostrarFactura(placa, numeroParqueo[i][j], horas, pago);

                for(int k = 0; k < totalRegistros; k++) {
    if(historial[k].placa == placa && historial[k].activo) {

        historial[k].salida = horaSalida;
        historial[k].pago = pago;
        historial[k].activo = false;

        break;
    }
}

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


void mostrarHistorial() {

    cout << "\n===== HISTORIAL =====\n";

    for(int i = 0; i < totalRegistros; i++) {

        cout << "Placa: " << historial[i].placa << endl;

        cout << "Estado: ";
        if(historial[i].activo)
            cout << "EN PARQUEADERO\n";
        else
            cout << "SALIO\n";

        double tiempo = difftime(
            historial[i].activo ? time(0) : historial[i].salida,
            historial[i].entrada
        ) / 60.0;

        cout << "Tiempo: " << tiempo << " minutos\n";

        if(!historial[i].activo)
            cout << "Pago: $" << historial[i].pago << endl;

        cout << "----------------------\n";
    }
}
