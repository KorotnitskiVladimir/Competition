//
//  Obstacle.hpp
//  Competition
//
//  Created by Коротницкий Владимир on 29.08.2024.
//

#ifndef Obstacle_hpp
#define Obstacle_hpp

#include <stdio.h>
using namespace std;

class Obstacle
{
protected:
    double size;
public:
    Obstacle();
    Obstacle(double s);
    void setSize(double s);
    double getSize() const;
    virtual string getType() const = 0;
    virtual void init() = 0;
};

class Track:public Obstacle
{
private:
    const string type = "track";
public:
    Track() {size = 0;}
    Track(double s): Obstacle(s) {}
    virtual string getType() const;
    virtual void init();
};

class Wall:public Obstacle
{
private:
    const string type = "wall";
public:
    Wall() {size = 0;}
    Wall(double s):Obstacle(s) {}
    virtual void init();
    virtual string getType() const;
};

#endif /* Obstacle_hpp */
