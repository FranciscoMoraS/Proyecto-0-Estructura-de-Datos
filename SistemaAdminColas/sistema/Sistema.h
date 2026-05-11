#pragma once

#include <string>
#include "../ed/LinkedList.h"
#include "../modelo/TipoUsuario.h"
#include "../modelo/Servicio.h"
#include "../modelo/Area.h"

class Sistema {
private:
	LinkedList<TipoUsuario>* usuarios;
	LinkedList<Servicio>* servicios;
	LinkedList<Area*>* areas;

public:
	Sistema();
	~Sistema();

	// --- Tipos de usuario ---
	void agregarTipoUsuario(const std::string& descripcion, int prioridad);
	void eliminarTipoUsuario(int posicion);
	int getCantidadTiposUsuario() const;
	const TipoUsuario& getTipoUsuario(int pos);

	// --- Servicios ---
	void agregarServicio(const std::string& descripcion, int prioridad, const std::string& codigoArea);
	void eliminarServicio(int posicion);
	void reordenarServicio(int desde, int hasta);
	int getCantidadServicios() const;
	const Servicio& getServicio(int pos);

	// --- Áreas ---
	void agregarArea(const std::string& codigo, const std::string& descripcion, int cantVentanillas);
	void eliminarArea(int pos);
	void modificarVentanillas(int posArea, int nuevaCantidad);
	int getCantidadVentanillas(int posArea) const;
	int getCantidadAreas() const;
	Area* getArea(int pos);

	// --- Tiquetes ---
	Tiquete solicitarTiquete(int posTipo, int posServicio);
	Tiquete atenderTiquete(int posArea, int numVentanilla);

	// --- Estadísticas y limpieza ---
	void mostrarEstadisticas();
	void limpiarColasYEstadisticas();
};