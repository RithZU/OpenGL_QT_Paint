#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_pencil_clicked();

    void on_btn_line_clicked();

    void on_sb_size_valueChanged(double arg1);

    void on_btn_circle_clicked();

    void on_pushButton_2_clicked();

    void on_btn_rect_clicked();

    void on_btn_clear_clicked();

    void on_btn_triangle_clicked();

private:
    Ui::MainWindow *ui;
    QTimer timer;
};

#endif // MAINWINDOW_H
