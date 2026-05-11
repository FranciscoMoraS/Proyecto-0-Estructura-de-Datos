/*
 * Archivo: Servicio.h
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Declaración de la clase Servicio, que representa una operación
 * específica que el usuario puede solicitar (por ejemplo: apertura de
 * cuenta, consulta de saldo, retiro). Cada servicio tiene una
 * descripción, una prioridad propia, el código del área donde se
 * atiende y un contador acumulado de tiquetes solicitados. La
 * referencia al área se mantiene por código (string).
 *
 */

#pragma once

#include <iostream>
#include <string>

class Servicio {
private:
	std::string descripcion;
	int prioridad = 0;
	std::string codigoArea;
	int totalTiquetes = 0;

public:
	Servicio() = default;
	Servicio(const std::string& descripcion, int prioridad, const std::string& codigoArea);
	Servicio(const Servicio&) = default;
	Servicio& operator=(const Servicio&) = default;
	~Servicio() = default;

	int getPrioridad() const;
	const std::string& getCodigoArea() const;

	void aumentarTiquetes();
	int getTotalTiquetes() const;
	void resetearTiquetes();

	friend std::ostream& operator<<(std::ostream& os, const Servicio& servicio);
};