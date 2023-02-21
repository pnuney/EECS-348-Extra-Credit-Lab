#include <stdio.h>
#include <stdbool.h>

int dep[5][5] = {
    {1,5,3,2,4},
    {1,3,4,2,5},
    {3,4,2,5,1},
    {3,1,2,4,5},
    {4,3,1,2,5}
};

int prog[5][5] = {
    {3,1,2,5,4},
    {4,3,1,5,2},
    {2,5,4,1,3},
    {4,5,2,1,3},
    {3,2,1,5,4}
};

int depCon[5] = {-1, -1, -1, -1, -1}; 
bool progBool[5] = {true, true, true, true, true}; 

void main() {
    while (true) {
        bool done = true;
        for (int i = 0; i < 5; i++) {
            if (depCon[i] == -1) { 
                done = false;
                for (int j = 0; j < 5; j++) {
                    int programmer = dep[i][j] - 1;
                    if (progBool[programmer]) { 
                        depCon[i] = programmer;
                        progBool[programmer] = false;
                        break;
                    } else {
                        int curr = depCon[programmer];
                        int currRanking = 0;
                        int nextRank = 0;
                        for (int k = 0; k < 5; k++) {
                            if (prog[programmer][k] == i + 1) {
                                nextRank = k;
                            }
                            if (prog[programmer][k] == curr + 1) {
                                currRanking = k;
                            }
                        }
                        if (nextRank < currRanking) {
                            depCon[i] = programmer;
                            progBool[programmer] = false;
                            depCon[curr] = -1;
                            break;
                        }
                    }
                }
            }
        }
        if (done) {
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("Department %d will get Programmer %d\n", i + 1, depCon[i] + 1);
    }
}