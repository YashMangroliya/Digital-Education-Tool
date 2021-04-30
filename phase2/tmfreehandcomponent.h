#ifndef TMFREEHANDCOMPONENT_H
#define TMFREEHANDCOMPONENT_H
#include<QMouseEvent>
#include<QWidget>
#include"drawablecomponent.h"
class TMFreeHandComponent: public DrawableComponent
{
public:
    TMFreeHandComponent();
    virtual void draw(QPainter *painter);
    QString ToString();
    void select(QPainter *painter);
    bool isOwnedByYou(int x,int y);
    int areYouBeingResized(int x,int y);
    void setOldX(int oldX);
    void setOldY(int oldY);
    void setCurrentX(int currentX);
    void setCurrentY(int currentY);
    int getCurrentX();
    int getCurrentY();
    int getOldX();
    int getOldY();
    void setColor(QString color);
    QString getColor();
    void setPenWidth(int penWidth);
    int getPenWidth();
private:
    int oldX=-1;
    int oldY=-1;
    int currentX;
    int currentY;
    QString color;
    int penWidth;
    QPen pen;
};

#endif // TMFREEHANDCOMPONENT_H
