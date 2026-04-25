#include <iostream>
using namespace std;

class Matrix
{
  float M[5][5];
  int n;
public:
  void read ()
  {
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter values of M[" << n << "][" << n - 1 << "]:\n";
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n - 1; j++)
        cin >> M[i][j];
  }
  float sumGivenIndex (int a)
  {
    float sum = 0;

    for (int j = 0; j < n - 1; j++)
    {
      sum += M[a][j];
    }
    return sum;
  }
  void set()
  {
    for (int i = 0; i < n; i++)
    {
      M[i][n - 1] = sumGivenIndex(i);
    }
  }
  void display()
  {
    cout << "n: " << n << endl;

    cout << "M[" << n << "][" << n << "]\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if(j + 1 == n)
        {
          cout << M[i][j] << "\n";
          break;
        }
        cout << M[i][j] << "\t";
      }
    }
  }
  // prefix
  Matrix operator-- ()
  {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        M[i][j]--;

    return *this;
  }
  // postfix
  Matrix operator-- (int)
  {
    Matrix temp = *this;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        M[i][j]--;

    return temp;
  }
  bool operator== (Matrix obj)
  {
    for (int i = 0; i < n; i++)
    {
      if(M[i][n - 1] != obj.M[i][n - 1])
        return false;
    }
    return true;
  }
  bool operator> (Matrix obj)
  {
    for (int i = 0; i < n; i++)
    {
      if(M[i][n - 1] > obj.M[i][n - 1])
        return true;
    }
    return false;
  }

  Matrix operator* (int a)
  {
    Matrix temp = *this;
  
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        temp.M[i][j] *= a;
      }
    }
  
    temp.set();
    return temp;
  }
};


int main()
{
  Matrix x, y, z;

  x.read();
  x.set();
  x.display();

  y.read();
  y.set();
  y.display();

  // z = --x;

  if (x == y)
    cout << "These objects are equal\n";
  else
    cout << "These objects are NOT equal\n";

  if (x > y)
  {
    cout << "The max object is X:\n";
    x.display();
  }
  else
  {
    cout << "The max object is Y:\n";
    y.display();
  }
}


