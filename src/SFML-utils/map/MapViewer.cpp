#include <SFML-utils/map/MapViewer.hpp>

#include <SFML-utils/map/VMap.hpp>

#include <iostream>

namespace sfutils
{
    namespace map
    {        
        MapViewer::MapViewer(const VMap& map,const ActionMap<int>& action_map) : ActionTarget(action_map),_map(map), _move_x(0), _move_y(0), _movement_speed(10)
        {
            bind(Action(sf::Event::MouseWheelMoved),[this](const sf::Event& event){
                     zoom(1-(event.mouseWheel.delta/5.0));
                 });

            bind(Configuration::MapInputs::MoveUp,[this](const sf::Event& event){
                    _move_y -=1;
                 });

            bind(Configuration::MapInputs::MoveDown,[this](const sf::Event& event){
                    _move_y +=1;
                 });

            bind(Configuration::MapInputs::MoveLeft,[this](const sf::Event& event){
                    _move_x -=1;
                 });

            bind(Configuration::MapInputs::MoveRight,[this](const sf::Event& event){
                    _move_x +=1;
                 });
        }

        void MapViewer::move(float offsetX, float offsetY)
        {
            _view.move(offsetX,offsetY);
        }

        void MapViewer::move(const sf::Vector2f& offset)
        {
            _view.move(offset);
        }

        void MapViewer::setPosition(float posX, float posY)
        {
            _view.setCenter(posX,posY);
        }

        void MapViewer::setPosition(const sf::Vector2f& pos)
        {
            _view.setCenter(pos);
        }

        void MapViewer::zoom(float factor)
        {
            _view.zoom(factor);
        }

        void MapViewer::setSize(float width,float height)
        {
            _view.setSize(width,height);
        }

        void MapViewer::setSize(const sf::Vector2f& size)
        {
            _view.setSize(size);
        }

        void MapViewer::update(float deltaTime)
        {
            if(_move_x or _move_y)
            {
                float delta = _map.tile_size*_movement_speed * deltaTime;
                move(_move_x * delta,_move_y * delta);
            }
            _move_x = _move_y = 0;

        }
        void MapViewer::setSpeed(float speed)
        {
            _movement_speed = speed;
        }

        void MapViewer::draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            sf::View view = target.getView();
            target.setView(_view);

            _map.draw(target,states,sf::FloatRect(target.mapPixelToCoords(sf::Vector2i(0,0),_view),
                                                  _view.getSize()));
            target.setView(view);
        }
    }
}
