#include <QtCore>
#include <QtGui>
#include "onyx/sys/sys_status.h"
#include "mwo_application.h"        // 本应用对象
#include "mwo_logger.h"             // 日志

int main(int argc, char * argv[])
{
    logger.log("ENTER main()");
    MwoApplication game(argc, argv);
    game.setApplicationName("FiveInRow");

    sys::SysStatus::instance().setSystemBusy(false);
    
    game.start();
    int ret = game.exec();

    logger.log("LEAVE main()");
    return ret;
}
