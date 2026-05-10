#include <iostream>
#include <string>
#include "TipoUsuario.h"

using std::string;

TipoUsuario::TipoUsuario(const string& descripcion, int prioridad) {
	this->descripcion = descripcion;
	this->prioridad = prioridad;
}

int TipoUsuario::getPrioridad() const {
	return prioridad;
}

void TipoUsuario::aumentarTiquetes() {
	totalTiquetes++;
}
int TipoUsuario::getTotalTiquetes() const {
	return totalTiquetes;
}

bool TipoUsuario::operator<(const TipoUsuario& other) const {
	return prioridad < other.prioridad;
}

std::ostream& operator<<(std::ostream& os, const TipoUsuario& usuario) {
	os << usuario.descripcion + " (prioridad: " + std::to_string(usuario.prioridad) + ")";
	return os;
}