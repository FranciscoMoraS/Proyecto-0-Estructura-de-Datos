#pragma once

#include <iostream>
#include <string>
#include <ctime>

class Tiquete {
private:
	static int consecutivo;

	std::string codigo;
	std::time_t horaSolicitud;
	std::time_t horaAtencion;	// 0 si aún no fue atendido
	int prioridadFinal;

public:
	Tiquete() = default;
	Tiquete(const std::string& codigoArea, int prioridadUsuario, int prioridadServicio);
	Tiquete(const Tiquete&) = default;
	Tiquete& operator=(const Tiquete&) = default;
	~Tiquete() = default;

	std::string getCodigo() const;
	std::time_t getHoraSolicitud() const;
	std::time_t getHoraAtencion() const;
	int getPrioridadFinal() const;

	void marcarAtentido();	// setea horaAtencion al momento actual
	double getTiempoDeEspera() const; // en segundos, la diferencia entre atención y solicitud

	bool operator<(const Tiquete& other) const;

	std::string ToString() const;
	friend std::ostream& operator<<(std::ostream& os, const Tiquete& tiquete);
};