#include <iostream>
#include <string>
#include "TipoUsuario.h"

using std::string;

TipoUsuario::TipoUsuario(const string& nombre, const string& descripcion, int prioridad) {
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->prioridad = prioridad;
	totalTiquetes = 0;
}

string TipoUsuario::getNombre() const {
	return nombre;
}
void TipoUsuario::setNombre(const string& nombre) {
	this->nombre = nombre;
}

string TipoUsuario::getDescripcion() const {
	return descripcion;
}
void TipoUsuario::setDescripcion(const string& descripcion) {
	this->descripcion = descripcion;
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

string TipoUsuario::toString() const {
	return nombre + " - " + descripcion + " (prioridad: " + std::to_string(prioridad) + ")";
}
std::ostream& operator<<(std::ostream& os, const TipoUsuario& usuario) {
	os << usuario.toString();
	return os;
}