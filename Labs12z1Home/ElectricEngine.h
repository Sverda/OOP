#pragma once
#include "Engine.h"
class ElectricEngine :
	public EngineClass
{
protected:
	double volt;	// charging voltage
	double time;	// working time
public:
	ElectricEngine();
	ElectricEngine(const ElectricEngine &mk);
	ElectricEngine(const double volt, const double time);
	~ElectricEngine();
	void SetVolt(const double volt);
	double GetVolt();
	void SetTime(const double time);
	double GetTime();
	void Print() const;
};

