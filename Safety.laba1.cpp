#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream fin;
	ofstream fout;
	fin.open("in.txt",std::ios::in);
	fout.open("out.txt", std::ios::out);
	
	char simbol;
	string keyword;
	cout << "Enter a key-word"<<endl;
	cin >> keyword;
	size_t s_index = 0;
	//lol
	while (fin.is_open()&&fout.is_open())
	{
		
			fin.get(simbol);
			simbol += keyword[s_index];
			fout << simbol;
			++s_index;
			if (s_index == keyword.size()) { s_index = 0; }
			if (fin.peek() == EOF) { break; }
		
	}
	fin.close(); fout.close();
	ifstream fin1;
	ofstream fout1;
	fin1.open("out.txt");
	fout1.open("decode.txt");
	s_index = 0;
	while (fin1.is_open()&&fout1.is_open()) 
	{		
			fin1.get(simbol);
			simbol -= keyword[s_index];
			fout1 << simbol;
			++s_index;
			if (s_index == keyword.size()) { s_index = 0; }
			if (fin.peek() == EOF) { break; }
	}
	system("pause");
	fin1.close(); fout1.close();
}
