#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
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
		case 2: menuTiquetes();				break;
		case 3: atenderTiquete();			break;
		case 4: menuAdministracion();		break;
		case 5: mostrarEstadisticas();		break;
		case 6: ejecutando = false;			break;
	}
}

void Interfaz::menuTiquetes() {
	bool enMenu = true;
	while (enMenu) {
		limpiarPantalla();
		cout << "===== TIQUETES =====\n\n";
		cout << "1. Solicitar\n";
		cout << "2. Regresar\n";

		int opcion = leerEnteroEnRango("Seleccione una opción: ", 1, 2);
		switch (opcion) {
		case 1: solicitarTiquete();     break;
		case 2: enMenu = false;         break;
		}
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
			case 2: menuAreas();					break;
			case 3: menuServicio();					break;
			case 4: limpiarColasYEstadisticas();	break;
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
		case 2: eliminarTipoUsuario();			break;
		case 3: enMenu = false;					break;
		}
	}
}

void Interfaz::menuAreas() {
	bool enMenu = true;
	while (enMenu) {
		limpiarPantalla();
		cout << "===== AREAS =====\n\n";
		mostrarAreas();
		cout << "\n1. Agregar\n";
		cout << "2. Modificar cantidad de ventanillas\n";
		cout << "3. Eliminar\n";
		cout << "4. Regresar\n";

		int opcion = leerEnteroEnRango("Seleccione una opción: ", 1, 4);
		switch (opcion) {
		case 1: agregarArea();              break;
		case 2: modificarVentanillas();     break;
		case 3: eliminarArea();             break;
		case 4: enMenu = false;             break;
		}
	}
}

void Interfaz::menuServicio() {
	bool enMenu = true;
	while (enMenu) {
		limpiarPantalla();
		cout << "===== SERVICIOS DISPONIBLES =====\n\n";
		mostrarServicios();
		cout << "\n1. Agregar\n";
		cout << "2. Eliminar\n";
		cout << "3. Reordenar\n";
		cout << "4. Regresar\n";

		int opcion = leerEnteroEnRango("Seleccione una opcion: ", 1, 4);
		switch (opcion) {
		case 1: agregarServicio();			  break;
		case 2: eliminarServicio();			  break;
		case 3: reordenarServicios();		  break;
		case 4: enMenu = false;               break;
		}
	}
}

void Interfaz::reordenarServicios() {
	limpiarPantalla();
	cout << "===== REORDENAR SERVICIOS =====\n\n";

	int n = sistema.getCantidadServicios();
	if (n < 2) {
		cout << "Se necesitan al menos dos servicios para reordenar.\n";
		presionarParaContinuar();
		return;
	}
	mostrarServicios();

	int desde = leerEnteroEnRango("\nNúmero del servicio a reubicar: ", 1, n);
	int hasta = leerEnteroEnRango("Posición destino: ", 1, n);

	if (desde == hasta) {
		cout << "\nNo hay cambio de posición.\n";
	}
	else {
		sistema.reordenarServicio(desde - 1, hasta - 1);
		cout << "\nServicio reubicado correctamente.\n";
	}

	presionarParaContinuar();
}

// ===================================================================
// ACCIONES
// ===================================================================
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

void Interfaz::eliminarTipoUsuario() {
	limpiarPantalla();

	cout << "===== ELIMINAR TIPO DE USUARIO =====\n\n";
	int n = sistema.getCantidadTiposUsuario();
	if (n == 0) {
		cout << "(No hay tipos de usuario para eliminar)\n";
		presionarParaContinuar();
		return;
	}
	mostrarTiposUsuario();

	int pos = leerEnteroEnRango("\nNúmero del tipo a eliminar: ", 1, n);
	cout << "\nADVERTENCIA: Eliminar un tipo de usuario borrará todos los tiquetes de todas las colas.\n";

	if (confirmar("¿Continuar?")) {
		sistema.eliminarTipoUsuario(pos - 1);
		cout << "\nTipo de usuario eliminado!\n";
	}
	else {
		cout << "\nOperación cancelada.\n";
	}
	presionarParaContinuar();

}

void Interfaz::mostrarServicios() {
	int n = sistema.getCantidadServicios();
	if (n == 0) {
		cout << "(No hay servicios configurados)\n";
		return;
	}
	cout << "Servicios actuales:\n";
	for (int i = 0; i < n; i++) {
		cout << "  " << (i + 1) << ". " << sistema.getServicio(i) << "\n";
	}
}

