#ifndef DFS_H
#define DFS_H
#include"stdafx.h"
#include"Eigen\Dense"
#include<iostream>
#include"readfiletomatrix.h"

using namespace std;
using  Eigen::MatrixXd;

int b[MAX] = { 0 };

int sum = 0;


//---------------------dfs�ĵݹ�ʵ��-  �ǵݹ��㷨����ջʵ�ֵ�------------------------------------------------//
void dfs(int i)
{
	MatrixXd  m(MAX, MAX);
	readfiletomatrix("matrix.txt", m);

	sum++;    
	if (sum == MAX)                     //sum��ʾ����ĸ��� ���sum=max˵�������Ѿ�ȫ���������� �Ϳ���ֱ�ӽ����� ���ǵݹ�ĵĽ�����
		return;
	else
	{
		for (int j = 0; j< m.cols(); j++)          //��ͷ��ʼ�ж��ĸ������i�ڵ������ӣ� �еĻ������Ǹ��ڵ�Ȼ��ݹ�
		{
			if (m(i, j) == 1 && b[j] == 0)
			{
				b[j] = 1;
				dfs(j);
			}
		}
		return;
	}
}

#endif