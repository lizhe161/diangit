#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int elevator = 1;  // 电梯的层数
int t = 0;         // 时间
int people = 0;    // 初始化电梯的人数
int from[10], to[10];  // 层数是否有人，目的层数
int max(void);
int min(void);
int finish(void);


int max() {
    int d = 0;
    int c;
    for (int c = 0; c < 10; c++) {
        if ((from[c] == 1 && c + 1 > elevator) || to[c] > elevator) {
            return 0;
        }
    }
    return 1;
}

int min() {
    int d = 0;
    int c;
    for (int c = 0; c < 10; c++) {
        if ((from[c] == 1 && c + 1 < elevator) || to[c] < elevator) {
            return 0;
        }
    }
    return 1;
}

int finish(void) {
    int f;
    for (f = 0; f < 10; f++) {
        if (from[f] != 0 || to[f] != 0)
            return 0;  // 有乘客未到达目的地，返回0
    }
    return 1;  // 所有乘客都已到达目的地，返回1
}

int main(void) {
    printf("请输入每层是否有人等待电梯，有则输1，无则输0:\n");
    int a;
    int b;
    int z;

    for (a = 0; a < 10; a++) {
        printf("请输入第%d层:\n", a + 1);
        scanf("%d", &from[a]);
        if (from[a] == 1) {
            printf("人位于%d层，请输入目的层数：\n", a + 1);
            scanf("%d", &to[a]);
        }
        else {
            continue;
        }
    }

    for (z = 0; z < 3; z++) {
        for (a = 0; a < 10; a++)  // 上的循环
        {
            if ((from[a] != 1 && to[a] != elevator) || people > 4) {
                elevator++;
                t++;
                printf("%5d,%5d,%5d\n", elevator, t, people);
            }
            else if (finish()) {
                break;
            }
            else if (to[a] - a - 1 > 0 && people < 4 && from[a] == 1 && elevator == a + 1) {
                elevator++;
                t++;
                people++;
                from[a] = 0;
                printf("%5d,%5d,%5d\n", elevator, t, people);
            }
            else if (max()) {
                printf("%5d,%5d,%5d\n", elevator, t, people);
                break;
            }
            else {
                for (b = 0; b < 10; b++) {
                    if ((to[b] > b + 1) && to[b] == elevator && to[b] != 0) {
                        people--;
                        to[b] = 0;

                    }
                }
                elevator++;
                t++;
                printf("%5d,%5d,%5d\n", elevator, t, people);
            }
        }

        for (a = 0; a < 10; a++)  // 下的循环
        {
            if ((from[a] != 1 && to[a] != elevator) || people > 4) {
                elevator--;
                t++;
                printf("%5d,%5d,%5d\n", elevator, t, people);
            }
            else if (finish()) {
                break;
            }

            else if (to[a] - a - 1 < 0 && people < 4 && from[a] == 1 && elevator == a + 1) {
                elevator--;
                t++;
                people++;
                from[a] = 0;
                printf("%5d,%5d,%5d\n", elevator, t, people);
            }
            else if (min()) {
                printf("%5d,%5d,%5d\n", elevator, t, people);
                break;
            }
            else {
                for (b = 0; b < 10; b++) {
                    if ((to[b] < b + 1) && to[b] == elevator && to[b] != 0) {
                        people--;
                        to[b] = 0;
                    }
                }
                elevator--;
                t++;
                printf("%5d,%5d,%5d\n", elevator, t, people);
            }
        }

        if (finish()) {
            printf("%5d,%5d,%5d\ndone", elevator, t, people);
            break;
        }
    }
    return 0;
}