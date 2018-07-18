#include "glwidget.h"
#include <vector>
#include <stdbool.h>
#include <QDebug>
using namespace std;

GLWidget::GLWidget(QWidget *parent):QGLWidget(parent)
{
    currentTool = new Pencil();
    lineTool = new Line();
    circleTool = new Circle();
    rectTool = new Rect();
    triTool = new Triangle();

   // Object obj; //list of points
    //objects.append(obj);
    this->lWidth = currentTool->getLineWidth();
    this->lWidthLine = lineTool->getLineWidth();
    this->pointSize = circleTool->getLineWidth();
    this->LineWidthRect = rectTool->getLineWidth();
    //this->LineWidthRect = triTool->getLineWidth();
    this->LineWidthTri = triTool->getLineWidth();




}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, h, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);


//    glDisable(GL_DEPTH_TEST);
//    glClearColor(1, 1, 1, 1);
//    w = width();
//    h = height();

//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();

//    glOrtho(0, w, h, 0, -1, 1);

//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();

}

void GLWidget::initializeGL()
{
    glClearColor(1,1,1,1);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0, 0, 0);
        //qDebug()<<GLWidget::usePencil<<" "<<GLWidget::useLine<<" "<<GLWidget::useCircle;

    lineTool->setLineWidth(this->lWidthLine);
        currentTool->setLineWidth(this->lWidth);
        currentTool->drawTemporary();
        currentTool->drawRemaining();

        lineTool->drawTemporary();
        lineTool->drawRemaining();

        circleTool->setLineWidth(this->pointSize);
        circleTool->drawTemporary();
        circleTool->drawRemaining();


        //circleTool->drawRemaining();

        rectTool->setLineWidth(this->LineWidthRect);
        rectTool->drawTemporary();
        rectTool->drawRemaining();

        if(clearClicked)
        {
            this->currentTool->newpoints.clear();
            this->lineTool->newpoints.clear();
            this->circleTool->newpoints.clear();
            this->rectTool->newpoints.clear();
            this->triTool->newpoints.clear();
            clearClicked = false;
        }
        triTool->setLineWidth(this->LineWidthRect);
        triTool->drawTemporary();
        triTool->drawRemaining();
        //qDebug()<<useRect;

}


void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if(GLWidget::usePencil==true)
    {
    if ((event->buttons() & Qt::LeftButton)) {

        currentTool->startDrawing(event->x(), event->y());

    }
    }
    else if(GLWidget::useLine==true)
    {
        if ((event->buttons() & Qt::LeftButton)) {

            lineTool->startDrawing(event->x(), event->y());

        }
    }
    else if(GLWidget::useCircle==true)
    {
        if ((event->buttons() & Qt::LeftButton)) {

            circleTool->startDrawing(event->x(), event->y());

        }
    }
    else if(GLWidget::useRect==true)
    {
        if ((event->buttons() & Qt::LeftButton)) {

            rectTool->startDrawing(event->x(), event->y());

        }
    }
    else if(GLWidget::useTriangle==true)
    {
        if ((event->buttons() & Qt::LeftButton)) {

            triTool->startDrawing(event->x(), event->y());

        }
    }


}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(GLWidget::usePencil==true)
    {
    this->currentTool->update(event->x(), event->y());
    }
    else if(GLWidget::useLine==true)
    {
        this->lineTool->update(event->x(), event->y());
    }
    else if(GLWidget::useCircle==true)
    {
        this->circleTool->update(event->x(), event->y());
    }
    else if(GLWidget::useRect==true)
    {
        this->rectTool->update(event->x(), event->y());
    }
    else if(GLWidget::useTriangle==true)
    {
        this->triTool->update(event->x(), event->y());
    }


}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(GLWidget::usePencil==true)
    {
    if (event->button() & Qt::LeftButton) {

        //this->objects.append(currentTool->stopDrawing(event->x(), event->y()));
       // this->objects.clear();
        currentTool->stopDrawing(event->x(), event->y());


    }
    }
    else if(GLWidget::useLine==true)
    {
    if (event->button() & Qt::LeftButton) {

        //this->objects.append(currentTool->stopDrawing(event->x(), event->y()));
       // this->objects.clear();
        lineTool->stopDrawing(event->x(), event->y());


    }
    }
    else if(GLWidget::useCircle==true)
    {
    if (event->button() & Qt::LeftButton) {

        //this->objects.append(currentTool->stopDrawing(event->x(), event->y()));
       // this->objects.clear();
        circleTool->stopDrawing(event->x(), event->y());


    }
    }
    else if(GLWidget::useRect==true)
    {
    if (event->button() & Qt::LeftButton) {

        //this->objects.append(currentTool->stopDrawing(event->x(), event->y()));
       // this->objects.clear();
        rectTool->stopDrawing(event->x(), event->y());


    }
    }
    else if(GLWidget::useTriangle==true)
    {
    if (event->button() & Qt::LeftButton) {

        //this->objects.append(currentTool->stopDrawing(event->x(), event->y()));
       // this->objects.clear();
        triTool->stopDrawing(event->x(), event->y());


    }
    }

}



