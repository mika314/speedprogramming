#include "game.hpp"
#include "painter.hpp"
#include <cstdlib>

Game::Game()
{
    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
        {
            field_[x][y].state = CLOSED;
            field_[x][y].hasMine = false;
        }
    for (int i = 0; i < 10; ++i)
    {
        int x, y;
        do
        {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        }
        while (field_[x][y].hasMine);
        field_[x][y].hasMine = true;
    }
}

void Game::draw()
{
    Painter p;
    for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
        {
            switch (field_[x][y].state)
            {
            case CLOSED:
                p.drawClosedField(x, y);
                break;
            case OPENED:
                if (!field_[x][y].hasMine)
                {
                    int minesAround = 0;
                    for (int yy = y - 1; yy <= y + 1; ++yy)
                        for (int xx = x - 1; xx <= x + 1; ++xx)
                        {
                            if ((xx == x && yy == y) ||
                                xx < 0 || xx >= WIDTH ||
                                yy < 0 || yy >= HEIGHT)
                                continue;
                            if (field_[xx][yy].hasMine)
                                ++minesAround;
                        }
                    p.drawOpenedField(x, y, minesAround);
                }
                else
                    p.drawMine(x, y);
                break;
            case FLAG:
                p.drawFlag(x, y);
                break;
            }
        }
}

void Game::open(int x, int y)
{
    field_[x][y].state = OPENED;
}

void Game::mark(int x, int y)
{
    switch (field_[x][y].state)
    {
    case OPENED:
        break;
    case CLOSED:
        field_[x][y].state = FLAG;
        break;
    case FLAG:
        field_[x][y].state = CLOSED;
        break;
    }
}
