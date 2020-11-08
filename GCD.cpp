#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int a,b,rest,x=1;
	
	cout << "Eingabe: ";
	cin >> a >> b;
	
	bool found = false;
	
	
	
	while(!found)
	{
		for(int i = 1; i<max(a,b); i++)
		{
			if(i*min(a,b)<max(a,b) and i+1*min(a,b)>max(a,b))
			{
				x=i;
				break;
			}
		}
		rest = max(a,b) - x*min(a,b);
		
		if(rest == 0)
		{
			break;
		}
		a = min(a,b);
		b = rest;
		
	}
	cout << endl << "Der GCD ist: " << min(a,b);
}
