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

string Servicio::toString() const {
	return descripcion + " [área: " + codigoArea + ", prioridad: " + std::to_string(prioridad) + "]";
}

std::ostream& operator<<(std::ostream& os, const Servicio& servicio) {
	os << servicio.toString();
	return os;
}