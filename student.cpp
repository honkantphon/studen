#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;
void numbervote(int chairman, int Data[]);
void calnumbervote(int chairman, int Data[], int &sumvote, int &sumnotvote);
void calpercent(int chairman, int Data[], float percent[]);
void report(int chairman, int Data[], float percent[], int sumvote);
int main()
{
	srand((unsigned int) time(0));
	int Data[1024] = {0};
	int chairman;
	int sumvote=0;
	int sumnotvote=0;
	float percent[1024];

	cout << "Enter number student chairman : ";
	cin >> chairman;
	cout << "\n";
	cout << "Number of right student : 500\n";

	numbervote(chairman, Data);
	calnumbervote(chairman, Data, sumvote, sumnotvote);
	cout << "Number of Votes : " << sumvote << " = " << fixed << setprecision(1) << (sumvote/(float)500)*100 << "%\n";
	cout << "Number of not Votes : " << sumnotvote << " = " << fixed << setprecision(1) << (sumnotvote/(float)500)*100 << "%\n\n";

	calpercent(chairman, Data, percent);
	report(chairman, Data, percent, sumvote);

	return(0);
}
void numbervote(int chairman, int Data[])
{
	int vote;
	for(int i=1; i<=500; i++){
		vote = (rand() % (chairman+1));
		Data[vote]++;
	}
}
void calnumbervote(int chairman, int Data[], int &sumvote, int &sumnotvote)
{
	for(int i=0; i<chairman; i++){
		sumvote += Data[i];
	}
	sumnotvote = Data[chairman-1];
}
void calpercent(int chairman, int Data[], float percent[])
{
	for(int i=0; i<chairman; i++){
		percent[i] = (Data[i]/(float)500)*100;
	}
}
void report(int chairman, int Data[], float percent[], int sumvote)
{
	cout << "Result of election chairman\n";
	cout << setfill('-') << setw(44) << "-" << "\n";
	cout << setfill(' ');
	cout << setw(5) << "No." << setw(10) << "Votes" << setw(20) << "Percent(%)\n";
	cout << setfill('-') << setw(44) << "-" << "\n";
	cout << setfill(' ');

	for(int i=0; i<chairman; i++){
		cout << setw(5) << i+1 << "."
			 << setw(10) << Data[i]
			 << setw(20) << fixed << setprecision(2) << percent[i] << "\n";
	}
	cout << setfill('-') << setw(44) << "-" << "\n";
	cout << setfill(' ');
	
	cout << setw(5) << "Total"
		 << setw(10) << sumvote
		 << setw(20) << "100.00\n";
}