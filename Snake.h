#ifndef _SNAKE_H__
#define _SNAKE_H__
#include <Map.h>
#include <iostream>

Map *m = Map::getMap();

class Node
{
public:
	Node() : x(0), y(0), next(nullptr) { }
	Node(int xx, int yy) : x(xx), y(yy) { }
//private:
	int x;
	int y;
	Node* next;
	Node* last;
};

class Snake
{
public:
	Snake() : len(0) { }
	void eatFood(size_t, size_t);
	void eatSelf();
	void touchWall();
	void goAhead(size_t, size_t);
	void judge(size_t, size_t);
private:
	Node *head;
	Node *tail;
	size_t len;
};

void Snake::eatFood(size_t x, size_t y)
{
	Node *newBody = new Node(x, y);
	newBody->next = head;
	head->last = newBody;
	head = newBody;
	++len;
}

void Snake::eatSelf()
{	
	//�����˾�
}

void Snake::touchWall()
{
	//�����˾�
}

void Snake::goAhead(size_t xx, size_t yy)
{
	tail = new Node(xx,yy);
	tail->next = head;
	head->last = tail;
	tail = tail->last;
	tail->next = nullptr;
}

void Snake::judge(size_t x, size_t y)
{
	switch (m->mapMatrix[x][y])
	{
	case 0:	
		touchWall();
	case 1:
		eatSelf();
	case 2:
		eatFood(x, y);
	default:
		goAhead(x, y);
	}
}


#endif
