#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Interfaz.h"
#include "../sistema/Sistema.h"

using std::cout;

Interfaz::Interfaz(Sistema& sistema) : sistema(sistema) {}

void Interfaz::iniciar() {
	cout << "Inicio programa\n";
}