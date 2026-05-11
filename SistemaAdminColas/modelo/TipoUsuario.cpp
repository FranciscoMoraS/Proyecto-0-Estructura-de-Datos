/*
 * Archivo: TipoUsuario.cpp
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Implementación de la clase TipoUsuario. Define el comportamiento de
 * comparación entre tipos según su prioridad (utilizado para mantener
 * la lista ordenada de tipos en el sistema), gestiona el contador de
 * tiquetes solicitados y provee la representación textual del tipo
 * para los menús internos del sistema.
 *
 */

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

std::string TipoUsuario::getDescripcion() const {
	return descripcion;
}

void TipoUsuario::aumentarTiquetes() {
	totalTiquetes++;
}

int TipoUsuario::getTotalTiquetes() const {
	return totalTiquetes;
}

void TipoUsuario::resetearTiquetes() {
	totalTiquetes = 0;
}

bool TipoUsuario::operator<(const TipoUsuario& other) const {
	return prioridad < other.prioridad;
}

std::ostream& operator<<(std::ostream& os, const TipoUsuario& usuario) {
	os << usuario.descripcion + " (prioridad: " + std::to_string(usuario.prioridad) + ")";
	return os;
}