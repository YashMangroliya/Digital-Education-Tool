#include "tmmodel.h"
#include "mainwindow.h"
TMModel::TMModel()
{
componentList=new QList<DrawableComponent*>();
imagePath=QString(":/images/bgImage1.png");
pixmap=new QPixmap(imagePath);
point=new QPoint((725)-(pixmap->width()/2),(450-(pixmap->height())/2));
}
TMModel::~TMModel()
{
    delete [] componentList;
}
void TMModel::addComponentToDS(DrawableComponent * component)
{
    componentList->push_back(component);
}
void TMModel::drawComponents(QPainter *painter)
{
    pen.setColor(QColor(QString("black")));
    pen.setWidth(3);
    painter->setPen(pen);
    painter->setClipRect(0,0,1920,1080);
    painter->drawPixmap(*point,*pixmap);
    drawingRectangle.setX(240);
    drawingRectangle.setY(50);
    drawingRectangle.setWidth(1450);
    drawingRectangle.setHeight(900);
    //painter->setClipRect(244,54,1442,892);

    //brush=new QBrush(QColor("Blue"));
    //painter->setBrush(*brush);
    //painter->drawRect(0,0,1920,1080);


    brush=new QBrush(QColor("White"));
    painter->setBrush(*brush);
    painter->drawRect(drawingRectangle);
    painter->setClipRect(248,58,1435,885);
    painter->drawRect(249,59,1432,882);
    brush=new QBrush;
    painter->setBrush(*brush);
    if(drawLines)
    {
        pen.setWidth(1);
        painter->setPen(pen);
        for(int y=50;y<960;y=y+50)
        {
            painter->drawLine(290,y,1630,y);
        }
        pen.setWidth(3);
        painter->setPen(pen);
    }
    for(DrawableComponent* component: *componentList)
    {
        component->draw(painter);
    }
}
void TMModel::processClick(QPainter *painter,int x,int y)
{
    count=0;

    for(DrawableComponent *d:*componentList)
    {
        if(d->isOwnedByYou(x,y))
        {
            d->select(painter);
            break;
        }
        count++;
    }
}
DrawableComponent* TMModel::dragHelper(int x,int y)
{
    for(DrawableComponent *d1:*componentList)
    {
        if(d1->isOwnedByYou(x,y))
        {
            return d1;
        }
    }
    return NULL;
}
QPair<int,DrawableComponent*> TMModel::resizeHelper(int x,int y)
{
    int selectedRectNumber=0;
    QPair<int,DrawableComponent*> pair;
    for(DrawableComponent *d1:*componentList)
    {
        selectedRectNumber=d1->areYouBeingResized(x,y);
        if(selectedRectNumber!=0)
        {
            pair=qMakePair(selectedRectNumber,d1);
            return pair;
        }
    }
    pair=qMakePair(0,nullptr);
    return pair;
}
