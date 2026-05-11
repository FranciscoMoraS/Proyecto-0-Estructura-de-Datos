/*
 * Archivo: Area.h
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Declaración de la clase Area, que representa una zona del local
 * dedicada a atender un conjunto de servicios. Cada área tiene un
 * código identificador, una descripción, una lista de ventanillas
 * propias y una cola de tiquetes con prioridad implementada sobre un
 * heap. Lleva el registro acumulado de tiquetes dispensados,
 * atendidos y tiempo de espera total para el cálculo de
 * estadísticas. La clase es no-copiable porque encapsula estructuras
 * de datos dinámicas no-copiables.
 *
 */

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
	Tiquete atenderTiquete(int numVentanilla);

	// --- Modificación de ventanillas ---
	const Ventanilla& getVentanilla(int pos);
	void modificarVentanillas(int nuevaCantidad);

	// --- limpieza ---
	void limpiarCola();
	void limpiarColaYEstadisticas();

	void imprimirCola() const;

	std::string getCodigo() const;
	std::string getDescripcion() const;
	int getCantidadEnCola() const;
	int getCantidadVentanillas() const;
	int getTiquetesDispensados() const;
	int getTiquetesAtendidos() const;
	double getTiempoPromedio() const;
	LinkedList<Ventanilla>& getVentanillas();
	HeapPriorityQueue<Tiquete>& getColaTiquetes();

	friend std::ostream& operator<<(std::ostream& os, const Area& area);
};