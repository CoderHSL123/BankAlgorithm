#include "init.h"
#include <stdio.h>

void init()
{
    printf("请输入进程数m和资源数n：");
    scanf("%d%d", &m, &n);
    
    printf("请输入可用资源Available向量（共%d个资源）：", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &Available[i]);
    }
    

    printf("请输入每个进程的最大需求Max（共%d个进程，每个进程%d个资源）：\n", m, n);
    for (int i = 0; i < m; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &Max[i][j]);
        }
    }

    printf("请输入每个进程的已分配资源Allocation（共%d个进程，每个进程%d个资源）：\n", m, n);
    for (int i = 0; i < m; i++) {
        printf("P%d: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

     // 计算Need矩阵
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    // 初始安全性检查
    int sequence[MAX_PROCESS];
    if (isSafe(sequence)) {
        printf("初始状态安全，安全序列：");
        for (int i = 0; i < m; i++) {
            printf("P%d ", sequence[i]);
        }
        printf("\n");
    } else {
        printf("初始状态不安全！请检查输入的Max和Allocation是否合理。\n");
    }
}