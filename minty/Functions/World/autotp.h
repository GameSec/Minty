#pragma once

#include "../FunctionIncludes.h"

namespace cheat {
	class AutoTP : public Function {
	public:
		struct TP {
			std::string name;
			std::string description;
			app::Vector3 position;
		};

		ConfigField<bool> f_Enabled;

		Hotkey f_TeleportBackHotkey;
		Hotkey f_TeleportForwardHotkey;
		Hotkey f_TeleportAutoHotkey;

		inline static bool ifAutomatic = false;
		inline static bool ifManual = false;
		inline static float timerWait = 0.0f;
		inline static bool b_startTeleporting = false;
		inline static TP currentPoint = {};
		inline static char folderPathBuffer[1024] = "";
		static std::vector<TP> parseds;
		inline static int currentPointIndex = 0;

		void GUI() override;
		void Outer() override;
		void Status() override;

		std::string getModule() override;

		static AutoTP& getInstance();

		AutoTP();
	};
}
