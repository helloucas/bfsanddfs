#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include<iostream>
#include<vector>
#include"Eigen\Dense"
#include<fstream>
#include<string>
#define MAX 5
using namespace std;
using Eigen::MatrixXd;

typedef  struct  AB
{
	int data;
	int  flag;
};

//const * char c_str()
//一个将string转换为 const* char的函数。
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

void readfiletomatrix(string filename, MatrixXd &m)
{
	ifstream infile;
	infile.open(filename, ios::in);
	if (!infile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	string str;
	for (int i = 0; i < m.cols(); i++)
	{
		getline(infile, str);
		vector<int>t = split(str, ',');
		for (int j = 0; j < m.cols(); j++)
		{
			m(i, j) = t[j];
		}
	}
}




int min1(vector<AB>&a)
{
	int min, k;
	int temp = 10000;
	for (int i = 0; i < a.size(); i++)
	{
		while (i<a.size()&&a[i].flag==1)
		{
			i++;
		}
		if (i<a.size()&&temp>a[i].data)
		{
			min = a[i].data;
			k = i;
		}

	}
	a[k].flag = 1;
	return k;
}


void  dijkstra()
{
	MatrixXd m(MAX, MAX);
	vector<AB>ab(m.cols());
	for (int i = 0; i < ab.size(); i++)
	{
		ab[i].flag = 0;
	}
	ab[0].flag = 1;
	for (int i = 0; i < ab.size(); i++)
	{
		ab[i].data = m(0, i);
	}




	for (int j = 1; j < ab.size(); j++)
	{
		int t = min1(ab);
		for (unsigned int i = 1; i<ab.size(); i++)
		{
			if (ab[i].data> ab[t].data + m(t, i))
			{
				ab[i].data = ab[t].data + m(t, i);
			}
		}
	 }



	cout << endl;

	for (int i = 0; i < ab.size(); i++)
	{
		cout << ab[i].data << "\t";
	}
	cout << endl;





}


#endif