void Interfaz::agregarServicio() {
	limpiarPantalla();
	cout << "===== AGREGAR SERVICIO =====\n\n";

	int numAreas = sistema.getCantidadAreas();
	if (numAreas == 0) {
		cout << "Debe existir al menos un área antes de agregar un servicio.\n";
		presionarParaContinuar();
		return;
	}

	string descripcion = leerTexto("Descripción: ");
	int prioridad = leerEntero("Prioridad (menor numero = mayor prioridad): ");

	mostrarAreas();

	int posArea = leerEnteroEnRango("\nÁrea de atención: ", 1, numAreas);
	Area* area = sistema.getArea(posArea - 1);
	string codigoArea = area->getCodigo();

	sistema.agregarServicio(descripcion, prioridad, codigoArea);

	cout << "\nServicio agregado correctamente!\n";
	presionarParaContinuar();
}

void Interfaz::eliminarServicio() {
	limpiarPantalla();
	cout << "===== ELIMINAR SERVICIO =====\n\n";

	int n = sistema.getCantidadServicios();
	if (n == 0) {
		cout << "(No hay servicios configurados)\n";
		presionarParaContinuar();
		return;
	}
	mostrarServicios();

	int pos = leerEnteroEnRango("\nNúmero del servicio a eliminar: ", 1, n);
	cout << "\nADVERTENCIA: Eliminar un servicio borrará todos los tiquetes de las colas de todas las áreas.\n";

	if (confirmar("¿Continuar?")) {
		sistema.eliminarServicio(pos - 1);
		cout << "\nServicio eliminado!\n";
	}
	else {
		cout << "\nOperación cancelada.\n";
	}

	presionarParaContinuar();
}

void Interfaz::mostrarEstadoColas() {
	limpiarPantalla();
	cout << "===== ESTADO DE COLAS =====\n";

	int numAreas = sistema.getCantidadAreas();
	if (numAreas == 0) {
		cout << "(No hay áreas configuradas)\n";
		presionarParaContinuar();
		return;
	}

	for (int i = 0; i < numAreas; i++) {
		Area* area = sistema.getArea(i);

		cout << *area << "\n";   // area's operator<<: "C - Cajas (4 ventanillas)"
		cout << "  Cola de tiquetes: ";
		area->imprimirCola();
		cout << "  Ventanillas:\n";
		int numVent = area->getCantidadVentanillas();
		for (int j = 0; j < numVent; j++) {
			cout << "    " << area->getVentanilla(j) << "\n";
		}
		cout << "\n";
	}

	presionarParaContinuar();
}

void Interfaz::mostrarAreas() {
	int n = sistema.getCantidadAreas();
	if (n == 0) {
		cout << "(No hay áreas configuradas)\n";
		return;
	}
	cout << "Áreas actuales:\n";
	for (int i = 0; i < n; i++) {
		cout << "  " << (i + 1) << ". " << *sistema.getArea(i) << "\n";
	}
}

void Interfaz::agregarArea() {
	limpiarPantalla();
	cout << "===== AGREGAR AREA =====\n\n";

	string codigo = leerTexto("Código del área (ej: C, S, E): ");

	int n = sistema.getCantidadAreas();
	for (int i = 0; i < n; i++) {
		if (sistema.getArea(i)->getCodigo() == codigo) {
			cout << "\nError: ya existe un área con código '" << codigo << "'.\n";
			presionarParaContinuar();
			return;
		}
	}

	string descripcion = leerTexto("Descripción: ");
	int cantVentanillas = leerEnteroEnRango("Cantidad de ventanillas: ", 1, 999);

	sistema.agregarArea(codigo, descripcion, cantVentanillas);

	cout << "\nÁrea agregada correctamente!\n";
	presionarParaContinuar();
}

