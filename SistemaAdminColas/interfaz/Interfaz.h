/*
 * Archivo: Interfaz.h
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Declaración de la clase Interfaz, responsable de toda la interacción
 * por consola con el usuario del sistema. Mantiene una referencia al
 * Sistema para delegar las operaciones de negocio y se encarga de la
 * navegación por menús (principal, tiquetes, administración, tipos de
 * usuario, áreas, servicios), la validación de entradas del usuario y
 * la presentación de información y estadísticas. Centraliza todos los
 * helpers de entrada/salida que utilizan los distintos menús.
 *
 */

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

	void mostrarServicios();
	void agregarServicio();
	void eliminarServicio();
	void reordenarServicios();

	void mostrarEstadoColas();

	void mostrarAreas();
	void agregarArea();
	void modificarVentanillas();
	void eliminarArea();
	void mostrarServiciosDeArea(const std::string& codigoArea);

	void atenderTiquete();
	void solicitarTiquete();

	void mostrarEstadisticas();

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