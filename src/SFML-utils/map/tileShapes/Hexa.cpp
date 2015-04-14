#include <SFML-utils/map/tileShapes/Hexa.hpp>
#include <cmath>

namespace sfutils
{
    namespace geometry
    {
        sf::ConvexShape Hexa::_shape;
        Hexa::__Initiatiser Hexa::__initiatiser__;

        const float sqrt_3_2 = sqrt(3)/2.0;

        const float width = sqrt_3_2;
        const float delta_x = width;
        const float delta_y = 3.0/4.0;

        const sf::ConvexShape& Hexa::getShape()
        {
            return _shape;
        }

        sf::Vector2f Hexa::mapCoordsToPixel(int X,int Y,float scale)
        {
            return sf::Vector2f((Y*delta_x + X*delta_y)*scale,
                                (Y*delta_y + X*delta_x)*scale);
        }

        sf::Vector2i Hexa::mapPixelToCoords(float X,float Y,float scale)
        {
            const float d_x = delta_x * scale;
            const float d_y = delta_y * scale;

            const float y = (-X*d_x + 2*Y*d_y)/(d_y*d_y - d_x*d_x);
            const float x = -(y*d_x - X)/d_y;

            return Hexa::round(x,y);
        }

        sf::Vector2i Hexa::round(float x, float y)
        {
            const float z = -y-x;

            float rx = std::round(x);
            float ry = std::round(y);
            float rz = std::round(z);

            const float diff_x = std::abs(rx - x);
            const float diff_y = std::abs(ry - y);
            const float diff_z = std::abs(rz - z);

            if(diff_x > diff_y and diff_x > diff_z)
                rx = -ry-rz;
            else if (diff_y > diff_z)
                ry = -rx-rz;

            return sf::Vector2i(rx,ry);
        }

        sf::IntRect Hexa::getTextureRect(int x,int y,float scale)
        {
            sf::Vector2f pos = mapCoordsToPixel(x,y,scale);
            sf::IntRect res(pos.x,
                          pos.y,
                          width * scale,
                          scale);
            return res;
        }

        int Hexa::distance(int x1,int y1, int x2,int y2)
        {
                return (std::abs(x1 - x2)
                    + std::abs(y1 - y2)
                    + std::abs((-x1 - y1) - (-x2 - y2))) / 2;
          }

        void Hexa::init()
        {
            _shape.setPointCount(6);
            _shape.setPoint(0,sf::Vector2f(width/2,0));
            _shape.setPoint(1,sf::Vector2f(width,0.25));
            _shape.setPoint(2,sf::Vector2f(width,0.75));
            _shape.setPoint(3,sf::Vector2f(width/2,1));
            _shape.setPoint(4,sf::Vector2f(0,0.75));
            _shape.setPoint(5,sf::Vector2f(0,0.25));
            
            _shape.setOrigin(width/2,0.5);
        }
        
    }
}
