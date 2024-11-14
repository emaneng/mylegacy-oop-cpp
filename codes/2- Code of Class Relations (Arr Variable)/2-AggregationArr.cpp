#include <iostream>
using namespace std;

class Department
{
	int id;
public:
	Department()
	{	
		cout << " D ";	
	}
	~Department()
	{	
		cout << " ~D ";	
	}
	int GetID()	
	{	
		return id;	
	}
	void PrintInfo()
	{
		cout << "( " << id << " ) ";
	}
	void ReadInfo()	
	{	
		cout << "Enter id: ";
		cin >> id; 	// better cin in temp variables and use setters
	}
}; // end of class Department

class School
{	
	Department* Arr[100];
	int count;
public:
	School()
	{	
		count = 0;
		cout << " S ";
	}
	void AddDep()
	{	
		if (count < 100)
		{	
			Arr[count] = new Department;
			Arr[count]->ReadInfo();
			count++;
		}
	}
	~School()
	{	
		for (int i = 0; i < count; i++)
			delete Arr[i];
		cout << " ~S ";
	}
	void RemoveDep(int id)
	{	
		for (int i = 0; i < count; i++)
		{	
			if (Arr[i]->GetID() == id)
			{	
				delete Arr[i];
				Arr[i] = Arr[count - 1];
				Arr[count - 1] = NULL;
				count--;
				return;
			}
		}
	}
	void PrintInfo()
	{
		cout << "Count of Departments = " << count << endl;
		for (int i = 0; i < count; i++)
		{
			Arr[i]->PrintInfo();
		}
		cout << endl;
	}
	void ReadInfo()
	{
		for (int i = 0; i < count; i++)
		{
			Arr[i]->ReadInfo();
		}
	}
}; // end of class School

int main()
{
	School S1;
	cout << endl;
	S1.AddDep();	S1.AddDep();
	S1.AddDep(); 	S1.AddDep();
	S1.PrintInfo();
	S1.RemoveDep(20);
	S1.PrintInfo();
	return 0;
} // S1 is destructed