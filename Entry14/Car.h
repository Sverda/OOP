#pragma once
class Car
{
protected:
	double price;
	char* engineType;
public:
	Car* next;
public:
	Car();
	Car(Car &mk);
	Car(double _price, char* _engineType);
	~Car();
	// Setters and getters
	void SetPrice(double _price);
	double GetPrice();
	void SetEngineType(char* _type);
	char* GetEngineType();
	// Other methods
	virtual void Print();
	void PrintList();
	void PrintLargerThan(double _price);
	// Operators
	Car& operator+=(const Car& mk);
};

