#include <iostream>
using namespace std;

class Teacher
{
	int id;
public:
	Teacher()
	{	
		cout << " T ";	
	}
	~Teacher()
	{	
		cout << " ~T ";	
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
		cin >> id;  // better cin in temp variables and use setters
	}
}; // end of class Teacher

class School
{	
	Teacher* Arr[100];
	int count;
public:
	School()
	{	
		count = 0;
		cout << " S ";
	}
	void AddTeacher(Teacher& obj) // must be sent by & or * (not by value)
	{	
		if (count < 100)
		{
			// no new Teacher
			Arr[count] = &obj;
			count++;
		}
	}
	~School()
	{	
		// no loop for delete Arr[i]
		cout << " ~S ";
	}
	void RemoveTeacher(int id)
	{	
		for (int i = 0; i < count; i++)
		{	
			if (Arr[i]->GetID() == id)
			{   
				// no delete Arr[i]
				Arr[i] = Arr[count - 1];
				Arr[count - 1] = NULL;
				count--;
				return;
			}
		}
	}
	void PrintInfo()
	{
		cout << "Count of Teachers = " << count << endl;
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
	Teacher T1;	T1.ReadInfo();
	Teacher T2;	T2.ReadInfo();
	Teacher T3;	T3.ReadInfo();
	Teacher T4;	T4.ReadInfo();
	School S1;
	cout << endl;
	S1.AddTeacher(T1);	S1.AddTeacher(T2);
	S1.AddTeacher(T3);	S1.AddTeacher(T4);
	S1.PrintInfo();
	S1.RemoveTeacher(20);
	S1.PrintInfo();
	return 0;
} // S1 then T4, T3, T2, and T1 are destructed