#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 20

int main() {
    int num = 1;
    while (num-- > 0) {
        printf("%d\n", num);
        char filename[100];
        memset(filename, 0, 100);
        char nums[100];
        strcat(filename, "hw_9datas\\fileIn");
        itoa(num, nums, 10);
        strcat(filename, nums);
        strcat(filename, ".txt");
        FILE *out = fopen(filename, "w");
        for (int i = 1; i <= NUM; i++) {
            fprintf(out, "ap %d %d %d\n", i, i, rand() % 200 + 1);
        }
        char cmd[40][5] = {{"qci"},
                           {"qci"},
                           {"qbs"},
                           {"qts"},
                           {"qv"},
                           {"qv"}};
        char s[110] = "ar";
        for (int i = 0; i < 700; i++) {
            int goal = rand() % 6;
            if (goal == 0) {
                int index = rand() % 6;
                if (index == 0 || index == 4 || index == 1 || index == 5) {
                    int a = rand() % ((int) (NUM * 1.01)) + 1;
                    int b = rand() % ((int) (NUM * 1.01)) + 1;
                    fprintf(out, "%s %d %d\n", cmd[index], a, b);
                } else {
                    fprintf(out, "%s\n", cmd[index]);
                }
            } else {
                int a = rand() % ((int) (NUM * 1.01)) + 1;
                int b = rand() % ((int) (NUM * 1.01)) + 1;
                int value = rand() % 100 + 1;
                fprintf(out, "%s %d %d %d\n", s, a, b, value);
            }
        }
        for (int i = 0; i < 200; i++) {
            int index = rand() % 6;
            if (index == 0 || index == 4 || index == 1 || index == 5) {
                int a = rand() % ((int) (NUM * 1.01)) + 1;
                int b = rand() % ((int) (NUM * 1.01)) + 1;
                fprintf(out, "%s %d %d\n", cmd[index], a, b);
            } else {
                fprintf(out, "%s\n", cmd[index]);
            }
        }
    }
    return 0;
}
