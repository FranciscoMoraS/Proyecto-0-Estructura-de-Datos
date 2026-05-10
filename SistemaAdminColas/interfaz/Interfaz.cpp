#include <iostream>
#include "Interfaz.h"

using std::cout;

Interfaz::Interfaz(Sistema& sistema) : sistema(sistema), ejecutando(true) {}

void Interfaz::iniciar() {
	cout << "Inicio programa\n";
}