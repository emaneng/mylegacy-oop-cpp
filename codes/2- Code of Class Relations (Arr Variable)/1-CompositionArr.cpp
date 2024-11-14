#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()
	{
		cout << " P ";
	}
	~Point()
	{
		cout << " ~P ";
	}
	void PrintInfo()
	{
		cout << "(" << x << "," << y << ") ";
	}
	void ReadInfo()
	{
		cout << "Please enter x and y:";
		cin >> x >> y; // better cin in temp variables and use setters
	}
}; // end of class Point

class Quad
{
	Point Arr[4];
public:
	Quad()
	{
		cout << " Q ";
	}
	~Quad()
	{
		cout << " ~Q ";
	}
	void PrintInfo()
	{
		for (int i = 0; i < 4; i++)
		{
			Arr[i].PrintInfo();
		}
		cout << endl;
	}
	void ReadInfo()
	{
		for (int i = 0; i < 4; i++)
		{
			Arr[i].ReadInfo();
		}
	}
}; // end of class Quad

int main()
{
	Quad Q1;
	cout << endl;
	Q1.ReadInfo();
	Q1.PrintInfo();
	return 0;
} // Q1 is destructed

