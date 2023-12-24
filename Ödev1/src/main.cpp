#include <fstream>
#include <string>
#include <sstream>
#include "Numbers.hpp"
#include "List.hpp"

int main()
{	
	try
	{
		List *All = new List();
		ifstream Text ("Numbers.txt", ios::in);
		int read;
		
		while(!(Text.eof()))
		{
			Numbers *Num = new Numbers();
			Text >> read;
			int digit = 0;
			int tmp = read;
			while(tmp > 0)
			{
				tmp = tmp / 10;
				digit++;
			}
			tmp = read;
			while(digit > 0)
			{
				int dig = tmp % 10;
				tmp = tmp / 10;
				Num->add(dig);
				digit--;
			}
			All->add(Num);
		}
		
		// MENU
		
		// Print Numbers, Addresses, Digits...
		for(int Local = 0; Local < All->count(); Local++)
		{
			cout << "##########  ";
		
			for(int i = 0; i < All->GetNode(Local)->GetNumber()->count(); i++)
			{
				cout << "******* ";
			}
			cout << "\n";
			cout << "#" << All->GetNode(Local)->GetNumber() << "#  ";
			
			for(int index = 0; index < All->GetNode(Local)->GetNumber()->count(); index++)
			{
				ostringstream pts;
				pts << All->GetNode(Local)->GetNumber()->GetDigitNode(index);
				string ptsS = pts.str();
				cout << "* " << ptsS.substr(5, 3) << " * ";
			}
			cout << "\n" << "#--------#  "; 
			for(int i = 0; i < All->GetNode(Local)->GetNumber()->count(); i++)
			{
				cout << "******* ";
			}
			cout << "\n" << "#";
			for(int i = 0; i < 8 - All->GetNode(Local)->GetNumber()->count(); i++)
			{
				cout << " ";
			}
			for(int index = 0; index < All->GetNode(Local)->GetNumber()->count(); index++)
			{
				cout << All->GetNode(Local)->GetNumber()->GetDigitNode(index)->Digit;
			}
			cout << "#  ";
			for(int index = 0; index < All->GetNode(Local)->GetNumber()->count(); index++)
			{
				cout << "*   " << All->GetNode(Local)->GetNumber()->GetDigitNode(index)->Digit << " * ";
			}
			cout << "\n" << "##########  ";
			for(int i = 0; i < All->GetNode(Local)->GetNumber()->count(); i++)
			{
				cout << "******* ";
			}			
			cout << "\n\n";
		}
		
		int choice;
		do
		{
			
			cout << "1. Tek Basamaklari Basa Al" << endl;
			cout << "2. Basamaklari Tersle" << endl;
			cout << "3. En Buyuk Sayiyi Cikar" << endl;
			cout << "4. Cikis Yap" << endl;
			cout << "Seciminiz: ";
			cin >> choice;
			switch(choice)
			{
				default:
					cout << "\n Yanlis Bir Deger Girdiniz. Tekrar Deneyiniz. \n";
					continue;
			}
		}while(choice != 4);
		
		
		Text.close();
		delete All;
	}
	
	catch(const char *text)
	{
		cout << text;
	}
	
	return 0;
}