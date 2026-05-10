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

	void aumentarTiquetes();
	int getTotalTiquetes() const;
	void resetearTiquetes();

	bool operator<(const TipoUsuario& other) const;

	friend std::ostream& operator<<(std::ostream& os, const TipoUsuario& usuario);
};