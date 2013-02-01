#include "onyx/data/configuration.h"
#include "onyx/ui/languages.h"
#include "mwo_application.h"
#include "mwo_logger.h"


MwoApplication::MwoApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
    logger.log("ENTER MwoApplication:MwoApplication().");
    ui::loadTranslator(QLocale::system().name());
    QCoreApplication::setOrganizationName(QLatin1String("Onyx"));
    QCoreApplication::setApplicationName(QLatin1String("Mwo Application"));
    logger.log("LEAVE MwoApplication:MwoApplication().");
}

MwoApplication::~MwoApplication(void)
{
    logger.log("ENTER MwoApplication:~MwoApplication().");
    logger.log("LEAVE MwoApplication:~MwoApplication().");
}

bool MwoApplication::start()
{
    logger.log("ENTER MwoApplication:start().");
    main_window_.showMaximized();
    main_window_.start();
    logger.log("LEAVE MwoApplication:start().");
    return true;
}

bool MwoApplication::stop()
{
    logger.log("ENTER MwoApplication:stop().");
    logger.log("LEAVE MwoApplication:stop().");
    return true;
}
