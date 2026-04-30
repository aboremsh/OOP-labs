#include <iostream>
using namespace std;

class Base
{
protected:
    float B[30];
    int n;
    int x;
    int y;
public:
    void read()
    {
        cout << "Enter larger than 0 for x: ";
        do
        {
            cin >> x;
        } while (x < 0);
        
        cout << "Enter larger than 0 for y: ";
        do
        {
            cin >> y;
        } while (y < 0);
        
        cout << "Enter n: ";
        cin >> n;

        cout << "Enter values of B[" << n << "]:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
        }
    }
    float Max()
    {
        float max = B[0];

        for (int i = 1; i < n; i++)
        {
            if(B[i] > max)
                max = B[i];
        }
        return max;
    }
    int FactMax()
    {
        int ele = (int) Max();
        int result = 1;

        for (int i = ele; i > 0; i--)
        {
            result *= i;    
        }
        return result;
    }
    void display()
    {
        cout << "n: " << n << endl;
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;

        cout << "Values of B[" << n << "] = ";
        for (int i = 0; i < n; i++)
        {
            cout << B[i] << " ";
        }
        cout << endl;
    }
};

class Drive1 : virtual public Base
{
protected:
    double D1[30];
public:
    void virtual set()
    {
        Base::read();

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 1; j < B[i] + 1; j++)
            {
                if ((int) B[i] % x == 0)
                {
                    sum += x * j * j;
                } else {
                    sum += x * j * j * j;
                }
            }
            D1[i] = sum;
        }
    }
    double Max()
    {
        double max = D1[0];

        for (int i = 1; i < n; i++)
        {
            if(D1[i] > max)
                max = D1[i];
        }
        return max;
    }
    int FactMax()
    {
        int ele = (int) Max();
        int result = 1;

        for (int i = ele; i > 0; i--)
        {
            result *= i;    
        }
        return result;
    }
};

class Drive2 : virtual public Base
{
protected:
    double D2[30];
public:
    void virtual set()
    {
        Base::read();

        for (int i = 0; i < n; i++)
        {
            int multi = 1;
            for (int j = 1; j < B[i] + 1; j++)
            {
                if ((int) B[i] % y == 0)
                {
                    multi *= y * j * j * j;
                } else {
                    multi *= y * j * j;
                }
            }
            D2[i] = multi;
        }
    }
    double Max()
    {
        double max = D2[0];

        for (int i = 1; i < n; i++)
        {
            if(D2[i] > max)
                max = D2[i];
        }
        return max;
    }
    int FactMax()
    {
        int ele = (int) Max();
        int result = 1;

        for (int i = ele; i > 0; i--)
        {
            result *= i;    
        }
        return result;
    }
};

class Drive : public Drive1, public Drive2
{
    double D3[3];
    double S;
public:
    void set()
    {
        // Base::read();
        Drive1::set();
        Drive2::set();

        for (int i = 0; i < 3; i++)
        {
            D3[i] = 
        }
        
    }
};








int main()
{

}
