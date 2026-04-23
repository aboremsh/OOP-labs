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
            {
                cout << "Dim[" << i << "][" << j << "]: ";
                cin >> Dim[i][j];
            }
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
        Rectangle::read();

        for (int i = 0; i < 10; i++)
        {
            RA[i] = area(i);
        }
    }
    void Print()
    {
        cout << "RA[10]: {";
        
        for (int i = 0; i < 10; i++)
        {
            if(i + 1 == 10)
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
        cout << "Enter vaules of H[10]: ";
        for (int i = 0; i < 10; i++)
        {
            cin >> H[i];
        }
        
        // Rectangle::read();
        RArea::set();

        for (int i = 0; i < 10; i++)
        {
            V[i] = H[i] * RA[i];
        }
    }
    void Print()
    {
        cout << "H[10]: {";
        for (int i = 0; i < 10; i++)
        {
            if(i + 1 == 10)
            {
                cout << H[i] << "}\n";
                break;
            }
            cout << H[i] << ", ";
        }

        cout << "V[10]: {";
        for (int i = 0; i < 10; i++)
        {
            if(i + 1 == 10)
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
