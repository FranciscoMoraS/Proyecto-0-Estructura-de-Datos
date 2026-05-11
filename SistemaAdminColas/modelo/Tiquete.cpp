/*
 * Archivo: Tiquete.cpp
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Implementación de la clase Tiquete. Genera códigos únicos mediante
 * un consecutivo estático compartido entre todos los tiquetes del
 * sistema, registra la hora de solicitud al momento de la creación,
 * marca la hora de atención cuando un tiquete es asignado a una
 * ventanilla y calcula el tiempo de espera transcurrido entre ambos
 * eventos.
 *
 */

#include <iostream>
#include <string>
#include <ctime>
#include "Tiquete.h"

using std::string;

int Tiquete::consecutivo = 100;

Tiquete::Tiquete(const string& codigoArea, int prioridadFinal) {
	codigo = codigoArea + std::to_string(consecutivo);
	consecutivo++;
	horaSolicitud = std::time(nullptr);
	this->prioridadFinal = prioridadFinal;
}

void Tiquete::marcarAtendido() {
	horaAtencion = std::time(nullptr);
}

double Tiquete::getTiempoDeEspera() const {
	if (horaAtencion == 0) return 0;
	return std::difftime(horaAtencion, horaSolicitud);
}

bool Tiquete::operator<(const Tiquete& other) const {
	return prioridadFinal < other.prioridadFinal;
}

std::string Tiquete::getCodigo() const {
	return codigo;
}

std::time_t Tiquete::getHoraSolicitud() const {
	return horaSolicitud;
}

std::time_t Tiquete::getHoraAtencion() const {
	return horaAtencion;
}

int Tiquete::getPrioridadFinal() const {
	return prioridadFinal;
}

std::ostream& operator<<(std::ostream& os, const Tiquete& tiquete) {
	os << tiquete.codigo << " (prioridad: " << tiquete.prioridadFinal << ")";
	return os;
}