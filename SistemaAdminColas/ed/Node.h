/*
 * Archivo: Node.h
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Plantilla genérica que representa un nodo de una lista enlazada
 * simple. Cada nodo almacena un elemento del tipo parametrizado y un
 * puntero al siguiente nodo de la lista. Es la unidad básica sobre la
 * que se construye LinkedList.
 *
 */

#pragma once

template <typename E>
class Node {
public:
	E element;
	Node<E>* next;

	Node(E element, Node<E>* next = nullptr) {
		this->element = element;
		this->next = next;
	}
	Node(Node<E>* next = nullptr) {
		this->next = next;
	}
};