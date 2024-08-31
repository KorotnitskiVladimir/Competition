//
//  Obstacle.cpp
//  Competition
//
//  Created by Коротницкий Владимир on 29.08.2024.
//

#include <iostream>
#include "Obstacle.hpp"
using namespace std;

Obstacle::Obstacle()
{
    size = 0;
    //type = "";
}

Obstacle::Obstacle(double s)
{
    try
    {
        if (s>0)
        {
            size = s;
            //type = "";
        }
        else
            throw "size could not be less or equal to zero";
    }
    catch (const char* s)
    {
        cout << s << endl;
    }
}

void Obstacle::setSize(double s)
{
    if (s>0)
        size = s;
}

double Obstacle::getSize() const
{
    return size;
}

string Track::getType() const
{
    return type;
}

string Wall::getType() const
{
    return type;
}

void Track::init()
{
    size = rand()%450;
}

void Wall::init()
{
    double mult = 1+((rand()%100+1)*0.01);
    double base = rand()%1 + 1;
    size = base * mult;
}
