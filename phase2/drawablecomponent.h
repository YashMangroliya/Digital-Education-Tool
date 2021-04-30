#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H
#include<QPainter>

class DrawableComponent
{
public:
    virtual QString ToString()=0;
    virtual void select(QPainter *painter)=0;
    virtual bool isOwnedByYou(int x,int y)=0;
    virtual void draw(QPainter *painter)=0;
    virtual int areYouBeingResized(int x,int y)=0;
};

#endif // DRAWABLECOMPONENT_H
