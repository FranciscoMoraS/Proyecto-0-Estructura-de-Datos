/*
 * Archivo: Area.cpp
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Implementación de la clase Area. Construye dinámicamente la lista de
 * ventanillas y la cola de tiquetes con prioridad al momento de su
 * creación, asignándole a cada ventanilla un nombre derivado del
 * código del área. Gestiona la inserción y extracción de tiquetes
 * según prioridad, la asignación del tiquete extraído a la ventanilla
 * indicada y el cálculo de estadísticas operativas (tiempo promedio
 * de espera, tiquetes dispensados y atendidos). Provee operaciones de
 * limpieza tanto parcial (solo cola) como total (cola + estadísticas
 * + estado de ventanillas).
 *
 */

#include <string>
#include <stdexcept>
#include "Area.h"
#include "Ventanilla.h"
#include "../ed/LinkedList.h"
#include "../ed/HeapPriorityQueue.h"


using std::string;
using std::runtime_error;

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
	colaTiquetes->insert(tiquete, tiquete.getPrioridadFinal());
	tiquetesDispensados++;
}

Tiquete Area::atenderTiquete(int numVentanilla) {
	if (numVentanilla >= ventanillas->getSize())
		throw runtime_error("Numero de ventanilla no valido.");
	Tiquete tiquete = colaTiquetes->removeMin();
	tiquete.marcarAtendido();
	ventanillas->goToPos(numVentanilla);
	Ventanilla ventanilla = ventanillas->getElement();
	double espera = ventanilla.atenderTiquete(tiquete);
	ventanillas->setElement(ventanilla);

	tiquetesAtendidos++;
	tiempoEsperaAcumulado += espera;

	return tiquete;
}

const Ventanilla& Area::getVentanilla(int pos) {
	ventanillas->goToPos(pos);
	return ventanillas->getElement();
}

void Area::modificarVentanillas(int nuevaCantidad) {
	ventanillas->clear();
	for (int i = 1; i <= nuevaCantidad; i++) {
		string nombreVentanilla = codigo + std::to_string(i);
		ventanillas->append(Ventanilla(nombreVentanilla));
	}
}

void Area::limpiarCola() {
	colaTiquetes->clear();
}

void Area::limpiarColaYEstadisticas() {
	colaTiquetes->clear();
	tiquetesAtendidos = 0;
	tiquetesDispensados = 0;
	tiempoEsperaAcumulado = 0;

	ventanillas->goToStart();
	while (!ventanillas->atEnd()) {
		Ventanilla v = ventanillas->getElement();
		v.limpiar();
		ventanillas->setElement(v);
		ventanillas->next();
	}
}

void Area::imprimirCola() const {
	if (colaTiquetes->isEmpty()) {
		std::cout << "(vacia)\n";
		return;
	}

	LinkedList<Tiquete> temp;
	while (!colaTiquetes->isEmpty()) {
		temp.append(colaTiquetes->removeMin());
	}

	std::cout << "[ ";
	temp.goToStart();
	bool primero = true;
	while (!temp.atEnd()) {
		if (!primero) std::cout << ", ";
		std::cout << temp.getElement().getCodigo();
		temp.next();
		primero = false;
	}
	std::cout << " ]\n";

	temp.goToStart();
	while (!temp.atEnd()) {
		const Tiquete& t = temp.getElement();
		colaTiquetes->insert(t, t.getPrioridadFinal());
		temp.next();
	}
}

string Area::getCodigo() const {
	return codigo;
}

string Area::getDescripcion() const {
	return descripcion;
}

int Area::getCantidadEnCola() const {
	return colaTiquetes->getSize();
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