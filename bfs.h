#ifndef BFS_H
#define BFS_H
#include"stdafx.h"
#include"Eigen\Dense"
#include"readfiletomatrix.h"
#include<iostream>
using namespace std;
using Eigen::MatrixXd;

//-------------������ȱ��� ʹ�� �����ݽṹ�Ƕ���-------------------------//

int book[MAX] = { 0 };     //Ϊ���б���������Ƿ񱻷��ʹ�
int queue[100] = { 0 };      //��Ϊ����ʹ��

int head  = 1;           //queue��ͷβָ�룻  ���±���Ϊָ��
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