void Interfaz::modificarVentanillas() {
	limpiarPantalla();
	cout << "===== MODIFICAR CANTIDAD DE VENTANILLAS =====\n\n";

	int n = sistema.getCantidadAreas();
	if (n == 0) {
		cout << "(No hay áreas configuradas)\n";
		presionarParaContinuar();
		return;
	}
	mostrarAreas();

	int pos = leerEnteroEnRango("\nNúmero del área a modificar: ", 1, n);

	cout << "\nVentanillas actuales: " << sistema.getCantidadVentanillas(pos-1) << "\n";
	int nueva = leerEnteroEnRango("Nueva cantidad: ", 1, 999);

	cout << "\nADVERTENCIA: las ventanillas actuales se eliminarán y se crearán\n"
		<< "de nuevo. Los tiquetes en cola se mantienen.\n";

	if (confirmar("¿Continuar?")) {
		sistema.modificarVentanillas(pos-1, nueva);
		cout << "\nCantidad de ventanillas modificada.\n";
	}
	else {
		cout << "\nOperación cancelada.\n";
	}

	presionarParaContinuar();
}

void Interfaz::eliminarArea() {
	limpiarPantalla();
	cout << "===== ELIMINAR AREA =====\n\n";

	int n = sistema.getCantidadAreas();
	if (n == 0) {
		cout << "(No hay áreas configuradas)\n";
		presionarParaContinuar();
		return;
	}
	mostrarAreas();

	int pos = leerEnteroEnRango("\nNúmero del área a eliminar: ", 1, n);
	Area* area = sistema.getArea(pos - 1);
	string codigo = area->getCodigo();

	cout << "\nServicios que también se eliminarán:\n";
	mostrarServiciosDeArea(codigo);

	cout << "\nADVERTENCIA: eliminar esta área también:\n"
		<< "  - Borra todas sus ventanillas\n"
		<< "  - Elimina los servicios listados arriba\n"
		<< "  - Vacía las colas de todas las áreas restantes\n";

	if (confirmar("¿Continuar?")) {
		sistema.eliminarArea(pos - 1);
		cout << "\nÁrea eliminada!\n";
	}
	else {
		cout << "\nOperación cancelada.\n";
	}

	presionarParaContinuar();
}

void Interfaz::mostrarServiciosDeArea(const string& codigoArea) {
	int n = sistema.getCantidadServicios();
	bool hayAlguno = false;
	for (int i = 0; i < n; i++) {
		const Servicio& s = sistema.getServicio(i);
		if (s.getCodigoArea() == codigoArea) {
			cout << "  - " << s << "\n";
			hayAlguno = true;
		}
	}
	if (!hayAlguno) {
		cout << "  (ninguno)\n";
	}
}

// -- Tiquetes --

void Interfaz::atenderTiquete() {
	limpiarPantalla();
	cout << "===== ATENDER TIQUETE =====\n\n";

	int nAreas = sistema.getCantidadAreas();
	if (nAreas == 0) {
		cout << "No hay áreas configuradas.\n";
		presionarParaContinuar();
		return;
	}

	mostrarAreas();
	int posArea = leerEnteroEnRango("\nSeleccione el área: ", 1, nAreas);
	Area* area = sistema.getArea(posArea - 1);

	int enCola = area->getCantidadEnCola();
	if (enCola == 0) {
		cout << "\nNo hay tiquetes en cola para esta área.\n";
		presionarParaContinuar();
		return;
	}
	cout << "\nTiquetes en cola: " << enCola << "\n";

	cout << "\nVentanillas del area:\n";
	int nVent = area->getCantidadVentanillas();
	for (int i = 0; i < nVent; i++) {
		cout << "  " << (i + 1) << ". " << area->getVentanilla(i) << "\n";
	}
	int numVent = leerEnteroEnRango("\nSeleccione ventanilla: ", 1, nVent);

	Tiquete t = sistema.atenderTiquete(posArea - 1, numVent - 1);

	cout << "\n===== TIQUETE ATENDIDO =====\n";
	cout << t << "\n";
	cout << "Tiempo de espera: "
		<< std::fixed << std::setprecision(2)
		<< t.getTiempoDeEspera()
		<< " segundos"
		<< std::defaultfloat << "\n";

	presionarParaContinuar();
}

