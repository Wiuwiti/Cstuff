#include "UserInterface.h"
#include <stdio.h>
#include <stdlib.h>

UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->_ctrl = c;

	return ui;
}

void destroyUI(UI * ui) {
	destroyController(ui->_ctrl);
	free(ui);
}

void printMenu() {
	printf("\n--------------------------------------------\n 1 - Add a material. \n 2 - TO DO \n");
	printf("--------------------------------------------\n");
}

int validComand(int command) {
	if (command >= 0 && command <= 4) {
		return 1;
	}return 0;
}

int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

void readStringWithSpaces(const char* message, int maxStrSize, char str[])
{
	printf(message);
	fgets(str, maxStrSize, stdin);
	// the newline is also read so we must eliminate it from the string
	int size = strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
}

int AddMaterialUI(UI* ui) {
	char _name[40],
		_supplier[40],
		str[200];
	int _amount,_day,_month,_year;
	Date* _date;
	fgetc(stdin);
	readStringWithSpaces("Name of material: ", 50, _name);
	readStringWithSpaces("Name of supplier: ", 50, _supplier);
	printf("The amount of material: "); scanf("%d", &_amount); fgetc(stdin);
	printf("\nExpiration day: "); scanf("%d", &_day); fgetc(stdin);
	printf("\nExpiration month: "); scanf("%d", &_month); fgetc(stdin);
	printf("\nExpiration year: "); scanf("%d", &_year); fgetc(stdin);
	_date = createDate(_day, _month, _year);
	toString(createMaterial(_name, _supplier, _amount, _date), str);
	//printf("%s\n", str);
	return addMaterialController(ui->_ctrl, _name, _supplier, _amount, _date);
	//printf("%s\n", str);
}

void listAllMaterials(UI* ui) {
	MaterialRepo* repo = getRepo(ui->_ctrl);
	//printf("d");
	int lenght = getRepoLength(repo);
	//printf("da");
	if (lenght == 0) {
		char* str = "There are no stored Materials";
		printf("%s \n", str);
	}
	for (int i = 0; i < getRepoLength(repo); i++) {
		char str[200];
		Material* _mat = getMaterialOnPosition(repo, i);
		toString(_mat, str);
		printf("%s", str);
	}
}


void startUI(UI* ui) {
	while (1) {
		printMenu();
		int command = readIntegerNumber("Input command:");
		while (validComand(command) == 0) {
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0) {
			break;
		}
		switch (command) {
		case 1:
		{
			int res = AddMaterialUI(ui);
			if (res == 1) {
				printf("Material succesfully added!");
			}
			else {
				printf("Error! Material could not be added!");
			}
			break;
		}case 2: {
			listAllMaterials(ui);
			break;
		}
		}
	}
}