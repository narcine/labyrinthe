#include "objectfactory.h"

Object* ObjectFactory::createObject(Object::Type type)
{
    using Type = Object::Type;
    Object * obj = nullptr;
    switch(type)
    {
        case Type::WALL:
            obj = new Wall();
        break;
        case Type::GROUND:
            obj = new Ground();
        break;
        default:
        break;

    }
    return obj;
}
