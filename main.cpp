#include <stdio.h>

#include "src/graphic/graphic.h"
#include "src/graphic/graphic_config.h"

int main()
{
     #ifdef USE_LOG
        if (OpenLogsFile()) 
            return OPEN_FILE_LOG_ERR;
    #endif


    sf::RenderWindow window(sf::VideoMode(Default_window_width, Default_window_height), "Sphere");


    Plane plane(Left_corner, Default_plane_height, Default_plane_width,
                Null_dot, Vector(10.0, 0.0, 0.0), Vector(0.0, -10.0, 0.0));


    //plane.DrawEmptyPlane(window);

    Sphere sphere(Dot(-50.0, -10.0, 0.0), 10.0, sf::Color::Blue);

    plane.RenderSphere(window, sphere);

    char update_window_flag = TRUE;

    sf::Event event;
    while (window.isOpen())
    {
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

       

        if (update_window_flag == TRUE)
        {
            window.display();
            update_window_flag = FALSE;
        }

    }
    

    #ifdef USE_LOG
        if (CloseLogsFile ())
            return OPEN_FILE_LOG_ERR;
    #endif

    return EXIT_SUCCESS;
}