#include "requestResource.h"
#include "init.h"
#include "safe.h"

void requestResource(int pid, int request[]) {
    // 检查：请求是否超过进程的最大需求
    for (int i = 0; i < n; i++) {
        if (request[i] > Need[pid][i]) {
            printf("错误：进程P%d的请求超过其最大需求！拒绝分配。\n", pid);
            return;
        }
    }
    
    // 检查：请求是否超过可用资源
    for (int i = 0; i < n; i++) {
        if (request[i] > Available[i]) {
            printf("错误：可用资源不足，进程P%d需要等待。\n", pid);
            return;
        }
    }
    
    // 预分配资源（修改Available、Allocation、Need）
    for (int i = 0; i < n; i++) {
        Available[i] -= request[i];
        Allocation[pid][i] += request[i];
        Need[pid][i] -= request[i];
    }
    
    // 检查预分配后是否安全
    int sequence[MAX_PROCESS];
    if (isSafe(sequence)) {
        printf("资源分配成功！安全序列：");
        for (int i = 0; i < m; i++) {
            printf("P%d ", sequence[i]);
        }
        printf("\n");
        
        // 打印当前资源状态
        printf("当前可用资源Available：");
        for (int i = 0; i < n; i++) {
            printf("%d ", Available[i]);
        }
        printf("\n");
        
        printf("已分配资源Allocation：\n");
        for (int i = 0; i < m; i++) {
            printf("P%d: ", i);
            for (int j = 0; j < n; j++) {
                printf("%d ", Allocation[i][j]);
            }
            printf("\n");
        }
        
        printf("需求资源Need：\n");
        for (int i = 0; i < m; i++) {
            printf("P%d: ", i);
            for (int j = 0; j < n; j++) {
                printf("%d ", Need[i][j]);
            }
            printf("\n");
        }
    } else {
        // 回滚资源分配（恢复预分配前的状态）
        for (int i = 0; i < n; i++) {
            Available[i] += request[i];
            Allocation[pid][i] -= request[i];
            Need[pid][i] += request[i];
        }
        printf("资源分配后系统不安全，拒绝分配请求！\n");
    }
}