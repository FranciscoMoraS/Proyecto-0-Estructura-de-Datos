#pragma once

#include <iostream>
#include <string>
#include <ctime>

class Tiquete {
private:
	static int consecutivo;

	std::string codigo;
	std::time_t horaSolicitud = 0;
	std::time_t horaAtencion = 0;
	int prioridadFinal = 0;

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

	void marcarAtendido();
	double getTiempoDeEspera() const;

	bool operator<(const Tiquete& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Tiquete& tiquete);
};