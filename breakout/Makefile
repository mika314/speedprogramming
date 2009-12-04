CPPFLAGS=-Wall -g
OBJECTS=breakout.o painter.o ball.o force.o brick.o wall.o\
 game.o pedal.o
TARGET=breakout
%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
$(TARGET): $(OBJECTS)
	g++ $(OBJECTS) -o $(TARGET) -g -lglut
breakout.o: breakout.cpp painter.hpp wall.hpp \
brick.hpp ball.hpp wall.hpp
painter.o: painter.cpp painter.hpp
ball.o: ball.cpp ball.hpp painter.hpp wall.hpp brick.hpp
force.o: force.cpp force.hpp 
brick.o: brick.cpp brick.hpp force.hpp painter.hpp ball.hpp
wall.o: wall.cpp wall.hpp brick.hpp force.hpp painter.hpp
game.o: game.cpp game.hpp wall.hpp brick.hpp force.hpp \
painter.hpp pedal.hpp
pedal.o: pedal.cpp pedal.hpp force.hpp painter.hpp ball.hpp