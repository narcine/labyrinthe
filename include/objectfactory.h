#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "object.h"

class ObjectFactory
{
public:
    ObjectFactory() = delete;
    static Object* createObject(Object::Type type);
};

#endif // OBJECTFACTORY_H
