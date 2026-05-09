#pragma once

#include <iostream>
#include <string>

class Servicio {
private:
	std::string nombre;
	std::string descripcion;
	int prioridad;
	std::string codigoArea;
	int codigoServicio;
	int cantidadTiquetes;

public:
	Servicio(const std::string& nombre, const std::string& descripcion, int prioridad, int codigoArea);
	Servicio(const Servicio&) = default;
	Servicio& operator=(const Servicio&) = default;
	~Servicio() = default;

	std::string getNombre() const;
	void setNombre(const std::string& nombre);

	std::string getDescripcion() const;
	void setDescripcion(const std::string& descripcion);

	int getPrioridad() const;
	void setPrioridad(int prioridad);

	int getArea() const;

	void aumentarTiquetes();
	int getTotalTiquetes() const;

	std::string toString() const;
	friend std::ostream& operator<<(std::ostream& os, const Servicio& servicio);
};