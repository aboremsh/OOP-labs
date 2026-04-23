#include <iostream>
using namespace std;

class Rectangle
{
protected:
    float Dim[10][2];
    int n;

public:
    void read()
    {
        cout << "Enter num. of rows n: ";
        cin >> n;

        cout << "Enter values of Matrix Dim[" << n << "][2]:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 2; j++)
                cin >> Dim[i][j];
    }
    float area(int a)
    {
        return (Dim[a][0] * Dim[a][1]);
    }
    void Print()
    {
        cout << "n: " << n << endl;

        cout << "Dim[" << n << "][2]:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << Dim[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

class RArea : public Rectangle
{
protected:
    float RA[10];

public:
    void set()
    {

        for (int i = 0; i < n; i++)
        {
            RA[i] = area(i);
        }
    }
    void Print()
    {
        cout << "RA[" << n << "]: {";

        for (int i = 0; i < n; i++)
        {
            if (i + 1 == n)
            {
                cout << RA[i] << "}\n";
                break;
            }
            cout << RA[i] << ", ";
        }
    }
};

class P_volume : public RArea
{
    float H[10];
    float V[10];

public:
    void set()
    {
        Rectangle::read();
        RArea::set();

        cout << "Enter vaules of H[" << n << "]:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> H[i];
        }

        for (int i = 0; i < n; i++)
        {
            V[i] = H[i] * RA[i];
        }
    }
    void Print()
    {
        cout << "H[" << n << "]: {";
        for (int i = 0; i < n; i++)
        {
            if (i + 1 == n)
            {
                cout << H[i] << "}\n";
                break;
            }
            cout << H[i] << ", ";
        }

        cout << "V[" << n << "]: {";
        for (int i = 0; i < n; i++)
        {
            if (i + 1 == n)
            {
                cout << V[i] << "}\n";
                break;
            }
            cout << V[i] << ", ";
        }
    }
};

int main()
{
    P_volume obj;

    obj.set();
    obj.Print();
}
