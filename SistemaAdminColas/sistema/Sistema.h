/*
 * Archivo: Sistema.h
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Declaración de la clase Sistema, orquestador central del programa.
 * Mantiene las listas de tipos de usuario, servicios y áreas, y expone
 * la API que utiliza la Interfaz para realizar todas las operaciones
 * del sistema: configuración (CRUD de tipos, servicios y áreas),
 * operación (solicitar y atender tiquetes) y mantenimiento (limpiar
 * colas y estadísticas). Toda la lógica de negocio vive en esta clase
 * o delega a las clases del modelo.
 *
 */

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
	void limpiarColasYEstadisticas();
};