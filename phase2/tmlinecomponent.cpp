#include "tmlinecomponent.h"
#include<drawablecomponent.h>
TMLineComponent::TMLineComponent()
{

}
void TMLineComponent::draw(QPainter *painter)
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(this->lineColor);
    painter->setPen(pen);
    painter->drawLine(this->lineStartPositionXCoordinate,this->lineStartPositionYCoordinate,this->lineEndPositionXCoordinate,this->lineEndPositionYCoordinate);

}
void TMLineComponent::setLineColor(QString lineColor)
{
    this->lineColor=lineColor;
}
QString TMLineComponent::getLineColor()
{
    return this->lineColor;
}
void TMLineComponent::setLineStartPositionXCoordinate(int lineStartPositionXCoordinate)
{
    this->lineStartPositionXCoordinate=lineStartPositionXCoordinate;
}
int TMLineComponent::getLineStartPositionXCoordinate()
{
    return this->lineStartPositionXCoordinate;
}
void TMLineComponent::setLineStartPositionYCoordinate(int lineStartPositionYCoordinate)
{
    this->lineStartPositionYCoordinate=lineStartPositionYCoordinate;
}
int TMLineComponent::getLineStartPositionYCoordinate()
{
    return this->lineStartPositionYCoordinate;
}
void TMLineComponent::setLineEndPositionXCoordinate(int lineEndPositionXCoordinate)
{
    this->lineEndPositionXCoordinate=lineEndPositionXCoordinate;
}
int TMLineComponent::getLineEndPositionXCoordinate()
{
    return this->lineEndPositionXCoordinate;
}
void TMLineComponent::setLineEndPositionYCoordinate(int lineEndPositionYCoordinate)
{
    this->lineEndPositionYCoordinate=lineEndPositionYCoordinate;
}
int TMLineComponent::getLineEndPositionYCoordinate()
{
    return this->lineEndPositionYCoordinate;
}

