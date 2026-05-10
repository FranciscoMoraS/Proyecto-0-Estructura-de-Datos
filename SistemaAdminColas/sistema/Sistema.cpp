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
void Sistema::agregarTipoUsuario(const std::string& descripcion, int prioridad) {
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