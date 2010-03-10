#pragma once
#include "keys.hpp"
#include "ship.hpp"
#include "bullet.hpp"
#include "asteroid.hpp"
#include <deque>
#include <set>

class Painter;

class Game
{
    Ship ship_;
    typedef std::deque<Bullet> Bullets;
    Bullets bullets_;
    typedef std::set<Asteroid *> Asteroids;
    Asteroids asteroids_;
    int level_;
    void reset();
public:
    enum { 
        DELTA_T = 1000 / 100,
        WIDTH = 854,
        HEIGHT = 480
    };
    Game();
    ~Game();
    void draw(Painter &p) const;
    void tick(Keys);
    int level() const;
};
