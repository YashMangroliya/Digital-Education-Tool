#include "tmfreelinecomponent.h"
#include<QtMath>
TMFreeLineComponent::TMFreeLineComponent()
{
    this->color=QString("Black");
    this->penWidth=3;
}
void TMFreeLineComponent::draw(QPainter *painter)
{
    this->pen.setColor(this->color);
    this->pen.setWidth(this->penWidth);
    painter->setPen(pen);
    painter->drawLine(startX,startY,endX,endY);
}
QString TMFreeLineComponent::ToString()
{
    return QString("Line");
}
void TMFreeLineComponent::select(QPainter *painter)
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(QString("Blue")));
    painter->setPen(pen);
    painter->drawRect(this->startX-5,this->startY-5,10,10);
    painter->drawRect(this->endX-5,this->endY-5,10,10);
}
bool TMFreeLineComponent::isOwnedByYou(int x,int y)
{
    /*int differenceX=this->startX-this->endX;
       if(differenceX==0)
       {
           if((x-this->startX)<2 && (x-this->startX)>-2 && ((y<this->startY && y>this->endY)|| (y>this->startY && y<this->endY)))
           {
               return true;
           }
       }
       int differenceY=this->startY-this->endY;
       if(differenceY==0)
       {
           if((y-this->startY)<2 && (y-this->startY)>-2 && ((x<this->startX &&x>this->endX)|| (x>this->startX && x<this->endX)))
           {
               return true;
           }
       }*/
       /*if((this->endY-startY)!=0 && (this->startX-this->endY)!=0 &&  ((y-this->startY)/(this->endY-this->startY)==(x-this->startX)/(this->endX-this->startX)))
       {
           if((((this->startX<x) && (x<this->endX)) || ((this->endX<x)&& (x<this->startX))))
           {
               if((this->startY<y<this->endY)|| (this->endY<y<this->startY)) return true;
           }
       }*/
    int distance;
    distance=qSqrt(qPow((endX-startX),2)+qPow((endY-startY),2));
    int distFromStart;
    distFromStart=qSqrt(qPow((x-startX),2)+qPow((y-startY),2));
    int distFromEnd;
    distFromEnd=qSqrt(qPow((endX-x),2)+qPow((endY-y),2));
    float totalDist;
    totalDist=distFromStart+distFromEnd;
    if((totalDist-0.2)<distance) return true;
    else return false;
}
int TMFreeLineComponent::areYouBeingResized(int x,int y)
{
    if((this->startX-5<x) && (x<this->startX+5) && (this->startY-5<y) && (y<this->startY+5)) return 1;
    else if((this->endX-5<x) && (x<this->endX+5) && (this->endY-5<y) && (y<this->endY+5)) return 2;
    else return 0;
}
void TMFreeLineComponent::setStartX(int startX)
{
    this->startX=startX;
}
int TMFreeLineComponent::getStartX()
{
    return this->startX;
}
void TMFreeLineComponent::setStartY(int startY)
{
    this->startY=startY;
}
int TMFreeLineComponent::getStartY()
{
    return this->startY;
}
void TMFreeLineComponent::setEndX(int endX)
{
    this->endX=endX;
}
int TMFreeLineComponent::getEndX()
{
    return this->endX;
}
void TMFreeLineComponent::setEndY(int endY)
{
    this->endY=endY;
}
int TMFreeLineComponent::getEndY()
{
    return this->endY;
}
void TMFreeLineComponent::setColor(QString color)
{
    this->color=color;
}
QString TMFreeLineComponent::getColor()
{
    return this->color;
}
void TMFreeLineComponent::setPenWidth(int penWidth)
{
    this->penWidth=penWidth;
}
int TMFreeLineComponent::getPenWidth()
{
    return this->penWidth;
}
