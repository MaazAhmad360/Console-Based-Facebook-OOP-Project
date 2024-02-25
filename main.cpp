#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

#include "System.h"
#include "Student.h"
#include "Course.h"
#include "Validator.h"
#include "FileHandler.h"


int main() {
    RenderWindow window(sf::VideoMode(800, 600), "My window");

    System learningManagementSystem;
    learningManagementSystem.loadDataFromFiles();
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    
    learningManagementSystem.displayMainMenu();
   
    return 0;
}
