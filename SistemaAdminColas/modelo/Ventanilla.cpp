#include "Ventanilla.h"

Ventanilla::Ventanilla(const std::string& nombre) {
	this->nombre = nombre;
}

double Ventanilla::atenderTiquete(const Tiquete& tiquete) {
	// atender el tiquete, indicar que existe tiquete en ventanilla
	// y retornar el tiempo de espera
}

std::string Ventanilla::getNombre() const {
	return nombre;
}

int Ventanilla::getTiquetesAtendidos() const {
	return tiquetesAtendidos;
}

std::ostream& operator<<(std::ostream& os, const Ventanilla& ventanilla) {
	// mostrar el nombre seguido del código del tiquete actual (si hay)
}