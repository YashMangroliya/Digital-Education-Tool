#ifndef TMRECTANGLECOMPONENT_H
#define TMRECTANGLECOMPONENT_H
#include<QString>
#include<QPainter>
#include<drawablecomponent.h>
class TMRectangleComponent:public DrawableComponent
{
public:
    TMRectangleComponent();
    void draw(QPainter* painter);
    void setRectangleColor(QString rectangleColor);
    void setRectangleStartPointXCoordinate(int rectangleStartPointXCoordinate);
    void setRectangleStartPointYCoordinate(int rectangleStartPointYCoordinate);
    void setRectangleWidth(int rectangleWidth);
    void setRectangleHeight(int rectangleHeight);
    void setRectangleFillColorCheckBox(bool rectangleFillColorCheckBox);
    void setRectangleFillColor(QString rectangleFillColor);

private:
    QString rectangleColor;
    int rectangleStartPointXCoordinate;
    int rectangleStartPointYCoordinate;
    int rectangleWidth;
    int rectangleHeight;
    bool rectangleFillColorCheckBox;
    QString rectangleFillColor;
};

#endif // TMRECTANGLECOMPONENT_H
