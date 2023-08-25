#include <fstream>
#include "ManageSystem.h"

int main() {
	if (ifstream("file1.txt")) {
		Load();
	}

	while (MainMenu()) {}

	return 0;
}
