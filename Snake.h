#ifndef _SNAKE_H__
#define _SNAKE_H__

class Node
{
public:
	Node() : x(0), y(0), next(nullptr) { }
	Node(int xx, int yy) : x(xx), y(yy) { }
private:
	int x, int y;
}

class Snake
{
public:
	Snake() : len(0), Node() { }
	void eatFood(int x, int y);
private:
	Node *head;
	Node *
	size_t len;
};

void Snake::eatFood(int x, int y)
{
	Node *newBody = new Node(x, y);
	Node *tmp = head->next;
	head->next = newBody;
	newBody->next = tmp;
	++len;
}

#endif
