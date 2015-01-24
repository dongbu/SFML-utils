#ifndef SFUTILS_MAP_MAPVIEWER_HPP
#define SFUTILS_MAP_MAPVIEWER_HPP

#include <SFML/Graphics.hpp>

#include <SFML-utils/core/ActionTarget.hpp>

namespace sfutils
{
    namespace map
    {
        class VMap;
        class MapViewer : public sf::Drawable, protected ActionTarget<int>
        {
            public:
                MapViewer(const MapViewer&) = delete;
                MapViewer& operator=(const MapViewer&) = delete;

                MapViewer(sf::RenderWindow& window,const VMap& map);
                MapViewer(sf::RenderWindow& window,const VMap& map,const ActionMap<int>& action_map);
                
                using ActionTarget::bind;
                using ActionTarget::unbind;
                using ActionTarget::processEvent;
                using ActionTarget::processEvents;

                void move(float offsetX, float offsetY);
                void move(const sf::Vector2f& offset);

                void setPosition(float posX, float posY);
                void setPosition(const sf::Vector2f& pos);

                void zoom(float factor);

                void setSize(float width,float height);
                void setSize(const sf::Vector2f& size);

                void update(float deltaTime);

                void setSpeed(float speed);

                void draw(sf::RenderStates states = sf::RenderStates::Default) const;

                sf::Vector2i mapPixelToCoords(float x,float y)const;
                sf::Vector2i mapPixelToCoords(const sf::Vector2f& pos)const;

                sf::Vector2f mapCoordsToPixel(int x,int y) const;
                sf::Vector2f mapCoordsToPixel(const sf::Vector2i& pos) const;


            private:
                const VMap& _map;
                sf::View _view;
                sf::Vector2i _mouse_pos;
                
                int _move_x, _move_y;
                float _movement_speed;
                sf::RenderWindow& _window;

                virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        };
    }
}
#endif
