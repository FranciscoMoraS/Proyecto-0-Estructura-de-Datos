/*
 * Archivo: Servicio.cpp
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Implementación de la clase Servicio. Gestiona el contador acumulado
 * de tiquetes solicitados para este servicio y provee la
 * representación textual completa (descripción, área de atención y
 * prioridad).
 *
 */

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

void Servicio::resetearTiquetes() {
	totalTiquetes = 0;
}

std::ostream& operator<<(std::ostream& os, const Servicio& s) {
	os << s.descripcion + " [área: " + s.codigoArea + ", prioridad: " + std::to_string(s.prioridad) + "]";
	return os;
}