#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int elevator = 1;  // ���ݵĲ���
int t = 0;         // ʱ��
int people = 0;    // ��ʼ�����ݵ�����
int from[10], to[10];  // �����Ƿ����ˣ�Ŀ�Ĳ���
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
            return 0;  // �г˿�δ����Ŀ�ĵأ�����0
    }
    return 1;  // ���г˿Ͷ��ѵ���Ŀ�ĵأ�����1
}

int main(void) {
    printf("������ÿ���Ƿ����˵ȴ����ݣ�������1��������0:\n");
    int a;
    int b;
    int z;

    for (a = 0; a < 10; a++) {
        printf("�������%d��:\n", a + 1);
        scanf("%d", &from[a]);
        if (from[a] == 1) {
            printf("��λ��%d�㣬������Ŀ�Ĳ�����\n", a + 1);
            scanf("%d", &to[a]);
        }
        else {
            continue;
        }
    }

    for (z = 0; z < 3; z++) {
        for (a = 0; a < 10; a++)  // �ϵ�ѭ��
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

        for (a = 0; a < 10; a++)  // �µ�ѭ��
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