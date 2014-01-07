#ifndef BROWSERWINDOW_H
#define BROWSERWINDOW_H

#include <QMainWindow>

namespace Ui {
    class BrowserWindow;
}

class BrowserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BrowserWindow(QWidget *parent = 0);
    ~BrowserWindow();

private:
    Ui::BrowserWindow *ui;
};

#endif // BROWSERWINDOW_H
