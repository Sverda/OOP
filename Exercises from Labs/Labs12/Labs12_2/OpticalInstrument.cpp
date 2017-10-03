#include "OpticalInstrument.h"
#include<cstdio>

void OpticalInstrument::SetZoom(double _zoom)
{
	zoom = _zoom;
}

double OpticalInstrument::GetZoom()
{
	return zoom;
}

void OpticalInstrument::SetWeight(double _weight)
{
	weight = _weight;
}

double OpticalInstrument::GetWeight()
{
	return weight;
}

OpticalInstrument::OpticalInstrument()
{
	SetZoom(0);
	SetWeight(0);
	next = nullptr;
}

OpticalInstrument::OpticalInstrument(double _zoom, double _weight)
{
	SetZoom(_zoom);
	SetWeight(_weight);
	next = nullptr;
}

OpticalInstrument::OpticalInstrument(OpticalInstrument & mk)
{
	SetZoom(mk.zoom);
	SetWeight(mk.weight);
	next = nullptr;
}

OpticalInstrument::~OpticalInstrument()
{
	delete next;
}

void OpticalInstrument::Print()
{
	printf("Optical Instrument: \n");
	printf("Zoom: %lf\nWeight: %lf\n\n", zoom, weight);
}

void OpticalInstrument::PrintList()
{
	Print();
	if (next != nullptr)
	{
		next->PrintList();
	}
}
