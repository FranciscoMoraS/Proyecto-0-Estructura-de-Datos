/*
 * Archivo: Ventanilla.cpp
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Implementación de la clase Ventanilla. Gestiona la asignación de
 * tiquetes al puesto de atención, calcula el tiempo de espera del
 * tiquete recibido, mantiene el conteo de atenciones y permite
 * reiniciar el estado de la ventanilla cuando se limpia el sistema.
 *
 */

#include "Ventanilla.h"

Ventanilla::Ventanilla(const std::string& nombre) {
	this->nombre = nombre;
}

double Ventanilla::atenderTiquete(const Tiquete& tiquete) {
	tiqueteActual = tiquete;
	tieneTiqueteActual = true;
	tiquetesAtendidos++;
	return tiquete.getTiempoDeEspera();
}

void Ventanilla::limpiar() {
	tiquetesAtendidos = 0;
	tieneTiqueteActual = false;
	tiqueteActual = Tiquete();
}

std::string Ventanilla::getNombre() const {
	return nombre;
}

int Ventanilla::getTiquetesAtendidos() const {
	return tiquetesAtendidos;
}

std::ostream& operator<<(std::ostream& os, const Ventanilla& ventanilla) {
	os << ventanilla.nombre << ": ";
	if (ventanilla.tieneTiqueteActual)
		os << ventanilla.tiqueteActual.getCodigo();
	else
		os << "(libre)";
	return os;
}