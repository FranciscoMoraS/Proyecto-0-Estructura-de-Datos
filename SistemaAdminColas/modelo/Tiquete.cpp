#include <iostream>
#include <string>
#include <ctime>
#include "Tiquete.h"

using std::string;

int Tiquete::consecutivo = 100;

Tiquete::Tiquete(const string& codigoArea, int prioridadUsuario, int prioridadServicio) {
	codigo = codigoArea + std::to_string(consecutivo);
	consecutivo++;
	horaSolicitud = std::time(nullptr);
	prioridadFinal = prioridadUsuario * 10 + prioridadServicio;
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