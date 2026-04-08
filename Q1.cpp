// 1 Question to ask at line: 71. about using pointer, Have I use it there?
#include <iostream>
using namespace std;

int abs(int num);

class Data
{
  int A[30];
  double S[30];
  int n;

public:
  int fact(int num)
  {
    int result = 1;
    if (num < 0)
      return 0;
    if (num == 0)
      return 1;
    for (int i = num; i > 0; i--)
      result *= i;
    return result;
  }
  double binomial(int a, int b)
  {
    if (a < 0)
      a *= -1;
    if (b < 0)
      b *= -1;
    return (double(fact(a)) / (fact(b) * fact(a - b)));
  }
  void read()
  {
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter a NON ZERO value for A[" << n << "]:\n";
    for (int i = 0; i < n; i++)
    {
      do
      {
        cout << "A[" << i << "]: ";
        cin >> A[i];
      } while (A[i] == 0);
    }
  }
  void setS()
  {
    for (int i = 0; i < n; i++)
    {
      S[i] = 0;
      for (int k = 0; k < i + 1  && k < n; k++)
        S[i] += binomial(i + 1, k + 1) * abs(A[k]);
    }
  }
  double sumS()
  {
    double sum = 0;
    for (int i = 0; i < n; i++)
      sum += S[i];
    return sum;
  }
  void display()
  {
    cout << "n: " << n << endl;
    cout << "A[" << n << "]\t\tS[" << n << "]\n";
    for (int i = 0; i < n; i++)
      cout << A[i] << "\t\t" << S[i] << endl;
  }
  // ++ prefix
  Data operator++()
  {
    for (int i = 0; i < n; i++)
      A[i]++;
    return *this;
  }
  // postfix ++
  Data operator++(int)
  {
    Data temp = *this;
    for (int i = 0; i < n; i++)
      A[i]++;
    return temp;
  }
  // X + constant => X.operator+(constant)
  Data operator+(int a)
  {
    Data temp;
    for (int i = 0; i < n; i++)
      temp.A[i] = A[i] + a;
    temp.setS();
    return temp;
  }
  // X < Y => X.opeerator<(Y)
  bool operator<(Data a)
  {
    return (sumS() < a.sumS());
  }
  bool operator!=(Data a)
  {
    for (int i = 0; i < n; i++)
      if (A[i] != a.A[i])
        return true;
    return false;
  }
};

int main()
{
  Data x, y, z;

  x.read();
  x.setS();
  x.display();
  z = x++;

  y.read();
  y.setS();
  y.display();
  z = ++y;
  

  if (x.sumS() < y.sumS())
    cout << "The min sum is " << x.sumS();
  else
    cout << "The min sum is " << y.sumS();

  if(x != y)
    cout << "These objects are NOT the same";
  else
    cout << "These objects are the same";
}

int abs(int num)
{
  if (num < 0)
    num *= -1;
  return num;
}