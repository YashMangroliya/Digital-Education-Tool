#include "tmfreehandcomponent.h"

TMFreeHandComponent::TMFreeHandComponent()
{

}
void TMFreeHandComponent::draw(QPainter *painter)
{
    this->pen.setColor(this->color);
    this->pen.setWidth(this->penWidth);
    painter->setPen(pen);
    painter->drawLine(oldX,oldY,currentX,currentY);
}
QString TMFreeHandComponent::ToString()
{
    return QString("Free Hand");
}
void TMFreeHandComponent::select(QPainter *painter)
{

}
bool TMFreeHandComponent::isOwnedByYou(int x,int y)
{
    return false;
}
int TMFreeHandComponent::areYouBeingResized(int x,int y)
{
    return 0;
}
void TMFreeHandComponent::setOldX(int oldX)
{
    this->oldX=oldX;
}
void TMFreeHandComponent::setOldY(int oldY)
{
    this->oldY=oldY;
}
void TMFreeHandComponent::setCurrentX(int currentX)
{
    this->currentX=currentX;
}
void TMFreeHandComponent::setCurrentY(int currentY)
{
    this->currentY=currentY;
}
int TMFreeHandComponent::getCurrentX()
{
    return this->currentX;
}
int TMFreeHandComponent::getCurrentY()
{
    return this->currentY;
}
int TMFreeHandComponent::getOldX()
{
    return oldX;
}
int TMFreeHandComponent::getOldY()
{
    return oldY;
}
void TMFreeHandComponent::setColor(QString color)
{
    this->color=color;
}
QString TMFreeHandComponent::getColor()
{
    return this->color;
}
void TMFreeHandComponent::setPenWidth(int penWidth)
{
    this->penWidth=penWidth;
}
int TMFreeHandComponent::getPenWidth()
{
    return this->penWidth;
}









