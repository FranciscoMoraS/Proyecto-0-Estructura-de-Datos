#include <iostream>
#include "Sistema.h"
#include "../ed/LinkedList.h"
#include "../modelo/TipoUsuario.h"

using std::string;

Sistema::Sistema() {
	usuarios = new LinkedList<TipoUsuario>();
	servicios = new LinkedList<Servicio>();
	// areas = new LinkedList<Area*>();		pendiente
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

	// TODO: limpiar tiquetes de todas las colas
}

LinkedList<TipoUsuario>& Sistema::getTiposUsuario() {
	return *usuarios;
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

LinkedList<Servicio>& Sistema::getServicios() {
	return *servicios;
}