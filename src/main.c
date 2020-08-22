#ifdef _WIN32
#include "win32_kbd.h"
#else
#error Unsupported window system
#endif

int main()
{
	while (!KillEvent())
		GenerateEvent();
}
