#pragma once
#include "Date.h"

typedef struct {
	char* _materialName;
	char* _materialSupplier;
	int _materialAmount;
	Date* _expirationDate;
}Material;

Material* createMaterial(char* materialName, char* materialSupplier, int materialAmount, Date* expirationDate);
void destroyMaterial(Material* m);
Material* copyMaterial(Material* m);

char* getMaterialName(Material* m);
char* getMaterialSupplier(Material* m);
int getMaterialAmount(Material* m);
Date* getExpirationDate(Material* m);

void toString(Material* m, char str[]);

void testMaterial();