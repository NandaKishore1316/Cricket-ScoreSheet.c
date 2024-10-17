#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct Batsman {
    char name[50];
    int runs;
    int balls;
    int fours;
    int sixes;
};
struct Bowler {
    char name[50];
    int overs;
    int runsGiven;
    int wickets;
};

void enterBatsmanDetails(struct Batsman batsmen[], int *batsmanCount);
void enterBowlerDetails(struct Bowler bowlers[], int *bowlerCount);
void displayBatsmanDetails(struct Batsman batsmen[], int batsmanCount);
void displayBowlerDetails(struct Bowler bowlers[], int bowlerCount);
void displayMatchSummary(struct Batsman batsmen[], int batsmanCount, struct Bowler bowlers[], int bowlerCount);
void displayRecords(struct Batsman batsmen[], int batsmanCount, struct Bowler bowlers[], int bowlerCount);
int isValidName(const char *name);

int main() {
    struct Batsman batsmen[11];
    struct Bowler bowlers[11];
    int batsmanCount = 0, bowlerCount = 0;
    int choice;

    do {
        printf("\n=== Cricket Score Sheet ===\n");
        printf("1. Enter Batsman Details\n");
        printf("2. Enter Bowler Details\n");
        printf("3. Display Batsman Details\n");
        printf("4. Display Bowler Details\n");
        printf("5. Display Match Summary\n");
        printf("6. Display Records\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterBatsmanDetails(batsmen, &batsmanCount);
                break;
            case 2:
                enterBowlerDetails(bowlers, &bowlerCount);
                break;
            case 3:
                displayBatsmanDetails(batsmen, batsmanCount);
                break;
            case 4:
                displayBowlerDetails(bowlers, bowlerCount);
                break;
            case 5:
                displayMatchSummary(batsmen, batsmanCount, bowlers, bowlerCount);
                break;
            case 6:
                displayRecords(batsmen, batsmanCount, bowlers, bowlerCount);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void enterBatsmanDetails(struct Batsman batsmen[], int *batsmanCount) {
    char name[50];
    do {
        printf("Enter Batsman Name: ");
        scanf("%s", name);
        if (isValidName(name)) {
            strcpy(batsmen[*batsmanCount].name, name);
            break;
        } else {
            printf("Invalid name. Please enter alphabetic characters only.\n");
        }
    } while (1);

    printf("Enter Runs: ");
    scanf("%d", &batsmen[*batsmanCount].runs);
    printf("Enter Balls Faced: ");
    scanf("%d", &batsmen[*batsmanCount].balls);
    printf("Enter Fours: ");
    scanf("%d", &batsmen[*batsmanCount].fours);
    printf("Enter Sixes: ");
    scanf("%d", &batsmen[*batsmanCount].sixes);
    (*batsmanCount)++;
}

void enterBowlerDetails(struct Bowler bowlers[], int *bowlerCount) {
    char name[50];
    do {
        printf("Enter Bowler Name: ");
        scanf("%s", name);
        if (isValidName(name)) {
            strcpy(bowlers[*bowlerCount].name, name);
            break;
        } else {
            printf("Invalid name. Please enter valid name.\n");
        }
    } while (1);

    printf("Enter Overs: ");
    scanf("%d", &bowlers[*bowlerCount].overs);
    printf("Enter Runs Given: ");
    scanf("%d", &bowlers[*bowlerCount].runsGiven);
    printf("Enter Wickets Taken: ");
    scanf("%d", &bowlers[*bowlerCount].wickets);
    (*bowlerCount)++;
}

void displayBatsmanDetails(struct Batsman batsmen[], int batsmanCount) {
    printf("\nBatsman Details:\n");
    for (int i = 0; i < batsmanCount; i++) {
        printf("Name: %s, Runs: %d, Balls: %d, Fours: %d, Sixes: %d, Strike Rate: %.2f\n", 
               batsmen[i].name, batsmen[i].runs, batsmen[i].balls, batsmen[i].fours, batsmen[i].sixes, 
               (float)batsmen[i].runs / batsmen[i].balls * 100);
    }
}

void displayBowlerDetails(struct Bowler bowlers[], int bowlerCount) {
    printf("\nBowler Details:\n");
    for (int i = 0; i < bowlerCount; i++) {
        printf("Name: %s, Overs: %d, Runs Given: %d, Wickets: %d, Economy Rate: %.2f\n", 
               bowlers[i].name, bowlers[i].overs, bowlers[i].runsGiven, bowlers[i].wickets, 
               (float)bowlers[i].runsGiven / bowlers[i].overs);
    }
}

void displayMatchSummary(struct Batsman batsmen[], int batsmanCount, struct Bowler bowlers[], int bowlerCount) {
    printf("\nMatch Summary:\n");
    int totalRuns = 0;
    for (int i = 0; i < batsmanCount; i++) {
        totalRuns += batsmen[i].runs;
    }
    printf("Total Runs Scored: %d\n", totalRuns);
}

void displayRecords(struct Batsman batsmen[], int batsmanCount, struct Bowler bowlers[], int bowlerCount) {
    printf("\nRecords:\n");
    struct Batsman topScorer = batsmen[0];
    struct Bowler topBowler = bowlers[0];
    for (int i = 1; i < batsmanCount; i++) {
        if (batsmen[i].runs > topScorer.runs) {
            topScorer = batsmen[i];
        }
    }
    for (int i = 1; i < bowlerCount; i++) {
        if (bowlers[i].wickets > topBowler.wickets) {
            topBowler = bowlers[i];
        }
    }
    printf("Top Scorer: %s with %d runs\n", topScorer.name, topScorer.runs);
    printf("Top Bowler: %s with %d wickets\n", topBowler.name, topBowler.wickets);
}

int isValidName(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            return 0;
        }
    }
    return 1;
}
