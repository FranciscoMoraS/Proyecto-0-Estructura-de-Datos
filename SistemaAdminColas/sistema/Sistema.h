#pragma once

#include <string>
#include "../ed/LinkedList.h"
#include "../modelo/TipoUsuario.h"
#include "../modelo/Servicio.h"
//#include "../modelo/Area.h" pendiente

class Sistema {
private:
	LinkedList<TipoUsuario>* usuarios;
	LinkedList<Servicio>* servicios;
	//LinkedList<Area*>* areas;	pendiente

public:
	Sistema();
	~Sistema();

	// --- Tipos de usuario ---
	void agregarTipoUsuario(const std::string& descripcion, int prioridad);
	void eliminarTipoUsuario(int posicion);
	LinkedList<TipoUsuario>& getTiposUsuario();

	// --- Servicios ---
	void agregarServicio(const std::string& descripcion, int prioridad, const std::string& codigoArea);
	void eliminarServicio(int posicion);
	void reordenarServicio(int desde, int hasta);
	LinkedList<Servicio>& getServicios();

	// --- Áreas (pendiente: requiere clase Area) ---
	// void agregarArea(const std::string& descripcion, const std::string& codigo, int cantidadVentanillas);
	// void modificarVentanillas(int posArea, int nuevaCantidad);
	// void eliminarArea(int posicion);
	// LinkedList<Area*>& getAreas();

	// --- Tiquetes (pendiente: requiere Area y Tiquete integrados) ---
	// void solicitarTiquete(int posTipo, int posServicio);
	// void atenderTiquete(int posArea, int numVentanilla);

	// --- Estadísticas y limpieza ---
	void mostrarEstadisticas();
	void limpiarColasYEstadisticas();
};