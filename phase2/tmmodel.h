#ifndef TMMODEL_H
#define TMMODEL_H
#include<drawablecomponent.h>
#include<tmfreecirclecomponent.h>
#include<tmfreelinecomponent.h>
#include<tmfreerectanglecomponent.h>
#include<tmfreehandcomponent.h>
#include<tmimagecomponent.h>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonArray>
#include<QFile>
#include<QPair>
class TMModel
{
public:
    TMModel();
    ~TMModel();
    void addComponentToDS(DrawableComponent * component);
    void drawComponents(QPainter *painter);
    QPair<int,DrawableComponent*> resizeHelper(int x,int y);
    QString lastAddedComponentType();
    void processClick(QPainter* painter,int x,int y);
    DrawableComponent* dragHelper(int x,int y);
    int count=0;
    QList<DrawableComponent* > *componentList;
    bool drawLines=false;

private:
    QRect drawingRectangle;
    bool flag=true;
    QPoint *point;
    QString imagePath;
    QPixmap *pixmap;
    QBrush *brush;
    QPen pen;

};

#endif // TMMODEL_H
