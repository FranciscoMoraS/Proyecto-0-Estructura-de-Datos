/*
 * Archivo: PriorityQueue.h
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Clase abstracta que define la interfaz general para una cola con
 * prioridad. Especifica las operaciones que toda implementación
 * concreta debe proveer: inserción con prioridad, consulta y
 * extracción del elemento de mayor prioridad, limpieza, consulta de
 * tamaño y estado, e impresión. La clase es no-copiable.
 * 
 */

#pragma once

template <typename E>
class PriorityQueue {
public:
	PriorityQueue() {}
	PriorityQueue(const PriorityQueue<E>&) = delete;
	void operator=(const PriorityQueue<E>&) = delete;
	virtual ~PriorityQueue() = default;
	virtual void insert(E element, int priority) = 0;
	virtual E min() = 0;
	virtual E removeMin() = 0;
	virtual void clear() = 0;
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
};