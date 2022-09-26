#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream fin;
	ofstream fout;
	fin.open("in.txt",std::ios::binary);
	fout.open("out.txt", std::ios::binary);
	
	char simbol;
	string keyword;
	cout << "Enter a key-word"<<endl;
	cin >> keyword;
	size_t s_index = 0;
	while (fin.is_open()&&fout.is_open())
	{
		
			fin.get(simbol);
			simbol += keyword[s_index];
			cout << simbol<< "   " << (int)simbol<<endl;
			fout << simbol;
			++s_index;
			if (s_index == keyword.size()) { s_index = 0; }
			if (fin.peek() == EOF) { break; }
		
	}
	fin.close(); fout.close();
	ifstream fin1;
	ofstream fout1;
	fin1.open("out.txt",std::ios::binary);
	fout1.open("decode.txt",std::ios::binary);
	s_index = 0;
	while (fin1.is_open()&&fout1.is_open()) 
	{		
			fin1.get(simbol);
			simbol -= (char)keyword[s_index];
			fout1 << (char)simbol;
			++s_index;
			if (s_index == keyword.size()) { s_index = 0; }
			if (fin1.peek() == EOF) { break; }
	}
	fin1.close(); fout1.close();
	system("pause");
	
}
