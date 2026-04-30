#include <iostream>
using namespace std;

class Data1
{
protected:
  float D1[30][30];
  int n;

public:
  void read()
  {
    cout << "Enter n: ";
    cin >> n;

    cout << "Enter values of D1[" << n << "][" << n - 1 << "]:\n";
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n - 1; j++)
      {
        cin >> D1[i][j];
      }
    }
  }
  bool isPrime(int a)
  {
    bool flag = true;
    for (int i = 2; i < a; i++)
    {
      if (a % i == 0)
      {
        flag = false;
        break;
      }
    }
    return flag;
  }
  int maxPrime(int a)
  {
    // int k = 0;
    // -----------
    // while (k < n && !isPrime(D1[]))
    // {
    //   k++;
    // }
    // -----------
    // if (k == n)
    // {
    //   cout << "NO PRIME FOUND :(\n";
    //   return -1;
    // }
    // -----------
    // int max = (int)D1[a][k];
    // -----------
    // for (int i = k + 1; i < n - 1; i++)
    // {
    //   int ele = (int)D1[a][i];
    // -----------
    //   if (isPrime(ele) && ele > max)
    //     max = ele;
    // }
    
    int max = -999999;

    for (int i = 0; i < n - 1; i++)
    {
      int ele = (int) D1[a][i];
      if(isPrime(ele) && ele > max)
        max = ele;
    }

    return max;
  }
  void virtual set()
  {
    for (int i = 0; i < n; i++)
    {
      D1[i][n - 1] = maxPrime(i);
    }
  }
  float virtual avg()
  {
    float sum = 0;

    for (int i = 0; i < n; i++)
    {
      sum += D1[i][n - 1];
    }
    return (sum / n);
  }
  void Dis_avg()
  {
    cout << "The average of last col. is: " << avg() << endl;
  }
  /*===========================*/
  void virtual display()
  {
    this->display();
  }
  /*===========================*/
};

class Data : public Data1
{
  float D[30];

public:
  int fact(int a)
  {
    int result = 1;

    for (int i = a; i > 0; i--)
    {
      result *= i;
    }
    return result;
  }
  void set()
  {
    Data1::read();
    Data1::set();

    for (int i = 0; i < n; i++)
    {
      D[i] = fact((int)D1[i][n - 1]);
    }
  }
  void display()
  {
    cout << "The values of D[" << n << "] = ";
    for (int i = 0; i < n; i++)
    {
      cout << D[i] << " ";
    }
    cout << endl;
  }
  float avg()
  {
    float sum = 0;

    for (int i = 0; i < n; i++)
    {
      sum += D[i];
    }
    return sum;
  }
};

int main()
{
  Data1 *p, X;
  Data Y;

  p = &X;
  p->read();
  p->set();

  cout << "The average of first obj: ";
  p->Dis_avg();

  p = &Y;
  p->set();
  p->display();

  cout << "The average of first obj: ";
  p->Dis_avg();
}
