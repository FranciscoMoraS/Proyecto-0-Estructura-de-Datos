#include <string>
#include "Area.h"
#include "../ed/LinkedList.h"
#include "../ed/HeapPriorityQueue.h"

using std::string;

Area::Area(const string& codigo, const string& descripcion, int cantVentanillas) {
	this->codigo = codigo;
	this->descripcion = descripcion;

	ventanillas = new LinkedList<Ventanilla>();
	colaTiquetes = new HeapPriorityQueue<Tiquete>();

	for (int i = 1; i <= cantVentanillas; i++) {
		string nombreVentanilla = codigo + std::to_string(i);
		ventanillas->append(Ventanilla(nombreVentanilla));
	}
}

Area::~Area() {
	delete ventanillas;
	delete colaTiquetes;
}

void Area::encolarTiquete(const Tiquete& tiquete) {
	// TODO
}

void Area::atenderTiquete(int numVentanilla) {
	// TODO
}

void Area::modificarVentanillas(int nuevaCantidad) {
	// TODO
}

void Area::limpiarColaYEstadisticas() {
	// TODO
}

string Area::getCodigo() const {
	return codigo;
}

string Area::getDescripcion() const {
	return descripcion;
}

int Area::getCantidadVentanillas() const {
	return ventanillas->getSize();
}

int Area::getTiquetesDispensados() const {
	return tiquetesDispensados;
}

int Area::getTiquetesAtendidos() const {
	return tiquetesAtendidos;
}

double Area::getTiempoPromedio() const {
	if (tiquetesAtendidos == 0) return 0.0;
	return tiempoEsperaAcumulado / tiquetesAtendidos;
}

LinkedList<Ventanilla>& Area::getVentanillas() {
	return *ventanillas;
}

HeapPriorityQueue<Tiquete>& Area::getColaTiquetes() {
	return *colaTiquetes;
}

std::ostream& operator<<(std::ostream& os, const Area& area) {
	os << area.codigo << " - " << area.descripcion << " (" << area.ventanillas->getSize() << " ventanillas)";
	return os;
}