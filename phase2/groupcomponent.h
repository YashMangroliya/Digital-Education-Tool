#ifndef GROUPCOMPONENT_H
#define GROUPCOMPONENT_H
#include<drawablecomponent.h>
#include<tmfreecirclecomponent.h>
#include<tmfreelinecomponent.h>
#include<tmfreerectanglecomponent.h>
#include<tmimagecomponent.h>
class GroupComponent
{
public:
    GroupComponent();
    QList<DrawableComponent*> *groupList;
    void add(QList<DrawableComponent*>* list);
    void move(int differenceX, int differenceY);
    void clear();
private:
    TMFreeLineComponent *tmFreeLineComponent;
    TMFreeCircleComponent * tmFreeCircleComponent;
    TMFreeRectangleComponent* tmFreerectangleComponent;
    TMImageComponent* tmImageComponent;

};

#endif // GROUPCOMPONENT_H
