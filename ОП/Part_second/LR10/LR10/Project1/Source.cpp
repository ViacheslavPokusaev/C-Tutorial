#include<iostream>
#include<math.h>
#define N 7
using namespace std;

// usual recurtion
double RecursArth(double x, int Count)
{
	if (Count == 1) return x; // exit from recurtion

	return (pow(x, Count) / Count) + RecursArth(x, Count - 2); // count sum and work with steck
}
// tail recurtion
double TailRecursArth(double x, int Count, double prev)
{
	if (Count == 1) return prev; // exit from recurtion

	return TailRecursArth(x, Count - 2, prev + (pow(x, Count) / Count)); // count sum and work with steck
}
// iteration recurtion
double Arth(double x)
{
	double arth = x, a = x; // save begining data
	for (int i = 1; i < N; i++)
	{
		a *= x * x; // count x^
		arth += a / (2 * i + 1); // count sum and save into value
	}
	return arth;
}
// recurtion with accuracy
double FuncArth(double x, double accuracy)
{
	// aN - cout numbers
	// aEps - , ...
	// aT - current member of the series
	double term = x;
	double sum = term;
	int	aN = 1;
	while (fabs(term) > accuracy)
	{
		term = 1;
		for (int i = 1; i <= 2 * aN + 1; i++)
			term *= x;
		term /= (2 * aN + 1);
		sum += term;
		++aN;
	}

	return sum;
}

int main()
{
	double x, accuracy;
	int count_iteration;

	while (true)
	{
		cout << "Enter x: "; cin >> x;

		while (x < -1 && x > 1)
		{
			x /= 10;
		}

		cout << "Enter count iteration (>0): "; cin >> count_iteration;

		while (count_iteration < 0)
		{
			cout << "Count iteration have to be > 0!\n";
			cout << "Enter count iteration (>0): "; cin >> count_iteration;
		}

		cout << "Enter accuracy (>0): "; cin >> accuracy;

		while (accuracy <= 0)
		{
			cout << "Accuracyhave to be > 0!\n";
			cout << "Enter accuracy (>0): "; cin >> accuracy;
		}

		cout << "RESULTS\n\n";
		cout << "Arth(" << x << ") = " << FuncArth(x, accuracy) << endl;
		cout << "Arth(" << x << ") = " << Arth(x) << endl;

		if (count_iteration % 2 == 0) count_iteration++;
		cout << "Arth(" << x << ") = " << RecursArth(x, count_iteration) << endl;
		cout << "Arth(" << x << ") = " << TailRecursArth(x, count_iteration, x) << endl;

		cout << "\n\n";
		system("pause");
		system("cls");
	}

	
	return 0;
}