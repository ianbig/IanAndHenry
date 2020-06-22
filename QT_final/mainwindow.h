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

private slots:
    void on_client1_switch_clicked();

    void on_client2_switch_clicked();

    void on_client3_switch_clicked();

private:
    int total_url_len;
    int total_url_cnt;
    Ui::MainWindow *ui;
    bool flag; // first set
    void setTime(std::tm*);
    void setProgress(std::tm*);
    void setServerInfo(std::tm*);
    void setWorkload();
    void setWebsite();
    void setClientInfo(std::tm*);
    QString date2qstring(std::tm*);
    QString time2qstring(std::tm*);
    void A_state_change();
    void B_state_change();
    void C_state_change();
};
#endif // MAINWINDOW_H
