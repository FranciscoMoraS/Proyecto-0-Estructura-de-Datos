/*
 * Archivo: HeapPriorityQueue.h
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Implementación genérica de una cola con prioridad sobre un heap
 * mínimo. Hereda de la clase abstracta PriorityQueue y delega el
 * almacenamiento a un MinHeap de pares (prioridad, elemento), donde
 * la prioridad actúa como clave de ordenamiento. Garantiza
 * inserción y extracción del elemento de mayor prioridad (menor
 * valor numérico) en tiempo logarítmico.
 *
 */

#pragma once

#include <iostream>
#include <stdexcept>
#include "PriorityQueue.h"
#include "Pair.h"
#include "MinHeap.h"
#include "Util.h"

using std::runtime_error;

template <typename E>
class HeapPriorityQueue : public PriorityQueue<E> {
private:
	MinHeap<Pair<int, E>>* pairs;

public:
	HeapPriorityQueue(int max = DEFAULT_MAX) {
		pairs = new MinHeap<Pair<int, E>>(max);
	}
	~HeapPriorityQueue() {
		delete pairs;
	}
	void insert(E element, int priority) {
		Pair<int, E> p(priority, element);
		pairs->insert(p);
	}
	E min() {
		return pairs->first().value;
	}
	E removeMin() {
		return pairs->removeFirst().value;
	}
	void clear() {
		pairs->clear();
	}
	int getSize() {
		return pairs->getSize();
	}
	bool isEmpty() {
		return pairs->isEmpty();
	}
	void print() {
		pairs->print();
	}
};