void Interfaz::solicitarTiquete() {
	limpiarPantalla();
	cout << "===== SOLICITAR TIQUETE =====\n\n";

	int nTipos = sistema.getCantidadTiposUsuario();
	if (nTipos == 0) {
		cout << "Debe existir al menos un tipo de usuario configurado.\n";
		presionarParaContinuar();
		return;
	}
	int nServ = sistema.getCantidadServicios();
	if (nServ == 0) {
		cout << "Debe existir al menos un servicio configurado.\n";
		presionarParaContinuar();
		return;
	}

	cout << "Tipos de usuario disponibles:\n";
	for (int i = 0; i < nTipos; i++) {
		const TipoUsuario& t = sistema.getTipoUsuario(i);
		cout << "  " << (i + 1) << ". " << t.getDescripcion() << "\n";
	}
	int posTipo = leerEnteroEnRango("\nSeleccione tipo de usuario: ", 1, nTipos);

	cout << "\nServicios disponibles:\n";
	for (int i = 0; i < nServ; i++) {
		const Servicio& s = sistema.getServicio(i);
		cout << "  " << (i + 1) << ". " << s << "\n";
	}
	int posServ = leerEnteroEnRango("\nSeleccione servicio: ", 1, nServ);

	Tiquete t = sistema.solicitarTiquete(posTipo - 1, posServ - 1);

	cout << "\n===== TIQUETE EMITIDO =====\n";
	cout << t << "\n";

	presionarParaContinuar();
}

// -- Estadísticas --

void Interfaz::mostrarEstadisticas() {
	limpiarPantalla();
	cout << "===== ESTADISTICAS DEL SISTEMA =====\n\n";

	cout << "--- Tiquetes solicitados por tipo de usuario ---\n";
	int nTipos = sistema.getCantidadTiposUsuario();
	if (nTipos == 0) {
		cout << "  (No hay tipos de usuario configurados)\n";
	}
	else {
		for (int i = 0; i < nTipos; i++) {
			const TipoUsuario& t = sistema.getTipoUsuario(i);
			cout << "  - " << t << ": " << t.getTotalTiquetes() << " tiquete(s)\n";
		}
	}

	cout << "\n--- Tiquetes solicitados por servicio ---\n";
	int nServ = sistema.getCantidadServicios();
	if (nServ == 0) {
		cout << "  (No hay servicios configurados)\n";
	}
	else {
		for (int i = 0; i < nServ; i++) {
			const Servicio& s = sistema.getServicio(i);
			cout << "  - " << s << ": " << s.getTotalTiquetes() << " tiquete(s)\n";
		}
	}

	cout << "\n--- Estadísticas por área ---\n";
	int nAreas = sistema.getCantidadAreas();
	if (nAreas == 0) {
		cout << "  (No hay áreas configuradas)\n";
	}
	else {
		for (int i = 0; i < nAreas; i++) {
			Area* area = sistema.getArea(i);
			cout << "\n  " << *area << "\n";
			cout << "    Tiquetes dispensados:      " << area->getTiquetesDispensados() << "\n";
			cout << "    Tiquetes atendidos:        " << area->getTiquetesAtendidos() << "\n";
			cout << "    Tiempo promedio de espera: "
				<< std::fixed << std::setprecision(2)
				<< area->getTiempoPromedio()
				<< " segundos"
				<< std::defaultfloat << "\n";
			cout << "    Ventanillas:\n";
			int nVent = area->getCantidadVentanillas();
			for (int j = 0; j < nVent; j++) {
				const Ventanilla& v = area->getVentanilla(j);
				cout << "      - " << v.getNombre() << ": " << v.getTiquetesAtendidos() << " atendido(s)\n";
			}
		}
	}

	presionarParaContinuar();
}

// --- Limpieza ---

void Interfaz::limpiarColasYEstadisticas() {
	limpiarPantalla();
	cout << "===== LIMPIAR COLAS Y ESTADISTICAS =====\n\n";

	cout << "Esta operación:\n"
		<< "  - Borra TODOS los tiquetes de TODAS las colas\n"
		<< "  - Resetea TODOS los contadores estadísticos a cero:\n"
		<< "      * Tiquetes por tipo de usuario\n"
		<< "      * Tiquetes por servicio\n"
		<< "      * Tiquetes dispensados y atendidos por área\n"
		<< "      * Tiempo de espera acumulado por área\n"
		<< "      * Tiquetes atendidos por ventanilla\n";

	if (confirmar("\n¿Continuar? Esta acción no se puede deshacer.")) {
		sistema.limpiarColasYEstadisticas();
		cout << "\nColas y estadísticas reiniciadas correctamente!\n";
	}
	else {
		cout << "\nOperación cancelada.\n";
	}

	presionarParaContinuar();
}

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