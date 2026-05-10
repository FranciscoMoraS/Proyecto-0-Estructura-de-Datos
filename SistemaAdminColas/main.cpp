#include <clocale>
#include <Windows.h>
#include "sistema/Sistema.h"
#include "interfaz/Interfaz.h"

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	setlocale(LC_ALL, "");

	Sistema sistema;
	Interfaz interfaz(sistema);
	interfaz.iniciar();

	return 0;
}