/*2. Write a program contains a class XData that has data members: SX[30] (float) ,
X[30] (float), n (number of elements for SX and X), a function to read data
members X and n, and set the elements of SX such that each element SXi is
equal to the {#######} for i=0,.., n-1, and a function to display data
members in tabular form. It contains a friend class Data, this class has data
members: S[30](float), b (int), D[30] (float), a function to read data member b,
set the elements of D such that each element Di is equal (b + Xi) for i=0,..,n-1,
and set the elements of S such that each Si is equal to Di + 2SXi for i=0,..,n-1,
a function to return the max element in S, a function to return max element in
SX for a given object from XData, a function to compare between max SX and
max S and return the max value. It contains a function to return the following
average: {###} for given object of class XData. 
In main function define objects of two classes, and call all functions on them.*/


#include <iostream>
using namespace std;


class XData
{
private:
	float SX[30];
	float X[30];
	int n;
public:
	void read()
	{
		cout << "Enter n: ";
		cin >> n;

		cout << "Enter elements of X[" << n << "]:\n";
		for (int i = 0; i < n; i++)
			cin >> X[i];

		for (int i = 0; i < n; i++)
		{
			SX[i] = 0;
			for (int j = 0; j <= i; j++)
				SX[i] += (X[j] * X[j]) / (i + j + 1.0);
		}
	}
	void display()
	{
		cout << "n: " << n << endl;
		cout << "SX[" << n << "]\t\tX[" << n << "]:\n";
		for (int i = 0; i < n; i++)
		{
			cout << SX[i] << "\t\t" << X[i] << endl;
		}
	}
	friend class Data;
};

class Data
{
private:
	float S[30];
	float D[30];
	int b;
public:
	void read(XData a)
	{
		cout << "Enter b: ";
		cin >> b;

		for (int i = 0; i < a.n; i++)
		{
			D[i] = b + a.X[i];
			S[i] = D[i] + 2 * a.SX[i];
		}
	}
	float maxOfS(XData a)
	{
		float max = S[0];
		for (int i = 1; i < a.n; i++)
			if (S[i] > max) max = S[i];
		return max;
	}
	float maxOfSX(XData a)
	{
		float max = a.SX[0];
		for (int i = 1; i < a.n; i++)
			if (a.SX[i] > max) max = a.SX[i];
		return max;
	}
	float maxOfSXAndS(XData b)
	{
		float A = maxOfS(b);
		float B = maxOfSX(b);
		if (A > B) return A;
		else return B;
	}
};

	
int main()
{
	XData x;
	x.read();
	x.display();

	Data y;
	y.read(x);
	cout << "Max S = " << y.maxOfS(x) << endl;
	cout << "Max SX = " << y.maxOfSX(x) << endl;
	cout << "Max between them = " << y.maxOfSXAndS(x) << endl;
}