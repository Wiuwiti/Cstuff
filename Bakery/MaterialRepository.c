#include "MaterialRepository.h"
#include <stdlib.h>
#include <string.h>
#include<assert.h>

MaterialRepo* createRepo() {
	MaterialRepo* v = (MaterialRepo*)malloc(sizeof(MaterialRepo));
	v->materials = createMaterialArray(CAPACITY);
	return v;
}


void destroyRepo(MaterialRepo* v) {
	if (v == NULL) {
		return;
	}
	for (int i = 0; i < getLength(v->materials); i++) { 
		Material* m = get(v->materials, i); 
	//	destroyMaterial(m); 
	}

	destroy(v->materials);
	free(v);
}

int findPositionOfMaterial(MaterialRepo* v, char* name) {
	if (v == NULL) {
		return -1;
	}
	for (int i = 0; i < getLength(v->materials); i++) {
		Material* material = get(v->materials,i);
		if (strcmp(material->_materialName, name) == 0) {
			return i;
		}
	}
	return -1;
}


Material* find(MaterialRepo* v, char* name) {
	if (v == NULL) {
		return NULL;
	}
	int pos = findPositionOfMaterial(v, name);
	if (pos == -1) {
		return NULL;
	}
	return get(v->materials, pos);
}

int addMaterial(MaterialRepo* v, Material* material) {
	if (v == NULL) {
		return 0;
	}
	if (find(v, material->_materialName) != NULL) {
		return 0;
	}

	Material* copy = copyMaterial(material);
	//printf("%d/%d/%d", copy->_expirationDate->_day,copy->_expirationDate->_month, copy->_expirationDate->_year);
	add(v->materials, copy);
	//printf("%d/%d/%d ", v->materials->_elems[0]->_expirationDate->_day, v->materials->_elems[0]->_expirationDate->_month, v->materials->_elems[0]->_expirationDate->_year);
	return 1;
}

void deleteMaterial(MaterialRepo* v, char* name) {
	if (v == NULL) {
		return;
	}
	int pos = findPositionOfMaterial(v, name);
	if (pos = -1) {
		return;
	}

	Material* material = get(v->materials, name);
	destroyMaterial(material);

	deleteElement(v->materials, pos);

}

int getRepoLength(MaterialRepo* v) {
	if (v == NULL) {
		return -1;
	}
	return getLength(v->materials);
}

Material* getMaterialOnPosition(MaterialRepo* v, int pos) {
	if (v == NULL) {
		return NULL;
	}
	if (pos < 0 || pos >= getLength(v->materials)) {
		return NULL;
	}
	return get(v->materials, pos);
}


