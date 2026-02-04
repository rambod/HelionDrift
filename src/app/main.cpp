#include "application.h"


#include <iostream>
#include "log.h"

int main()
{
    helion::log::set_level(helion::log::Level::Trace);

    LOG_INFO("Helion Drift Start up");
    LOG_TRACE("Trace logging enabled");
    helion::application app;
    app.run();

    return 0;
}