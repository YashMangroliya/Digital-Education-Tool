#ifndef TMTEXTCOMPONENT_H
#define TMTEXTCOMPONENT_H
#include<drawablecomponent.h>
#include<QString>
#include<QPainter>
class TMTextComponent: public DrawableComponent
{
public:
    TMTextComponent();
    void draw(QPainter* painter);
    void setTextColor(QString color);
    void setTextSize(int textSize);
    void setText(QString text);
    void setTextFont(QString textFont);
    void setTextpositionXCoordinate(int textPositionXCoordinate);
    void setTextpositionYCoordinate(int textPositionYCoordinate);
    void setTextBold(bool textBold);

private:
    QString textColor;
    QString text;
    QString textFont;
    int textSize;
    int textPositionXCoordinate;
    int textPositionYCoordinate;
    bool textBold;
};

#endif // TMTEXTCOMPONENT_H
