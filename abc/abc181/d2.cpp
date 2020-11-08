#include <stdio.h>
#include <string.h>

int i;
char s[200001];
int len;
int cnt[10];

int main() {
    scanf("%s", s);
    len = strlen(s);

    if (len == 1) {
        if (s[0] == '0' || s[0] == '8')
            puts("Yes");
        else
            puts("No");

        return 0;
    }
    
    if (len == 2) {
        if (((s[0] - '0') * 10 + (s[1] - '0')) % 8 == 0 || ((s[1] - '0') * 10 + (s[0] - '0')) % 8 == 0)
            puts("Yes");
        else
            puts("No");

        return 0;
    }

    for (i = 0; i < len; i++)
        cnt[s[i] - '0']++;

    for (i = 104; i < 1000; i += 8) {
        int d1 = i / 100;
        int d2 = i / 10 % 10;
        int d3 = i % 10;

        if (cnt[d1] <= 0) {
            continue;
        }
        cnt[d1]--;

        if (cnt[d2] <= 0) {
            cnt[d1]++;
            continue;
        }
        cnt[d2]--;

        if (cnt[d3] <= 0) {
            cnt[d1]++;
            cnt[d2]++;
            continue;
        }

        puts("Yes");
        return 0;
    }

    puts("No");
    return 0;
}
