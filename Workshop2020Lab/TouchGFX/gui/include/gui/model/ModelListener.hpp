#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }
    
    virtual void newJunctionTempValue(int value) {}
    virtual void userButtonPressed() {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
