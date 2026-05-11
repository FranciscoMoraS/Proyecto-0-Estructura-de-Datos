#pragma once

#include <iostream>
#include <string>
#include "../ed/LinkedList.h"
#include "../ed/HeapPriorityQueue.h"
#include "Ventanilla.h"
#include "Tiquete.h"

class Area {
private:
	std::string codigo;
	std::string descripcion;
	LinkedList<Ventanilla>* ventanillas;
	HeapPriorityQueue<Tiquete>* colaTiquetes;

	int tiquetesDispensados = 0;
	int tiquetesAtendidos = 0;
	double tiempoEsperaAcumulado = 0.0;

public:
	Area(const std::string& codigo, const std::string& descripcion, int cantVentanillas);
	Area(const Area&) = delete;
	const Area& operator=(const Area&) = delete;
	~Area();

	// --- Operaciones tiquete ---
	void encolarTiquete(const Tiquete& tiquete);
	void atenderTiquete(int numVentanilla);

	// --- Modificación de ventanillas ---
	const Ventanilla& getVentanilla(int pos);
	void modificarVentanillas(int nuevaCantidad);

	// --- limpieza ---
	void limpiarCola();
	void limpiarColaYEstadisticas();

	void imprimirCola() const;

	std::string getCodigo() const;
	std::string getDescripcion() const;
	int getCantidadVentanillas() const;
	int getTiquetesDispensados() const;
	int getTiquetesAtendidos() const;
	double getTiempoPromedio() const;
	LinkedList<Ventanilla>& getVentanillas();
	HeapPriorityQueue<Tiquete>& getColaTiquetes();

	friend std::ostream& operator<<(std::ostream& os, const Area& area);
};