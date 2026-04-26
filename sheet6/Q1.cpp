#include <iostream>
using namespace std;

class EQN
{
  float A[20][20];
  int X[20];
  int n;

public:
  void read()
  {
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter values of X[" << n << "]:\n";
    for (int i = 0; i < n; i++)
      cin >> X[i];

    cout << "Enter values of A[" << n << "][" << n - 1 << "]:\n";
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n - 1; j++)
        cin >> A[i][j];
  }
  void setLastCol()
  {
    for (int j = 0; j < n; j++)
    {
      float sum = 0;
      for (int i = 0; i < n - 1; i++)
      {
        sum += A[j][i] * X[i];
      }
      A[j][n - 1] = sum;
    }
  }
  int Rn()
  {
    return n;
  }
  int operator[](int a)
  {
    return X[a];
  }
  EQN operator+=(int a)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        A[i][j] += a;
      }
    }
    setLastCol();
    return *this;
  }
  bool operator==(EQN obj)
  {
    for (int i = 0; i < n; i++)
    {
      if (X[i] != obj.X[i])
        return false;
    }
    return true;
  }
  bool operator>(EQN obj)
  {
    for (int i = 0; i < n; i++)
    {
      if (A[i][n - 1] < obj.A[i][n - 1])
        return false;
    }
    return true;
  }

  friend ostream &operator<<(ostream &, EQN &);
  friend EQN compareMax(EQN, EQN);
  friend void compareEqu(EQN, EQN);

};

ostream &operator<<(ostream &out, EQN &obj)
{
  cout << "The elements of A[" << obj.n << "][" << obj.n << "]:\n";
  for (int i = 0; i < obj.n; i++)
  {
    for (int j = 0; j < obj.n; j++)
    {
      out << obj.A[i][j] << " ";
    }
    out << endl;
  }
  return out;
};

EQN compareMax(EQN obj_1, EQN obj_2)
{
  // if (obj_1 > obj_2)
  //   return obj_1;
  // return obj_2;

  return (obj_1 > obj_2 ? obj_1 : obj_2);
};

void compareEqu(EQN obj_1, EQN obj_2)
{
  if(obj_1 == obj_2)
    cout << "Are the same\n";
  else
    cout << "Are NOT the same\n";
};


int main()
{
  EQN x, y, z;

  x.read();
  x.setLastCol();
  
  y.read();
  y.setLastCol();

  cout << "x:object__ elements of array: ";
  for (int i = 0; i < x.Rn(); i++)
  {
    cout << x[i] << " ";
  }
  cout << "\n===================\n";

  compareEqu(x, y);
}
