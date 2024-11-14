#include <iostream>
using namespace std;

class Point 
{
	int x, y;
public:
	Point(int x, int y) // non-default constructor
	{		
		this->x = x;
		this->y = y;
		cout << " P " << endl;	
	}
	~Point()
	{		
		cout << " ~P " << endl;	
	}
	void PrintInfo()
	{		
		cout << "Point(" << x << "," << y << ")" << endl;	
	}
	void ReadInfo()
	{		
		cout << "Enter x and y: ";
		cin >> x >> y;	
	}
}; // end of class Point

class Line 
{
	//Point P1(1, 2); // Error
	Point P1;
	Point P2;
public:
	// member-initializer list ==> is a must if only a non-default constr. of Point
	Line(int x1, int y1, int x2, int y2) : P1(x1, y1), P2(x2, y2)
	{		
		cout << " L " << endl;	
	}
	Line() : P1(1, 2), P2(3, 4)
	{
	}
	~Line()
	{		
		cout << " ~L " << endl;	
	}
	void PrintInfo()
	{		
		P1.PrintInfo();
		P2.PrintInfo();
	}
	void ReadInfo()
	{		
		P1.ReadInfo();
		P2.ReadInfo();
	}
}; // end of class Line

int main()
{
	Line L1(1, 2, 3, 4);
	L1.ReadInfo();
	L1.PrintInfo();
	return 0;
} // L1 is destructed

