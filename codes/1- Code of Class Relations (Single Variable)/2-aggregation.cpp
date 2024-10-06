#include <iostream>
using namespace std;

class Department 
{
	int id;
public:
	Department(int id)
	{		
		this->id = id;
		cout << " D " << endl;	
	}
	~Department()
	{		
		cout << " ~D " << endl;	
	}
	void PrintInfo()
	{		
		cout << "Department(" << id << ")" << endl;	
	}
	void ReadInfo()
	{		
		cout << "Enter id: ";
		cin >> id;	
	}
}; // end of class Department

class School 
{
	Department* Ptr;
public:
	School()
	{		
		Ptr = new Department(0);
		cout << " S " << endl;	
	}
	~School()
	{		
		delete Ptr;
		cout << " ~S " << endl;	
	}
	void PrintInfo()
	{		
		Ptr->PrintInfo();
	}
	void ReadInfo()
	{		
		Ptr->ReadInfo();
	}
}; // end of class School

int main()
{
	School S1;
	S1.ReadInfo();
	S1.PrintInfo();
	return 0;
} // S1 is destructed

