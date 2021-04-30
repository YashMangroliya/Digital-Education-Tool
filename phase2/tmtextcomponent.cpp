#include "tmtextcomponent.h"
#include "drawablecomponent.h"

TMTextComponent::TMTextComponent()
{

}
void TMTextComponent::draw(QPainter* painter)
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(this->textColor);
    painter->setPen(pen);
    if(textBold) painter->setFont(QFont(this->textFont,this->textSize,QFont::Bold));
    else painter->setFont(QFont(this->textFont,this->textSize));
    painter->drawText(this->textPositionXCoordinate+3,this->textPositionYCoordinate+this->textSize+10,text);
}

void TMTextComponent::setTextColor(QString textColor)
{
    this->textColor=textColor;
}

void TMTextComponent::setText(QString text)
{
    this->text=text;
}

void TMTextComponent::setTextFont(QString textFont)
{
    this->textFont=textFont;
}

void TMTextComponent::setTextSize(int textSize)
{
    this->textSize=textSize;
}

void TMTextComponent::setTextpositionXCoordinate(int textPositionXCoordinate)
{
    this->textPositionXCoordinate=textPositionXCoordinate;
}

void TMTextComponent::setTextpositionYCoordinate(int textPositionYCoordinate)
{
    this->textPositionYCoordinate=textPositionYCoordinate;
}

void TMTextComponent::setTextBold(bool textBold)
{
    this->textBold=textBold;
}

