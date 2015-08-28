#ifndef READFILE_H
#define READFILE_H
#include<iostream>
#include<fstream>
#include"Eigen\Dense"
#include<vector>
using namespace std;
using Eigen::MatrixXd;


vector<int>split(string str, char delimiter)
{
	vector<int>temp;
	stringstream ss(str);                       // Turn the string into a stream.
	string  tok;
	while (getline(ss, tok, delimiter)) {
		int p = atoi(tok.c_str());           // c_str()一个将string转换为 const* char的函数。
		temp.push_back(p);
	}
	return temp;
}


void readfiletomatrix(string  filename, MatrixXd &m)
{
	ifstream  infile;
	infile.open(filename, ios::in);
	if (!infile)
	{
		cerr << "sorry , the file is not open or not exist" << endl;
		exit(1);
	}

	string  str;
	for (int i = 0; i < m.rows(); i++)
	{
		getline(infile, str);
		vector<int>temp = split(str, ',');
		for (int j = 0; j < m.cols(); j++)
		{
			m(i, j) = temp[j];
		}
	}

}
#endif