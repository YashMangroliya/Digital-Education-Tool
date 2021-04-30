#include "tmimagecomponent.h"

TMImageComponent::TMImageComponent()
{
}
void TMImageComponent::setPixmap(QPixmap* pixmap)
{
    this->pixmap=pixmap;
}
QPixmap* TMImageComponent::getPixmap()
{
    return this->pixmap;
}
void TMImageComponent::setImageStartPoint(QPoint* point)
{
    this->startPoint=point;
}
QPoint* TMImageComponent::getImageStartPoint()
{
    return this->startPoint;
}
void TMImageComponent::setPath(QString path)
{
    this->path=path;
}
QString TMImageComponent::getPath()
{
    return this->path;
}
QString TMImageComponent::ToString()
{
    return QString("Image");
}
void TMImageComponent::select(QPainter *painter)
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(QString("Blue")));
    painter->setPen(pen);
    painter->drawRect(this->startPoint->x()-5,this->startPoint->y()-5,10,10);
    painter->drawRect(this->startPoint->x()-5,this->startPoint->y()+this->pixmap->height()-5,10,10);
    painter->drawRect(this->startPoint->x()+this->pixmap->width()-5,this->startPoint->y()-5,10,10);
    painter->drawRect(this->startPoint->x()+this->pixmap->width()-5,this->startPoint->y()+this->pixmap->height()-5,10,10);
}
bool TMImageComponent::isOwnedByYou(int x,int y)
{
    if(((this->startPoint->x()<x) && (x<(this->startPoint->x()+this->pixmap->width()))) && ((this->startPoint->y()<y) && (y<(this->startPoint->y()+this->pixmap->height())))) return true;
    //else if(this->startPoint->x()>x>(this->startPoint->x()+this->pixmap->width()) && this->startPoint->y()>y>(this->startPoint->y()+this->pixmap->height())) return true;
    //else if(this->startPoint->x()<x<(this->startPoint->x()+this->pixmap->width()) && this->startPoint->y()>y>(this->startPoint->y()+this->pixmap->height())) return true;
    //else if(this->startPoint->x()>x>(this->startPoint->x()+this->pixmap->width()) && this->startPoint->y()<y<(this->startPoint->y()+this->pixmap->height())) return true;
    else return false;
}
int TMImageComponent::areYouBeingResized(int x,int y)
{
    if((((this->startPoint->x()-5)<x) && (x<(this->startPoint->x()+5))) && (((this->startPoint->y()-5)<y) &&(y<(this->startPoint->y()+5)))) return 1;
    else if(((this->startPoint->x()+this->pixmap->width()-5<x) && (x<this->startPoint->x()+this->pixmap->width()+5)) && ((this->startPoint->y()-5<y) && (y<this->startPoint->y()+5))) return 2;
    else if(((this->startPoint->x()-5<x) && (x<this->startPoint->x()+5)) && ((this->startPoint->y()+this->pixmap->height()-5<y) && (y<this->startPoint->y()+this->pixmap->height()+5))) return 3;
    else if(((this->startPoint->x()+this->pixmap->width()-5<x) && (x<this->startPoint->x()+this->pixmap->width()+5)) && ((this->startPoint->y()+this->pixmap->height()-5<y) && (y<this->startPoint->y()+this->pixmap->height()+5))) return 4;
    else return 0;
}
void TMImageComponent::draw(QPainter *painter)
{
    painter->drawPixmap(this->startPoint->x(),this->startPoint->y(),*pixmap);
}

