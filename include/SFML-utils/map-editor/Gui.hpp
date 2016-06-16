#ifndef SFUTILS_EDITOR_GUI_HPP
#define SFUTILS_EDITOR_GUI_HPP

#include <SFML/Graphics.hpp>
#include <SFML-utils/map/Models.hpp>

namespace CEGUI
{
    class OpenGLRenderer;
    class System;
    class Window;
    class Listbox;
    class ListboxItem;
    class ListboxTextItem;
    class GUIContext;
}

namespace sfutils
{
    namespace editor
    {
        class Editor;
        class Gui
        {
            public:
                Gui(const Gui&) = delete;
                Gui& operator=(const Gui&) = delete;

                Gui(sf::RenderWindow& mainWindow,Editor& owner);
                ~Gui();

                bool processEvent(const sf::Event& event);
                void update(const sf::Time& deltaTime);
                void render();

                void setMainInfo(const std::string& text);
                void setTitle(const std::string& text);

                void addLayer(sfutils::map::LayerModel::pointer& layer,bool begin=false);
                void delLayer(sfutils::map::LayerModel::pointer& layer);

                void addTexture(const std::string& tex);
                void delTexture(const std::string& tex);

                int getCurrentLayerZIndex() const;

                void reset();

            private:
                Editor& _owner;
                sf::RenderWindow& _window;
                CEGUI::Window* _root;
                CEGUI::Window* _newLayer;
                CEGUI::GUIContext* _context;

                CEGUI::Listbox* _layerList;
                void _clearLayerList();
                void _setLayerListItemNames();

                CEGUI::Listbox* _textureList;
                void _clearTextureList();

                static CEGUI::ListboxTextItem* _helperCreateTextItem(const std::string& txt, void* userData = nullptr);

                /*menu*/
                void _registerMenuBarCallbacks();
                ////file
                bool _event_menuBar_file_new();
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
                bool _event_leftPanel_texture_selected();
                ////Tab
                bool _event_leftPanel_tab_changed(const std::string& name);
                //////NPC
                bool _event_leftPanel_tab_NPC_selected(CEGUI::Listbox* box);
                bool _event_leftPanel_tab_NPC_add();
                bool _event_leftPanel_tab_NPC_remove();
                //////creatures
                bool _event_leftPanel_tab_creature_selected(CEGUI::Listbox* box);
                bool _event_leftPanel_tab_creature_add();
                bool _event_leftPanel_tab_creature_remove();
                //////buldings
                bool _event_leftPanel_tab_bulding_selected(CEGUI::Listbox* box);
                bool _event_leftPanel_tab_bulding_add();
                bool _event_leftPanel_tab_bulding_remove();


                /*top*/

                /*miniMap*/
                void _registerMiniMapCallbacks();
                bool _event_miniMap_zoom(float value);

                /*Right panel*/
                void _registerRightPanelCallbacks();
                ////Layers
                //bool _event_rightPanel_layer_selected();
                bool _event_rightPanel_layers_add();
                bool _event_rightPanel_layers_up();
                bool _event_rightPanel_layers_down();
                bool _event_rightPanel_layers_check();
                bool _event_rightPanel_layers_remove();
                ////tab
                bool _event_rightPanel_tab_changed(const std::string& name);
                //////Brush
                bool _event_rightPanel_tab_brush_selected(CEGUI::Listbox* box);
                //////NPC
                bool _event_rightPanel_tab_NPC_selected(CEGUI::Listbox* box);


                /* New Layer Popup */
                void _showNewLayerPopup();
                ///events
                bool _event_newLayer_ok(CEGUI::Window* newLayerWindow);

        };
    }
}
#endif
