#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QPainter>
#include<QList>
#include<tmfreerectanglecomponent.h>
#include<tmfreelinecomponent.h>
#include<tmfreecirclecomponent.h>
#include<tmfreehandcomponent.h>
#include<groupcomponent.h>
#include<tmimagecomponent.h>
#include<QKeyEvent>
#include<QFileDialog>
#include<QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class TMModel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent* mousePressEvent);
    virtual void mouseMoveEvent(QMouseEvent* mouseMoveEvent);
    virtual void mouseReleaseEvent(QMouseEvent* mouseReleaseEvent);
    virtual void mouseDoubleClickEvent(QMouseEvent* mouseClickedEvent);
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void keyReleaseEvent(QKeyEvent * event);

private slots:
    void on_freeHandButton_clicked();

    void on_freeLineButton_clicked();

    void on_freeRectangleButton_clicked();

    void on_freeCircleButton_clicked();

    void on_pickButton_clicked();

    void on_groupButton_clicked();

    void on_ungroupButton_clicked();


    void on_saveButton_clicked();

    void on_openButton_clicked();

    void on_deleteButton_clicked();

    void on_drawHorizontalLinesButton_clicked();
    void on_mathSymbolsButton_clicked();


    void on_imageButton_clicked();

    void on_piButton_clicked();

    void on_mathSymbolPanelCrossButton_clicked();

    void on_thethaButton_clicked();

    void on_omegaButton_clicked();

    void on_percentageButton_clicked();

    void on_alphaButton_clicked();

    void on_betaButton_clicked();

    void on_gammaButton_clicked();

    void on_deltaButton_clicked();

    void on_infiniteButton_clicked();

    void on_rootButton_clicked();

    void on_integralButton_clicked();

    void on_hashButton_clicked();

    void on_submattionButton_clicked();

    void on_lembdaButton_clicked();

    void on_leftBracketButton_clicked();

    void on_rightBracketButton_clicked();

    void on_blackButton_clicked();

    void on_blueButton_clicked();

    void on_redButton_clicked();

    void on_orangleButton_clicked();

    void on_yellowButton_clicked();

    void on_purpleButton_clicked();

    void on_greyButton_clicked();

    void on_greenButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_drawingList_itemClicked(QListWidgetItem *item);

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    QPainter* painter;
    TMModel *tmModel;
    QPen pen;
    TMFreeHandComponent* tmFreeHandComponent;
    TMFreeRectangleComponent* tmFreerectangleComponent;
    TMFreeLineComponent *tmFreeLineComponent;
    TMFreeCircleComponent* tmFreeCircleComponent;
    TMImageComponent * tmImageComponent;
    int oldX=-1;
    int oldY=-1;
    bool freeHandFlag=false;
    bool freeLineFlag=false;
    bool freeCircleFlag=false;
    bool freeRectangleFlag=false;
    bool circleSelection=false;
    bool rectangleSelection=false;
    bool lineSelection=false;
    bool pickFlag=false;
    bool clickedFlag=false;
    int clickedX=-1;
    int clickedY=-1;
    int c=0;
    int pickPressedX;
    int pickPressedY;
    int pickMovedX;
    int pickMovedY;
    DrawableComponent* draggedComponent;
    bool dragMoveFlag=false;
    QList<DrawableComponent* > *selectedComponentList;
    DrawableComponent * drawableComponent;
    bool ctrlFlag=false;
    GroupComponent *groupComponent;
    bool groupFlag=false;
    QString saveFileName;
    QString openFileName;
    bool drawImage=false;
    QPair<int,DrawableComponent*> pair;
    bool resizeFlag=false;
    DrawableComponent* resizableComponent;
    int diffX=0;
    int diffY=0;
    QString penColor;
    int penWidth;
    QListWidgetItem *item;
    int itemIndex=-1;
};
#endif // MAINWINDOW_H
