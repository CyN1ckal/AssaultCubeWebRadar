// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"
#include <iostream>
#include <thread>
#include <vector>

#include "HTTPRequest.hpp"

#include "Vector3.h"
#include "Config.h"
#include "MainLoop.h"
#include "Console.h"
#include "KeybindLoop.h"
#include "HTTPRequests.h"

#include "Reclass.h"
#include "Offsets.h"

#include "InfiniteHealth.h"
#include "PrintPlayerCoords.h"
#include "StartingThread.h"
#include "PrintPlayerlist.h"
#

#include "TestingOutput.h"

#include <curl/curl.h>
#include "NetworkingLoop.h"
#endif //PCH_H
