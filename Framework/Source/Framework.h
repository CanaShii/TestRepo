#pragma once

// This header includes all files inside the framework project.
// It is meant for use by game projects ONLY.
// As new files are created, include them here so the game has easy access to them.
// It should not be included by any files inside the framework project.

#include "CoreHeaders.h"

#include "../Libraries/imgui/imgui.h"
#include "../Libraries/json/json.hpp"

#include "FWCore.h"
#include "GameCore.h"
#include "Events/FWEventManager.h"
#include "Events/FWEvent.h"
#include "Events/InputEvent.h"
#include "UI/ImGuiManager.h"
#include "Utility/Utility.h"
#include "Mesh/Mesh.h"
#include "Mesh/Texture.h"
#include "Math/vec2.h"
#include "Utility/ShaderProgram.h"

