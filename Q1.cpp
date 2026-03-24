/*1. Write a program contains a function to check if a given positive number prime or
not. This program contains two classes Data1 and Data2. A class Data1 has data
members: D1[20][20] (float), n (dimension of D1), a function to read data
members: n, D1 except the last row in D1, and set the elements of last row in D1
such that each element D1(n-1,i) is the max element in column i (i=0,..,n-1), a
function to return the sum of prime elements in D1 for last row, and a function to
display the data member D1 in a matrix form. 
Class Data2 has data members: D2[20] (float), m ( number of elements of D2), a function to read data members , a
function to return the sum of all prime numbers in D2, and a function to display
data member D2 in a vector form. These classes contain the following friend
functions:
i. Function to compare between the objects’ sum for two given objects of two
classes, and display the object with min value.
ii. Function to return the average of the objects’ sum for two given objects of
two classes.
 In main function define objects of two classes, and call all functions on them.
*/

//#include <iostream>
//using namespace std;
//
//bool isPrime(int num);
//
//class Data2;
//class Data1
//{
//private:
//	float D1[20][20];
//	int n;
//public:
//	void set()
//	{
//		cout << "Enter n: ";
//		cin >> n;
//		cout << "Enter the matrix D1[" << n << "][" << n << "]:\n";
//		for (int i = 0; i < n - 1; i++)
//			for (int j = 0; j < n; j++)
//				cin >> D1[i][j];
//		
//		for (int i = 0; i < n; i++)
//		{
//			float max = D1[0][i];
//			for (int j = 0; j < n - 1; j++)
//				if (D1[j][i] > max) max = D1[j][i];
//			D1[n - 1][i] = max;
//		}
//	}
//	void display()
//	{
//		cout << "The matrix D1[" << n << "][" << n << "] is:\n";
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//			{
//				cout << D1[i][j] << " ";
//				if (j + 1 == n) cout << endl;
//			}
//	}
//	int sumOfPrimes()
//	{
//		int sum = 0;
//		for (int j = 0; j < n; j++)
//			if (isPrime((int)D1[n - 1][j])) sum += (int)D1[n - 1][j];
//		return sum;
//	}
//	friend void cmprSum(Data1, Data2);
//	friend double avg(Data1, Data2);
//};
//
//class Data2
//{
//private:
//	float D2[20];
//	int m;
//public:
//	void read()
//	{
//		cout << "Enter m: ";
//		cin >> m;
//		cout << "Enter elements of D2[" << m << "]:\n";
//		for (int i = 0; i < m; i++)
//			cin >> D2[i];
//	}
//	float sumOfPrimes()
//	{
//		int sum = 0;
//		for (int i = 0; i < m; i++)
//			if (isPrime((int)D2[i])) sum += (int)D2[i];
//		return sum;
//	}
//	void displayHor()
//	{
//		cout << "The vector array is:\n";
//		cout << "(";
//		for (int i = 0; i < m; i++)
//		{
//			if (i + 1 == m)
//			{
//				cout << D2[i] << ")";
//				break;
//			}
//			if(i < m) cout << D2[i] << ", ";
//		}
//		cout << endl;
//	}
//	void displayVer()
//	{
//		cout << "The vector array is:\n";
//		cout << "[";
//		for (int i = 0; i < m; i++)
//		{
//			if (i == 0)
//			{
//				cout << D2[i] << endl;
//				continue;
//			}
//			if (i + 1 == m)
//			{
//				cout << " " << D2[i] << "]";
//				break;
//			}
//			if(i < m) cout << " " << D2[i] << "\n";
//		}
//	}
//	friend void cmprSum(Data1, Data2);
//	friend double avg(Data1, Data2);
//};
//
//void cmprSum(Data1 a, Data2 b)
//{
//	if (a.sumOfPrimes() > b.sumOfPrimes()) 
//	{
//		cout << "\nThe min class is:\n";
//		b.displayHor();
//	}
//	else
//	{
//		cout << "\nThe min class is:\n";
//		a.display();
//	}
//}
//
//double avg(Data1 a, Data2 b)
//{
//	return (a.sumOfPrimes() + b.sumOfPrimes()) / 2;
//}
//
//int main()
//{	
//	Data1 x;
//	x.set();
//	x.display();
//
//	Data2 y;
//	y.read();
//	y.displayHor();
//	y.displayVer();
//
//	cmprSum(x, y);
//	cout << "The avg is: " << avg(x, y);
//}
//
//bool isPrime(int num)
//{
//	if (num <= 1) return false;
//	bool flag = true;
//	for (int i = 2; i < num; i++)
//		if (num % i == 0) flag = false;
//	return flag;
//}