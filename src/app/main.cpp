#include <iostream>
#include "log.h"

int main()
{
    helion::log::set_level(helion::log::Level::Trace);

    LOG_INFO("Helion Drift Start up");
    LOG_TRACE("Trace logging enabled");

    return 0;
}