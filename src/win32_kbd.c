#include <stdio.h>
#include "win32_kbd.h"

static int __noEvent = 0;

void GenerateEvent()
{
	if (GetAsyncKeyState(RELEASE_KEY))
		__noEvent = 1;
	else
		__noEvent = 0;

	if (__noEvent) {
		YieldProcessor();
		return;
	}
	
	INPUT inputs[2];
	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = VK_SPACE;
	inputs[0].ki.wScan = MapVirtualKeyEx(VK_SPACE, MAPVK_VK_TO_VSC, GetKeyboardLayout(0));
	inputs[0].ki.dwFlags = 0;

	inputs[1] = inputs[0];
	inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;
	
	SHORT ret = GetAsyncKeyState(VK_SPACE);
	if ((unsigned)ret == 0) {
		SendInput(1, &inputs[0], sizeof(INPUT));
		Sleep(5);
		SendInput(1, &inputs[1], sizeof(INPUT));
		Sleep(5);
	} else  {
		YieldProcessor();
	}
}

int KillEvent()
{
	if (GetAsyncKeyState(KILL_KEY))
		return 1;

	return 0;
}
