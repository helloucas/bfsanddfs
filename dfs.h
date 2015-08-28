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


//---------------------dfs的递归实现-  非递归算法是用栈实现的------------------------------------------------//
void dfs(int i)
{
	MatrixXd  m(MAX, MAX);
	readfiletomatrix("matrix.txt", m);

	sum++;    
	if (sum == MAX)                     //sum表示顶点的个数 如果sum=max说明顶点已经全部遍历完了 就可以直接结束了 这是递归的的结束口
		return;
	else
	{
		for (int j = 0; j< m.cols(); j++)          //从头开始判断哪个顶点和i节点有链接， 有的话访问那个节点然后递归
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