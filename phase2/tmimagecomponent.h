#ifndef TMIMAGECOMPONENT_H
#define TMIMAGECOMPONENT_H
#include<drawablecomponent.h>
#include<QString>

class TMImageComponent: public DrawableComponent
{
private:
    QPixmap* pixmap;
    QPoint* startPoint;
    QString path;
public:
    TMImageComponent();
    void setPixmap(QPixmap* pixmap);
    QPixmap* getPixmap();
    void setImageStartPoint(QPoint* point);
    QPoint* getImageStartPoint();
    void setPath(QString path);
    QString getPath();
    QString ToString();
    void select(QPainter *painter);
    bool isOwnedByYou(int x,int y);
    int areYouBeingResized(int x,int y);
    void draw(QPainter *painter);
};

#endif // TMIMAGECOMPONENT_H
