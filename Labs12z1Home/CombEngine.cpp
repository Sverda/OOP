#include "CombEngine.h"
#include<cstdio>
#include<cstring>

CombEngine::CombEngine()
{
	fuelType = new char[] {"Pb95"};
	cubCap = 1;
}

CombEngine::CombEngine(const CombEngine & mk)
{
	int ftlen = strlen(mk.fuelType);
	fuelType = new char[ftlen + 1];
	strcpy(fuelType, mk.fuelType);
	cubCap = mk.cubCap;
}

CombEngine::CombEngine(const char * ft, const int cc)
{
	replaceFuelType(ft);
	cubCap = cc;
}


CombEngine::~CombEngine()
{
	delete fuelType;
}

void CombEngine::SetFuelType(const char *c)
{
	replaceFuelType(c);
}

char * CombEngine::GetFuelType()
{
	return fuelType;
}

void CombEngine::SetCubCap(const int capacity)
{
	if (capacity > 0)
	{
		cubCap = capacity;
	}
}

int CombEngine::GetCubCap()
{
	return cubCap;
}

void CombEngine::Print() const
{
	printf("Combustion Engine:\n");
	printf("Fuel type: %s\n", fuelType);
	printf("Cubic capacity: %d\n\n", cubCap);
}

void CombEngine::replaceFuelType(const char * c)
{
	int clen = strlen(c);
	delete fuelType;
	fuelType = new char[clen + 1];
	strcpy(fuelType, c);
}