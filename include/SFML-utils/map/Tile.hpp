#ifndef SFUTILS_MAP_TILE_HPP
#define SFUTILS_MAP_TILE_HPP

#include <SFML/Graphics.hpp>

namespace sfutils
{
    namespace map
    {
        template<typename GEOMETRY>
        class Tile : public sf::Drawable
        {
            public:
                Tile(const Tile&) = delete;
                Tile& operator=(const Tile&) = delete;

                Tile(Tile&&) = default;
                Tile& operator=(Tile&&) = default;

                static sf::Vector2i mapPixelToCoords(int x,int y);
                static sf::Vector2i mapPixelToCoords(const sf::Vector2i& pos);

                static sf::Vector2f mapCoordsToPixel(int x,int y);
                static sf::Vector2f mapCoordsToPixel(const sf::Vector2i& pos);

                Tile(int pos_x,int pos_y);
                
                template< typename ...Args>
                inline void setFillColor(Args&& ... args);

                template< typename ...Args>
                void setPosition(Args&& ... args);

                template< typename ...Args>
                sf::Vector2i getPosition(Args&& ... args);

                void setTexture(const sf::Texture *texture,bool resetRect=false);


            private:
                sf::ConvexShape _shape;

                virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        };
    }
}
#include <SFML-utils/map/Tile.tpl>
#endif
