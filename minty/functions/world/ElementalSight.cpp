﻿#include "ElementalSight.h"

namespace cheat {
    static void LevelSceneElementViewPlugin_Tick_Hook(app::LevelSceneElementViewPlugin* __this, float inDeltaTime);

    ElementalSight::ElementalSight() : Function() {
        f_Enabled = config::getValue("functions:ElementalSight", "enabled", false);
        f_Hotkey = Hotkey("functions:ElementalSight");
        
        HookManager::install(app::MoleMole_LevelSceneElementViewPlugin_Tick, LevelSceneElementViewPlugin_Tick_Hook);
    }

    ElementalSight& ElementalSight::getInstance() {
        static ElementalSight instance;
        return instance;
    }

    void ElementalSight::GUI() {
        ConfigCheckbox(_("Permanent Elemental Sight"), f_Enabled, _("Elemental sight is kept on even when moving.\n"
                     "To turn off, toggle off and use Elemental Sight again."));

        if (f_Enabled.getValue()) {
            ImGui::Indent();
            f_Hotkey.Draw();
            ImGui::Unindent();
        }
    }

    void ElementalSight::Outer() {
        if (f_Hotkey.IsPressed())
            f_Enabled.setValue(!f_Enabled.getValue());
    }

    void ElementalSight::Status() {
        if (f_Enabled.getValue())
            ImGui::Text("Elemental Sight");
    }

    std::string ElementalSight::getModule() {
        return _("World");
    }

    void LevelSceneElementViewPlugin_Tick_Hook(app::LevelSceneElementViewPlugin* __this, float inDeltaTime) {
        auto& elementalSight = ElementalSight::getInstance();

        if (elementalSight.f_Enabled.getValue())
            app::MoleMole_LevelSceneElementViewPlugin_TriggerElementView(__this, true);
        CALL_ORIGIN(LevelSceneElementViewPlugin_Tick_Hook, __this, inDeltaTime);
    }
}
