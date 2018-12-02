#pragma once
//Disabled Warning
#pragma warning (disable : 4251)

// ------------------------- External -----------------------------

//STD Headers
#include <iostream>
#include <stdlib.h>
#include <functional>
#include <sstream>

//Vendor - Spdlog
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h> //console logging
#include <spdlog/fmt/ostr.h>

//-----------------------------------------------------------------

// --------------------------- Internal ----------------------------

//Debug Utility
#include "Polar/MemLeakDetector.h"
#include "Polar/Log.h"

//Event system
#include "Polar/Events/ApplicationEvent.h"
#include "Polar/Events/KeyEvent.h"
#include "Polar/Events/MouseEvent.h"

//-----------------------------------------------------------------