#include <iostream>
#include <iostream>
#include <QString>
#include <QStringList>
#include "calsses/fibscounter.h"
#include "config/appl_conf.h"
#include "config/logger_conf.h"
#include "shared/logger/logger.h"
#include "shared/logger/format.h"
#include "logger/config.h"

void get_config_update(int& null_n,int& first_n,int& to_n);

#define log_info_m     alog::logger().info    (alog_line_location,     "Prepair")
#define log_debug_m    alog::logger().debug   (alog_line_location, "Application")
#define log_debug_w_m  alog::logger().debug   (alog_line_location,     "Working")
enum commands
{
    fibCounter_start = 0,
    fibReset_start = 1,
    fibsCounter_stop = 2
};
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
    config::base().setSaveDisabled(false);

    if (!config::base().readFile(configFile.toStdString()))
    {
        return 1;
    }

    config::observerBase().start();

    alog::configDefaultSaver();
    alog::configExtendedSavers();
    alog::printSaversInfo();

    alog::logger().addSaverStdOut(alog::Level::Info);
    alog::logger().addSaverStdOut(alog::Level::Debug);

    int actualCommand = 0;

    int nullValueFibs = 0;
    int firstValueFibs = 0;
    int finalValue = 0; //я чьмо. Не значение, а номер последнего значения
    get_config_update(nullValueFibs,firstValueFibs,finalValue);

    fibsCounter* fibCounterOBJ = new fibsCounter(nullValueFibs,firstValueFibs,finalValue);

    log_info_m << " -- null_n: " << nullValueFibs << " first_n: " << firstValueFibs << " to: " << finalValue;
    log_debug_m << " -- null_n: " << nullValueFibs << "first_n: " << firstValueFibs << " to: " << finalValue;

    std::cout << "input num of command (0-count/1-reset&count/2-stop): ";

    while(true)
    {
        std::cin >> actualCommand;
        std::cout<< std::endl;

        if(actualCommand == commands::fibReset_start)
        {   config::observerBase().stop();

            config::dirExpansion(configFile);
            if (!QFile::exists(configFile))
            {
                delete fibCounterOBJ;
                return 1;
            }

            config::base().setReadOnly(false);
            config::base().setSaveDisabled(false);

            if (!config::base().readFile(configFile.toStdString()))
            {
                delete fibCounterOBJ;
                return 1;
            }

            config::observerBase().start();

            get_config_update(nullValueFibs,firstValueFibs,finalValue);
            fibCounterOBJ->count_reset(nullValueFibs,firstValueFibs,finalValue);
            continue;
        }
        if(actualCommand == commands::fibCounter_start)
        {
            fibCounterOBJ->count();
            continue;
        }
        if(actualCommand == commands::fibsCounter_stop)
        {
            break;
        }
    }

    delete fibCounterOBJ;
    alog::logger().stop();
    return 0;
}
void get_config_update(int& null_n,int& first_n,int& to_n)
{
    config::base().getValue("application.null_n", null_n);
    config::base().getValue("application.first_n", first_n);
    config::base().getValue("application.to", to_n);
}
