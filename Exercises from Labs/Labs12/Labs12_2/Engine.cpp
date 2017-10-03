#include "Engine.h"
#include<cstdio>

void Engine::SetPower(double _power)
{
	if (_power < 0)
	{
		power = 0;
	}
	else
	{
		power = _power;
	}
}

double Engine::GetPower()
{
	return power;
}

void Engine::SetSize(double _size)
{
	if (_size < 0)
	{
		size = 0;
	}
	else
	{
		size = _size;
	}
}

double Engine::GetSize()
{
	return size;
}

Engine::Engine()
{
	SetPower(0);
	SetSize(0);
	next = nullptr;
}

Engine::Engine(double power, double size)
{
	SetPower(power);
	SetSize(size);
	next = nullptr;
}

Engine::Engine(Engine & mk)
{
	SetPower(mk.power);
	SetSize(mk.size);
	next = nullptr;
}


Engine::~Engine()
{
	delete next;
}

void Engine::Print()
{
	printf("Engine: \n");
	printf("Power: %lf\nSize: %lf\n\n", power, size);
}

void Engine::PrintList()
{
	Print();
	if (next != nullptr)
	{
		next->PrintList();
	}
}
