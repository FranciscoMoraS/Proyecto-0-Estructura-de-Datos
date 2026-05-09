#pragma once

#include <iostream>
#include <string>

class TipoUsuario {
private:
	std::string nombre;
	std::string descripcion;
	int prioridad;
	int totalTiquetes;

public:
	TipoUsuario(const std::string& nombre, const std::string& descripcion, int prioridad);
	TipoUsuario(const TipoUsuario&) = default;
	TipoUsuario& operator=(const TipoUsuario&) = default;
	~TipoUsuario() = default;

	std::string getNombre() const;
	void setNombre(const std::string& nombre);

	std::string getDescripcion() const;
	void setDescripcion(const std::string& descripcion);

	int getPrioridad() const;

	void aumentarTiquetes();
	int getTotalTiquetes() const;

	bool operator<(const TipoUsuario& other) const;

	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& os, const TipoUsuario& usuario);
};