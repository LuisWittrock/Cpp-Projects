#include <iostream>
#include <math.h>

using namespace std;
/* h² = q * p,	p = a²/c,	q = c - p*/

class Dreieck{
	
	public:
	
		
		float katheteA, katheteB;
		float hypothenuse(){
			return sqrt(katheteA*katheteA+katheteB*katheteB);
		}
		float flaeche(){
			return katheteA * katheteB / 2;
		}
		float p(){
			return katheteA * katheteA / hypothenuse();
		}
		float q(){
			return hypothenuse() - p();
		}
		float hoehe(){
			return sqrt(q() * p());
		}
		
};


int main()
{
	Dreieck dreieck;
	cout << "Rechtwinklige Dreiecke: " << "\n" << "\n" << "\n";
	
	cout << "Seite A: ";
	cin >> dreieck.katheteA;
	
	cout << "Seite B: ";
	cin >> dreieck.katheteB;
	
	cout <<"\n"<< "Seite c: "<< dreieck.hypothenuse() << "\n" << "Fläche: " << dreieck.flaeche() << "\n" << "\n" << "p: "
		 << dreieck.p() << "\n" << "q: " << dreieck.q() << "\n" << "Höhe: " << dreieck.hoehe() << "\n" ;
 
	
	}
