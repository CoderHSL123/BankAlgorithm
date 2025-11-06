#pragma once

#define MAX_PROCESS 10  // 最大进程数
#define MAX_RESOURCE 10 // 最大资源种类数

int m, n; // 进程数m，资源数n
int Available[MAX_RESOURCE];    // 可用资源向量
int Max[MAX_PROCESS][MAX_RESOURCE];       // 进程最大需求矩阵
int Allocation[MAX_PROCESS][MAX_RESOURCE];// 已分配资源矩阵
int Need[MAX_PROCESS][MAX_RESOURCE];      // 需求资源矩阵（Need = Max - Allocation）

void init();