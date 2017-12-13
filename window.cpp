#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

int main()
{
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;

<<<<<<< HEAD
    sf::Window window(sf::VideoMode(640, 480), "SFML & OpenGL", sf::Style::Default, contextSettings);
=======
    sf::Window window(sf::VideoMode(640, 480), "SFML window with OpenGL", sf::Style::Default, contextSettings);
>>>>>>> 5e51d0702332f3258e4ffec52db35c8216fd47f4

    window.setActive();

    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 1.f);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    glViewport(0, 0, window.getSize().x, window.getSize().y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
    glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);


    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), cube);
    glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), cube + 3);

    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();

            if (event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        glRotatef(clock.getElapsedTime().asSeconds() * 50, 1.f, 0.f, 0.f);
        glRotatef(clock.getElapsedTime().asSeconds() * 30, 0.f, 1.f, 0.f);
        glRotatef(clock.getElapsedTime().asSeconds() * 90, 0.f, 0.f, 1.f);

        glDrawArrays(GL_TRIANGLES, 0, 36);

        window.display();
    }

    return EXIT_SUCCESS;
}
