#include <iostream>
using namespace std;
/*

*/

class Matrix
{
  float M[20][20];
  int n;

public:
  void read()
  {
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter M[" << n << "][" << n - 1 << "]\n";
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n - 1; j++)
        cin >> M[i][j];
  }
  float sumForGivenIndex(int a)
  {
    float sum = 0;
    for (int i = 0; i <= n - 2; i++)
      sum += M[a][i];
    return sum;
  }
  void setLastCol()
  {
    for (int i = 0; i < n; i++)
      M[i][n - 1] = sumForGivenIndex(i);
  }
  void display()
  {
    cout << "M[" << n << "]:\n";
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        if (j + 1 == n)
        {
          cout << M[i][j] << endl;
          break;
        }
        cout << M[i][j] << " ";
      }
  }
  Matrix operator++()
  {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        M[i][j]++;
    return *this;
  }
  // postfix ++
  Matrix operator++(int)
  {
    Matrix temp = *this;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        M[i][j]++;
    return temp;
  }
  Matrix operator*(int a)
  {
    Matrix mat = *this;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        mat.M[i][j] *= a;
    mat.setLastCol();
    return mat;
  }
  bool operator==(Matrix a)
  {
    for (int i = 0; i < n; i++)
      if (M[i][n - 1] == a.M[i][n - 1])
        return true;
    return false;
  }
  bool operator>(Matrix a)
  {
    bool flag = false;
    for (int i = 0; i < n; i++)
      if (M[i][n - 1] > a.M[i][n - 1])
        flag = true;
    return flag;
  }
};

int main()
{
  Matrix x, y, z;

  x.read();
  x.setLastCol();
  x.display();

  y.read();
  y.setLastCol();
  y.display();

  z = ++x;

  if (x == y)
    cout << "These objects are equal\n";
  else
    cout << "These objects are NOT equal\n";

  if (x > y)
  {
    cout << "The max object is:\n";
    x.display();
  }
  else
  {
    cout << "The max object is:\n";
    y.display();
  }
}
