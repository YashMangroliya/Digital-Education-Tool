#include "tmrectanglecomponent.h"

TMRectangleComponent::TMRectangleComponent()
{

}

void TMRectangleComponent::draw(QPainter* painter)
{
    QPen pen;
    pen.setColor(QColor(this->rectangleColor));
    painter->setPen(pen);
    if(this->rectangleFillColorCheckBox)
    {
        QBrush brush(QColor(this->rectangleFillColor));
        painter->setBrush(brush);
    }
    painter->drawRect(this->rectangleStartPointXCoordinate,this->rectangleStartPointYCoordinate,this->rectangleWidth,this->rectangleHeight);
}
void TMRectangleComponent::setRectangleColor(QString rectangleColor)
{
    this->rectangleColor=rectangleColor;
}
void TMRectangleComponent::setRectangleStartPointXCoordinate(int rectangleStartPointXCoordinate)
{
    this->rectangleStartPointXCoordinate=rectangleStartPointXCoordinate;
}
void TMRectangleComponent::setRectangleStartPointYCoordinate(int rectangleStartPointYCoordinate)
{
    this->rectangleStartPointYCoordinate=rectangleStartPointYCoordinate;
}
void TMRectangleComponent::setRectangleWidth(int rectangleWidth)
{
    this->rectangleWidth=rectangleWidth;
}
void TMRectangleComponent::setRectangleHeight(int rectangleHeight)
{
    this->rectangleHeight=rectangleHeight;
}
void TMRectangleComponent::setRectangleFillColorCheckBox(bool rectangleFillColorCheckBox)
{
    this->rectangleFillColorCheckBox=rectangleFillColorCheckBox;
}
void TMRectangleComponent::setRectangleFillColor(QString rectangleFillColor)
{
    this->rectangleFillColor=rectangleFillColor;
}
