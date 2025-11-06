#include <stdio.h>
#include "init.h"
#include "safe.h"
#include "requestResource.h"

/**
 * @author 刘怡飞
 * @date 2025-11-07
 * @brief 一共三个函数，分别是init、isSafe、requestResource，
 *  他们的作用分别是初始化系统状态、检查系统是否安全、处理进程资源请求
 */

int main() {
    init();
    int pid, request[MAX_RESOURCE];
    printf("\n请输入进程ID和资源请求（例如：0 1 0 0 表示进程0请求资源[1,0,0]，输入-1结束程序）：\n");
    
    while (1) {
        printf("输入进程ID和请求资源：");
        scanf("%d", &pid);
        if (pid == -1) {
            break;
        }
        if (pid < 0 || pid >= m) {
            printf("进程ID无效，请重新输入！\n");
            continue;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &request[i]);
        }
        requestResource(pid, request);
    }
    
    printf("程序结束。\n");
    return 0;
}