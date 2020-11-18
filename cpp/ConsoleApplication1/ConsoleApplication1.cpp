#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

// Function Declaration
void myFunction();
int functionWithArgs(int a, int b=10);
void myFunction2(string coun = "China"); // default arguments in declaration

int myFunc(int a, int b);
string myFunc(string a, string b);
double myFunc(double a, double b);

// Class Declaration
class Car {
public:
	string name;
	int speed(int maxSpeed);
};
int Car::speed(int maxSpeed) {
	return maxSpeed;
}

// Class with Constructor
class Vehicle {
private:
	string brand;
	string model;
	int year;
	double price = 10000;
public:
	
	Vehicle(string x, string y, int z) {
		brand = x;
		model = y;
		year = z;
	}

	Vehicle(string x, string y, int z, double p) {
		brand = x;
		model = y;
		year = z;
		price = p;
	}

	string getBrand() {
		return brand;
	}
	string getModel() {
		return model;
	}
	int getYear() {
		return year;
	}
	double getPrice() {
		return price;
	}
};

// Class Inheritance
class Truck : public Vehicle {

public:
	Truck(string x, string y, int z, int p) :Vehicle(x, y, z, p) {}
	
	double getPrice() {
		return 1000;
	}

};

int main() {

	int a = 4, b = 2;
	switch (a)
	{
	case 4: b++;
	case 0:  b++;break;
	default:
		a--;
	}
	cout << "a=" << a << " b=" << b << endl;

	int car[5] = { 1,2,3,4,5 };
	int *p = &car[3];
	cout << p[0] << p[1] << p[2] << endl;;


	/*
	// Assignment Operators
	int num = 12;
	string str = "Hello";
	cout << (num&7) << endl;
	

	// string concatentation
	string str1 = "john";
	string str2 = "smith";
	string fullname = str1 + " " + str2;
	cout << fullname << endl;

	fullname.append("!!");
	cout << fullname << endl;
	
	// adding Numbers and Strings
	string a = "12";
	string b = "32";
	string num1 = a + b;
	cout << num1 << endl;

	// changing String Charaters
	string myString = "Hello";
	myString[0] = 'J';
	cout << myString << endl;

	// User input Strings, get entire line 
	
	string fullName;
	cout << "input full name" << endl;
	// cin >> fullName;
	getline(cin, fullName);
	cout << "full name is: " << fullName << endl;

	// math functions
	cout << sqrt(2) << cbrt(2) << endl;

	// Boolean Values
	bool isCodingFun = true;
	bool isFishTasty = false;
	cout << isCodingFun << " " << isFishTasty << endl;

	// short hand if else
	int time = 20;
	cout << (time < 18 ? "Good Day! " : "Good evening!") << endl;

	// switch case
	int index = 2;
	switch (index)
	{
	case 1:
		cout << "1\n";
		break;
	case 3:
		cout << "2\n";
		break;

	default:
		cout << "nothing!\n";
		break;
	}

	// while loop
	int i = 0;
	while (true) {
		cout << "haha" << endl;
		i++;
		if (i >= 5) {
			break;
		}
	}

	// do while
	do
	{
		if (i > 10)
		{
			break;
		}
		i++;
		cout << "papa" << endl;
	} while (true);

	// Array

	string arr[4] = { "abc","def","ghi","jk" };
	arr[0] = "mno";

	for (string x : arr) {
		cout << x << endl;
	}

	// References
	string food = "pizza";
	string& meal = food;
	cout << "food is " << food << "\nmeal is " << meal << endl;
	cout << "address of food is " << &meal << "  " << &food << endl;

	// Pointer
	string* dinner = &meal;
	cout << "food is " << food << "\ndinner is " << *dinner << endl;
	// Modify the pointer value
	*dinner = "hamburg";
	cout << "food is " << food << "\ndinner is " << *dinner << endl;
	*/
	

	myFunction(); // dont forget the brackets()
	cout << functionWithArgs(3) << endl;
	myFunction2();

	// funciton reloading 
	cout << myFunc(10, 2)<<endl;
	cout << myFunc(120.23,3490.23)<<endl;
	string str1 = "asc", str2 = "hasd";
	cout << myFunc(str1, str2) <<endl;
	cout << myFunc("aswj","dog")<<endl;

	Car car1;
	car1.name = "Porsche";
	cout << car1.name << car1.speed(300)<<endl;

	// Constructor
	Vehicle car2("Porsche", "711", 1994,20000);
	cout << car2.getBrand() <<" "<< car2.getModel() << " " << car2.getYear() << " " << car2.getPrice() << endl;

	// Inheritance
	Truck vovle("Volve", "***", 1994, 30000);
	cout << vovle.getBrand() << " " << vovle.getModel() << " " << vovle.getYear() << " " << vovle.getPrice() << endl;

	Vehicle* car3 = &vovle;
	cout << car3->getBrand() << " " << car3->getModel() << " " << car3->getYear() << " " << car3->getPrice() << endl;

	//
	int nums[4] = {1,2,3,4};
	string str = "haha";
	cout << str << " " << str.length() << endl;

	cerr << "error occurs" << endl;
}

void myFunction() {
	cout << "My first function!" << endl;
}

int functionWithArgs(int a, int b) {
	return a + b;
}

void myFunction2(string coun) {
	cout << coun << endl;
}

int myFunc(int a, int b) {
	return a + b;
}
string myFunc(string a, string b) {
	return a + b;
}
double myFunc(double a, double b) {
	return a + b;
}

