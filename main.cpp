#include <stdio.h>

#include "src/graphic/graphic.h"
#include "src/graphic/graphic_config.h"

#include "src/graphic/scene/scene.h"

int main()
{
     #ifdef USE_LOG
        if (OpenLogsFile()) 
            return OPEN_FILE_LOG_ERR;
    #endif

    sf::RenderWindow window(sf::VideoMode(Default_window_width, Default_window_height), "Sphere");

    Scene scene(Vector(0.0, 0.0, -80.0), Default_window_height, Default_window_width);

    Sphere sphere(Vector(200, 200, 0), 10.0, 0.1, Material( {0.1, 0, 0.1}, {0.7, 0, 0.7}, {1, 1, 1}, 400, 1));
    Light light({5, 10, 10},
                {1, 1, 1},
                {1, 1, 1},
                {1, 1, 1});

    scene.AddLight(light);
    scene.AddSphere(sphere);

    scene.Render(window);

    char update_window_flag = TRUE;


    sf::Event event;
    while (window.isOpen())
    {   
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        update_window_flag = TRUE;
    
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