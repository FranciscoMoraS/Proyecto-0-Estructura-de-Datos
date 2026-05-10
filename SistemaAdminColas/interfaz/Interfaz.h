#pragma once

#include <iostream>
#include <string>
#include "../sistema/Sistema.h"

class Interfaz {
private:
	Sistema& sistema;
	bool ejecutando;

public:
	Interfaz(Sistema& sistema);
	void iniciar();
};