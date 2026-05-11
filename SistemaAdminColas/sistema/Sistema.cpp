#include <iostream>
#include "Sistema.h"
#include "../ed/LinkedList.h"
#include "../modelo/TipoUsuario.h"
// #include "../modelo/Area.h"

using std::string;
using std::cout;

Sistema::Sistema() {
	usuarios = new LinkedList<TipoUsuario>();
	servicios = new LinkedList<Servicio>();
	// areas = new LinkedList<Area*>();
}

Sistema::~Sistema() {
	delete usuarios;
	delete servicios;
	// delete areas;
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

	/*areas->goToStart();
	while (!areas->atEnd()) {
		Area* area = areas->getElement();
		area->limpiarCola();
		areas->next();
	}*/
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

	// TODO: limpiar tiquetes de todas las colas
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

// --- Estadísticas y Limpieza ---

void Sistema::mostrarEstadisticas() {
	cout << "===== ESTADISTICAS DEL SISTEMA =====\n\n";

	cout << "-- Tiquetes emitidos por tipo de usuario --\n";
	if (usuarios->getSize() == 0) {
		cout << "  (sin datos)\n";
	}
	else {
		usuarios->goToStart();
		while (!usuarios->atEnd()) {
			const TipoUsuario& usuario = usuarios->getElement();
			cout << "  " << usuario << " -> " << usuario.getTotalTiquetes() << " tiquetes\n";
			usuarios->next();
		}
	}

	cout << "\n-- Tiquetes solicitados por servicio --\n";
	if (servicios->getSize() == 0) {
		cout << "  (sin datos)\n";
	}
	else {
		servicios->goToStart();
		while (!servicios->atEnd()) {
			const Servicio& servicio = servicios->getElement();
			cout << "  " << servicio << " -> " << servicio.getTotalTiquetes() << " tiquetes\n";
			servicios->next();
		}
	}

	// TODO: estadísticas por área (tiempo promedio, dispensados) y por ventanilla (atendidos)
}

void Sistema::limpiarColasYEstadisticas() {
	// TODO: cuando Area exista
}