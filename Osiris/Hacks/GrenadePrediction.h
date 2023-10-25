#pragma once

#include "../imgui/imgui.h"

#include "../SDK/EngineTrace.h"
#include "../SDK/UserCmd.h"
#include "../SDK/Vector.h"

#include <array>

namespace nadePrediction {
	void run(UserCmd* cmd) noexcept;
	void draw() noexcept;
};