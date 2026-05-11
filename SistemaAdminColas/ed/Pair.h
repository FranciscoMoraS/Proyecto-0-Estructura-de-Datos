/*
 * Archivo: Pair.h
 * Autores: Edwin Muñoz y Francisco Mora
 *
 * Plantilla genérica que representa una dupla clave-valor. Utilizada
 * por HeapPriorityQueue para asociar una prioridad (clave) con su
 * elemento correspondiente (valor). Las operaciones de comparación
 * se definen exclusivamente sobre la clave, permitiendo ordenar los
 * pares según su prioridad sin requerir que el tipo del valor sea
 * comparable.
 *
 */

#pragma once

#include <iostream>

template <typename K, typename V>
class Pair {
public:
	K key;
	V value;

	Pair() = default;
	Pair(K key) {
		this->key = key;
	}
	Pair(K key, V value) {
		this->key = key;
		this->value = value;
	}
	bool operator==(const Pair<K, V>& other) {
		return key == other.key;
	}
	bool operator!=(const Pair<K, V>& other) {
		return key != other.key;
	}
	bool operator<(const Pair<K, V>& other) {
		return key < other.key;
	}
	bool operator<=(const Pair<K, V>& other) {
		return key <= other.key;
	}
	bool operator>(const Pair<K, V>& other) {
		return key > other.key;
	}
	bool operator>=(const Pair<K, V>& other) {
		return key >= other.key;
	}
	friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& p) {
		os << "(" << p.key << ", " << p.value << ")";
		return os;
	}
};