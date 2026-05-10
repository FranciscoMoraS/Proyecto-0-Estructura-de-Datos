#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Interfaz.h"

using std::cout;

Interfaz::Interfaz(Sistema& sistema) : sistema(sistema), ejecutando(true) {}

void Interfaz::iniciar() {
	while (ejecutando) {
		menuPrincipal();
	}
}

// ===================================================================
// MENÚS
// ===================================================================
void Interfaz::menuPrincipal() {
	limpiarPantalla();
	cout << "===== SISTEMA DE ADMINISTRACIÓN DE COLAS =====\n";
	cout << "1. Estado de las colas\n";
	cout << "2. Tiquetes\n";
	cout << "3. Atender\n";
	cout << "4. Administración\n";
	cout << "5. Estadísticas del sistema\n";
	cout << "6. Salir\n";

	int opcion = leerEnteroEnRango("Seleccione una opción: ", 1, 6);
	switch (opcion) {
	case 1: "mostrarEstadoColas()";		break;
	case 2: "menuTiquetes()";			break;
	case 3: "atenderTiquete()";			break;
	case 4: "menuAdministracion()";		break;
	case 5: "mostrarEstadisticas()";	break;
	case 6:
		ejecutando = false;
		std::cout << "Saliendo del programa...\n";
		break;
	}
}

void Interfaz::limpiarPantalla() {
	std::system("cls");
}

// ===================================================================
// HELPERS DE E/S
// ===================================================================
int Interfaz::leerEntero(const std::string& prompt) {
	int valor;
	while (true) {
		cout << prompt;
		std::string linea;
		std::getline(std::cin, linea);
		std::stringstream ss(linea);
		if (ss >> valor && (ss >> std::ws).eof())
			return valor;
		cout << "Entrada inválida. Escoja una opción del menú.\n";
	}
}