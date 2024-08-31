//
//  Competitor.cpp
//  Competition
//
//  Created by Коротницкий Владимир on 29.08.2024.
//

#include "Competitor.hpp"
#include <string>

Competitor::Competitor()
{
    vitality = strenght = 0;
    name = "";
}

Competitor::Competitor(double v, double s, string n)
{
    try
    {
        if (v>0 && s>0 && n!="")
        {
            vitality = v;
            strenght = s;
            name = n;
        }
        else
            throw "incorrect input";
    }
    catch (const char* s)
    {
        cout << s << endl;
    }
}

void Competitor::setVitality(double v)
{
    if (v>0)
        vitality = v;
}

double Competitor::getVitality() const
{
    return vitality;
}

void Competitor::setStrenght(double s)
{
    if (s>0)
        strenght = s;
}

double Competitor::getStrenght() const
{
    return strenght;
}

void Competitor::setName(string s)
{
    if (s!="")
        name = s;
}

string Competitor::getName() const
{
    return name;
}

bool Competitor::moveObstacle(const Obstacle *obj)
{
    string obst = typeid(*obj).name();
    if (obst=="4Wall")
    {
        if (strenght>obj->getSize())
            return true;
        else
            return false;
    }
    else
    {
        if (vitality>obj->getSize())
            return true;
        else
            return false;
    }
}

void Competitor::init()
{
    name = names[rand()%10];
    vitality = rand()%500;
    double mult = 1.3+((rand()%100+1)*0.01);
    double base = rand()%1 + 1;
    strenght = mult * base;
}

void Human::run()
{
    cout << "Human runs";
}

void Human::jump()
{
    cout << "Human jumps";
}

void Cat::run()
{
    cout << "Cat runs";
}

void Cat::jump()
{
    cout << "Cat jumps";
}

void Robot::run()
{
    cout << "Robot runs";
}

void Robot::jump()
{
    cout << "Robot jumps";
}
