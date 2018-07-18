#ifndef DRAWTOOLS_H
#define DRAWTOOLS_H
#include<QColor>
#include <QDebug>
#include "common.h"
#include <vector>
#include <cmath>
using namespace std;


class DrawTool
{
public:
    //function of tools
    virtual void startDrawing(GLint x, GLint y) = 0;
    virtual void update(GLint x, GLint y) = 0;
    virtual void stopDrawing(GLint x, GLint y) = 0;
    virtual void drawTemporary() {}
    virtual void drawRemaining() {}
    ~DrawTool() {}
};

//Pencil is a subclass of tools
class Pencil: public DrawTool
{
private:
    //color of tool

    QColor color;
    Object temp;
    vector< GLint > points;



    float LineWidth=3;
    float newLineWidth=3;
    float newLineWidthRemaining=3;
    float LineWidthCircle = 3;


public:
    Pencil();
    ~Pencil() {}
    void startDrawing(GLint x, GLint y); //drawing
    void update(GLint x, GLint y); //update
    void stopDrawing(GLint x, GLint y); //stop drawing
    void drawTemporary(); //temporary draw
    void drawRemaining();
    vector<vector<GLint> > newpoints;




   // vector<vector<GLint> > getNewpoints() const;

    float getLineWidth();
    void setLineWidth(float value);
    vector<vector<GLint> > getNewpoints() const;
    void setNewpoints(const vector<vector<GLint> > &value);
};
class Line: public DrawTool
{
private:
    //color of tool

    QColor color;
    Object temp;
    vector< GLint > points;


    float LineWidth=3;
    float newLineWidth=3;
    float newLineWidthRemaining=3;

public:
    Line();
    ~Line() {}
    void startDrawing(GLint x, GLint y); //drawing
    void update(GLint x, GLint y); //update
    void stopDrawing(GLint x, GLint y); //stop drawing
    void drawTemporary(); //temporary draw
    void drawRemaining();
    vector<vector<GLint> > newpoints;



   // vector<vector<GLint> > getNewpoints() const;

    float getLineWidth();
    void setLineWidth(float value);
    vector<vector<GLint> > getNewpoints() const;
    void setNewpoints(const vector<vector<GLint> > &value);
};
class Circle: public DrawTool
{
private:
    //color of tool

    QColor color;
    Object temp;
    vector< GLint > points;


    float LineWidth=3;
    float newLineWidth=3;
    float newLineWidthRemaining=3;
    float radius=1;

public:
    Circle();
    ~Circle() {}
    void startDrawing(GLint x, GLint y); //drawing
    void update(GLint x, GLint y); //update
    void stopDrawing(GLint x, GLint y); //stop drawing
    void drawTemporary(); //temporary draw
    void drawRemaining();
    void drawMidPoint(float xCenter,float yCenter,float radius);
    void drawCircle(float xCircle,float yCircle);
    vector<vector<GLint> > newpoints;



   // vector<vector<GLint> > getNewpoints() const;

    float getLineWidth();
    void setLineWidth(float value);
    float findRadius(int x1, int x2,int y1, int y2)
    {
        return sqrt((pow(y2-y1,2)+pow(x2-x1,2)));
    }

    vector<vector<GLint> > getNewpoints() const;
    void setNewpoints(const vector<vector<GLint> > &value);
};
class Rect: public DrawTool
{
private:
    //color of tool

    QColor color;
    Object temp;
    vector< GLint > points;


    float LineWidth=3;
    float newLineWidth=3;
    float newLineWidthRemaining=3;

public:
    Rect();
    ~Rect() {}
    void startDrawing(GLint x, GLint y); //drawing
    void update(GLint x, GLint y); //update
    void stopDrawing(GLint x, GLint y); //stop drawing
    void drawTemporary(); //temporary draw
    void drawRemaining();
    vector<vector<GLint> > newpoints;



   // vector<vector<GLint> > getNewpoints() const;

    float getLineWidth();
    void setLineWidth(float value);
    vector<vector<GLint> > getNewpoints() const;
    void setNewpoints(const vector<vector<GLint> > &value);
};
class Triangle: public DrawTool
{
private:
    //color of tool

    QColor color;
    Object temp;
    vector< GLint > points;


    float LineWidth=3;
    float newLineWidth=3;
    float newLineWidthRemaining=3;

public:
    Triangle();
    ~Triangle() {}
    void startDrawing(GLint x, GLint y); //drawing
    void update(GLint x, GLint y); //update
    void stopDrawing(GLint x, GLint y); //stop drawing
    void drawTemporary(); //temporary draw
    void drawRemaining();
    vector<vector<GLint> > newpoints;



   // vector<vector<GLint> > getNewpoints() const;

    float getLineWidth();
    void setLineWidth(float value);
    vector<vector<GLint> > getNewpoints() const;
    void setNewpoints(const vector<vector<GLint> > &value);
};


#endif // DRAWTOOLS_H
