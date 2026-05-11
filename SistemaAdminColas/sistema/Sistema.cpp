/*
 * Archivo: Sistema.cpp
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Implementación del orquestador central del Sistema de Administración
 * de Colas con Prioridad. Coordina las operaciones sobre tipos de
 * usuario, servicios y áreas, gestiona la solicitud y atención de
 * tiquetes (incluyendo el cálculo de la prioridad final mediante la
 * fórmula PT = PU * 10 + PS), y administra el ciclo de vida de los
 * objetos en memoria dinámica.
 *
 */

#include <iostream>
#include "Sistema.h"
#include "../ed/LinkedList.h"
#include "../modelo/TipoUsuario.h"
#include "../modelo/Area.h"

using std::string;
using std::cout;

Sistema::Sistema() {
	usuarios = new LinkedList<TipoUsuario>();
	servicios = new LinkedList<Servicio>();
	areas = new LinkedList<Area*>();
}

Sistema::~Sistema() {
	delete usuarios;
	delete servicios;

	areas->goToStart();
	while (!areas->atEnd()) {
		delete areas->getElement();
		areas->next();
	}
	delete areas;
}

// --- Tipos de usuario ---

void Sistema::agregarTipoUsuario(const string& descripcion, int prioridad) {
	TipoUsuario nuevo(descripcion, prioridad);

	usuarios->goToStart();
	while (!usuarios->atEnd() && usuarios->getElement() < nuevo) {
		usuarios->next();
	}
	usuarios->insert(nuevo);
}

void Sistema::eliminarTipoUsuario(int posicion) {
	usuarios->goToPos(posicion);
	usuarios->remove();

	areas->goToStart();
	while (!areas->atEnd()) {
		Area* area = areas->getElement();
		area->limpiarCola();
		areas->next();
	}
}

int Sistema::getCantidadTiposUsuario() const {
	return usuarios->getSize();
}

const TipoUsuario& Sistema::getTipoUsuario(int pos) {
	usuarios->goToPos(pos);
	return usuarios->getElement();
}

// --- Servicios ---

void Sistema::agregarServicio(const string& descripcion, int prioridad, const string& codigoArea) {
	Servicio nuevo(descripcion, prioridad, codigoArea);
	servicios->append(nuevo);
}

void Sistema::eliminarServicio(int posicion) {
	servicios->goToPos(posicion);
	servicios->remove();

	areas->goToStart();
	while (!areas->atEnd()) {
		areas->getElement()->limpiarCola();
		areas->next();
	}
}

void Sistema::reordenarServicio(int desde, int hasta) {
	servicios->goToPos(desde);
	Servicio s = servicios->remove();

	servicios->goToPos(hasta);
	servicios->insert(s);
}

int Sistema::getCantidadServicios() const {
	return servicios->getSize();
}

const Servicio& Sistema::getServicio(int pos) {
	servicios->goToPos(pos);
	return servicios->getElement();
}

// --- Áreas ---

void Sistema::agregarArea(const std::string& codigo, const std::string& descripcion, int cantVentanillas) {
	Area* nueva = new Area(codigo, descripcion, cantVentanillas);
	areas->append(nueva);
}

void Sistema::eliminarArea(int pos) {
	areas->goToPos(pos);
	Area* area = areas->getElement();
	string codigo = area->getCodigo();

	areas->remove();
	delete area;

	servicios->goToStart();
	while (!servicios->atEnd()) {
		if (servicios->getElement().getCodigoArea() == codigo) {
			servicios->remove();
		}
		else {
			servicios->next();
		}
	}

	areas->goToStart();
	while (!areas->atEnd()) {
		areas->getElement()->limpiarCola();
		areas->next();
	}
}

void Sistema::modificarVentanillas(int posArea, int nuevaCantidad) {
	areas->goToPos(posArea);
	Area* area = areas->getElement();
	area->modificarVentanillas(nuevaCantidad);
}

int Sistema::getCantidadVentanillas(int posArea) const {
	areas->goToPos(posArea);
	Area* area = areas->getElement();
	return area->getCantidadVentanillas();
}

int Sistema::getCantidadAreas() const {
	return areas->getSize();
}

Area* Sistema::getArea(int pos) {
	areas->goToPos(pos);
	return areas->getElement();
}

// --- Tiquetes ---
Tiquete Sistema::solicitarTiquete(int posTipo, int posServicio) {
	usuarios->goToPos(posTipo);
	TipoUsuario tipo = usuarios->getElement();
	tipo.aumentarTiquetes();
	int prioridadUsuario = tipo.getPrioridad();
	usuarios->setElement(tipo);

	servicios->goToPos(posServicio);
	Servicio servicio = servicios->getElement();
	servicio.aumentarTiquetes();
	int prioridadServicio = servicio.getPrioridad();
	string codigoArea = servicio.getCodigoArea();
	servicios->setElement(servicio);

	int prioridadFinal = prioridadUsuario * 10 + prioridadServicio;

	Area* area = nullptr;
	areas->goToStart();
	while (!areas->atEnd()) {
		Area* a = areas->getElement();
		if (a->getCodigo() == codigoArea) {
			area = a;
			break;
		}
		areas->next();
	}

	Tiquete t(codigoArea, prioridadFinal);
	area->encolarTiquete(t);

	return t;
}

Tiquete Sistema::atenderTiquete(int posArea, int numVentanilla) {
	areas->goToPos(posArea);
	Area* area = areas->getElement();
	return area->atenderTiquete(numVentanilla);
}

// --- Estadísticas y Limpieza ---

void Sistema::limpiarColasYEstadisticas() {
	usuarios->goToStart();
	while (!usuarios->atEnd()) {
		TipoUsuario t = usuarios->getElement();
		t.resetearTiquetes();
		usuarios->setElement(t);
		usuarios->next();
	}

	servicios->goToStart();
	while (!servicios->atEnd()) {
		Servicio s = servicios->getElement();
		s.resetearTiquetes();
		servicios->setElement(s);
		servicios->next();
	}

	areas->goToStart();
	while (!areas->atEnd()) {
		areas->getElement()->limpiarColaYEstadisticas();
		areas->next();
	}
}