#include <SFML-utils/map/VLayer.hpp>

namespace sfutils
{
    namespace map
    {
        VLayer::VLayer(const std::string& type,int z,bool isStatic) :
            _isStatic(isStatic),
            _type(type),
            _visibility(true),
            _z(z)
        {
        }

        VLayer::~VLayer()
        {
        }

        int VLayer::getZ()const
        {
            return _z;
        }

        void VLayer::setZ(int z)
        {
            _z = z;
        }

        const std::string& VLayer::getType()const
        {
            return _type;
        }

        bool VLayer::isStatic()const
        {
            return _isStatic;
        }

        bool VLayer::isVisible() const
        {
            return _visibility;
        }

        void VLayer::setVisible(bool visibility)
        {
            _visibility = visibility;
        }


    }
}
