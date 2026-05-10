#include <iostream>
#include <string>
#include "Servicio.h"

using std::string;

Servicio::Servicio(const string& descripcion, int prioridad, const string& codigoArea) {
	this->descripcion = descripcion;
	this->prioridad = prioridad;
	this->codigoArea = codigoArea;
}

int Servicio::getPrioridad() const {
	return prioridad;
}

const string& Servicio::getCodigoArea() const {
	return codigoArea;
}

void Servicio::aumentarTiquetes() {
	totalTiquetes++;
}

int Servicio::getTotalTiquetes() const {
	return totalTiquetes;
}

std::ostream& operator<<(std::ostream& os, const Servicio& s) {
	os << s.descripcion + " [área: " + s.codigoArea + ", prioridad: " + std::to_string(s.prioridad) + "]";
	return os;
}