#pragma once
#include "Engine.h"

class CombEngine :
	public EngineClass
{
protected:
	char* fuelType;
	int cubCap;		// cupic capacity
private:
	void replaceFuelType(const char* c);
public:
	CombEngine();
	CombEngine(const CombEngine &mk);
	CombEngine(const char* ft, const int cc);
	~CombEngine();
	void SetFuelType(const char*);
	char* GetFuelType();
	void SetCubCap(const int);
	int GetCubCap();
	void Print() const;
};

