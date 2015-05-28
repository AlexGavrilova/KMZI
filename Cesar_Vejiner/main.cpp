// kmzi_1_itog.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <fstream>

using namespace std;
int main(int argc, char* argv[])
{
	int n;
	int j = atoi(argv[1]);
	int key; 
	string result = ""; 
	n = atoi(argv[2]);
	cout << n;
	ifstream in(argv[3]);
	switch (j)
	{
		/*======================================================================================================
															Caesar
		=======================================================================================================*/
	case 1:
	{
			  switch (n)
			  {
			  case 1: 
			  {
						  key = atoi(argv[4]);
						  if (key > 26)
							  key = key % 26; 
						  string s; 
						  getline(in, s);
						  cout << "Text: \n" << s << endl;
						  in.close();

						  cout << "The cipher text\n";

						  for (int i = 0; i < s.length(); i++)
						  {
							  if (((int)(s[i]) < 65) || ((int)(s[i]) > 122))
								  result += s[i];
							  if (((int)(s[i]) >= 97) && ((int)(s[i]) <= 122))
							  {
								  if ((int)(s[i]) + key > 122)
									  result += (char)((int)(s[i]) + key - 26);
								  else
									  result += (char)((int)(s[i]) + key);
							  }
							  if (((int)(s[i]) >= 65) && ((int)(s[i]) <= 90))
							  {
								  if ((int)(s[i]) + key > 90)
									  result += (char)((int)(s[i]) + key - 26);
								  else
									  result += (char)((int)(s[i]) + key);
							  }
						  }
						  cout << "Encryption complete! Result:\n";
						  cout << result;
						  break;
			  }
			  case 2:
			  {
						  cout << "Enter value shift for decryption\n";
						  cin >> key;
						  if (key > 26)
							  key = key % 26;

						  string s;
						  getline(in, s);
						  cout << "Text: \n" << s << endl;
						  in.close();
						  for (int i = 0; i < s.length(); i++)
						  {
							  if (((int)(s[i]) < 65) || ((int)(s[i]) > 122))
								  result += s[i];
							  if (((int)(s[i]) >= 97) && ((int)(s[i]) <= 122))
							  {
								  if ((int)(s[i]) - key < 97)
									  result += (char)((int)(s[i]) - key + 26);
								  else
									  result += (char)((int)(s[i]) - key);
							  }
							  if (((int)(s[i]) >= 65) && ((int)(s[i]) <= 90))
							  {
								  if ((int)(s[i]) - key < 65)
									  result += (char)((int)(s[i]) - key + 26);
								  else
									  result += (char)((int)(s[i]) - key);
							  }
						  }
						  cout << "\n";
						  cout << "Decryption complete! Result:\n";
						  cout << result; 
						  break;
			  }
			  default: 
			  {
						   cout << "Error!\n";
						   break;
			  }
			  }

			  break;
	}
		/*======================================================================================================
															Vijiner
		=======================================================================================================*/
	case 2:
	{
			  int k;
			  string result = ""; 
			  string key = ""; 
			  string mes = ""; 
			  string key_on_s = "";
			  bool flag;
			  int x = 0, y = 0; 
			  int registr = 0; 
			  char dublicat; 
			  int shift = 0; char **tabula_recta = new char *[26]; 
			  for (int i = 0; i < 26; i++)tabula_recta[i] = new char[26];
			  string alfabet = "abcdefghigklmnopqrstuvwxyz"; 
			  for (int i = 0; i < 26; i++)
			  for (int j = 0; j < 26; j++)
			  {
				  shift = j + i;
				  if (shift >= 26) shift = shift % 26;
				  tabula_recta[i][j] = alfabet[shift];
			  }

			  cout << "Enter encryption key:\n";
			  cin >> key;
			  cout << "Enter text:\n";
			  cin >> mes;

			  for (int i = 0; i < mes.length(); i++)
			  {
				  key_on_s += key[i % key.length()];
			  }
			  for (int i = 0; i < mes.length(); i++)
			  {
				  if (((int)(mes[i]) < 65) || ((int)(mes[i]) > 122))
					  result += mes[i];
				  else
				  { 
					  int l = 0;
					  flag = false;
					  while ((l < 26) && (flag == false))
					  {
						  if (key_on_s[i] == tabula_recta[l][0])
						  {
							  x = l;
							  flag = true;
						  }
						  l++;
					  }
					  if (((int)(mes[i]) <= 90) && ((int)(mes[i]) >= 65))
					  {
						  dublicat = (char)((int)(mes[i]) + 32);
						  registr = 1;
					  }
					  else
					  {
						  registr = 0;
						  dublicat = mes[i];
					  }
					  l = 0; flag = false;
					  while ((l < 26) && (flag == false))
					  {
						  if (dublicat == tabula_recta[0][l])
						  {
							  y = l;
							  flag = true;
						  }
						  l++;
					  }
					  if (registr == 1)
					  {
						  dublicat = char((int)(tabula_recta[x][y]) - 32);
						  result += dublicat;
					  }
					  else result += tabula_recta[x][y];
				  }
			  }
			  cout << "Encryption complete! Result:\n";
			  cout << result; 

			  cout << endl << endl;
			  cout << "Do you want to decrypt this message?:" << endl << "1. Yes" << endl << "2. No" << endl << "--> ";
			  cin >> k;
			  switch (k)
			  {
			  case 1:{
						 mes = result;
						 result = "";
						 
						 for (int i = 0; i < mes.length(); i++){
							 key_on_s += key[i % key.length()];
						 }
						 for (int i = 0; i < mes.length(); i++){
							 if (((int)(mes[i]) < 65) || ((int)(mes[i]) > 122))result += mes[i];
							 else{
								 int l = 0; flag = false;
								 while ((l < 26) && (flag == false)){
									 if (key_on_s[i] == tabula_recta[l][0]){
										 x = l; flag = true;
									 }
									 l++;
								 }
								 if (((int)(mes[i]) <= 90) && ((int)(mes[i]) >= 65)){
									 dublicat = (char)((int)(mes[i]) + 32);
									 registr = 1;
								 }
								 else{
									 registr = 0;
									 dublicat = mes[i];
								 }
								 l = 0;
								 flag = false;
								 while ((l < 33) && (flag == false)){
									 if (dublicat == tabula_recta[x][l]){
										 y = l; flag = true;
									 }
									 l++;
								 }
								 if (registr == 1){
									 dublicat = char((int)(tabula_recta[0][y]) - 32);
									 result += dublicat;
								 }
								 else result += tabula_recta[0][y];
							 }
						 }
						 cout << "Decryption complete! Result:\n";
						 cout << result << endl;

						 break;
			  }
			  case 2:
			  {
						cout << endl << "Thanks for your attantion!  :)" << endl << endl;
						break;
			  }
			  default: {
						   cout << "Error! \n"; break; }
			  }
			  break;
	}

		return 0;
	}
}
