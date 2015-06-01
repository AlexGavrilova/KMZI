// caesar.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int main(int argc, char* argv[])
{
	int EnDec;
	if (argc != 4)
	{
		cout << "Incorrect string! Enter arguments as: input.txt output.txt key. \n";
		return 0;
	}
	ifstream infile;
	infile.open(argv[1], ios::in);
	ofstream outfile;
	outfile.open(argv[2], ios::out);
	if ((infile.fail()) || (outfile.fail()))
	{
		cout << "Error: openning file.\n";
		return 0;
	}
	cout << "Choose ciper:\n";
	cout << "1. Cesar\n";
	cout << "2. Vijiner\n";
	int k;
	cin >> k;
	switch (k)
	{
	case 1:
	{
			  cout << "1. Encryption \n2. Decruption\n";
			  cin >> EnDec;
			  char brr;
			  int shift = atoi(argv[3]) % 256;
			  string result = "";
			  while (!infile.eof())
			  {
				  brr = infile.get();
				  if (brr != EOF)
				  {
					  if (EnDec == 1)
						  brr = (brr + shift) % 256;
					  if (EnDec == 2)
						  brr = (brr - shift) % 256;
					  result = result + brr;
				  }
			  }
			  cout << "Result: " << result << "\n";
			  outfile << result;
			  break;


	}
	case 2:
	{
			  cout << "1. Encryption \n2. Decruption\n";
			  cin >> EnDec;
			  char brr;
			  string s = argv[3];
			  string result = "";
			  string::iterator i = s.begin();
			  while (!infile.eof())
			  {
				  brr = infile.get();
				  if (brr != EOF)
				  {
					  if (EnDec == 1)
						  brr = (brr + *i) % 256;
					  if (EnDec == 2)
						  brr = (brr - *i) % 256;
					  result = result + brr;
					  if (i + 1 == s.end())
						  i = s.begin();
					  else
						  i++;
				  }
			  }
			  cout << "Result: " << result << "\n";
			  outfile << result;
			  break;
	}
	default:
	{
			   cout << "Error!\n";
			   break;
	}
	}
	infile.close();
	outfile.close();
	return 0;
}
