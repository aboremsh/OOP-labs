#include <iostream>
using namespace std;

class Data1
{
protected:
    string S1;
    double D1[20];
    int a;
    int n;
public:
    void read()
    {
        cout << "Enter S1: ";
        cin >> S1;

        cout << "Enter n For Data1: ";
        cin >> n;

        cout << "Enter elements of D1[" << n << "]:\n";
        for (int i = 0; i < n; i++)
        {
            cout << "D[" << i << "]: ";
            cin >> D1[i];
        }

        cout << "Enter a: ";
        cin >> a;
    }
    double Sum()
    { 
        double sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            if(int(D1[i]) % a == 0)
                sum += D1[i] * D1[i];
            else
                sum += D1[i] * D1[i] * D1[i];
        }

        return sum;
    }
    double SumEle()
    {
        double sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            sum += D1[i];
        }

        return sum;
    }
    void display()
    {
        cout << "S1: " << S1 << endl;
        cout << "a: " << a << endl;
        cout << "n: " << n << endl;
        
        for (int i = 0; i < n; i++)
            cout << "D1[" << i << "]: " << D1[i] << endl;
    } 
};

class Data2
{
protected:
    string S2;
    double D2[20];
    int b;
    int m;
public:
    void read()
    {
        cout << "Enter S2: ";
        cin >> S2;

        cout << "Enter m of Data2: ";
        cin >> m;

        cout << "Enter elements of D2[" << m << "]:\n";
        for (int i = 0; i < m; i++)
        {
            cout << "D[" << i << "]: ";
            cin >> D2[i];
        }

        cout << "Enter b: ";
        cin >> b;
    }
    double Sum()
    {
        double sum = 0;

        for (int i = 0; i < m; i++)
        {
            if(int(D2[i]) > b)
                sum += 2 * (D2[i] * D2[i]);
            else
                sum += 3 * (D2[i] * D2[i] * D2[i]);
        }
        
        return sum;
    }
    double SumEle()
    {
        double sum = 0;
        
        for (int i = 0; i < m; i++)
        {
            sum += D2[i];
        }

        return sum;
    }
    void display()
    {
        cout << "S2: " << S2 << endl;
        cout << "b: " << b << endl;
        cout << "m: " << m << endl;
        
        for (int i = 0; i < m; i++)
            cout << "D2[" << i << "]: " << D2[i] << endl;
    }
};

class Data : public Data1, public Data2
{
    string ND;
    double Sum_T;
public:
    void read()
    {
        Data1::read();
        Data2::read();

        cout << "Enter ND: ";
        cin >> ND;

        Sum_T = Data1::Sum() + Data2::Sum();
    }
    double avg()
    {
        return ((Data1::SumEle() + Data2::SumEle()) / (n + m));
    }
    void display()
    {
        Data1::display();
        Data2::display();

        cout << "ND: " << ND << endl;
        cout << "Sum_T: " << Sum_T << endl;
    }
};


int main()
{
    Data child;

    child.read();
    cout << "Avg is: " << child.avg() << endl;
    child.display();
}
