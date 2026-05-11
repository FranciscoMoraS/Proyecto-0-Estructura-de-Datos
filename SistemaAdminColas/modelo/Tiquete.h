/*
 * Archivo: Tiquete.h
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Declaración de la clase Tiquete, que representa un turno emitido por
 * el sistema. Cada tiquete tiene un código único compuesto por el
 * código del área más un consecutivo global, registra los timestamps
 * de solicitud y atención, y conoce su prioridad final calculada según
 * la fórmula PT = PU * 10 + PS. El consecutivo estático garantiza que
 * los códigos nunca se reutilicen durante la ejecución del programa.
 *
 */

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
	Tiquete(const std::string& codigoArea, int prioridadFinal);
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