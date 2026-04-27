#include <iostream>
using namespace std;

class XData
{
  double X[20];
  int y;
  int m;

public:
  double avg()
  {
    double sum = 0;
    for (int i = 0; i < m; i++)
    {
      sum += X[i];
    }
    return (sum / m);
  }

  friend istream &operator>>(istream &, XData &);
  friend ostream &operator<<(ostream &, XData &);

  int Rm() { return m; }
  int Ry() { return y; }
  double RX(int i) { return X[i]; }
};

istream &operator>>(istream &in, XData &obj)
{
  cout << "Enter m: ";
  in >> obj.m;

  cout << "Enter y: ";
  in >> obj.y;

  cout << "Enter values of X[" << obj.m << "]:\n";
  for (int i = 0; i < obj.m; i++)
  {
    in >> obj.X[i];
  }
  return in;
};

ostream &operator<<(ostream &out, XData &obj)
{
  out << "m: " << obj.m << endl;
  out << "y: " << obj.y << endl;

  out << "Elements of X[" << obj.m << "] = ";
  for (int i = 0; i < obj.m; i++)
  {
    out << obj.X[i] << " ";
  }
  out << endl;

  return out;
};

class Data
{
  XData A[30];
  double B[30];
  int n;

public:
  void read()
  {
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter elements of A[" << n << "]:\n";
    for (int i = 0; i < n; i++)
    {
      cin >> A[i];
    }

    for (int i = 0; i < n; i++)
    {
      double sum = 0;
      for (int j = 0; j < A[i].Rm(); j++)
      {
        double X = A[i].RX(j);
        int y = A[i].Ry();
        if ((int)X % y == 0)
          sum += X * X;
      }
      B[i] = sum;
    }
  }
  void display()
  {
    cout << "\n=================\n";
    cout << "n: " << n << endl;

    cout << "A[" << n << "] = ";
    for (int i = 0; i < n; i++)
    {
      cout << A[i] << " ";
    }
    cout << endl;

    cout << "B[" << n << "] = ";
    for (int i = 0; i < n; i++)
    {
      cout << B[i] << " ";
    }
    cout << endl;
  }

  friend double maxAvg(Data);
  friend void cmprMaxAvg(Data, Data);
};

double maxAvg(Data obj)
{
  double max = obj.A[0].avg();

  for (int i = 1; i < obj.n; i++)
  {
    if (obj.A[i].avg() > max)
      max = obj.A[i].avg();
  }
  return max;
};

void cmprMaxAvg(Data obj_1, Data obj_2)
{
  double m1 = maxAvg(obj_1);
  double m2 = maxAvg(obj_2);
  if (m1 > m2)
  {
    cout << "The max average is: " << m1;
    cout << endl
         << "The max object is:\n";
    obj_1.display();
  }
};

int main()
{
  Data x, y;

  x.read();
  x.display();

  y.read();
  y.display();

  cmprMaxAvg(x, y);
}
