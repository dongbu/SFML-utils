#ifndef SFUTILS_EDITOR_GUI_HPP
#define SFUTILS_EDITOR_GUI_HPP

#include <SFML/Graphics.hpp>

namespace CEGUI
{
    class OpenGLRenderer;
    class System;
    class Window;
    class Listbox;
}

namespace sfutils
{
    namespace editor
    {
        class Gui
        {
            public:
                Gui(const Gui&) = delete;
                Gui& operator=(const Gui&) = delete;

                Gui(const sf::Vector2u& size);

                bool processEvent(const sf::Event& event);
                void update(const sf::Time& deltaTime);
                void render(sf::RenderTarget& target);

                void setMainInfo(const std::string& text);

            private:
                CEGUI::Window* _root;

                /*menu*/
                void _registerMenuBarCallbacks();
                ////file
                bool _event_menuBar_file_open();
                bool _event_menuBar_file_save();
                ////edit
                bool _event_menuBar_edit_undo();
                bool _event_menuBar_edit_redo();
                ////map
                bool _event_menuBar_map_resize();
                bool _event_menuBar_map_shape();
                bool _event_menuBar_map_position();

                /*left panel*/
                void _registerLeftPanelCallbacks();
                ////texture
                bool _event_leftPanel_texture_selected(CEGUI::Listbox* box);
                ////Tab
                bool _event_leftPanel_tab_changed(const std::string& name);
                //////NPC
                bool _event_leftPanel_tab_NPC_add();
                bool _event_leftPanel_tab_NPC_remove();
                bool _event_leftPanel_tab_NPC_selected();
                //////creatures
                bool _event_leftPanel_tab_creature_add();
                bool _event_leftPanel_tab_creature_remove();
                bool _event_leftPanel_tab_creature_selected();
                //////buldings
                bool _event_leftPanel_tab_bulding_add();
                bool _event_leftPanel_tab_bulding_remove();
                bool _event_leftPanel_tab_bulding_selected();

                /*miniMap*/
                void _registerMiniMapCallbacks();
                bool _event_miniMap_zoom(float value);

                /*Right panel*/
                void _registerRightPanelCallbacks();
                ////Layers
                bool _event_rightPanel_layers_add();
                bool _event_rightPanel_layers_up();
                bool _event_rightPanel_layers_down();
                bool _event_rightPanel_layers_remove();
                ////tab
                bool _event_rightPanel_tab_changed();
                //////Brush
                bool _event_rightPanel_tab_brush_selected();
                //////NPC
                bool _event_rightPanel_tab_NPC_selected();

        };
    }
}
#endif
