#ifndef TMFREELINECOMPONENT_H
#define TMFREELINECOMPONENT_H
#include<drawablecomponent.h>

class TMFreeLineComponent: public DrawableComponent
{
public:
    TMFreeLineComponent();
    virtual void draw(QPainter *painter);
    QString ToString();
    void select(QPainter *painter);
    bool isOwnedByYou(int x,int y);
    int areYouBeingResized(int x,int y);
    void setStartX(int startX);
    void setStartY(int startY);
    void setEndX(int endX);
    void setEndY(int endY);
    int getStartX();
    int getStartY();
    int getEndX();
    int getEndY();
    void setColor(QString color);
    QString getColor();
    void setPenWidth(int penWidth);
    int getPenWidth();
private:
    int startX;
    int startY;
    int endX;
    int endY;
    QString color;
    int penWidth;
    QPen pen;
};

#endif // TMFREELINECOMPONENT_H
