#include "Date.h"
#include <crtdbg.h>
#include "DynamicArray.h"
#include "Material.h"
#include "OperationStack.h"
#include "UserInterface.h"
int main() {
	//testDate();
	//testDynamicArray();
	//testStack();
	testMaterial();
	MaterialRepo* _repo = createRepo();
	OperationStack* _operationStack = createOperationStack();
	Controller* _ctrl = createController(_repo, _operationStack);
	Date* _date = createDate(6,6,6);
	addMaterialController(_ctrl, "jeje", "bubub", 40, _date);
	UI* _ui = createUI(_ctrl);
	startUI(_ui);
	destroyUI(_ui);
	_CrtDumpMemoryLeaks();
	return 0;
}