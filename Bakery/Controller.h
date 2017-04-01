#pragma once
#include "MaterialRepository.h"
#include "Date.h"
#include "OperationStack.h"

typedef struct {
	MaterialRepo* repo;
	OperationStack* undoStack;
}Controller;

Controller* createController(MaterialRepo* v, OperationStack* undeS);
void destroyController(Controller* c);


int addMaterialController(Controller* c, char* name, char* supplier, int amount, char* expirationDate);

MaterialRepo* getRepo(Controller* c);

//toDo
MaterialRepo* filterByExpirationDate(Controller* c, Date* expirationDate, char materialName[]);

int undo(Controller* c);