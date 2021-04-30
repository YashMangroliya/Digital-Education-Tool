#include "groupcomponent.h"

GroupComponent::GroupComponent()
{
    groupList=new QList<DrawableComponent*>;
}
void GroupComponent::add(QList<DrawableComponent*>* list)
{
    this->groupList=list;
}
void GroupComponent::move(int diffX,int diffY)
{
    for(DrawableComponent* draggedComponent:*groupList)
    {
        if(draggedComponent->ToString().compare(QString("Circle"))==0)
        {
                tmFreeCircleComponent=(TMFreeCircleComponent*)draggedComponent;
                tmFreeCircleComponent->setCenterPointX(tmFreeCircleComponent->getCenterPointX()+diffX);
                tmFreeCircleComponent->setCenterPointY(tmFreeCircleComponent->getCenterPointY()+diffY);
        }
        if(draggedComponent->ToString().compare(QString("Line"))==0)
        {
            tmFreeLineComponent=(TMFreeLineComponent*)draggedComponent;
            tmFreeLineComponent->setStartX(tmFreeLineComponent->getStartX()+diffX);
            tmFreeLineComponent->setStartY(tmFreeLineComponent->getStartY()+diffY);
            tmFreeLineComponent->setEndX(tmFreeLineComponent->getEndX()+diffX);
            tmFreeLineComponent->setEndY(tmFreeLineComponent->getEndY()+diffY);
        }
        if(draggedComponent->ToString().compare(QString("Rectangle"))==0)
        {
            tmFreerectangleComponent=(TMFreeRectangleComponent*)draggedComponent;
            tmFreerectangleComponent->setStartX(tmFreerectangleComponent->getStartX()+diffX);
            tmFreerectangleComponent->setStartY(tmFreerectangleComponent->getStartY()+diffY);
            tmFreerectangleComponent->setEndX(tmFreerectangleComponent->getEndX()+diffX);
            tmFreerectangleComponent->setEndY(tmFreerectangleComponent->getEndY()+diffY);
        }
        if(draggedComponent->ToString().compare(QString("Image"))==0)
        {
            tmImageComponent=(TMImageComponent*)draggedComponent;
            QPoint* point=new QPoint(tmImageComponent->getImageStartPoint()->x()+diffX,tmImageComponent->getImageStartPoint()->y()+diffY);
            tmImageComponent->setImageStartPoint(point);
        }
    }
}
void GroupComponent::clear()
{
    this->groupList=NULL;
}
