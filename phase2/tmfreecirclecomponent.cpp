#include "tmfreecirclecomponent.h"
#include<QtMath>
TMFreeCircleComponent::TMFreeCircleComponent()
{

}
void TMFreeCircleComponent::draw(QPainter *painter)
{
    this->pen.setColor(this->color);
    this->pen.setWidth(this->penWidth);
    painter->setPen(pen);
    painter->drawEllipse(QPoint(this->centerPointX,this->centerPointY),this->radius,this->radius);
}
QString TMFreeCircleComponent::ToString()
{
    return QString("Circle");
}
void TMFreeCircleComponent::select(QPainter* painter)
{
    QPen pen;
    pen.setColor(QColor(QString("Blue")));
    pen.setWidth(3);
    painter->setPen(pen);
    int centerX=this->centerPointX;
    int centerY=this->centerPointY;
    int radius=this->radius;
    painter->drawRect(centerX-5,centerY+radius-5,10,10);
    painter->drawRect(centerX-5,centerY-radius-5,10,10);
    painter->drawRect(centerX+radius-5,centerY-5,10,10);
    painter->drawRect(centerX-radius-5,centerY-5,10,10);
}
bool TMFreeCircleComponent::isOwnedByYou(int x,int y)
{
    int value;
    value=(this->radius)-qSqrt(qPow((x-this->centerPointX),2)+(qPow((y-this->centerPointY),2)));
    if((value<7 && value>=0 )|| (value>-7 && value<=0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int TMFreeCircleComponent::areYouBeingResized(int x,int y)
{
    if(((this->centerPointX-5<x) && (x<this->centerPointX+5)) && ((this->centerPointY-this->radius-5<y) && (y< this->centerPointY-radius+5))) return 1;
    else if(((this->centerPointX+this->radius-5<x) && (x<this->centerPointX+radius+5)) && ((this->centerPointY-5<y) && (y<this->centerPointY+5))) return 2;
    else if(((this->centerPointX-5<x) && (x<this->centerPointX+5)) && ((this->centerPointY+this->radius-5<y) && (y< this->centerPointY+radius+5))) return 3;
    else if(((this->centerPointX-this->radius-5<x) && (x<this->centerPointX-radius+5)) && ((this->centerPointY-5<y) && (y<this->centerPointY+5))) return 4;
    else return 0;
}
void TMFreeCircleComponent::setCenterPointX(int centerPointX)
{
    this->centerPointX=centerPointX;
}
int TMFreeCircleComponent::getCenterPointX()
{
    return centerPointX;
}
void TMFreeCircleComponent::setCenterPointY(int centerPointY)
{
    this->centerPointY=centerPointY;
}
int TMFreeCircleComponent::getCenterPointY()
{
    return centerPointY;
}
void TMFreeCircleComponent::setRadius(int radius)
{
    this->radius=radius;
}
int TMFreeCircleComponent::getRadius()
{
    return radius;
}
void TMFreeCircleComponent::setColor(QString color)
{
    this->color=color;
}
QString TMFreeCircleComponent::getColor()
{
    return this->color;
}
void TMFreeCircleComponent::setPenWidth(int penWidth)
{
    this->penWidth=penWidth;
}
int TMFreeCircleComponent::getPenWidth()
{
    return this->penWidth;
}
