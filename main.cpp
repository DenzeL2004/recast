#include <stdio.h>

#include "src/graphic/graphic.h"
#include "src/graphic/graphic_config.h"

int main()
{
     #ifdef USE_LOG
        if (OpenLogsFile()) 
            return OPEN_FILE_LOG_ERR;
    #endif


    Plane plane(Left_corner, Default_plane_height, Default_plane_width,
                Null_dot, Vector(10.0, 0.0, 0.0), Vector(0.0, -10.0, 0.0), sf::Color::Black);

    std::vector<Light> lights = {Light(Vector(-2.0, -4.0, -30.0), 250.0), Light(Vector(5.0, 15.0, -20.0), 150.0)};

    Vector camera(0.0, 0.0, -70.0);

    Example(plane, lights, camera);
    
    

    #ifdef USE_LOG
        if (CloseLogsFile ())
            return OPEN_FILE_LOG_ERR;
    #endif

    return EXIT_SUCCESS;
}