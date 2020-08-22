#ifndef WIN32_KBD_H
#define WIN32_KBD_H

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>

// Config

#define RELEASE_KEY VK_LMENU
#define KILL_KEY VK_RMENU

void GenerateEvent();
int KillEvent();

#endif
