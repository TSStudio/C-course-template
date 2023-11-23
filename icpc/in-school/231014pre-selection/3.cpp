#include <cstdio>
#include <algorithm>
using std::sort;

struct card {
    int num;
    char suit;
} c[5];

int mapper(char num) {
    if (num >= '2' && num <= '9') {
        return num - '0';
    } else if (num == 'T') {
        return 10;
    } else if (num == 'J') {
        return 11;
    } else if (num == 'Q') {
        return 12;
    } else if (num == 'K') {
        return 13;
    } else if (num == 'A') {
        return 14;
    }
}
bool cmp(card a, card b) {
    if (a.num == b.num) {
        return a.suit < b.suit;
    } else {
        return a.num < b.num;
    }
}
bool judge_1() {  //High card
    return true;
}
bool judge_2() {  //Pair
    return c[0].num == c[1].num || c[1].num == c[2].num || c[2].num == c[3].num || c[3].num == c[4].num;
}
bool judge_3() {  //Two pairs
    return c[0].num == c[1].num && c[2].num == c[3].num || c[0].num == c[1].num && c[3].num == c[4].num || c[1].num == c[2].num && c[3].num == c[4].num;
}
bool judge_4() {  //Three of a kind
    return c[0].num == c[1].num && c[1].num == c[2].num || c[1].num == c[2].num && c[2].num == c[3].num || c[2].num == c[3].num && c[3].num == c[4].num;
}
bool judge_5() {  //Straight
    if (c[0].num == 2 && c[1].num == 3 && c[2].num == 4 && c[3].num == 5 && c[4].num == 14) {
        return true;
    }
    for (int i = 1; i < 5; ++i) {
        if (c[i].num != c[i - 1].num + 1) {
            return false;
        }
    }
    return true;
}
bool judge_6() {  //Flush
    for (int i = 1; i < 5; ++i) {
        if (c[i].suit != c[i - 1].suit) {
            return false;
        }
    }
    return true;
}
bool judge_7() {  //Full house
    return c[0].num == c[1].num && c[1].num == c[2].num && c[3].num == c[4].num || c[0].num == c[1].num && c[2].num == c[3].num && c[3].num == c[4].num;
}
bool judge_8() {  //Four of a kind
    return c[0].num == c[1].num && c[1].num == c[2].num && c[2].num == c[3].num || c[1].num == c[2].num && c[2].num == c[3].num && c[3].num == c[4].num;
}
bool judge_9() {  //Straight flush
    return judge_5() && judge_6();
}
bool judge_10() {  //Royal flush
    return judge_9() && c[0].num == 10;
}

void do_judge() {
    for (int i = 0; i < 5; ++i) {
        char temp;
        while (temp = getchar(), (temp == ' ' || temp == '\n' || temp == '\r'))
            ;
        c[i].num = mapper(temp);
        c[i].suit = getchar();
    }
#ifdef DEBUG
    for (int i = 0; i < 5; ++i) {
        printf("%d %c\n", c[i].num, c[i].suit);
    }
#endif
    sort(c, c + 5, cmp);
    if (judge_10()) {
        printf("Royal flush\n");
    } else if (judge_9()) {
        printf("Straight flush\n");
    } else if (judge_8()) {
        printf("Four of a kind\n");
    } else if (judge_7()) {
        printf("Full house\n");
    } else if (judge_6()) {
        printf("Flush\n");
    } else if (judge_5()) {
        printf("Straight\n");
    } else if (judge_4()) {
        printf("Three of a kind\n");
    } else if (judge_3()) {
        printf("Two pairs\n");
    } else if (judge_2()) {
        printf("Pair\n");
    } else if (judge_1()) {
        printf("Highcard\n");
    }
}

int main() {
#ifdef DEBUG
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int N;
    scanf("%d", &N);
    while (N--) {
        do_judge();
    }

    return 0;
}