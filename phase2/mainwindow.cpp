#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<drawablecomponent.h>
#include<tmmodel.h>
#include<tmfreehandcomponent.h>
#include<tmfreelinecomponent.h>
#include<tmfreecirclecomponent.h>
#include<tmimagecomponent.h>
#include<QtMath>
#include<QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tmModel=new TMModel;
    //this->setMouseTracking(true);
    tmFreeLineComponent=new TMFreeLineComponent;
    tmFreeCircleComponent=new TMFreeCircleComponent;
    tmFreerectangleComponent=new TMFreeRectangleComponent;
    QIcon freeHandIcon(QPixmap(":/images/freeHandIcon.png"));
    this->ui->freeHandButton->setIcon(freeHandIcon);
    this->ui->freeHandButton->setToolTip(QString("Free Hand"));
    QIcon rectangleIcon(QPixmap(":/images/rectangleIcon.png"));
    this->ui->freeRectangleButton->setIcon(rectangleIcon);
    this->ui->freeRectangleButton->setToolTip(QString("Rectangle"));
    QIcon lineIcon(QPixmap(":/images/lineIcon.png"));
    this->ui->freeLineButton->setIcon(lineIcon);
    this->ui->freeLineButton->setToolTip(QString("Line"));
    QIcon circleIcon(QPixmap(":/images/circleIcon.png"));
    this->ui->freeCircleButton->setIcon(circleIcon);
    this->ui->freeCircleButton->setToolTip(QString("Circle"));
    QPixmap *save=new QPixmap(":/images/saveIcon.png") ;
    QIcon saveIcon(*save);
    this->ui->saveButton->setIcon(saveIcon);
    this->ui->saveButton->setIconSize(QSize(save->width()-13,save->height()-13));
    this->ui->saveButton->setToolTip(QString("Save"));
    QPixmap *open=new QPixmap(":/images/openIcon.png") ;
    QIcon openIcon(*open);
    this->ui->openButton->setIcon(openIcon);
    this->ui->openButton->setIconSize(QSize(open->width(),open->height()));
    this->ui->openButton->setToolTip(QString("Open"));
    QIcon deleteIcon(QPixmap(":/images/deleteIcon.png"));
    this->ui->deleteButton->setIcon(deleteIcon);
    this->ui->deleteButton->setToolTip(QString("Delete"));
    QIcon drawHorizontalLines(QPixmap(":/images/horizontalLinesIcon.PNG"));
    this->ui->drawHorizontalLinesButton->setIcon(drawHorizontalLines);
    this->ui->drawHorizontalLinesButton->setToolTip(QString("Horizontal Lines on Page"));
    QPixmap *group=new QPixmap(":/images/groupIcon.png") ;
    QIcon groupIcon(*group);
    this->ui->groupButton->setIcon(groupIcon);
    this->ui->groupButton->setIconSize(QSize(group->width(),group->height()));
    QPixmap *ungroup=new QPixmap(":/images/ungroupIcon.png") ;
    QIcon ungroupIcon(*ungroup);
    this->ui->ungroupButton->setIcon(ungroupIcon);
    this->ui->ungroupButton->setIconSize(QSize(ungroup->width(),ungroup->height()));
    QPixmap *image=new QPixmap(":/images/imageIcon.png") ;
    QIcon imageIcon(*image);
    this->ui->imageButton->setIcon(imageIcon);
    this->ui->imageButton->setIconSize(QSize(image->width(),image->height()));
    QPixmap *pi=new QPixmap(":/images/piSymbol.png") ;
    QIcon piIcon(*pi);
    this->ui->piButton->setIcon(piIcon);
    this->ui->piButton->setIconSize(QSize(pi->width(),pi->height()));
    QPixmap *thetha=new QPixmap(":/images/thethaSymbol.png") ;
    QIcon thethaIcon(*thetha);
    this->ui->thethaButton->setIcon(thethaIcon);
    this->ui->thethaButton->setIconSize(QSize(thetha->width(),thetha->height()));
    QPixmap *omega=new QPixmap(":/images/omegaSymbol.png") ;
    QIcon omegaIcon(*omega);
    this->ui->omegaButton->setIcon(omegaIcon);
    this->ui->omegaButton->setIconSize(QSize(omega->width(),omega->height()+11));
    QPixmap *percentage=new QPixmap(":/images/percentageSymbol.png") ;
    QIcon percentageIcon(*percentage);
    this->ui->percentageButton->setIcon(percentageIcon);
    this->ui->percentageButton->setIconSize(QSize(percentage->width(),percentage->height()));
    QPixmap *delta=new QPixmap(":/images/deltaSymbol.png") ;
    QIcon deltaIcon(*delta);
    this->ui->deltaButton->setIcon(deltaIcon);
    this->ui->deltaButton->setIconSize(QSize(delta->width(),delta->height()));
    QPixmap *alpha=new QPixmap(":/images/alphaSymbol.png") ;
    QIcon alphaIcon(*alpha);
    this->ui->alphaButton->setIcon(alphaIcon);
    this->ui->alphaButton->setIconSize(QSize(alpha->width(),alpha->height()));
    QPixmap *beta=new QPixmap(":/images/betaSymbol.png") ;
    QIcon betaIcon(*beta);
    this->ui->betaButton->setIcon(betaIcon);
    this->ui->betaButton->setIconSize(QSize(beta->width(),beta->height()));
    QPixmap *gamma=new QPixmap(":/images/gammaSymbol.png") ;
    QIcon gammaIcon(*gamma);
    this->ui->gammaButton->setIcon(gammaIcon);
    this->ui->gammaButton->setIconSize(QSize(gamma->width(),gamma->height()));
    QPixmap *hash=new QPixmap(":/images/hashSymbol.png") ;
    QIcon hashIcon(*hash);
    this->ui->hashButton->setIcon(hashIcon);
    this->ui->hashButton->setIconSize(QSize(hash->width(),hash->height()));
    QPixmap *integral=new QPixmap(":/images/integralSymbol.png") ;
    QIcon integralIcon(*integral);
    this->ui->integralButton->setIcon(integralIcon);
    this->ui->integralButton->setIconSize(QSize(integral->width(),integral->height()));
    QPixmap *lembda=new QPixmap(":/images/lembdaSymbol.png") ;
    QIcon lembdaIcon(*lembda);
    this->ui->lembdaButton->setIcon(lembdaIcon);
    this->ui->lembdaButton->setIconSize(QSize(lembda->width(),lembda->height()));
    QPixmap *root=new QPixmap(":/images/rootSymbol.png") ;
    QIcon rootIcon(*root);
    this->ui->rootButton->setIcon(rootIcon);
    this->ui->rootButton->setIconSize(QSize(root->width(),root->height()));
    QPixmap *submattion=new QPixmap(":/images/submattionSymbol.png") ;
    QIcon submattionIcon(*submattion);
    this->ui->submattionButton->setIcon(submattionIcon);
    this->ui->submattionButton->setIconSize(QSize(submattion->width(),submattion->height()));
    QPixmap *infinite=new QPixmap(":/images/infiniteSymbol.png") ;
    QIcon infiniteIcon(*infinite);
    this->ui->infiniteButton->setIcon(infiniteIcon);
    this->ui->infiniteButton->setIconSize(QSize(infinite->width(),infinite->height()));
    QPixmap *leftBracket=new QPixmap(":/images/leftBracketSymbol.png") ;
    QIcon leftBracketIcon(*leftBracket);
    this->ui->leftBracketButton->setIcon(leftBracketIcon);
    this->ui->leftBracketButton->setIconSize(QSize(leftBracket->width(),leftBracket->height()));
    QPixmap *rightBracket=new QPixmap(":/images/rightBracketSymbol.png") ;
    QIcon rightBracketIcon(*rightBracket);
    this->ui->rightBracketButton->setIcon(rightBracketIcon);
    this->ui->rightBracketButton->setIconSize(QSize(rightBracket->width(),rightBracket->height()));
    QPixmap *cross=new QPixmap(":/images/crossIcon.png") ;
    QIcon crossIcon(*cross);
    this->ui->mathSymbolPanelCrossButton->setIcon(crossIcon);
    this->ui->mathSymbolPanelCrossButton->setIconSize(QSize(cross->width(),cross->height()));
    selectedComponentList=new QList<DrawableComponent*>;
    groupComponent=new GroupComponent;
    this->ui->mathSymbolsPanel->setGeometry(240,340,370,220);
    this->ui->mathSymbolsPanel->setVisible(false);
    penColor=QString("Black");
    penWidth=3;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete selectedComponentList;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    painter=new QPainter(this);
    //painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setClipRect(240,50,1452,902);
    tmModel->drawComponents(painter);
    //pen.setWidth(3);
    //pen.setColor(QString("Black"));
    //painter->setPen(pen);
    if(freeRectangleFlag)
    {
        if(tmFreerectangleComponent!=NULL)tmFreerectangleComponent->draw(painter);
    }
    if(freeCircleFlag)
    {
        if(tmFreeCircleComponent!=NULL)tmFreeCircleComponent->draw(painter);
    }
    if(freeLineFlag)
    {
        if(tmFreeLineComponent!=NULL)tmFreeLineComponent->draw(painter);
    }
    if(clickedFlag)
    {
        clickedFlag=false;

        if(selectedComponentList->size()>0)
        {
            for(DrawableComponent *d:*selectedComponentList)
            {
                d->select(painter);
            }
        }
        /*else
        {
            for(DrawableComponent *d:*groupComponent->groupList)
            {
                d->select(painter);
            }
        }*/
        /*c=tmModel->componentList->size()-tmModel->count;
        if(c>0)
        {
            this->ui->drawingList->item(c-1)->setSelected(true);
        }*/

    }
    if(itemIndex!=-1)tmModel->componentList->at(tmModel->componentList->size()-(itemIndex+1))->select(painter);
    itemIndex=-1;
    painter->end();
}
void MainWindow::mousePressEvent(QMouseEvent* mousePressEvent)
{
    if(mousePressEvent->buttons()==Qt::LeftButton)
    {
        if(this->freeHandFlag)
        {
            this->oldX=mousePressEvent->x();
            this->oldY=mousePressEvent->y();
        }
        if(freeLineFlag)
        {
            tmFreeLineComponent=new TMFreeLineComponent;
            tmFreeLineComponent->setStartX(mousePressEvent->x());
            tmFreeLineComponent->setStartY(mousePressEvent->y());
            tmFreeLineComponent->setEndX(mousePressEvent->x());
            tmFreeLineComponent->setEndY(mousePressEvent->y());
            tmFreeLineComponent->setColor(this->penColor);
            tmFreeLineComponent->setPenWidth(this->penWidth);
        }
        if(this->freeRectangleFlag)
        {
            tmFreerectangleComponent=new TMFreeRectangleComponent;
            tmFreerectangleComponent->setStartX(mousePressEvent->x());
            tmFreerectangleComponent->setStartY(mousePressEvent->y());
            tmFreerectangleComponent->setEndX(mousePressEvent->x());
            tmFreerectangleComponent->setEndY(mousePressEvent->y());
            tmFreerectangleComponent->setColor(this->penColor);
            tmFreerectangleComponent->setPenWidth(this->penWidth);
        }
        if(this->freeCircleFlag)
        {
            tmFreeCircleComponent=new TMFreeCircleComponent;
            tmFreeCircleComponent->setCenterPointX(mousePressEvent->x());
            tmFreeCircleComponent->setCenterPointY(mousePressEvent->y());
            tmFreeCircleComponent->setColor(this->penColor);
            tmFreeCircleComponent->setPenWidth(this->penWidth);
        }
        if(this->pickFlag)
        {
            this->pickPressedX=mousePressEvent->x();
            this->pickPressedY=mousePressEvent->y();
            dragMoveFlag=false;
            resizeFlag=false;
            pair=tmModel->resizeHelper(pickPressedX,pickPressedY);
            if(pair.first==0)
            {
                draggedComponent=tmModel->dragHelper(pickPressedX,pickPressedY);
                if(draggedComponent!=NULL)
                {
                    if(selectedComponentList->indexOf(draggedComponent)!=-1) dragMoveFlag=true;
                }
            }
            else
            {
                resizableComponent=pair.second;
                if(selectedComponentList->indexOf(resizableComponent)!=-1)resizeFlag=true;
            }

        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* mouseMoveEvent)
{
    this->lineSelection=false;
    this->rectangleSelection=false;
    this->circleSelection=false;
    if(mouseMoveEvent->buttons()==Qt::LeftButton)
    {
        if(this->freeHandFlag)
        {
            tmFreeHandComponent=new TMFreeHandComponent;
            tmFreeHandComponent->setOldX(this->oldX);
            tmFreeHandComponent->setOldY(this->oldY);
            tmFreeHandComponent->setCurrentX(mouseMoveEvent->x());
            tmFreeHandComponent->setCurrentY(mouseMoveEvent->y());
            tmFreeHandComponent->setColor(this->penColor);
            tmFreeHandComponent->setPenWidth(this->penWidth);
            this->tmModel->addComponentToDS(tmFreeHandComponent);
            QWidget::update();
            this->oldX=tmFreeHandComponent->getCurrentX();
            this->oldY=tmFreeHandComponent->getCurrentY();
        }
        if(this->freeLineFlag)
        {
            tmFreeLineComponent->setEndX(mouseMoveEvent->x());
            tmFreeLineComponent->setEndY(mouseMoveEvent->y());
            QWidget::update();
        }
        if(this->freeRectangleFlag)
        {
            tmFreerectangleComponent->setEndX(mouseMoveEvent->x());
            tmFreerectangleComponent->setEndY(mouseMoveEvent->y());
            QWidget::update();
        }
        if(this->freeCircleFlag)
        {
            tmFreeCircleComponent->setRadius(qSqrt(qPow((tmFreeCircleComponent->getCenterPointX()-mouseMoveEvent->x()),2)+qPow((tmFreeCircleComponent->getCenterPointY()-mouseMoveEvent->y()),2)));
            QWidget::update();
        }
        if(pickFlag && dragMoveFlag && draggedComponent!=NULL)
        {
            diffX=mouseMoveEvent->x()-pickPressedX;
            diffY=mouseMoveEvent->y()-pickPressedY;
            pickPressedX=mouseMoveEvent->x();
            pickPressedY=mouseMoveEvent->y();
            if(groupFlag==false)
            {
                if(draggedComponent->ToString().compare(QString("Circle"))==0)
                {
                    tmFreeCircleComponent=(TMFreeCircleComponent*)draggedComponent;
                    tmFreeCircleComponent->setCenterPointX(tmFreeCircleComponent->getCenterPointX()+diffX);
                    tmFreeCircleComponent->setCenterPointY(tmFreeCircleComponent->getCenterPointY()+diffY);
                    QWidget::update();
                }
                if(draggedComponent->ToString().compare(QString("Line"))==0)
                {
                    tmFreeLineComponent=(TMFreeLineComponent*)draggedComponent;
                    tmFreeLineComponent->setStartX(tmFreeLineComponent->getStartX()+diffX);
                    tmFreeLineComponent->setStartY(tmFreeLineComponent->getStartY()+diffY);
                    tmFreeLineComponent->setEndX(tmFreeLineComponent->getEndX()+diffX);
                    tmFreeLineComponent->setEndY(tmFreeLineComponent->getEndY()+diffY);
                    QWidget::update();
                }
                if(draggedComponent->ToString().compare(QString("Rectangle"))==0)
                {
                    tmFreerectangleComponent=(TMFreeRectangleComponent*)draggedComponent;
                    tmFreerectangleComponent->setStartX(tmFreerectangleComponent->getStartX()+diffX);
                    tmFreerectangleComponent->setStartY(tmFreerectangleComponent->getStartY()+diffY);
                    tmFreerectangleComponent->setEndX(tmFreerectangleComponent->getEndX()+diffX);
                    tmFreerectangleComponent->setEndY(tmFreerectangleComponent->getEndY()+diffY);
                    QWidget::update();

                }
                if(draggedComponent->ToString().compare(QString("Image"))==0)
                {
                    tmImageComponent=(TMImageComponent*)draggedComponent;
                    QPoint* point=new QPoint(tmImageComponent->getImageStartPoint()->x()+diffX,tmImageComponent->getImageStartPoint()->y()+diffY);
                    tmImageComponent->setImageStartPoint(point);
                    QWidget::update();
                }

            }
            else
            {
                groupComponent->move(diffX,diffY);
                QWidget::update();
            }


        }
        if(pickFlag && resizableComponent!=NULL && resizeFlag)
        {
            diffX=mouseMoveEvent->x()-pickPressedX;
            diffY=mouseMoveEvent->y()-pickPressedY;
            pickPressedX=mouseMoveEvent->x();
            pickPressedY=mouseMoveEvent->y();
            if(resizableComponent->ToString().compare(QString("Rectangle"))==0)
            {
                tmFreerectangleComponent=(TMFreeRectangleComponent*)resizableComponent;
                if(pair.first==1)
                {
                    tmFreerectangleComponent->setStartX(tmFreerectangleComponent->getStartX()+diffX);
                    tmFreerectangleComponent->setStartY(tmFreerectangleComponent->getStartY()+diffY);
                }
                else if(pair.first==2)
                {
                    tmFreerectangleComponent->setEndX(tmFreerectangleComponent->getEndX()+diffX);
                    tmFreerectangleComponent->setStartY(tmFreerectangleComponent->getStartY()+diffY);
                }
                else if(pair.first==3)
                {
                    tmFreerectangleComponent->setStartX(tmFreerectangleComponent->getStartX()+diffX);
                    tmFreerectangleComponent->setEndY(tmFreerectangleComponent->getEndY()+diffY);
                }
                else if(pair.first==4)
                {
                    tmFreerectangleComponent->setEndX(tmFreerectangleComponent->getEndX()+diffX);
                    tmFreerectangleComponent->setEndY(tmFreerectangleComponent->getEndY()+diffY);
                }
                QWidget::update();
            }
            else if(resizableComponent->ToString().compare(QString("Circle"))==0)
            {
                tmFreeCircleComponent=(TMFreeCircleComponent*) resizableComponent;
                //int diffRadius=qSqrt(qPow((pickPressedX-mouseMoveEvent->x()),2)+qPow((pickPressedY-mouseMoveEvent->y()),2));
                if(pair.first==1)
                {
                    tmFreeCircleComponent->setRadius(tmFreeCircleComponent->getRadius()-diffY);
                }
                else if(pair.first==2)
                {
                    tmFreeCircleComponent->setRadius(tmFreeCircleComponent->getRadius()+diffX);
                }
                else if(pair.first==3)
                {
                    tmFreeCircleComponent->setRadius(tmFreeCircleComponent->getRadius()+diffY);
                }
                else if(pair.first==4)
                {
                    tmFreeCircleComponent->setRadius(tmFreeCircleComponent->getRadius()-diffX);
                }
                QWidget::update();
            }
            else if(resizableComponent->ToString().compare(QString("Line"))==0)
            {
                tmFreeLineComponent=(TMFreeLineComponent*) resizableComponent;
                if(pair.first==1)
                {
                    tmFreeLineComponent->setStartX(tmFreeLineComponent->getStartX()+diffX);
                    tmFreeLineComponent->setStartY(tmFreeLineComponent->getStartY()+diffY);
                }
                else if(pair.first==2)
                {
                    tmFreeLineComponent->setEndX(tmFreeLineComponent->getEndX()+diffX);
                    tmFreeLineComponent->setEndY(tmFreeLineComponent->getEndY()+diffY);
                }
                QWidget::update();
            }
            else if(resizableComponent->ToString().compare(QString("Image"))==0)
            {
                /*tmImageComponent=(TMImageComponent*)resizableComponent;
                if(pair.first==1)
                {
                    QPoint startPoint(tmImageComponent->getImageStartPoint()->x()+diffX,tmImageComponent->getImageStartPoint()->y()+diffY);
                    tmImageComponent->setImageStartPoint(&startPoint);

                }
                else if(pair.first==2)
                {
                    tmFreerectangleComponent->setEndX(tmFreerectangleComponent->getEndX()+diffX);
                    tmFreerectangleComponent->setStartY(tmFreerectangleComponent->getStartY()+diffY);
                }
                else if(pair.first==3)
                {
                    tmFreerectangleComponent->setStartX(tmFreerectangleComponent->getStartX()+diffX);
                    tmFreerectangleComponent->setEndY(tmFreerectangleComponent->getEndY()+diffY);
                }
                else if(pair.first==4)
                {
                    tmFreerectangleComponent->setEndX(tmFreerectangleComponent->getEndX()+diffX);
                    tmFreerectangleComponent->setEndY(tmFreerectangleComponent->getEndY()+diffY);
                }*/
                QWidget::update();
            }
        }
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent* mouseReleaseEvent)
{
    if(freeLineFlag)
    {
        tmModel->addComponentToDS(tmFreeLineComponent);
        item=new QListWidgetItem(tmFreeLineComponent->ToString());
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        this->ui->drawingList->insertItem(0,item);
        //this->ui->drawingList->item(0)->setSelected(true);
        QWidget::update();
    }
    if(freeCircleFlag)
    {
        tmModel->addComponentToDS(tmFreeCircleComponent);
        item=new QListWidgetItem(tmFreeCircleComponent->ToString());
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        this->ui->drawingList->insertItem(0,item);
        QWidget::update();
    }
    if(freeRectangleFlag)
    {
        tmModel->addComponentToDS(tmFreerectangleComponent);
        item=new QListWidgetItem(tmFreerectangleComponent->ToString());
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        this->ui->drawingList->insertItem(0,item);
        QWidget::update();
    }
    if(freeHandFlag)
    {
        item=new QListWidgetItem(tmFreeHandComponent->ToString());
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        this->ui->drawingList->insertItem(0,item);
    }
    if(pickFlag /*&& draggedComponent!=NULL*/)
    {
        clickedFlag=true;
        QWidget::update();
        //draggedComponent=NULL;
        //dragMoveFlag=false;
    }
}
void MainWindow::mouseDoubleClickEvent(QMouseEvent* mouseClickedEvent)
{
    clickedFlag=true;
    if((!ctrlFlag) && (selectedComponentList->size()!=0)) selectedComponentList->clear();
    drawableComponent=tmModel->dragHelper(mouseClickedEvent->x(),mouseClickedEvent->y());
    if(drawableComponent!=NULL)
    {
        int itemIndex1=tmModel->componentList->size()-tmModel->componentList->indexOf(drawableComponent)-1;
        selectedComponentList->push_back(drawableComponent);
        this->ui->drawingList->item(itemIndex1)->setSelected(true);
    }
    QWidget::update();
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if(event->key()==Qt::Key_Control) ctrlFlag=true;
}
void MainWindow::keyReleaseEvent(QKeyEvent * event)
{
    if(event->key()==Qt::Key_Control) ctrlFlag=false;
}
void MainWindow::on_freeHandButton_clicked()
{
    if(this->freeHandFlag) this->freeHandFlag=false;
    else
    {
        this->circleSelection=false;
        this->freeHandFlag=true;
        this->freeLineFlag=false;
        this->freeRectangleFlag=false;
        this->freeCircleFlag=false;
        this->pickFlag=false;
        this->ui->mathSymbolsPanel->setVisible(false);
        this->selectedComponentList->clear();
        this->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        QWidget::update();
    }
}
void MainWindow::on_freeLineButton_clicked()
{
    if(this->freeLineFlag)this->freeLineFlag=false;
    else
    {
        this->circleSelection=false;
        this->freeLineFlag=true;
        this->freeHandFlag=false;
        this->freeRectangleFlag=false;
        this->freeCircleFlag=false;
        this->pickFlag=false;
        this->ui->mathSymbolsPanel->setVisible(false);
        this->selectedComponentList->clear();
        this->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        QWidget::update();
    }
}

void MainWindow::on_freeRectangleButton_clicked()
{
    if(this->freeRectangleFlag) this->freeRectangleFlag=false;
    else
    {
        this->circleSelection=false;
        this->freeRectangleFlag=true;
        this->freeHandFlag=false;
        this->freeLineFlag=false;
        this->freeCircleFlag=false;
        this->pickFlag=false;
        this->ui->mathSymbolsPanel->setVisible(false);
        this->selectedComponentList->clear();
        this->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        QWidget::update();
    }
}

void MainWindow::on_freeCircleButton_clicked()
{
    if(this->freeCircleFlag) this->freeCircleFlag=false;
    else
    {
        this->circleSelection=false;
        this->freeCircleFlag=true;
        this->freeHandFlag=false;
        this->freeLineFlag=false;
        this->freeRectangleFlag=false;
        this->pickFlag=false;
        this->ui->mathSymbolsPanel->setVisible(false);
        this->selectedComponentList->clear();
        this->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        QWidget::update();
    }
}

void MainWindow::on_pickButton_clicked()
{
    if(pickFlag) this->pickFlag=false;
    else
    {
        this->pickFlag=true;
        this->freeHandFlag=false;
        this->freeLineFlag=false;
        this->freeRectangleFlag=false;
        this->freeCircleFlag=false;
        this->ui->mathSymbolsPanel->setVisible(false);
        this->selectedComponentList->clear();
        this->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        groupFlag=false;
    }
}
/*void QListWidget::itemClicked(QListWidgetItem *item)
{

}
*/

void MainWindow::on_groupButton_clicked()
{
    this->freeHandFlag=false;
    this->freeLineFlag=false;
    this->freeRectangleFlag=false;
    this->freeCircleFlag=false;
    this->ui->mathSymbolsPanel->setVisible(false);
    if(selectedComponentList->size()==0) return;
    else
    {
        groupFlag=true;
        groupComponent->add(selectedComponentList);
    }

}

void MainWindow::on_ungroupButton_clicked()
{
    groupFlag=false;
    groupComponent->clear();
    this->ui->mathSymbolsPanel->setVisible(false);
}

void MainWindow::on_saveButton_clicked()
{
    saveFileName=QFileDialog::getSaveFileName(this,QString("Save As"),tr("*.ptr"));
    if(saveFileName==NULL) return;
    //tmModel->saveData(saveFileName);
    QFile file(saveFileName);
    file.open(QFile::WriteOnly);
    QJsonArray jsonArray;
    for(DrawableComponent* drawableComponent:*tmModel->componentList)
    {
        if(drawableComponent->ToString().compare(QString("Circle"))==0)
        {
            QJsonObject object;
            tmFreeCircleComponent=(TMFreeCircleComponent*)drawableComponent;
            object.insert(QString("drawingType"),QJsonValue(QString(tmFreeCircleComponent->ToString())));
            object.insert(QString("centerPointX"),QJsonValue(tmFreeCircleComponent->getCenterPointX()));
            object.insert(QString("centerPointY"),QJsonValue(tmFreeCircleComponent->getCenterPointY()));
            object.insert(QString("radius"),QJsonValue(tmFreeCircleComponent->getRadius()));
            object.insert(QString("penColor"),QJsonValue(tmFreeCircleComponent->getColor()));
            object.insert(QString("penWidth"),QJsonValue(tmFreeCircleComponent->getPenWidth()));
            jsonArray.append(object);
        }
        else if(drawableComponent->ToString().compare(QString("Line"))==0)
        {
            QJsonObject object;
            tmFreeLineComponent=(TMFreeLineComponent*)drawableComponent;
            object.insert(QString("drawingType"),QJsonValue(QString(tmFreeLineComponent->ToString())));
            object.insert(QString("startX"),QJsonValue(tmFreeLineComponent->getStartX()));
            object.insert(QString("startY"),QJsonValue(tmFreeLineComponent->getStartY()));
            object.insert(QString("endX"),QJsonValue(tmFreeLineComponent->getEndX()));
            object.insert(QString("endY"),QJsonValue(tmFreeLineComponent->getEndY()));
            object.insert(QString("penColor"),QJsonValue(tmFreeLineComponent->getColor()));
            object.insert(QString("penWidth"),QJsonValue(tmFreeLineComponent->getPenWidth()));
            jsonArray.append(object);
        }
        else if(drawableComponent->ToString().compare(QString("Rectangle"))==0)
        {
            QJsonObject object;
            tmFreerectangleComponent=(TMFreeRectangleComponent*)drawableComponent;
            object.insert(QString("drawingType"),QJsonValue(QString(tmFreerectangleComponent->ToString())));
            object.insert(QString("startX"),QJsonValue(tmFreerectangleComponent->getStartX()));
            object.insert(QString("startY"),QJsonValue(tmFreerectangleComponent->getStartY()));
            object.insert(QString("endX"),QJsonValue(tmFreerectangleComponent->getEndX()));
            object.insert(QString("endY"),QJsonValue(tmFreerectangleComponent->getEndY()));
            object.insert(QString("penColor"),QJsonValue(tmFreerectangleComponent->getColor()));
            object.insert(QString("penWidth"),QJsonValue(tmFreerectangleComponent->getPenWidth()));
            jsonArray.append(object);
        }
        else if(drawableComponent->ToString().compare(QString("Free Hand"))==0)
        {
            QJsonObject object;
            tmFreeHandComponent=(TMFreeHandComponent*)drawableComponent;
            object.insert(QString("drawingType"),QJsonValue(QString(tmFreeHandComponent->ToString())));
            object.insert(QString("oldX"),QJsonValue(tmFreeHandComponent->getOldX()));
            object.insert(QString("oldY"),QJsonValue(tmFreeHandComponent->getOldY()));
            object.insert(QString("currentX"),QJsonValue(tmFreeHandComponent->getCurrentX()));
            object.insert(QString("currentY"),QJsonValue(tmFreeHandComponent->getCurrentY()));
            object.insert(QString("penColor"),QJsonValue(tmFreeHandComponent->getColor()));
            object.insert(QString("penWidth"),QJsonValue(tmFreeHandComponent->getPenWidth()));
            jsonArray.append(object);
        }
        else if(drawableComponent->ToString().compare(QString("Image"))==0)
        {
            QJsonObject object;
            tmImageComponent=(TMImageComponent*)drawableComponent;
            object.insert(QString("drawingType"),QJsonValue(tmImageComponent->ToString()));
            object.insert(QString("path"),QJsonValue(tmImageComponent->getPath()));
            object.insert(QString("imageStartPointX"),QJsonValue(tmImageComponent->getImageStartPoint()->x()));
            object.insert(QString("imageStartPointY"),QJsonValue(tmImageComponent->getImageStartPoint()->y()));
            jsonArray.append(object);

        }
    }
    QJsonDocument jsonDocument(jsonArray);
    file.write(jsonDocument.toJson());
    file.close();
    QWidget::update();
}

void MainWindow::on_openButton_clicked()
{
    openFileName=QFileDialog::getOpenFileName(this,QString("Open"),tr("*.ptr"));
    if(openFileName==NULL) return;
    //tmModel->loadData(openFileName);
    QFile file(openFileName);
    file.open(QFile::ReadOnly);
    QString value=file.readAll();
    file.close();
    QJsonDocument jsonDocument=QJsonDocument::fromJson(value.toUtf8());
    QJsonArray jsonArray=jsonDocument.array();
    for(QJsonValue value: jsonArray)
    {
        QJsonObject object(value.toObject());
        if(object.value(QString("drawingType")).toString().compare(QString("Circle"))==0)
        {
            tmFreeCircleComponent=new TMFreeCircleComponent;
            tmFreeCircleComponent->setCenterPointX(object.value(QString("centerPointX")).toInt());
            tmFreeCircleComponent->setCenterPointY(object.value(QString("centerPointY")).toInt());
            tmFreeCircleComponent->setRadius(object.value(QString("radius")).toInt());
            tmFreeCircleComponent->setColor(object.value(QString("penColor")).toString());
            tmFreeCircleComponent->setPenWidth(object.value(QString("penWidth")).toInt());
            tmModel->componentList->push_back(tmFreeCircleComponent);
            item=new QListWidgetItem(QString("Circle"));
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            this->ui->drawingList->insertItem(0,item);
        }
        else if(object.value(QString("drawingType")).toString().compare(QString("Line"))==0)
        {
            tmFreeLineComponent=new TMFreeLineComponent;
            tmFreeLineComponent->setStartX(object.value(QString("startX")).toInt());
            tmFreeLineComponent->setStartY(object.value(QString("startY")).toInt());
            tmFreeLineComponent->setEndX(object.value(QString("endX")).toInt());
            tmFreeLineComponent->setEndY(object.value(QString("endY")).toInt());
            tmFreeLineComponent->setColor(object.value(QString("penColor")).toString());
            tmFreeLineComponent->setPenWidth(object.value(QString("penWidth")).toInt());
            tmModel->componentList->push_back(tmFreeLineComponent);
            item=new QListWidgetItem(QString("Line"));
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            this->ui->drawingList->insertItem(0,item);
        }
        else if(object.value(QString("drawingType")).toString().compare(QString("Rectangle"))==0)
        {
            tmFreerectangleComponent=new TMFreeRectangleComponent;
            tmFreerectangleComponent->setStartX(object.value(QString("startX")).toInt());
            tmFreerectangleComponent->setStartY(object.value(QString("startY")).toInt());
            tmFreerectangleComponent->setEndX(object.value(QString("endX")).toInt());
            tmFreerectangleComponent->setEndY(object.value(QString("endY")).toInt());
            tmFreerectangleComponent->setColor(object.value(QString("penColor")).toString());
            tmFreerectangleComponent->setPenWidth(object.value(QString("penWidth")).toInt());
            tmModel->componentList->push_back(tmFreerectangleComponent);
            item=new QListWidgetItem(QString("Rectangle"));
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            this->ui->drawingList->insertItem(0,item);
        }
        else if(object.value(QString("drawingType")).toString().compare(QString("Free Hand"))==0)
        {
            tmFreeHandComponent=new TMFreeHandComponent;
            tmFreeHandComponent->setOldX(object.value(QString("oldX")).toInt());
            tmFreeHandComponent->setOldY(object.value(QString("oldY")).toInt());
            tmFreeHandComponent->setCurrentX(object.value(QString("currentX")).toInt());
            tmFreeHandComponent->setCurrentY(object.value(QString("currentY")).toInt());
            tmFreeHandComponent->setColor(object.value(QString("penColor")).toString());
            tmFreeHandComponent->setPenWidth(object.value(QString("penWidth")).toInt());
            tmModel->componentList->push_back(tmFreeHandComponent);
            item=new QListWidgetItem(QString("Free Hand"));
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            this->ui->drawingList->insertItem(0,item);
        }
        else if(object.value(QString("drawingType")).toString().compare(QString("Image"))==0)
        {
            tmImageComponent=new TMImageComponent;
            QString path=object.value(QString("path")).toString();
            tmImageComponent->setPath(path);
            tmImageComponent->setPixmap(new QPixmap(path));
            QPoint *imageStartPoint=new QPoint;
            imageStartPoint->setX(object.value(QString("imageStartPointX")).toInt());
            imageStartPoint->setY(object.value(QString("imageStartPointY")).toInt());
            tmImageComponent->setImageStartPoint(imageStartPoint);
            tmModel->componentList->push_back(tmImageComponent);
            item=new QListWidgetItem(QString("Image"));
            item->setFlags(item->flags() | Qt::ItemIsEditable);
            this->ui->drawingList->insertItem(0,item);
        }
    }
    QWidget::update();
}

void MainWindow::on_deleteButton_clicked()
{
    if(selectedComponentList!=NULL)
    {
        for(DrawableComponent* d: *selectedComponentList)
        {
            tmModel->componentList->removeAt(tmModel->componentList->indexOf(d));
            this->ui->drawingList->takeItem(tmModel->componentList->indexOf(d)-tmModel->componentList->size()+1);
        }
        selectedComponentList->clear();
        tmFreeLineComponent=NULL;
        tmFreeCircleComponent=NULL;
        tmFreerectangleComponent=NULL;
        QWidget::update();
    }
}
void MainWindow::on_drawHorizontalLinesButton_clicked()
{
    if(tmModel->drawLines==false)tmModel->drawLines=true;
    else tmModel->drawLines=false;
    QWidget::update();
}

void MainWindow::on_mathSymbolsButton_clicked()
{
    if(this->ui->mathSymbolsPanel->isVisible())this->ui->mathSymbolsPanel->setVisible(false);
    else this->ui->mathSymbolsPanel->setVisible(true);
}


void MainWindow::on_imageButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QFileDialog::getOpenFileName(this,QString("Open"),QString("*.png ;; *.jpg"));
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QListWidgetItem *item=new QListWidgetItem(QString("Image"));
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    this->ui->drawingList->insertItem(0,item);
    QWidget::update();
}

void MainWindow::on_piButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/piSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();
}

void MainWindow::on_mathSymbolPanelCrossButton_clicked()
{
    this->ui->mathSymbolsPanel->setVisible(false);
}

void MainWindow::on_thethaButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/thethaSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_omegaButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/omegaSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_percentageButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/percentageSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_alphaButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/alphaSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_betaButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/betaSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_gammaButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/gammaSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_deltaButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/deltaSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_infiniteButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/infiniteSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_rootButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/rootSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_integralButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/integralSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_hashButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/hashSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_submattionButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/submattionSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_lembdaButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/lembdaSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_leftBracketButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/leftBracketSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();

}

