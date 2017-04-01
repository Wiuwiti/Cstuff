#include "DynamicArray.h"
#include <stdlib.h>
#include <assert.h>

DynamicArray* createMaterialArray(int capacity) {
	DynamicArray* _dynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));

	if (_dynamicArray == NULL) {
		return NULL;
	}

	_dynamicArray->_capacity = capacity;
	_dynamicArray->_length = 0;

	_dynamicArray->_elems = (TElement*)malloc(capacity * sizeof(TElement));
	if (_dynamicArray->_elems == NULL)
		return NULL;

	return _dynamicArray;
}

void destroy(DynamicArray* arr) {
	if (arr == NULL) {
		return;
	}

	free(arr->_elems);
	arr->_elems = NULL;

	free(arr);
	arr = NULL;

}

void resize(DynamicArray* arr) {
	if (arr == NULL) {
		return;
	}

	arr->_capacity *= 2;
	arr->_elems = (TElement*)realloc(arr->_elems, arr->_capacity * sizeof(TElement));

}

void add(DynamicArray* arr, TElement t) {
	if (arr == NULL)
	{
		return;
	}
	if (arr->_elems == NULL){
		return;
	}

	if (arr->_length == arr->_capacity) {
		resize(arr);
	}
	arr->_elems[arr->_length++] = t;
}

void deleteElement(DynamicArray* arr, int pos) {
	if (arr == NULL) {
		return;
	}
	if (arr->_elems == NULL) {
		return;
	}
	for (int i = pos; i < arr->_length - 1; i++) {
		arr->_elems[i] = arr->_elems[i + 1];
	}
	arr->_length--;
}

int getLength(DynamicArray* arr) {
	if (arr == NULL) {
		return -1;
	}
	return arr->_length;
}

TElement get(DynamicArray* arr, int pos) {
	return arr->_elems[pos];

}

void testDynamicArray() {
	DynamicArray* _dynamicArray = createMaterialArray(2);
	if (_dynamicArray == NULL) {
		assert(0);
	}

	assert(_dynamicArray->_capacity == 2);
	assert(_dynamicArray->_length == 0);

	Date* _date = createDate(30, 10, 1994);
	Date* _date2 = createDate(31, 10, 1994);
	Material* _material = createMaterial("uuu", "aaaa", 20, _date);
	Material* _material2 = createMaterial("vdvd", "fvbiofsv", 41 , _date2);
	add(_dynamicArray, _material);
	assert(_dynamicArray->_length == 1);

	add(_dynamicArray, _material2);
	assert(_dynamicArray->_length == 2);

	Date* _date3 = createDate(25,10,1994);
	Material* _material3 = createMaterial("vdavd", "scsdc", 41, _date3);
	add(_dynamicArray, _material3);
	assert(_dynamicArray->_length == 3);
	assert(_dynamicArray->_capacity == 4);
	printf("%d\n", isExpired(_material->_expirationDate, _material2->_expirationDate));

	deleteElement(_dynamicArray, 0);
	Material* m = get(_dynamicArray, 0);
	assert(strcmp(getMaterialName(m), "vdvd") == 0);
	assert(_dynamicArray->_length == 2);
	destroy(_dynamicArray);
	destroyMaterial(_material);
	destroyMaterial(_material2);
	destroyMaterial(_material3);

	system("pause");

}