#include "windowcontroller.h"

#ifndef SERVER_CONSOLE
# include <QApplication>
#else
# include <QtCore>
#endif

int main(int argc, char *argv[])
{
#ifndef SERVER_CONSOLE
    QApplication a(argc, argv);
#else
    QCoreApplication a(argc, argv);
#endif
    WindowController c;
    c.load();

#ifndef SERVER_CONSOLE
    QApplication::setApplicationDisplayName("Mana Flow");
#endif

    QCoreApplication::setApplicationName("Mana Flow");

# ifndef BUILD_ID
    QCoreApplication::setApplicationVersion("0.0.1");
# else
    QCoreApplication::setApplicationVersion(QString("0.0.") + QString::number(BUILD_ID));
# endif

    return a.exec();
}
