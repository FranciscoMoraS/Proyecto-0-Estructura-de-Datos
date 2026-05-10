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

public:
	Interfaz(Sistema& sistema);
	void iniciar();
};