#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Interfaz.h"

using std::cout;
using std::string;

Interfaz::Interfaz(Sistema& sistema) : sistema(sistema), ejecutando(true) {}

void Interfaz::iniciar() {
	while (ejecutando) {
		menuPrincipal();
	}
}

// ===================================================================
// MENÚS
// ===================================================================
void Interfaz::menuPrincipal() {
	limpiarPantalla();
	cout << "===== SISTEMA DE ADMINISTRACIÓN DE COLAS =====\n";
	cout << "1. Estado de las colas\n";
	cout << "2. Tiquetes\n";
	cout << "3. Atender\n";
	cout << "4. Administración\n";
	cout << "5. Estadísticas del sistema\n";
	cout << "6. Salir\n";

	int opcion = leerEnteroEnRango("Seleccione una opción: ", 1, 6);
	switch (opcion) {
		case 1: mostrarEstadoColas();		break;
		case 2: "menuTiquetes()";			break;
		case 3: atenderTiquete();			break;
		case 4: menuAdministracion();		break;
		case 5: "mostrarEstadisticas()";	break;
		case 6: ejecutando = false;			break;
	}
}

void Interfaz::menuAdministracion() {
	bool enMenu = true;
	while (enMenu) {
		limpiarPantalla();
		cout << "===== ADMINISTRACIÓN =====\n";
		cout << "1. Tipos de usuario\n";
		cout << "2. Áreas\n";
		cout << "3. Servicios disponibles\n";
		cout << "4. Limpiar colas y estadísticas\n";
		cout << "5. Regresar\n";

		int opcion = leerEnteroEnRango("Seleccione una opción: ", 1, 5);
		switch (opcion) {
			case 1: menuTiposUsuario();				break;
			case 2: "menuAreas()";					break;
			case 3: "menuServicios()";				break;
			case 4: "limpiarColasYEstadisticas()";	break;
			case 5: enMenu = false;					break;
		}
	}
}

void Interfaz::menuTiposUsuario() {
	bool enMenu = true;
	while (enMenu) {
		limpiarPantalla();
		cout << "===== TIPOS DE USUARIO =====\n\n";
		mostrarTiposUsuario();
		cout << "\n1. Agregar\n";
		cout << "2. Eliminar\n";
		cout << "3. Regresar\n";

		int opcion = leerEnteroEnRango("Seleccione una opción: ", 1, 3);
		switch (opcion) {
		case 1: agregarTipoUsuario();			break;
		case 2: "menuAreas()";					break;
		case 3: enMenu = false;					break;
		}
	}
}

void Interfaz::mostrarTiposUsuario() {
	int n = sistema.getCantidadTiposUsuario();
	if (n == 0) {
		cout << "(No hay tipos de usuario configurados)\n";
		return;
	}
	cout << "Tipos de usuario actuales:\n";
	for (int i = 0; i < n; i++) {
		cout << "  " << (i + 1) << ". " << sistema.getTipoUsuario(i) << "\n";
	}
}

void Interfaz::agregarTipoUsuario() {
	limpiarPantalla();
	cout << "===== AGREGAR TIPO DE USUARIO =====\n\n";

	string descripcion = leerTexto("Descripción: ");
	int prioridad = leerEntero("Prioridad (menor numero = mayor prioridad): ");

	sistema.agregarTipoUsuario(descripcion, prioridad);

	cout << "\nTipo de usuario agregado correctamente!\n";
	presionarParaContinuar();
}

// menuTiquetes, menuAreas, menuServicios siguen
// el mismo patrón de menuAdministracion.

// ===================================================================
// ACCIONES
// ===================================================================
void Interfaz::mostrarEstadoColas() {
	limpiarPantalla();
	cout << "===== ESTADO DE COLAS =====\n";
	cout << "[TODO: mostrar estado de las colas]\n";
	presionarParaContinuar();
}

void Interfaz::atenderTiquete() {
	limpiarPantalla();
	cout << "[TODO: atender tiquete]\n";
	presionarParaContinuar();
}

// siguen el mismo patrón

// ===================================================================
// HELPERS DE E/S
// ===================================================================
int Interfaz::leerEntero(const string& prompt) {
	int valor;
	while (true) {
		cout << prompt;
		string linea;
		std::getline(std::cin, linea);
		std::stringstream ss(linea);
		if (ss >> valor && (ss >> std::ws).eof())
			return valor;
		cout << "Entrada inválida. Ingrese un número entero.\n";
	}
}

int Interfaz::leerEnteroEnRango(const string& prompt, int min, int max) {
	while (true) {
		int valor = leerEntero(prompt);
		if (valor >= min && valor <= max)
			return valor;
		cout << "El valor debe estar entre " << min << " y " << max << ".\n";
	}
}

string Interfaz::leerTexto(const string& prompt) {
	cout << prompt;
	string texto;
	std::getline(std::cin, texto);
	return texto;
}

bool Interfaz::confirmar(const string& mensaje) {
	cout << mensaje << " [s para confirmar]: ";
	string respuesta;
	std::getline(std::cin, respuesta);
	return !respuesta.empty() && (respuesta[0] == 's' || respuesta[0] == 'S');
}

void Interfaz::presionarParaContinuar() {
	std::cout << "\nPresione ENTER para continuar...";
	string dummy;
	std::getline(std::cin, dummy);
}

void Interfaz::limpiarPantalla() {
	std::system("cls");
}