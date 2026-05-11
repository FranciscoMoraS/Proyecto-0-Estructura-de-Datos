/*
 * Archivo: main.cpp
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Punto de entrada del Sistema de Administración de Colas con Prioridad.
 * Configura la consola para soportar UTF-8 en Windows, instancia el Sistema
 * y la Interfaz, e inicia el ciclo principal del programa.
 *
 */

#define NOMINMAX

#include <clocale>
#include <Windows.h>
#include "sistema/Sistema.h"
#include "interfaz/Interfaz.h"

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Sistema sistema;
	Interfaz interfaz(sistema);
	interfaz.iniciar();

	return 0;
}