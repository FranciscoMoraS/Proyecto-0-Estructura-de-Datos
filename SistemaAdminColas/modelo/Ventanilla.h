#pragma once

#include <iostream>
#include <string>
#include "Tiquete.h"

class Ventanilla {
private:
	std::string nombre;
	int tiquetesAtendidos = 0;
	Tiquete tiqueteActual;
	bool tieneTiqueteActual = false;

public:
	Ventanilla() = default;
	Ventanilla(const std::string& nombre);
	Ventanilla(const Ventanilla&) = default;
	Ventanilla& operator=(const Ventanilla&) = default;
	~Ventanilla() = default;

	Tiquete getTiquete() const;
	void atenderTiquete();
	int getTiquetesAtendidos() const;

	std::string getNombre() const;

	bool getTieneTiqueteActual() const;

	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& os, const Ventanilla& ventanilla);
};