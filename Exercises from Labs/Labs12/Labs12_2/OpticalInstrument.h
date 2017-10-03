#pragma once
class OpticalInstrument
{
protected:
	double zoom;
	double weight;
public:
	OpticalInstrument* next;
public:
	OpticalInstrument();
	OpticalInstrument(double _zoom, double _weight);
	OpticalInstrument(OpticalInstrument &mk);
	~OpticalInstrument();
	// Setters and getters
	void SetZoom(double _zoom);
	double GetZoom();
	void SetWeight(double _weight);
	double GetWeight();
	// Other methods
	void Print();
	void PrintList();
};

