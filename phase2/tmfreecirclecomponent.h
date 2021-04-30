#ifndef TMCIRCLECOMPONENT_H
#define TMCIRCLECOMPONENT_H
#include<drawablecomponent.h>

class TMFreeCircleComponent:public DrawableComponent
{
public:
    TMFreeCircleComponent();
    virtual void draw(QPainter *painter);
    QString ToString();
    void select(QPainter* painter);
    bool isOwnedByYou(int x,int y);
    int areYouBeingResized(int x,int y);
    void setCenterPointX(int x);
    int getCenterPointX();
    void setCenterPointY(int y);
    int getCenterPointY();
    void setRadius(int radius);
    int getRadius();
    void setColor(QString color);
    QString getColor();
    void setPenWidth(int penWidth);
    int getPenWidth();
private:
    int centerPointX;
    int centerPointY;
    int currentPointX;
    int currentPointY;
    int radius;
    QString color;
    int penWidth;
    QPen pen;
};

#endif // TMCIRCLECOMPONENT_H
