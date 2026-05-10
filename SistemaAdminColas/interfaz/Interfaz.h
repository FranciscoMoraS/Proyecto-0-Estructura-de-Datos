#pragma once

#include "../sistema/Sistema.h"

class Interfaz {
private:
	Sistema& sistema;

public:
	Interfaz(Sistema& sistema);
	void iniciar();
};