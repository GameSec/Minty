#pragma once

#include "../FunctionIncludes.h"

namespace cheat {
	class MultiHit : public Function {
	public:
		ConfigField<bool> f_Enabled;
		ConfigField<int> f_Hits;

		Hotkey f_Hotkey;

		void GUI() override;
		void Outer() override;
		void Status() override;

		std::string getModule() override;

		static MultiHit& getInstance();

		MultiHit();
	};
}
