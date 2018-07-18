#include "drawtools.h"
#include <vector>
#include <QDebug>
#include <GL/gl.h>

using namespace std;




//pencil functions
float Pencil::getLineWidth()
{
    return LineWidth;
}

void Pencil::setLineWidth(float value)
{
    LineWidth = value;
}

vector<vector<GLint> > Pencil::getNewpoints() const
{
    return newpoints;
}

void Pencil::setNewpoints(const vector<vector<GLint> > &value)
{
    newpoints = value;
}

Pencil::Pencil()
    : DrawTool()
{
    color = QColor(0, 0, 0);
}

void Pencil::startDrawing(GLint x, GLint y) {

    //add linewidth , x y coordinates to list
    this->points.push_back((int)LineWidth);
    newLineWidth = points[0];
    this->points.push_back(x);
    this->points.push_back(y);




}

void Pencil::update(GLint x, GLint y) {
    //add x,y coordinates as cursor move
    this->points.push_back(x);
    this->points.push_back(y);

}

void Pencil::stopDrawing(GLint x, GLint y) {
    //push our points list to list of points
    newpoints.push_back(points);
    points.clear(); //clear the points

}

void Pencil::drawTemporary()
{
    glLineWidth(newLineWidth);
    //qDebug()<<newLineWidth;
    glBegin(GL_LINE_STRIP);
    for(unsigned int i=1;i<points.size();i+=2)
    {

        glVertex2d(points[i+0],points[i+1]);


    }
   // qDebug()<<points.size()<<endl;
     glEnd();


}
void Pencil::drawRemaining()
{
        glColor3ub( 0, 0, 0 );
        for(unsigned int i =0;i<newpoints.size();i++)
        {
            newLineWidthRemaining = newpoints[i][0];
            glLineWidth(newLineWidthRemaining);
            glBegin( GL_LINE_STRIP);

            for(unsigned int j=1;j<newpoints[i].size();j+=2)
            {
                glVertex2f(newpoints[i][j+0],newpoints[i][j+1]);
            }
            //temp.clear();
            glEnd();

        }
}
//line functions
vector<vector<GLint> > Line::getNewpoints() const
{
    return newpoints;
}

void Line::setNewpoints(const vector<vector<GLint> > &value)
{
    newpoints = value;
}

Line::Line() :DrawTool()
{
    color = QColor(0, 0, 0);
}
void Line::startDrawing(GLint x, GLint y) {

    //add linewidth , x y coordinates to list
    this->points.push_back((int)LineWidth);
    newLineWidth = points[0];
    this->points.push_back(x);
    this->points.push_back(y);




}

void Line::update(GLint x, GLint y) {
    //add x,y coordinates as cursor move
    this->points.push_back(x);
    this->points.push_back(y);

}

void Line::stopDrawing(GLint x, GLint y) {
    //push our points list to list of points
    newpoints.push_back(points);
    points.clear(); //clear the points

}

void Line::drawTemporary()
{
    glLineWidth(newLineWidth);
    //qDebug()<<newLineWidth;
    glBegin(GL_LINE_STRIP);

    if(points.size()>4)
    {
        glVertex2d(points[1],points[2]);
        glVertex2d(points[points.size()-2],points[points.size()-1]);
    }



     glEnd();


}
void Line::drawRemaining()
{
        glColor3ub( 0, 0, 0 );

        for(unsigned int i =0;i<newpoints.size();i++)
        {

            newLineWidthRemaining = newpoints[i][0];
            glLineWidth(newLineWidthRemaining);
            glBegin( GL_LINE_STRIP);
            //qDebug()<<newpoints[i][0]<<" "<<newpoints[i][1];

            glVertex2f(newpoints[i][1],newpoints[i][2]); //start points of list
            //glVertex2f(30,30);
            glVertex2f(newpoints[i][newpoints[i].size()-2],newpoints[i][newpoints[i].size()-1]); //end points of list
           // qDebug()<<newpoints[i][newpoints[i].size()-2]<<" "<<newpoints[i][newpoints[i].size()-1];




            //temp.clear();
            glEnd();

        }
}

