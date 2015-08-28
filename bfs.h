#ifndef BFS_H
#define BFS_H
#include"stdafx.h"
#include"Eigen\Dense"
#include"readfiletomatrix.h"
#include<iostream>
using namespace std;
using Eigen::MatrixXd;

//-------------广度优先遍历 使用 的数据结构是队列-------------------------//

int book[MAX] = { 0 };     //为了判别这个顶点是否被访问过
int queue[100] = { 0 };      //作为队列使用

int head  = 1;           //queue的头尾指针；  用下标作为指针
int  tail = 1;
void bfs(int i)
{
	MatrixXd  m(MAX, MAX);
	readfiletomatrix("matrix.txt", m);

	book[i] = 1;
	head++;
	queue[head] = i;
	while (tail < head)
	{
		int t = queue[++tail];
		for (int j = 0; j < m.cols(); j++)
		{
			if (m(t, j) == 1 && book[j] == 0)
			{
				head++;
				queue[head] = j;
				book[j] = 1;
				cout << j << "\t";
			}
			if (head>m.cols())
				break;
		}

	}
}

#endif