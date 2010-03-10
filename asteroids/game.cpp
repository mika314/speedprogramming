#include "game.hpp"
#include <cmath>
#include <cstdlib>

Game::Game(): level_(1)
{
    reset();
}

Game::~Game()
{
    for (Asteroids::iterator i = asteroids_.begin(); i != asteroids_.end(); ++i)
        delete *i;
}

void Game::reset()
{
    bullets_.clear();
    for (Asteroids::iterator i = asteroids_.begin(); i != asteroids_.end(); ++i)
        delete *i;
    asteroids_.clear();
    for (int i = 0; i < level_; ++i)
    {
        Asteroid *a = new Asteroid;
        a -> size = 64;
        a -> x = rand() % WIDTH - WIDTH / 2;
        a -> y = rand() % HEIGHT - HEIGHT / 2;
        a -> vx = rand() % 40 - 20;
        a -> vy = rand() % 40 - 20;
        asteroids_.insert(a);
    }
}

void Game::draw(Painter &p) const
{
    ship_.draw(p);
    for (Bullets::const_iterator i = bullets_.begin(); i != bullets_.end(); ++i)
        i -> draw(p);
    for (Asteroids::const_iterator i = asteroids_.begin(); i != asteroids_.end(); ++i)
        (*i) -> draw(p);
}

void Game::tick(Keys keys)
{
    ship_.tick(keys);
    if (keys[KEY_FIRE] && (bullets_.size() == 0 || bullets_.back().live > 200))
    {
        Bullet b;
        b.vx = 100 * cos(ship_.angel());
        b.vy = 100 * sin(ship_.angel());
        b.x = 20 * cos(ship_.angel());
        b.y = 20 * sin(ship_.angel());
        bullets_.push_back(b);
    };
    
    Vector v = { 0, 0 };
    if (keys[KEY_UP])
    {
        v.x = -200 * cos(ship_.angel());
        v.y = -200 * sin(ship_.angel());
    }
    if (keys[KEY_DOWN])
    {
        v.x = 200 * cos(ship_.angel());
        v.y = 200 * sin(ship_.angel());
    }
    for (Bullets::iterator i = bullets_.begin(); i != bullets_.end(); ++i)
        i -> tick(v);
    for (Asteroids::const_iterator i = asteroids_.begin(); i != asteroids_.end(); ++i)
        (*i) -> tick(v);
    for (Asteroids::const_iterator a = asteroids_.begin(); a != asteroids_.end(); ++a)
        for (Bullets::iterator b = bullets_.begin(); b != bullets_.end(); ++b)
        {
            float d = sqrt((b -> x - (*a) -> x) * (b -> x - (*a) -> x) + (b -> y - (*a) -> y) * (b -> y - (*a) -> y));
            if (d < ((*a) -> size + 1.5))
            {
                if ((*a) -> size > 8)
                {
                    (*a) -> size /= 1.414;
                    Asteroid *aa = new Asteroid(**a);
                    aa -> vx += rand() % 20 - 20;
                    aa -> vy += rand() % 20 - 20;
                    asteroids_.insert(aa);
                }
                else
                {
                    delete *a;
                    asteroids_.erase(*a);
                    if (asteroids_.size() == 0)
                    {
                        ++level_;
                        reset();
                        return;
                    }
                }
                goto a;
            }
        }
    a:
    for (Asteroids::const_iterator a = asteroids_.begin(); a != asteroids_.end(); ++a)
    {
        float d = sqrt((*a) -> x * (*a) -> x + (*a) -> y * (*a) -> y);
        if (d < ((*a) -> size + 15))
        {
            reset();
            return;
        }
    }
    while (bullets_.size() != 0 && bullets_.front().live > 3000)
        bullets_.pop_front();
}

int Game::level() const
{
    return level_;
}
