//#include <QtCore>
//#include <QtGui>
#include "onyx/sys/sys_status.h"
#include "mwo_application.h"        // 本应用对象
#include "mwo_logger.h"             // 日志

int main(int argc, char * argv[])
{
    logger.log("ENTER main()");

    sys::SysStatus::instance().setSystemBusy(false);    // set system not busy via D-BUS. see onyx/sys/service.h
    
    MwoApplication game(argc, argv);
    game.start();

    logger.log("ENTER game.exec()");
    int ret = game.exec();                              // main loop
    logger.log("LEAVE game.exec()");

    logger.log("LEAVE main()");
    return ret;
}
