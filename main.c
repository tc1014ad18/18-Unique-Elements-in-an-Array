#include <stdio.h>
#include <stdbool.h>

struct numbers {
    int number;
    bool processed;
    bool unique;
};

int main() {
    int n;
    printf("Hullo, Mate!\nGive me a list of numbers and I'll tell you how many unique numbers there are.\n");
    printf("How many numbers are we dealing with? ");
    scanf("%d", n);

    if (n <= 0) {
        printf("If you don't want to work, just tell me, mate! See you around.\n");
        return 0;
    }

    struct numbers myNumbers[n];
    int uniques = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &myNumbers[i].number);
        myNumbers[i].processed = false;
        myNumbers[i].unique = false;
    }

    for (int i = 0; i < n - 1; i++) {
        int number = myNumbers[i].number;
        if (!myNumbers[i].processed) {
            myNumbers[i].processed = true;
            bool unique = true;
            for (int j = i + 1; j < n; j++) {
                if (myNumbers[j].number == number) {
                    if (unique) {
                        unique = false;
                    }
                    myNumbers[j].processed = true;
                }
            }
            if (unique) {
                uniques++;
            }
        }
    }

    printf("There are %d unique numbers in your liste, mate, and they are:\n", uniques);
    for (int i = 0; i < n; i++) {
        if (myNumbers[i].unique) {
            printf("%d ", myNumbers[i].number);
        }
    }

    return 0;
}