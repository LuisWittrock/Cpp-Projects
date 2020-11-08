#include <iostream>
#include <fstream>

using namespace std;

ofstream outFile;	//in datei schreiben.
ifstream inFile;	//aus datei lesen.
int numberOfLines = 1; 

class Bank
{
	private:
		int	lineNumber; 
		string account_number;
		string firstName;
		string lastName;
		double balance;
	public:
		void addRecord();
		void showData();
		void searchRecord();
		void mainMenu();
		void writeData();
};

void Bank::addRecord()	//füge einen eintrag hinzu mit ACCOUNTNUMMER, FIRST NAME, LAST NAME, BALANCE.
{
	cout << "Account Number: ";
	cin >> account_number;
	cout << endl;
	
	cout << "First Name: ";
	cin >> firstName;
	cout << endl;
	
	cout << "Last Name: ";
	cin >> lastName;
	cout << endl;
	
	cout << "Balance: ";
	cin >> balance;
	cout << endl;
}
void Bank::showData()	//zeige den jetzigen mit addRecord  erstellten eintrag.
{
	cout << "Account Number: " << account_number << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Balance: " << balance << endl;
	mainMenu();
}
void Bank::writeData()	//eingegebenen daten in Datei schreiben.
{
	addRecord();
	outFile.open("Database.txt", ios::app);
	
	outFile << numberOfLines << " " << account_number <<" "<< firstName <<" "<< lastName <<" "<< balance << endl;
	numberOfLines++;
	outFile.close();
	mainMenu();
}
void Bank::searchRecord()	//einen eintrag mit einer Nummer suchen.
{
	inFile.open("Database.txt");
	int suchen;
	cout << "Suche..." << endl;
	cout << "Es gibt " << numberOfLines-1 << " Einträge. " << endl;
	
	do
	{
		cout << "Bitte wählen sie einen: ";
		cin >> suchen;
	}
	while(suchen < 0 or suchen > numberOfLines);
	
	while(inFile >> lineNumber >> account_number >> firstName >> lastName >> balance)
	{
		cout << lineNumber;
		if(lineNumber == suchen)
		{
			break;
		}
	}
	
	inFile.close();
	showData();
}
void Bank::mainMenu()	//hauptmenu.
{
	int option;
	cout << "************************************************************" << endl;
	cout << "Wählen sie eine option.";
	cout << endl << "Drücken sie 1 um einen Eintrag hinzuzufügen.";
	cout << endl << "Drücken sie 2 um einen Eintrag anzuzeigen";
	cout << endl << "Drücken sie 3 um einen Eintrag zu suchen";
	cout << endl << "Drücken sie 4 um das Programm zu Schließen" << endl;
	cout << "************************************************************" << endl;
	
	
	
	
	do
	{
		cout << "Eingabe: ";
		cin >> option;
	}
	while(option < 0 or option > 4);
	
	
	cout << endl;
	
	switch(option)
	{
		case 1:
			writeData();
			break;
		case 2:
			showData();
			break;
		case 3:
			searchRecord();
			break;
		case 4:
			cout << endl << "Tschüss..." << endl;
			exit(1);
		
	}
		
}



int main()
{
	inFile.open("Database.txt");
	string unused;
	while(getline(inFile, unused))
	{
		numberOfLines++;
	}
	inFile.close();
	cout << "Einträge: "<< numberOfLines-1 << endl;
	
	Bank A;
	A.mainMenu();
}

