float Line::getLineWidth()
{
    return Line::LineWidth;
}

void Line::setLineWidth(float value)
{
    LineWidth = value;
}

//circle

float Circle::getLineWidth()
{
    return LineWidth;
}

void Circle::setLineWidth(float value)
{
    LineWidth = value;
}

vector<vector<GLint> > Circle::getNewpoints() const
{
    return newpoints;
}

void Circle::setNewpoints(const vector<vector<GLint> > &value)
{
    newpoints = value;
}

Circle::Circle()
    : DrawTool()
{
    color = QColor(0, 0, 0);
}

void Circle::startDrawing(GLint x, GLint y) {

    //add linewidth , x y coordinates to list
    this->points.push_back((int)LineWidth);
    newLineWidth = points[0];
    this->points.push_back(x);
    this->points.push_back(y);




}

void Circle::update(GLint x, GLint y) {
    //add x,y coordinates as cursor move
    this->points.push_back(x);
    this->points.push_back(y);

}

void Circle::stopDrawing(GLint x, GLint y) {
    //push our points list to list of points
    newpoints.push_back(points);
    points.clear(); //clear the points

}

void Circle::drawTemporary()
{
    glPointSize(newLineWidth);
    //qDebug()<<newLineWidth;
    //glBegin(GL_LINE_STRIP);

    if(points.size()>4)
    {
        int x1 = points[1];
        int x2 = points[points.size()-2];
        int y1 = points[2];
        int y2 = points[points.size()-1];

    radius = findRadius(x1,x2,y1,y2);
    Circle::drawMidPoint(x1,y1,radius);
    }


     //glEnd();


}
void Circle::drawRemaining()
{
        glColor3ub( 0, 0, 0 );
        for(unsigned int i =0;i<newpoints.size();i++)
        {

            newLineWidthRemaining = newpoints[i][0];
            glPointSize(newLineWidthRemaining);
            if(newpoints[i].size()>4)
            {

            int x1 = newpoints[i][1];
            int x2 = newpoints[i][newpoints[i].size()-2];
            int y1 = newpoints[i][2];
            int y2 = newpoints[i][newpoints[i].size()-1];
            float rad = findRadius(x1,x2,y1,y2);

             drawMidPoint(x1,y1,rad);
            }

            //temp.clear();


        }

}

void Circle::drawMidPoint(float xCenter, float yCenter, float radius)
{



        int x = 0;
        int y = radius;
        int p = 5/4 - radius;//5/4 is rounded to 1 for integer radius

         while(x<y)  {// iterates to draw the first sector
            x++;
             if(p < 0)// the mid point is inside the circle
             {

                  p += 2*x + 1;
             }
             else {// the mid point is outside or at the circle
                  y--;
                  p += 2 * (x - y) + 1;
             }
         glBegin(GL_POINTS);
             glVertex2i(xCenter + x, yCenter + y);
             glVertex2i(xCenter - x, yCenter + y);
             glVertex2i(xCenter + x, yCenter - y);
             glVertex2i(xCenter - x, yCenter - y);
             glVertex2i(xCenter + y, yCenter + x);
             glVertex2i(xCenter - y, yCenter + x);
             glVertex2i(xCenter + y, yCenter - x);
             glVertex2i(xCenter - y, yCenter - x);
         glEnd();
         }

}

void Circle::drawCircle(float xCircle, float yCircle)
{


}
//rect
vector<vector<GLint> > Rect::getNewpoints() const
{
    return newpoints;
}

void Rect::setNewpoints(const vector<vector<GLint> > &value)
{
    newpoints = value;
}

Rect::Rect() :DrawTool()
{
    color = QColor(0, 0, 0);
}
void Rect::startDrawing(GLint x, GLint y) {

    //add linewidth , x y coordinates to list
    this->points.push_back((int)LineWidth);
    newLineWidth = points[0];
    this->points.push_back(x);
    this->points.push_back(y);




}

