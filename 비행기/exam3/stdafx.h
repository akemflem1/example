// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// TODO: reference additional headers your program requires here
#include "../../engine/irrlicht/include/irrlicht.h"
#include "../../engine/plusEngine.h"
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "explosion.h"
#include <time.h>

#define PI 3.14159265358979324
#define MAX_ENEMY 1024
#define MAX_BULLET 1024
#define MAX_EXPLOSION 1024
#define FPS 60.0