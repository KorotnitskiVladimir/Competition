#include "Competitor.hpp"

struct Competition
{
    int c;
    int o;
    Competitor** competitors = nullptr;
    Obstacle** obstacles = nullptr;
    void initCompetitors();
    void initObstalces();
    void initCompetition();
};

void Competition::initCompetitors()
{
    competitors = new Competitor* [c];
    for (int i=0; i<c; i++)
    {
        int c = rand()%3;
        switch (c)
        {
        case 0:
            competitors[i] = new Human;
            break;
        case 1:
            competitors[i] = new Cat;
            break;
        case 2:
            competitors[i] = new Robot;
        }
        competitors[i]->init();
    }
}

void Competition::initObstalces()
{
    obstacles = new Obstacle* [o];
    for (int i=0; i<o; i++)
    {
        int c = rand()%2;
        switch (c)
        {
        case 0:
            obstacles[i] = new Track;
            break;
        case 1:
            obstacles[i] = new Wall;
            break;
        }
        obstacles[i]->init();
    }
}

void Competition::initCompetition()
{
    initCompetitors();
    initObstalces();
        for (int i=0; i<c; i++)
    {
        int compCounter = 0;
        double lenghtCounter = 0;
        double heightCounter = 0;
        for (int j=0; j<o; j++)
        {
            string ob = obstacles[j]->getType();
            string m = "";
            if (competitors[i]->moveObstacle(obstacles[j]))
            {
                cout << competitors[i]->getName() << " ";
                if (ob=="track")
                {
                    competitors[i]->run();
                    m = "length";
                    lenghtCounter += obstacles[j]->getSize();
                }
                else
                {
                    competitors[i]->jump();
                    m = "height";
                    heightCounter += obstacles[j]->getSize();
                }
                cout << " and successfully passes obstacle " << ob << " with " << obstacles[j]->getSize() << " meters" << endl;
                compCounter++;
            }
            else
            {
                cout << competitors[i]->getName() << " ";
                if (ob=="track")
                {
                    competitors[i]->run();
                    m = "length";
                    lenghtCounter += competitors[i]->getVitality();
                }
                else
                {
                    competitors[i]->jump();
                    m = "height";
                    heightCounter += competitors[i]->getStrenght();
                }
                cout << ", but was not able to pass obstacle " << ob << " with " << obstacles[j]->getSize() << " meters" << endl;
                cout << "Result is ";
                if (ob=="track")
                    cout << competitors[i]->getVitality() << " meters" << endl;
                else
                    cout << competitors[i]->getStrenght() << " meters" << endl;
                break;
            }
        }
        cout << competitors[i]->getName() << " finishes with " << compCounter << " completed competitions" << endl;
        cout << "His result in run is " << lenghtCounter << " meters" << endl;
        cout << "His result in jumps is " << heightCounter << " meters" << endl;
    }
}
