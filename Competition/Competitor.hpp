//
//  Competitor.hpp
//  Competition
//
//  Created by Коротницкий Владимир on 29.08.2024.
//

#ifndef Competitor_hpp
#define Competitor_hpp

#include <stdio.h>
#include <iostream>
#include "Obstacle.hpp"
using namespace std;

const string names[] = {"Felix", "Guy", "Garret", "Fox", "Hunk", "Rufus", "Riger", "Akolite", "Neo", "Chao"};

class Competitor
{
protected:
    double vitality;
    double strenght;
    string name;
public:
    Competitor();
    Competitor(double v, double s, string n);
    void setVitality(double v);
    double getVitality() const;
    void setStrenght(double s);
    double getStrenght() const;
    void setName(string s);
    string getName() const;
    void init();
    virtual void jump() = 0;
    virtual void run() = 0;
    bool moveObstacle(const Obstacle* obj);
};

class Human:public Competitor
{
public:
    Human() {vitality = strenght = 0; name = "";}
    Human(double v, double s, string n): Competitor(v, s, n) {}
    virtual void jump();
    virtual void run();
};

class Cat:public Competitor
{
public:
    Cat() {vitality = strenght = 0; name = "";}
    Cat(double v, double s, string n): Competitor(v, s, n) {}
    virtual void jump();
    virtual void run();
};

class Robot:public Competitor
{
public:
    Robot() {vitality = strenght = 0; name = "";}
    Robot(double v, double s, string n): Competitor(v, s, n) {}
    virtual void jump();
    virtual void run();
};

#endif /* Competitor_hpp */
