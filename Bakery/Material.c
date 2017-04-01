#include "Material.h"
#include "Date.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Material* createMaterial(char* materialName, char* materialSupplier, int materialAmount, Date* expirationDate) {
	Material* m = (Material*)malloc(sizeof(Material));
	
	m->_materialName = (char*)malloc(sizeof(char) * (strlen(materialName) + 1));
	strcpy(m->_materialName, materialName);

	m->_materialSupplier = (char*)malloc(sizeof(char) * (strlen(materialSupplier) + 1));
	strcpy(m->_materialSupplier, materialSupplier);

	m->_materialAmount = materialAmount;

	m->_expirationDate = (Date*)malloc(sizeof(Date));
	m->_expirationDate = expirationDate;

	return m;
}

void destroyMaterial(Material* m) {

	free(m->_expirationDate);
	free(m->_materialName);
	free(m->_materialSupplier);
	free(m);
}

Material* copyMaterial(Material* m) {
	if (m == NULL)
		return NULL;
	Date* _date = m->_expirationDate;
	//printf("%d\n", _date->_day);
	Material* newMaterial = createMaterial(m->_materialName, m->_materialSupplier, m->_materialAmount, _date);
	return newMaterial;
}

char* getMaterialName(Material* m) {
	return m->_materialName;
}

char* getMaterialSupplier(Material* m) {
	return m->_materialSupplier;
}

Date* getExpirationDate(Material* m) {
	return m->_expirationDate;
}

int getMaterialAmount(Material* m) {
	return m->_materialAmount;
}

void toString(Material* m, char str[]) {
	char str2[200];
	toStringDate(m->_expirationDate, str2);
	sprintf(str, "Material %s is provided by %s and the available amount is %d and the expiration date is on %s. \n", m->_materialName, m->_materialSupplier, m->_materialAmount, str2);
}

void testMaterial() {
	char str[400];
	Date* date = createDate(10, 10, 1994);
	Date* date2 = createDate(9, 10, 1994);
	Material* material = createMaterial("pauine", "vhed", 20, date);
	printf("%s \n %d \n", getMaterialName(material), getExpirationDate(material)->_year);
	printf("%d \n", isExpired(getExpirationDate(material), date2));
	toString(material, str);
	printf("%s\n", str);
	system("pause");
}