/*
 * Archivo: List.h
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Clase abstracta que define la interfaz general para una lista
 * lineal. Especifica las operaciones que toda implementación concreta
 * debe proveer: inserción y eliminación de elementos, acceso y
 * modificación del elemento actual, navegación por la lista mediante
 * un cursor (inicio, fin, posición específica, avance y retroceso),
 * consulta del estado del cursor e impresión. La clase es no-copiable.
 *
 */

#pragma once

template <typename E>
class List {
public:
	List() {}
	List(const List<E>&) = delete;
	void operator=(const List<E>&) = delete;
	virtual ~List() = default;
	virtual void insert(E element) = 0;
	virtual void append(E element) = 0;
	virtual void setElement(E element) = 0;
	virtual const E& getElement() = 0;
	virtual E remove() = 0;
	virtual void clear() = 0;
	virtual void goToStart() = 0;
	virtual void goToEnd() = 0;
	virtual void goToPos(int pos) = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool atStart() = 0;
	virtual bool atEnd() = 0;
	virtual int getPos() = 0;
	virtual int getSize() = 0;
	virtual void print() = 0;
};