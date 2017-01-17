#include <QtCore>

#ifdef __RASPBERRY_PI_3__

#include "GPIOManager.h"

GPIO::GPIOManager *manager = NULL;

bool export_gpio(GPIO::GPIOManager* manager, unsigned int gpio)
{
    return (bool)(manager->exportPin(gpio) ? false : true);
}

bool unexport_gpio(GPIO::GPIOManager* manager, unsigned int gpio)
{
    return (bool)(manager->unexportPin(gpio) ? false : true);
}

bool getdir_gpio(GPIO::GPIOManager* manager, unsigned int gpio)
{
    int direction = manager->getDirection(gpio);

    if (direction == -1)
        return false;

    QString message = "Error, no direction found.";

    if (direction == GPIO::INPUT)
        message = "GPIO direction is: input.";
    else if (direction == GPIO::OUTPUT)
        message = "GPIO direction is: output.";

    qInfo() << message;

    return true;
}

bool setdir_gpio(GPIO::GPIOManager* manager, unsigned int gpio, unsigned int direction)
{
    if (direction > 1) {
        qInfo() << "Error, invalid gpio direction.";
        return false;
    }

    int result = manager->setDirection(gpio, (GPIO::DIRECTION)direction);

    if (result == -1)
        return false;

    qInfo() << "Ok.";

    return true;
}

bool getvalue_gpio(GPIO::GPIOManager* manager, unsigned int gpio)
{
    int value = manager->getValue(gpio);

    if (value == -1)
        return false;

    QString message = "Error, no direction found.";

    if (value == GPIO::HIGH)
        message = "GPIO  value is: high.";
    else if (value == GPIO::LOW)
        message = "GPIO value is: low.";

    qInfo() << message;

    return true;
}

bool setvalue_gpio(GPIO::GPIOManager* manager, unsigned int gpio, unsigned int value)
{
    if (value > 1) {
        qInfo() << "Error, invalid gpio value.";
        return false;
    }

    int result = manager->setValue(gpio, (GPIO::PIN_VALUE)value);

    if (result == -1)
        return false;

    qInfo() << "Ok.";

    return true;
}

#endif

void help()
{
    qInfo() << "usage: gpio-tester <command> <gpio number> [ optional parameters ]";
    qInfo() << "";
    qInfo() << "   commands:";
    qInfo() << "     - export";
    qInfo() << "     - unexport";
    qInfo() << "     - getdir";
    qInfo() << "     - setdir <value>";
    qInfo() << "     - getvalue";
    qInfo() << "     - setvalue <value>";
    qInfo() << "";
}

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);

    bool result = false;
    QStringList args;

    for (int i=0; i<argc; i++)
        args.append(QString(argv[i]));

    qInfo() << "";
    qInfo() << "Command: ";
    qInfo() << args.join(" ");
    qInfo() << "";
    if (argc >= 2) {
        if (QString(argv[1]) == QString("export")
         || QString(argv[1]) == QString("unexport")
         || QString(argv[1]) == QString("getdir")
         || QString(argv[1]) == QString("setdir")
         || QString(argv[1]) == QString("getvalue")
         || QString(argv[1]) == QString("setvalue"))
            qInfo() << "Valid command.";
        else
            qInfo() << "Invalid command";
    }
    if (argc >= 3) {
        bool ok;
        int gpio = QString(argv[2]).toUInt(&ok, 10);
        if (ok)
            qInfo() << "Valid gpio:" << QString::number(gpio);
        else
            qInfo() << "Invalid gpio.";
    }

#ifdef __RASPBERRY_PI_3__
    manager = GPIO::GPIOManager::getInstance();

    if (argc < 3) {
        help();
    }
    else if (QString(argv[1]) == QString("export") && argc == 3) {
        result = export_gpio(manager, QString(argv[2]).toUInt());
    }
    else if (QString(argv[1]) == QString("unexport") && argc == 3) {
        result = unexport_gpio(manager, QString(argv[2]).toUInt());
    }
    else if (QString(argv[1]) == QString("getdir") && argc == 3) {
        result = getdir_gpio(manager, QString(argv[2]).toUInt());
    }
    else if (QString(argv[1]) == QString("setdir") && argc == 4) {
        result = setdir_gpio(manager, QString(argv[2]).toUInt(), QString(argv[3]).toUInt());
    }
    else if (QString(argv[1]) == QString("getvalue") && argc == 3) {
        result = getvalue_gpio(manager, QString(argv[2]).toUInt());
    }
    else if (QString(argv[1]) == QString("setvalue") && argc == 4) {
        result = setvalue_gpio(manager, QString(argv[2]).toUInt(), QString(argv[3]).toUInt());
    }
    else {
        help();
    }
#else
    qInfo() << "";
    help();
#endif

    //return a.exec();
    return result;
}