void MainWindow::on_rightBracketButton_clicked()
{
    this->pickFlag=false;
    QString imagePath=QString(":/images/rightBracketSymbol.png");
    tmImageComponent=new TMImageComponent();
    QPixmap *pixmap;
    pixmap=new QPixmap(imagePath);
    tmImageComponent->setPixmap(pixmap);
    tmImageComponent->setPath(imagePath);
    QPoint *point=new QPoint((725)-(pixmap->width()/2)+240,(450-(pixmap->height())/2)+50);
    tmImageComponent->setImageStartPoint(point);
    tmModel->addComponentToDS(this->tmImageComponent);
    QWidget::update();
}

void MainWindow::on_blackButton_clicked()
{
    this->penColor=QString("Black");
}

void MainWindow::on_blueButton_clicked()
{
    this->penColor=QString("Blue");
}

void MainWindow::on_redButton_clicked()
{
    this->penColor=QString("Red");
}

void MainWindow::on_orangleButton_clicked()
{
    this->penColor=QString("Orange");
}

void MainWindow::on_yellowButton_clicked()
{
    this->penColor=QString("Yellow");
}
void MainWindow::on_purpleButton_clicked()
{
    this->penColor=QString("Purple");
}
void MainWindow::on_greyButton_clicked()
{
    this->penColor=QString("Grey");
}
void MainWindow::on_greenButton_clicked()
{
    this->penColor=QString("Green");
}
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    this->penWidth=value;
}
void MainWindow::on_drawingList_itemClicked(QListWidgetItem *item)
{
    itemIndex=this->ui->drawingList->row(item);
    QWidget::update();
}
void MainWindow::on_clearButton_clicked()
{
    tmModel->componentList->clear();
    this->tmFreeLineComponent=nullptr;
    this->tmFreeCircleComponent=nullptr;
    this->tmFreeHandComponent=nullptr;
    this->tmImageComponent=nullptr;
    this->tmFreerectangleComponent=nullptr;
    this->ui->drawingList->clear();
    QWidget::update();
}
