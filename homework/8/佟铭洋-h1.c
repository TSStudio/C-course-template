#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct card {
    int num;
    char suit;
} c[5];

int cmp(const void *ap, const void *bp) {
    struct card a = *(struct card *)ap;
    struct card b = *(struct card *)bp;
    if (a.num == b.num) {
        return a.suit < b.suit ? -1 : 1;
    } else {
        return a.num - b.num;
    }
}
bool judge_1() {  //High card
    return true;
}
bool judge_2() {  //Pair
    return c[0].num == c[1].num || c[1].num == c[2].num || c[2].num == c[3].num || c[3].num == c[4].num;
}
bool judge_4() {  //Three of a kind
    return (c[0].num == c[1].num && c[1].num == c[2].num) || (c[1].num == c[2].num && c[2].num == c[3].num) || (c[2].num == c[3].num && c[3].num == c[4].num);
}
bool judge_6() {  //Flush
    for (int i = 1; i < 5; ++i) {
        if (c[i].suit != c[i - 1].suit) {
            return false;
        }
    }
    return true;
}

char *bestHand(int *ranks, int ranksSize, char *suits, int suitsSize) {
    for (int i = 0; i < 5; ++i) {
        c[i].num = ranks[i];
        c[i].suit = suits[i];
    }
    qsort(c, 5, sizeof(struct card), cmp);
    for (int i = 0; i < 5; ++i) {
        printf("%d%c ", c[i].num, c[i].suit);
    }
    if (judge_6()) {
        return "Flush";
    } else if (judge_4())
        return "Three of a Kind";
    else if (judge_2())
        return "Pair";
    else
        return "High Card";
}