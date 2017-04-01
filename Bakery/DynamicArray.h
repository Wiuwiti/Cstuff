#pragma once
#include "Material.h"
#include "Date.h"
#define CAPACITY 20

typedef Material* TElement;

typedef struct {
	TElement* _elems;
	int _length;
	int _capacity;
}DynamicArray;

DynamicArray* createMaterialArray(int capacity);

void destroy(DynamicArray* arr);

void add(DynamicArray* arr, TElement t);

void deleteElement(DynamicArray* arr, int pos);

int getLength(DynamicArray* arr);

TElement get(DynamicArray* arr, int pos);

void testDynamicArray();
