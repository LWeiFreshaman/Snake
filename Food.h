#ifndef FOOD_H__
#define FOOD_H__

#include<cstdlib>
#include<ctime>
#include "Map.h"

//extern const size_t sizeX;
//extern const size_t sizeY;

Map* m = Map::getMap();

class Food
{
public:
	Food() = default;
	Food(size_t xx, size_t yy);
	Food(const Food&);
	Food& operator=(Food);
	bool operator==(Food);
	void ate();

	size_t x;
	size_t y;
};

Food::Food(size_t xx, size_t yy)	
	: x(xx), y(yy)	
{	
	
}

Food::Food(const Food& f)
	: x(f.x), y(f.y) 
{
	
}

bool Food::operator==(Food f)
{
	return (x == f.x && y == f.y);
}

Food& Food::operator=(Food f)
{
	x = f.x;
	y = f.y;

	return *this;
}

Food random(size_t sizeX, size_t sizeY)
{
	return Food(rand() % sizeX + 1, rand() % sizeY + 1);
}

void Food::ate()
{
	Food tmp;

	do 
	{
		tmp = random(sizeX, sizeY);
	}
	while (m->mapMatrix[tmp.x][tmp.y] == 1);

	*this = tmp;
}

#endif