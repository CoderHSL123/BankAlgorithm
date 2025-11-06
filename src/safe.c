#include "safe.h"
#include "init.h"
#include <stdio.h>

int isSafe(int sequence[])
{
    int work[MAX_RESOURCE];  // 工作向量（复制Available）
    int finish[MAX_PROCESS] = {0}; // 标记进程是否完成
    int count = 0;           // 完成的进程数
    
    // 初始化work为Available的拷贝
    for (int i = 0; i < n; i++) {
        work[i] = Available[i];
    }
    
    while (count < m) {
        int found = 0; // 标记是否找到可完成的进程
        for (int i = 0; i < m; i++) {
            if (finish[i] == 0) {
                int j;
                // 检查当前进程的Need是否≤work
                for (j = 0; j < n; j++) {
                    if (Need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == n) { // 所有资源需求都满足
                    sequence[count] = i; // 记录安全序列
                    count++;
                    finish[i] = 1;
                    // 释放该进程的已分配资源到work
                    for (j = 0; j < n; j++) {
                        work[j] += Allocation[i][j];
                    }
                    found = 1;
                }
            }
        }
        if (!found) {
            break; // 无进程可完成，系统不安全
        }
    }
    return count == m; // 所有进程都完成则安全
}