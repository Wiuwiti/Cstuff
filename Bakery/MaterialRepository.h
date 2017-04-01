#pragma once
#include "Material.h"
#include "DynamicArray.h"

typedef struct {
	DynamicArray* materials;
}MaterialRepo;


MaterialRepo* createRepo();

void destroyRepo(MaterialRepo* v);

Material* find(MaterialRepo* v, char* name);

int findPositionOfMaterial(MaterialRepo* v, char* name);

int addMaterial(MaterialRepo* v, Material* material);

void deleteMaterial(MaterialRepo* v, char* name);

int getRepoLength(MaterialRepo* v);

Material* getMaterialOnPosition(MaterialRepo* v, int pos);

void testMaterialRepo();


