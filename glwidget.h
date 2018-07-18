#ifndef GLWIDGET_H
#define GLWIDGET_H
#include <QGLWidget>
#include <QObject>
#include <QtOpenGL/QGLWidget>
#include <QMouseEvent>
#include <QList>
#include <cmath>
#include <QDebug>
#include <QPair>
#include <QWidget>
#include "drawtools.h"


class GLWidget : public QGLWidget
{
    Q_OBJECT


private:
    QList<Object> objects; //list of list of points points
    QPoint lastPos;
    Pencil *currentTool;
    Circle *circleTool;
    Rect *rectTool;
    Line *lineTool;
    Triangle *triTool;
    QColor bgcolor;


public:
    explicit GLWidget(QWidget *parent=0);
    void resizeGL(int w,int h);
    void initializeGL();
    void paintGL();
    float lWidth;
    float lWidthLine;
    float pointSize;
    float LineWidthRect;
    float LineWidthTri;
    bool usePencil = true, useLine = false,useCircle = false,useRect = false,useTriangle = false, clearClicked = false;



protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


};

#endif // GLWIDGET_H
