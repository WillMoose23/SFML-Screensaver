//
// Created by Moose on 3/7/2021.
//

#ifndef MAIN_CPP_BALL_H
#define MAIN_CPP_BALL_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cctype>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <cstdlib>
#include <random>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using std::string;


int random(int, int);


class Ball : public sf::Drawable, sf::Transformable
        {
        private:
            sf::CircleShape ball;

        public:
            Ball();
            ~Ball();

        virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
        void bounce();


};

#endif //MAIN_CPP_BALL_H
