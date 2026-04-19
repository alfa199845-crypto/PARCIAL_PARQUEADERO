# Sistema de Parqueadero en C++

## Descripción
Este proyecto consiste en la creacion de un sistema de parqueadero en consola, que permite registrar la entrada y salida de vehículos, calcular el tiempo de permanencia y el valor a pagar, así como visualizar el estado del parqueadero en tiempo real. se genera factura que discrimina conducta del vehiculo.

---

## Funcionalidades principales

- Visualización de un mapa del parqueadero (16x16)
- Registro de ingreso de vehículos (placa + hora)
- Registro de salida con cálculo de tiempo y pago
- Visualización de espacios ocupados y disponibles
- Menú interactivo
- historial de ingresos y egresos
- Generar factura

---

## Innovaciones implementadas

### 1. Numeración de parqueaderos
Se asignó un número único a cada espacio de parqueo.

**¿Para qué?**  
Permitir al usuario elegir manualmente dónde estacionar.

**¿Cómo se implementó?**  
Se utilizó una matriz adicional (`numeroParqueo`) que asigna un identificador a cada posición válida.

---

### 2. Selección manual de parqueo
El usuario puede elegir el número del parqueadero donde desea estacionar.

---

### 3. Validación de placas duplicadas
El sistema evita que un vehículo con la misma placa ingrese más de una vez.

---

### 4. Búsqueda de vehículos
Permite buscar un vehículo por su placa.

**Resultado:**  
- Se muestra el número del parqueadero  
- Se imprime el mapa resaltando la posición

---

### 5. Resaltado visual en el mapa
Cuando se busca un vehículo, su ubicación se muestra en color verde.

---

### 6. Historial de vehículos
Se guarda información de todos los vehículos:

- Placa
- Hora de entrada
- Hora de salida
- Tiempo de permanencia
- Pago realizado
- Estado (activo o retirado)

---

### 7. Mejora visual del mapa
Se utilizó `setw()` para alinear correctamente los elementos del mapa.

---

## Ejecución del programa

### Compilación (Windows con MinGW)

Abrir la terminal en la carpeta del proyecto y ejecutar:
primero entrar a la carpeta proyecto1 en el cmd y despues ejecutar el comando de compilar

```bash
cd proyecto1
g++ main.cpp funciones.cpp -o parqueadero.exe

Bibliografia
## Referencias técnicas del código

El desarrollo del sistema se basa en funciones propias implementadas en el archivo `funciones.cpp`, las cuales estructuran la lógica principal del parqueadero.

### Funciones clave

* `mostrarmapa()`
  Encargada de la visualización del parqueadero en consola, incluyendo resaltado de posiciones mediante códigos ANSI.

* `ingresarvehiculo()`
  Gestiona el ingreso de vehículos, validando duplicados y asignando espacios disponibles. Además, registra la entrada en el historial.

* `placaExiste(string placa)`
  Función de validación que evita el ingreso de vehículos duplicados en el sistema.

* `buscarVehiculo()`
  Permite localizar un vehículo dentro del parqueadero y resaltar su posición en el mapa.

* `registrarSalida()`
  Calcula el tiempo de permanencia utilizando `time()` y `difftime()`, determina el costo del servicio y actualiza el historial del vehículo.

* `mostrarHistorial()`
  Presenta los registros de entrada y salida, mostrando estado, tiempo de permanencia y pago realizado.

---

## Uso de inteligencia artificial

Durante el desarrollo se utilizaron herramientas de inteligencia artificial como apoyo en:

* Optimización de funciones
* Mejora de la lógica del programa
* Organización del código
* Explicación de conceptos en C++

Estas herramientas fueron empleadas como guía de aprendizaje, mientras que la implementación final, adaptación y pruebas fueron realizadas de forma autónoma.

---

## Referencia

OpenAI. (2026). *ChatGPT (modelo GPT-5.3)*.
Herramienta utilizada como apoyo en el desarrollo del proyecto.


