#include "Controller.h"
#include <stdlib.h>
#include <string.h>


Controller* createController(MaterialRepo* r, OperationStack* undoS){
	Controller* c = (Controller*)malloc(sizeof(Controller));

	c->repo = r;
	c->undoStack = undoS;
	return c;

}

void destroyController(Controller* c) {
	destroyRepo(c->repo);

	destroyOperationStack(c->undoStack);
	free(c);
}

int addMaterialController(Controller* c, char* name, char* supplier, int amount, Date * expirationDate) {
	
	
	Material* _material = createMaterial(name, supplier, amount, expirationDate);
	char str[200];
	//toString(_material, str);
	//printf("%s\n\n", str );
	int res = addMaterial(c->repo, _material);
	if (res == 1) {
		Operation* _operation = createOperation(_material, "add");
		push(c->undoStack, _operation);
		destroy(_operation);
	}
	destroyMaterial(_material);
	return res;
}

MaterialRepo* getRepo(Controller* c) {
	return c->repo;
}

MaterialRepo* filterByExpirationDate(Controller* c, Date* expirationDate, char materialName[]) {
	MaterialRepo* res = createRepo();
	if (expirationDate==NULL)
	{
		return NULL;
	}
	if (strcmp(materialName, NULL) == 0) {
		for (int i = 0; i < getRepoLength(c->repo); i++) {
			Material* m = getMaterialOnPosition(c->repo, i);
			if (isExpired(m->_expirationDate, expirationDate) == 1) {
				add(res, m);
			}
		}
	}
	else {
		return NULL;
	}
	return res;
}