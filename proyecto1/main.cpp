#include <iostream>
using namespace std;

void mostrarmapa();

int main() {

    // Inicializamos todo el parqueadero vacío
    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            parqueadero[i][j].ocupado = false;
            parqueadero[i][j].placa = "";
        }
    }

    // Mostrar el mapa
    mostrarmapa();

    return 0;
}
