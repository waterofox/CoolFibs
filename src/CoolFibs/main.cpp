#include <iostream>
#include <iostream>
#include <QString>
#include <QStringList>

#include "config/appl_conf.h"
#include "config/logger_conf.h"
#include "shared/logger/logger.h"
#include "shared/logger/format.h"
#include "logger/config.h"

#define log_info_m     alog::logger().info    (alog_line_location,     "Prepair")
#define log_debug_m    alog::logger().debug   (alog_line_location, "Application")
#define log_debug_w_m  alog::logger().debug   (alog_line_location,     "Working")


int fib_nums(const int null, const int first, const int to);
int main()
{
    alog::logger().start();
    alog::logger().addSaverStdOut(alog::Level::Debug2);

    QString configFile = config::qdir() + "/coolFibsConfig.config";

    config::dirExpansion(configFile);
    if (!QFile::exists(configFile))
    {
        return 1;
    }

    config::base().setReadOnly(false);
    config::base().setSaveDisabled(true);

    if (!config::base().readFile(configFile.toStdString()))
    {
        return 1;
    }

    config::observerBase().start();

    //alog::logger().start();

    alog::configDefaultSaver();
    alog::configExtendedSavers();
    alog::printSaversInfo();

    alog::logger().addSaverStdOut(alog::Level::Info);
    alog::logger().addSaverStdOut(alog::Level::Debug);


    int nullValueFibs = 0;
    int firstValueFibs = 0;
    int finalValue = 0; //я чьмо. Не значение, а номер последнего значения
    config::base().getValue("application.null_n", nullValueFibs);
    config::base().getValue("application.first_n", firstValueFibs);
    config::base().getValue("application.to", finalValue);
    log_info_m << " -- null_n: " << nullValueFibs << " first_n: " << firstValueFibs << " to: " << finalValue;
    log_debug_m << " -- null_n: " << nullValueFibs << "first_n: " << firstValueFibs << " to: " << finalValue;
    std::cout << std::endl;
    fib_nums(nullValueFibs,firstValueFibs,finalValue);

    config::observerBase().stop();
    alog::logger().stop();
    return 0;
}
int fib_nums(const int first, const int second, const int to)
{
    int fib_first = first;
    int fib_second = second;
    int fib_switch;
    for(int i = 2; i <= to; ++i)
    {
        fib_switch = fib_second;
        fib_second = fib_second+fib_first;
        fib_first = fib_switch;
        log_debug_w_m << " -- num: " << i << ' ' << "value: " << fib_second;
        log_debug_m << " -- num: " << i << ' ' << "value: " << fib_second;
    }
    return fib_second;
}
