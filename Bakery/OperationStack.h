#pragma once
#include "Material.h"
#include "Date.h"
#include "DynamicArray.h"
#include <string.h>


typedef struct {
	Material* _material;
	char* _operationType;
}Operation;

Operation* createOperation(Material* material, char* operationType);
void destroyOperation(Operation* operation);
Operation* copyOperation(Operation* operation);
char* getOperationType(Operation* operation);
Material* getMaterial(Operation* operation);;


typedef struct {
	Operation* _operations[100];
	int _length;
}OperationStack;

OperationStack* createOperationStack();
void destroyOperationStack(OperationStack* s);
void push(OperationStack* s, Operation* o);
Operation* pop(OperationStack* s);
int isEmpty(OperationStack* s);
int isFull(OperationStack* s);

void testStack();
