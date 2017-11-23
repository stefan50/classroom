#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
	string name_;
	long id_;
public:
	Employee()
	: name_("default")
	{
		cout << "def" << endl; 
	}
	Employee(const string& name, long id)
	: name_(name),
	  id_(id)
	{}

	const string& get_name() const
	{
		return name_;
	}
	
	int get_level() const
	{
		return level_;
	}

	void print() const
	{
		cout << "Emp:\t" << name_ << "\t" << id_ << endl;
	}
};

class Manager: public Employee //public inheritance
{
	int level_;
public:
	Manager(const string& name,  int id, int level)
	: Employee(name,id),
	  level_(level)
	{}

	int get_level() const
	{
		return level_;
	}
	
	void print() const
	{
		//Employee::print();   //able to do that
		cout << "Man:\t" << name_ << "\t" << id_ << "\t" << level_ << endl;
	}
};

int main()
{
	Employee e1("ivcho", 1001);
	e1.print();

	Manager m1 = Manager("pesho", 10001, 1);
	m1.print(); //inherited from Employee; ability to overwrite
	return 0;
}
