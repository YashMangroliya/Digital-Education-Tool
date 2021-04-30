#include "tmfreerectanglecomponent.h"

TMFreeRectangleComponent::TMFreeRectangleComponent()
{
    this->color=QString("Black");
    this->penWidth=3;
}
void TMFreeRectangleComponent::draw(QPainter *painter)
{
    this->pen.setColor(this->color);
    this->pen.setWidth(this->penWidth);
    painter->setPen(pen);
    QRect rect(QPoint(this->startX,this->startY),QPoint(this->endX,this->endY));
    painter->drawRect(rect);
}
QString TMFreeRectangleComponent::ToString()
{
    return QString("Rectangle");
}
void TMFreeRectangleComponent::select(QPainter *painter)
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(QString("Blue")));
    painter->setPen(pen);
    painter->drawRect(this->startX-5,this->startY-5,10,10);
    painter->drawRect(this->endX-5,this->startY-5,10,10);
    painter->drawRect(this->startX-5,this->endY-5,10,10);
    painter->drawRect(this->endX-5,this->endY-5,10,10);

}
bool TMFreeRectangleComponent::isOwnedByYou(int x,int y)
{
    if((y<this->startY+3 && y>this->startY-3) && ((x>this->startX && x<this->endX) || (x<this->startX && x>this->endX))) return true;
    if((x<this->startX+3 && x>this->startX-3) && ((y>this->startY && y<this->endY) || (y<this->startY && y>this->endY))) return true;
    if((y<this->endY+3 && y>this->endY-3) && ((x>this->startX && x<this->endX) || ((x<this->startX && x>this->endX)))) return true;
    if((x<this->endX+3 && x>this->endX-3) && ((y>this->startY && y<this->endY) || (y<this->startY && y>this->endY))) return true;
    return false;
}
int TMFreeRectangleComponent::areYouBeingResized(int x,int y)
{
    if((((this->startX-5)<x) && (x<(this->startX+5))) && (((this->startY-5)<y) &&(y<(this->startY+5)))) return 1;
    else if(((this->endX-5<x) && (x<this->endX+5)) && ((this->startY-5<y) && (y<this->startY+5))) return 2;
    else if(((this->startX-5<x) && (x<this->startX+5)) && ((this->endY-5<y) && (y<this->endY+5))) return 3;
    else if(((this->endX-5<x) && (x<this->endX+5)) && ((this->endY-5<y) && (y<this->endY+5))) return 4;
    else return 0;
}
void TMFreeRectangleComponent::setStartX(int startX)
{
    this->startX=startX;
}
int TMFreeRectangleComponent::getStartX()
{
    return this->startX;
}
void TMFreeRectangleComponent::setStartY(int startY)
{
    this->startY=startY;
}
int TMFreeRectangleComponent::getStartY()
{
    return this->startY;
}
void TMFreeRectangleComponent::setEndX(int endX)
{
    this->endX=endX;
}
int TMFreeRectangleComponent::getEndX()
{
    return this->endX;
}
void TMFreeRectangleComponent::setEndY(int endY)
{
    this->endY=endY;
}
int TMFreeRectangleComponent::getEndY()
{
    return this->endY;
}
void TMFreeRectangleComponent::setColor(QString color)
{
    this->color=color;
}
QString TMFreeRectangleComponent::getColor()
{
    return this->color;
}
void TMFreeRectangleComponent::setPenWidth(int penWidth)
{
    this->penWidth=penWidth;
}
int TMFreeRectangleComponent::getPenWidth()
{
    return this->penWidth;
}
