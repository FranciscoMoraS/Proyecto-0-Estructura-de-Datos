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
	void menuTiposUsuario();
	void menuAreas();
	void menuServicio();

	// --- Acciones ---
	void mostrarTiposUsuario();
	void agregarTipoUsuario();
	void eliminarTipoUsuario();

	void mostrarEstadoColas();
	void seleccionarTipoYServicio();
	void atenderTiquete();
	void mostrarEstadisticas();

	void mostrarAreas();
	void agregarArea();
	void modificarVentanillas();
	void eliminarArea();
	void mostrarServiciosDeArea(const std::string& codigoArea);

	void agregarServicio();
	void eliminarServicio();
	void reordenarServicios();

	void limpiarColasYEstadisticas();

	// --- Helpers de E/S ---
	int leerEntero(const std::string& prompt);
	int leerEnteroEnRango(const std::string& prompt, int min, int max);
	std::string leerTexto(const std::string& prompt);
	bool confirmar(const std::string& mensaje);
	void presionarParaContinuar();
	void limpiarPantalla();

public:
	Interfaz(Sistema& sistema);
	void iniciar();
};