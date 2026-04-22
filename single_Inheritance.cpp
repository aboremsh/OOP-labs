/*
It contains a class Student which is a subclass from Level that has:
  i. Data member: name (string), ID(int), total_d(float), total_c(int),
      GPA (char).
  ii. A function read() to read data members,
      and set the value of total_d which is equal to the sum of all degrees for all courses,
    total_c which is the sum of Credit for all courses,
    and set the value of GPA according to the following table:
In main function, define an array of Student class with length n, read
and print the elements of this array in suitable form for each object.
*/

#include <iostream>
using namespace std;

struct Course
{
  string C_name;
  float degree;
  int Credit;

  void get()
  {
    cout << "Enter C_name: ";
    cin >> C_name;

    cout << "Enter degree: ";
    cin >> degree;

    cout << "Enter Credit: ";
    cin >> Credit;

    cout << "|--------------|" << endl;
  }
};

class Level
{
protected:
  Course L[5];

public:
  void read()
  {
    cout << "Enter values of L[5]:\n";

    for (int i = 0; i < 5; i++)
      L[i].get();
  }
  void Print()
  {
    cout << "\t\tC_name\t\tdegree\t\tCredit\n";
    for (int i = 0; i < 5; i++)
    {
      Course ele = L[i];
      cout << "L[" << i << "]\t\t" << ele.C_name << "\t\t" << ele.degree << "\t\t" << ele.Credit << endl;
    }
  }
};

class Student : public Level
{
  string name;
  string ID;
  float total_d;
  int total_c;
  string GPA;

public:
  float avgDegree()
  {
    return (total_d / 5);
  }

  void read()
  {
    Level::read();

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter ID: ";
    cin >> ID;

    total_d = 0;
    for (int i = 0; i < 5; i++)
    {
      total_d += L[i].degree;
    }

    total_c = 0;
    for (int i = 0; i < 5; i++)
    {
      total_c += L[i].Credit;
    }

    // float avg = avgDegree();
    if (avgDegree() >= 92)
      GPA = 'A';
    else if (avgDegree() >= 84 && avgDegree() < 92)
      GPA = "B+";
    else if (avgDegree() >= 80 && avgDegree() < 84)
      GPA = "B";
    else if (avgDegree() >= 75 && avgDegree() < 80)
      GPA = "C+";
    else if (avgDegree() >= 65 && avgDegree() < 75)
      GPA = "C";
    else if (avgDegree() >= 60 && avgDegree() < 65)
      GPA = "D";
    else if (avgDegree() <= 60)
      GPA = "F";
    else
      cout << "________Fall to calc________\n";
  }
  void Print()
  {
    cout  << "name: " << name
          << "\tID: " << ID
          << "\t\ttotal_d: " << total_d
          << "\t\ttotal_c: " << total_c
          << "\t\tGPA: " << GPA
          << endl;
  }
};

int main()
{

  Student arr[3];

  for (int i = 0; i < 3; i++)
  {
    arr[i].read();
  }

  for (int i = 0; i < 3; i++)
  {
    arr[i].Print();
  }
}