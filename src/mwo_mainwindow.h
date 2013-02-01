#ifndef MWO_VIEW_H_
#define MWO_VIEW_H_

#include <QtGui/QtGui>
#include "onyx/ui/ui.h"
#include "onyx/ui/status_bar.h"
#include "onyx/ui/ui_utils.h"
#include "onyx/screen/screen_proxy.h"

using namespace ui;

class MwoMainwindow : public QWidget
{
    Q_OBJECT

public:
    MwoMainwindow(QWidget *parent = 0);
    ~MwoMainwindow();

public:
    bool start();
    bool stop();
    bool exec(const QStringList & args);

protected:
    virtual void mousePressEvent(QMouseEvent*);
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *ke);
    virtual void closeEvent(QCloseEvent * event);
    virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual void paintEvent(QPaintEvent *);

private Q_SLOTS:
    void OnTimer();

private:
    QTimer      timer_;
    StatusBar*  status_bar_;
};


#endif
