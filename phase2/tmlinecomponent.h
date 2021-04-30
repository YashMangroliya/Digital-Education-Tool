#ifndef TMLINECOMPONENT_H
#define TMLINECOMPONENT_H
#include<QString>
#include<QPainter>
#include "drawablecomponent.h"
class TMLineComponent:public DrawableComponent
{
private:

    QString lineColor;
    int lineStartPositionXCoordinate;
    int lineStartPositionYCoordinate;
    int lineEndPositionXCoordinate;
    int lineEndPositionYCoordinate;
public:
    TMLineComponent();
    void draw(QPainter *painter);
    void setLineColor(QString lineColor);
    QString getLineColor();
    void setLineStartPositionXCoordinate(int lineStartPositionXCoordinate);
    int getLineStartPositionXCoordinate();
    void setLineStartPositionYCoordinate(int lineStartPositionYCoordinate);
    int getLineStartPositionYCoordinate();
    void setLineEndPositionXCoordinate(int lineEndPositionXCoordinate);
    int getLineEndPositionXCoordinate();
    void setLineEndPositionYCoordinate(int lineEndPositionYCoordinate);
    int getLineEndPositionYCoordinate();

};

#endif // TMLINECOMPONENT_H
