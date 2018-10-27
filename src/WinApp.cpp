#include "WinApp.h"

void WinApp::Start(Game g) {
	system(g.GetPath());
}