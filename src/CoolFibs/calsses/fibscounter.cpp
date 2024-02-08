#include "fibscounter.h"

//#include "config/logger_conf.h"
#include "shared/logger/logger.h"
//#include "shared/logger/format.h"
//#include "logger/config.h"

#define log_info_m     alog::logger().info    (alog_line_location,     "Prepair")
#define log_debug_m    alog::logger().debug   (alog_line_location, "Application")
#define log_debug_w_m  alog::logger().debug   (alog_line_location,     "Working")

fibsCounter::fibsCounter(const int null_n, const int first_n, const int to_n)
{
    this->_first_n = first_n;
    this->_null_n = null_n;
    this->_to_n = to_n;
}

int fibsCounter::count()
{
    int fib_first = this->_null_n;
    int fib_second = this->_first_n;
    int fib_switch;
    for(int i = 2; i <= this->_to_n; ++i)
    {
        fib_switch = fib_second;
        fib_second = fib_second+fib_first;
        fib_first = fib_switch;
        log_debug_w_m << " -- num: " << i << ' ' << "value: " << fib_second;
        log_debug_m << " -- num: " << i << ' ' << "value: " << fib_second;
    }
    return fib_second;
}

int fibsCounter::count_reset(const int null_n, const int first_n, const int to_n)
{
    this->_first_n = first_n;
    this->_null_n = null_n;
    this->_to_n = to_n;

    log_debug_w_m << " -- reset";
    log_debug_m << " -- reset";

    return this->count();
}

fibsCounter::~fibsCounter()
{

}
