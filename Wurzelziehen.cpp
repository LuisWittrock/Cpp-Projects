#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	double g,sol,b,a;
	bool found = false;
	
	
	cout << "Von welcher Zahl wollen sie die Wurzel berechnen? " << endl;
	cout << "Eingabe: ";
	cin >> g;
	
	for(int i = 1; i<g; i++)
	{
		if(i*i <= g and (i+1)*(i+1) >= g)
		{
			a = i;
			break;
		}
	}
	while(!found)
	{
		
		cout << "a: " << a << endl << "b: " << b << endl;
		b = g/a;
		a = (a+b)/2;
		
		if((max(a,b)-min(a,b))<1e-9)
		{
			sol = a;
			found = true;
		}
	}
	
	cout << setprecision(5);
	cout << sol;
	
}
