#pragma once
class Engine
{
protected:
	double power;	// KM
	double size;	// dm^3
public:
	Engine* next;
public:
	Engine();
	Engine(double power, double size);
	Engine(Engine &mk);
	~Engine();
	// Setters and getters
	void SetPower(double _power);
	double GetPower();
	void SetSize(double _size);
	double GetSize();
	// Other
	void Print();
	void PrintList();
};

