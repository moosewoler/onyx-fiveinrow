#include <sys/time.h>
#include <QtGui/QtGui>
#include "onyx/screen/screen_update_watcher.h"
#include "onyx/sys/sys_status.h"
#include "onyx/sys/platform.h"
#include "onyx/data/configuration.h"
#include "mwo_mainwindow.h"
#include "mwo_logger.h"

MwoMainwindow::MwoMainwindow(QWidget *parent)
    : QWidget(0, Qt::FramelessWindowHint)
{
    logger.log("ENTER MwoMainwindow:MwoMainwindow().");

    //setWindowTitle(QCoreApplication::tr("Five In Row"));

    ////setAutoFillBackground(true);
    ////setBackgroundRole(QPalette::Base);
    ////gomoku = new GomokuWidget(this);

    //// set up status bar
    //status_bar_ = new StatusBar(this, MENU |CONNECTION | BATTERY | MESSAGE | CLOCK | SCREEN_REFRESH);
    //status_bar_->setFocusPolicy(Qt::NoFocus);
    ////connect(status_bar_, SIGNAL(menuClicked()), this, SLOT(showMenu()));

    //// set up vertical layout
    //QVBoxLayout *layout = new QVBoxLayout;
    //layout->setMargin(0);
    //layout->addWidget(status_bar_);
    //setLayout(layout);

    //// set up popup menu to long press screen
    ////SysStatus & sys_status = SysStatus::instance();
    ////connect( &sys_status, SIGNAL( mouseLongPress(QPoint, QSize) ), gomoku, SLOT( onMouseLongPress(QPoint, QSize) ) );
    ////connect( gomoku, SIGNAL( popupMenu() ), this, SLOT( showMenu() ) );
    
    // set up screen watcher and refresh
    onyx::screen::watcher().addWatcher(this);
    update();
    onyx::screen::watcher().enqueue(this, onyx::screen::ScreenProxy::GC);

    logger.log("LEAVE MwoMainwindow:MwoMainwindow().");
}

MwoMainwindow::~MwoMainwindow()
{
    logger.log("ENTER MwoMainwindow:~MwoMainwindow().");
    logger.log("LEAVE MwoMainwindow:~MwoMainwindow().");
}

void MwoMainwindow::keyPressEvent(QKeyEvent *e)
{
    logger.log("ENTER MwoMainwindow:keyPressEvent().");
    switch (e->key())
    {
    case Qt::Key_Down:
    case Qt::Key_Up:
        break;
    default:
        QWidget::keyPressEvent(e);
        break;
    }
    e->accept();
    logger.log("LEAVE MwoMainwindow:keyPressEvent().");
}

void MwoMainwindow::keyReleaseEvent(QKeyEvent *ke)
{
    logger.log("ENTER MwoMainwindow:keyReleaseEvent().");
    switch (ke->key())
    {
    case ui::Device_Menu_Key:
        logger.log(QString("INFO  Device_Menu_Key pressed."));
        break;
    case Qt::Key_Left:
        logger.log(QString("INFO  Key_Left pressed."));
        break;
    case Qt::Key_Right:
        logger.log(QString("INFO  Key_Right pressed."));
        break;
    case Qt::Key_PageDown:
        logger.log(QString("INFO  Key_PageDown pressed."));
        break;
    case Qt::Key_Down:
        logger.log(QString("INFO  Key_Down pressed."));
        break;
    case Qt::Key_PageUp:
        break;
    case Qt::Key_Up:
        logger.log(QString("INFO  Key_Up pressed."));
        break;
    case Qt::Key_C:
        logger.log(QString("INFO  Key_C pressed."));
        break;
    case Qt::Key_Escape:
    case Qt::Key_Home:
        logger.log(QString("INFO  Key_Home pressed."));
        stop();
    default:
        logger.log(QString("INFO  unknown key pressed."));
        QWidget::keyReleaseEvent(ke);
        break;
    }
    ke->ignore();
    logger.log("LEAVE MwoMainwindow:keyReleaseEvent().");
}

void MwoMainwindow::closeEvent(QCloseEvent * event)
{
    logger.log("ENTER MwoMainwindow:closeEvent().");
    QWidget::closeEvent(event);
    logger.log("LEAVE MwoMainwindow:closeEvent().");
}

void MwoMainwindow::mousePressEvent(QMouseEvent*me)
{
    logger.log("ENTER MwoMainwindow:mousePressEvent().");
    //me->accept();
    logger.log("LEAVE MwoMainwindow:mousePressEvent().");
}

bool MwoMainwindow::eventFilter(QObject *obj, QEvent *e)
{
    logger.log("ENTER MwoMainwindow:eventFilter().");

    qDebug("Select event:%d", e->type());
    if (e->type() == QEvent::MouseButtonRelease && obj->isWidgetType())
    {
        onyx::screen::instance().updateWidget(0, onyx::screen::ScreenProxy::GU);
    }

    logger.log("LEAVE MwoMainwindow:eventFilter().");
    return QObject::eventFilter(obj, e);
}

void MwoMainwindow::paintEvent(QPaintEvent *e)
{
    logger.log("ENTER MwoMainwindow:paintEvent().");
    logger.log("LEAVE MwoMainwindow:paintEvent().");
}

bool MwoMainwindow::start()
{
    logger.log("ENTER MwoMainwindow:start().");
    logger.log("LEAVE MwoMainwindow:start().");
    return true;
}

bool MwoMainwindow::stop()
{
    logger.log("ENTER MwoMainwindow:stop().");
    qApp->exit();
    logger.log("LEAVE MwoMainwindow:stop().");
    return true;
}

bool MwoMainwindow::exec(const QStringList & args)
{
    logger.log("ENTER MwoMainwindow:exec().");
    logger.log("LEAVE MwoMainwindow:exec().");
    return true;
}

void MwoMainwindow::OnTimer()
{
    logger.log("ENTER MwoMainwindow:OnTimer().");
    logger.log("LEAVE MwoMainwindow:OnTimer().");
}
