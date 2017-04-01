#include "OperationStack.h"
#include<string.h>
#include<stdlib.h>
#include<assert.h>

Operation* createOperation(Material* material, char* operationType) {
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->_material = copyMaterial(material);

	if (operationType != NULL)
	{
		o->_operationType = (char*)malloc(sizeof(char) * (strlen(operationType) + 1));
		strcpy(o->_operationType, operationType);
	}
	else
		o->_operationType = NULL;

	return o;
}

Operation* copyOperation(Operation* o) {
	if (o == NULL) {
		return NULL;
	}
	Operation* newOp = createOperation(o->_material, o->_operationType);
	return newOp;
}

void destroyOperation(Operation* o) {
	if (o == NULL) {
		return;
	}
	free(o->_material);
	free(o->_operationType);
	free(o);
}

char* getOperationType(Operation* o){
	return o->_operationType;
}

Material* getMaterial(Operation* o) {
	return o->_material;
}




OperationStack* createOperationStack() {
	OperationStack* operationStack = (OperationStack*)malloc(sizeof(OperationStack));
	operationStack->_length = 0;
	return operationStack;

}

void destroyOperationStack(OperationStack* s) {
	if (s == NULL) {
		return;
	}
	for (int i = 0; i < s->_length; i++) {
		destroyOperation(s->_operations[i]);
	}

	free(s);
}

void push(OperationStack* s, Operation* o) {
	if (isFull(s)) {
		return;
	}
	s->_operations[s->_length++] = copyOperation(o);
}

Operation* pop(OperationStack* s) {
	if (isEmpty(s)) {
		return NULL;
	}
	s->_length--;
	return s->_operations[s->_length];
}

int isEmpty(OperationStack* s) {
	return (s->_length == 0);
}

int isFull(OperationStack* o) {
	return o->_length == 100;
}


void testStack() {
	OperationStack* s = createOperationStack();

	Date* _date1 = createDate(10, 12, 1994);
	Date* _date2 = createDate(12, 12, 1241);
	Material* _material1 = createMaterial("vds", "vsfd", 20, _date1);
	Material* _material2 = createMaterial("vdccs", "dvdwvs", 40, _date2);
	Operation* o1 = createOperation(_material1, "add");
	Operation* o2 = createOperation(_material2, "add");
	Operation* o3 = createOperation(_material1, "remove");

	
	
	destroyMaterial(_material2);
	destroyMaterial(_material1);
	printf("merghr");
	system("pause");
	push(s, o1);
	push(s, o2);
	push(s, o3);
	
	
	destroyOperation(o1);
	destroyOperation(o2);
	destroyOperation(o3);
	printf("merghr");
	system("pause");
	
	assert(isFull(&s) == 0);
	assert(isEmpty(&s) == 1);

}