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

	double atenderTiquete(const Tiquete& tiquete); // retorna tiempo de espera
	
	void limpiar();

	std::string getNombre() const;
	int getTiquetesAtendidos() const;

	friend std::ostream& operator<<(std::ostream& os, const Ventanilla& ventanilla);
};