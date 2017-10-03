#include "ElectricEngine.h"
#include<cstdio>



ElectricEngine::ElectricEngine() :EngineClass()
{
	volt = 50;
	time = 100;
}

ElectricEngine::ElectricEngine(const ElectricEngine & mk) :EngineClass()
{
	volt = mk.volt;
	time = mk.time;
}

ElectricEngine::ElectricEngine(const double volt, const double time) :EngineClass()
{
	this->volt = volt;
	this->time = time;
}


ElectricEngine::~ElectricEngine()
{
}

void ElectricEngine::SetVolt(const double volt)
{
	if (volt > 0)
	{
		this->volt = volt;
	}
}

double ElectricEngine::GetVolt()
{
	return volt;
}

void ElectricEngine::SetTime(const double time)
{
	if (time > 0)
	{
		this->time = time;
	}
}

double ElectricEngine::GetTime()
{
	return time;
}

void ElectricEngine::Print() const
{
	printf("Electric Engine:\n");
	printf("Charging voltage: %lf\n", volt);
	printf("Working time: %lf\n\n", time);
}
