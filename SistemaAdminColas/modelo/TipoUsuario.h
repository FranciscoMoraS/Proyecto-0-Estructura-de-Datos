/*
 * Archivo: TipoUsuario.h
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Declaración de la clase TipoUsuario, que representa una categoría
 * de cliente del sistema (por ejemplo: adulto mayor, persona con
 * discapacidad, cliente regular). Cada tipo tiene una descripción,
 * una prioridad numérica utilizada en el cálculo del peso final de
 * los tiquetes y un contador acumulado de tiquetes solicitados por
 * usuarios de esta categoría.
 *
 */

#pragma once

#include <iostream>
#include <string>

class TipoUsuario {
private:
	std::string descripcion;
	int prioridad = 0;
	int totalTiquetes = 0;

public:
	TipoUsuario() = default;
	TipoUsuario(const std::string& descripcion, int prioridad);
	TipoUsuario(const TipoUsuario&) = default;
	TipoUsuario& operator=(const TipoUsuario&) = default;
	~TipoUsuario() = default;

	int getPrioridad() const;
	std::string getDescripcion() const;

	void aumentarTiquetes();
	int getTotalTiquetes() const;
	void resetearTiquetes();

	bool operator<(const TipoUsuario& other) const;

	friend std::ostream& operator<<(std::ostream& os, const TipoUsuario& usuario);
};