void Rect::update(GLint x, GLint y) {
    //add x,y coordinates as cursor move
    this->points.push_back(x);
    this->points.push_back(y);

}

void Rect::stopDrawing(GLint x, GLint y) {
    //push our points list to list of points
    newpoints.push_back(points);
    points.clear(); //clear the points

}

void Rect::drawTemporary()
{
    glLineWidth(newLineWidth);
    //qDebug()<<newLineWidth;
//    glBegin(GL_LINE_STRIP);

//    if(points.size()>4)
//    {
//        glVertex2d(points[1],points[2]);
//        glVertex2d(points[points.size()-2],points[points.size()-1]);
//    }

    if(points.size()>4)
    {
        glBegin(GL_LINE_LOOP);
   // glRectd(points[1],points[2],points[points.size()-2],points[points.size()-1]);
        float x1 = points[1];
        float x2 = points[points.size()-2];
        float y1 = points[2];
        float y2 = points[points.size()-1];

        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
        glEnd();
    }




     //glEnd();


}
void Rect::drawRemaining()
{
        glColor3ub( 0, 0, 0 );

        for(unsigned int i =0;i<newpoints.size();i++)
        {

            newLineWidthRemaining = newpoints[i][0];
            glLineWidth(newLineWidthRemaining);
            if(newpoints[i].size()>4)
            {
            glBegin( GL_LINE_LOOP);
            float x1 = newpoints[i][1];
            float x2 = newpoints[i][newpoints[i].size()-2];
            float y1 = newpoints[i][2];
            float y2 = newpoints[i][newpoints[i].size()-1];

            glVertex2f(x1, y1);
            glVertex2f(x2, y1);
            glVertex2f(x2, y2);
            glVertex2f(x1, y2);
            glEnd();

            }



            //temp.clear();


        }
}

float Rect::getLineWidth()
{
    return Rect::LineWidth;
}

void Rect::setLineWidth(float value)
{
    LineWidth = value;
}

//triangle

Triangle::Triangle() :DrawTool()
{
    color = QColor(0, 0, 0);
}
void Triangle::startDrawing(GLint x, GLint y) {

    //add linewidth , x y coordinates to list
    this->points.push_back((int)LineWidth);
    newLineWidth = points[0];
    this->points.push_back(x);
    this->points.push_back(y);




}

void Triangle::update(GLint x, GLint y) {
    //add x,y coordinates as cursor move
    this->points.push_back(x);
    this->points.push_back(y);

}

void Triangle::stopDrawing(GLint x, GLint y) {
    //push our points list to list of points
    newpoints.push_back(points);
    points.clear(); //clear the points

}

void Triangle::drawTemporary()
{
    glLineWidth(newLineWidth);
    //qDebug()<<newLineWidth;


    if(points.size()>4)
    {
        glBegin(GL_TRIANGLES);
        int x1 = points[1];
        int y1 = points[2];
        int x2 = points[points.size()-2];
        int y2 = points[points.size()-1];
        int midX = points[1];
        int midY = points[points.size()-1];
        int x3 = midX- (x2-midX);
        int y3 = points[points.size()-1];

        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glEnd();

    }







}
void Triangle::drawRemaining()
{
        glColor3ub( 0, 0, 0 );

        for(unsigned int i =0;i<newpoints.size();i++)
        {


            newLineWidthRemaining = newpoints[i][0];
            glLineWidth(newLineWidthRemaining);


            glBegin(GL_TRIANGLES);
            int x1 = newpoints[i][1];
            int y1 = newpoints[i][2];
            int x2 = newpoints[i][newpoints[i].size()-2];
            int y2 = newpoints[i][newpoints[i].size()-1];
            int midX = newpoints[i][1];
            int midY = newpoints[i][newpoints[i].size()-1];
            int x3 = midX- (x2-midX);
            int y3 = newpoints[i][newpoints[i].size()-1];
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glEnd();

        }
}

float Triangle::getLineWidth()
{
    return Triangle::LineWidth;
}

void Triangle::setLineWidth(float value)
{
    LineWidth = value;
}



