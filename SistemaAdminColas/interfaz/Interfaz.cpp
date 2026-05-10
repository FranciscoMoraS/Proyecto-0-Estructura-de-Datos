#include <iostream>
#include <cstdlib>
#include "Interfaz.h"

using std::cout;

Interfaz::Interfaz(Sistema& sistema) : sistema(sistema), ejecutando(true) {}

void Interfaz::iniciar() {
	while (ejecutando) {
		cout << "Inicio programa\n";
	}
}

// ===================================================================
// MENÚS
// ===================================================================

void Interfaz::limpiarPantalla() {
	std::system("cls");
}