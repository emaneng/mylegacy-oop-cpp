#include <iostream>
using namespace std;

class Teacher 
{
	int id;
public:
	Teacher(int id)
	{		
		this->id = id;
		cout << " T " << endl;	
	}
	~Teacher()
	{		
		cout << " ~T " << endl;	
	}
	void PrintInfo()
	{		
		cout << "Teacher(" << id << ")" << endl;	
	}
	void ReadInfo()
	{		
		cout << "Enter id: ";
		cin >> id;	
	}
}; // end of class Teacher

class School 
{
	Teacher* Ptr;
public:
	School()
	{		
		cout << " S " << endl;	
		Ptr = NULL;
	}
	~School()
	{		
		cout << " ~S " << endl;	
	}
	void AddTeacher(Teacher * pOuterTeacher)
	{
		Ptr = pOuterTeacher;
	}
	void DropTeacher()
	{
		Ptr = NULL;
	}
	void PrintInfo()
	{		
		if(Ptr)  // if(Ptr != NULL)
			Ptr->PrintInfo();
	}
	void ReadInfo()
	{	
		if(Ptr)
			Ptr->ReadInfo();
	}
}; // end of class School

int main()
{
	School S;
	S.ReadInfo();

	Teacher T1(0);
	if(true)
	{
		School S1;
		S1.AddTeacher(&T1);
	} // S1 is destructed
	School S2;
	S2.AddTeacher(&T1);
	S2.ReadInfo();
	S2.PrintInfo();
	return 0;
} // S2 and T1 are destructed

