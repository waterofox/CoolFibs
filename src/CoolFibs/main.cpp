#include <iostream>
#include <iostream>
#include <QString>
#include <QStringList>

#include "config/appl_conf.h"
//#include "config/logger_conf.h"
//#include "shared/logger/logger.h"
//#include "shared/logger/format.h"
//#include "logger/config.h"
int fib_nums(const int null, const int first, const int to);
int main()
{
    QString configFile = config::qdir() + "/coolFibsConfig.config";

    config::dirExpansion(configFile);
    if (!QFile::exists(configFile))
    {
        std::cout << ".config does not exist: " << std::endl;
        std::cout << configFile.toStdString() << std::endl;
        return 1;
    }
    std::cout << ".config was detacted";

    //
    config::base().setReadOnly(false);
    config::base().setSaveDisabled(true);

    if (!config::base().readFile(configFile.toStdString()))
    {
        return 1;
    }

    int nullValueFibs = 0;
    int firstValueFibs = 0;
    int finalValue = 0;
    config::base().getValue("application.null", nullValueFibs);
    config::base().getValue("application.first", firstValueFibs);
    config::base().getValue("application.to", finalValue);
    std::cout << std::endl;
    fib_nums(nullValueFibs,firstValueFibs,finalValue);
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
        std::cout << "num: " << i << ' ' << "value: " << fib_second << std::endl;
    }
    return fib_second;
}
