#ifndef _WINAPP_
#define _WINAPP_

#include "Application.h"
#include "windows.h"

class WinApp : public Application {

	public:
		void Start(Game);
};
#endif //_WINAPP_