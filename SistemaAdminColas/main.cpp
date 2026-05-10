#include "sistema/Sistema.h"
#include "interfaz/Interfaz.h"

int main() {
	Sistema sistema;
	Interfaz interfaz(sistema);
	interfaz.iniciar();

	return 0;
}