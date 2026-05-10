#include <iostream>
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

	//int opcion = leerEnteroEnRango("Seleccione una opción: ", 1, 6);
	//switch
	ejecutando = false;
}

void Interfaz::limpiarPantalla() {
	std::system("cls");
}