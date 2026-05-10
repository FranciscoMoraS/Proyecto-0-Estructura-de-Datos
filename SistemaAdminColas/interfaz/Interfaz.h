#pragma once

#include <iostream>
#include <string>
#include "../sistema/Sistema.h"

class Interfaz {
private:
	Sistema& sistema;
	bool ejecutando;

	// --- Menús (loops de navegación) ---
	void menuPrincipal();
	void menuTiquetes();
	void menuAdministracion();
	void menuTipoUsuario();
	void menuAreas();
	void menuServicio();

	// --- Acciones ---
	void mostrarEstadoColas();
	void seleccionarTipoYServicio();
	void atenderTiquete();
	void mostrarEstadisticas();

	void agregarArea();
	void modificarVentanillas();
	void eliminarArea();

	void agregarServicio();
	void eliminarServicio();
	void reordenarServicios();

	void limpiarColasYEstadisticas();

public:
	Interfaz(Sistema& sistema);
	void iniciar();
};