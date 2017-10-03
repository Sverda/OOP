#pragma once
class FigGeo
{
public:
	double x;
	double y;
public:
	FigGeo() :x(0), y(0){}
	FigGeo(FigGeo &mk) :x(mk.x), y(mk.y){}
	FigGeo(double nx, double ny) :x(nx), y(ny){}
	~FigGeo();
};

