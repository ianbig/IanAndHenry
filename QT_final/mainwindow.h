#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getTime();
public slots:
    void update();

private:
    Ui::MainWindow *ui;
    bool flag; // first set
    void setTime(std::tm*);
    void setProgress();
    void setServerInfo(std::tm*);
    void setWorkload();
    void setWebsite();
    void setClientInfo(std::tm*);
    QString date2qstring(std::tm*);
    QString time2qstring(std::tm*);
};
#endif // MAINWINDOW_H
