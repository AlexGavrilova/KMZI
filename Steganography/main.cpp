//
//  main.cpp
//  Stegonagrathya

//  Copyright (c) 2015 Gavrilova_Sasha. All rights reserved.
//


#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <bitset>

using namespace std;

vector<unsigned char> read(ifstream &inputFile)
{
    vector<unsigned char> buf((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
    
    return buf;
}

int main(int argc, char* argv[])
{
    ifstream wavFile;
    wavFile.open(argv[1], ios::in | ios::binary);
    if (!wavFile)
    {
        cout << "Error! Unable to open wav file! " << argv[1] << endl;
        return 0;
    }
    
    ifstream txtFile;
    txtFile.open(argv[2], ios::in | ios::binary);
    if (!txtFile)
    {
        cout << "Error! Unable to open txt file! " << argv[2] << endl;
        return 0;
    }
    
    vector<unsigned char> mas_wav = read(wavFile);
    vector<unsigned char> mas_txt = read(txtFile);
    
    for (int i = 8; i < 12; i++)
	{
		tmp += mas_wav[i];
	}
	if (tmp != wav)
	{
		cout << "Error! This file isn't wav file!";
		return 0;
	}
    
    if (mas_wav.size() - 44 < mas_txt.size() * 8)
    {
        cout << "Error! Increase wav file capacity." << endl;
        return 0;
    }
    
    size_t j = 44;
    for (size_t i = 0; i < mas_txt.size(); i++)
    {
        unsigned char wav = mas_wav[j];
        unsigned char txtByte = mas_txt[i];
        
        unsigned char bit = txtByte;
        
        for (size_t k = 0; k < 8; k++)
        {
            bit <<= i;
            bit >>= (7 - i);
            
            wav >>= 1;
            wav <<= 1;
            
            if (bit)
            {
                wav += 1;
            }
            
            mas_wav[j] = wav;
            ++j;
            wav = mas_wav[j];
        }
        
    }
    
    ofstream outputFile;
    outputFile.open(argv[3],ios::trunc | ios::binary);
    
    for (size_t i = 0; i < mas_wav.size(); i++)
    {
        outputFile << static_cast<unsigned char>(mas_wav[i]);
    }
    
    outputFile.close();
    return 0;
}
