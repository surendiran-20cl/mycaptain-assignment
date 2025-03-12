#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 11
#define MAX_OVERS 20

// Structure for Batsman
struct Batsman {
    char name[50];
    int runs;
    int balls;
    int fours;
    int sixes;
};

// Structure for Bowler
struct Bowler {
    char name[50];
    int overs;
    int runsConceded;
    int wickets;
};

// Structure for Match Details
struct Match {
    char team1[50], team2[50];
    int overs;
    int totalRuns;
    int wickets;
    int extras;
    struct Batsman batsmen[MAX_PLAYERS];
    struct Bowler bowlers[MAX_PLAYERS];
};

// Function prototypes
void displayDateTime();
void enterBatsmanDetails(struct Match *);
void enterBowlerDetails(struct Match *);
void displayScoreSheet(struct Match *);

int main() {
    struct Match match;
    
    printf("===== Cricket Score Sheet =====\n");

    // Get date and time
    displayDateTime();

    // Input team details
    printf("Enter Team 1 Name: ");
    scanf("%s", match.team1);
    printf("Enter Team 2 Name: ");
    scanf("%s", match.team2);
    printf("Enter Number of Overs: ");
    scanf("%d", &match.overs);

    // Initialize match stats
    match.totalRuns = 0;
    match.wickets = 0;
    match.extras = 0;

    // Input player details
    enterBatsmanDetails(&match);
    enterBowlerDetails(&match);

    // Display the score sheet
    displayScoreSheet(&match);

    return 0;
}

// Function to display current date and time
void displayDateTime() {
    time_t t;
    time(&t);
    printf("Date & Time: %s\n", ctime(&t));
}

// Function to enter batsman details
void enterBatsmanDetails(struct Match *match) {
    printf("\nEnter Batsman Details:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Batsman %d Name: ", i + 1);
        scanf("%s", match->batsmen[i].name);
        printf("Runs Scored: ");
        scanf("%d", &match->batsmen[i].runs);
        printf("Balls Faced: ");
        scanf("%d", &match->batsmen[i].balls);
        printf("Number of Fours: ");
        scanf("%d", &match->batsmen[i].fours);
        printf("Number of Sixes: ");
        scanf("%d", &match->batsmen[i].sixes);

        match->totalRuns += match->batsmen[i].runs;
    }
}

// Function to enter bowler details
void enterBowlerDetails(struct Match *match) {
    printf("\nEnter Bowler Details:\n");
    for (int i = 0; i < 5; i++) { // Assuming 5 bowlers per team
        printf("Bowler %d Name: ", i + 1);
        scanf("%s", match->bowlers[i].name);
        printf("Overs Bowled: ");
        scanf("%d", &match->bowlers[i].overs);
        printf("Runs Conceded: ");
        scanf("%d", &match->bowlers[i].runsConceded);
        printf("Wickets Taken: ");
        scanf("%d", &match->bowlers[i].wickets);
    }
}

// Function to display the match scorecard
void displayScoreSheet(struct Match *match) {
    printf("\n===== Match Score Sheet =====\n");
    printf("Match Between: %s vs %s\n", match->team1, match->team2);
    printf("Total Overs: %d\n", match->overs);
    printf("Total Runs: %d\n", match->totalRuns);
    printf("Total Wickets: %d\n", match->wickets);

    // Display Batsmen Stats
    printf("\n===== Batsmen Stats =====\n");
    printf("Name\tRuns\tBalls\tFours\tSixes\tStrike Rate\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        double strikeRate = (match->batsmen[i].balls > 0) ? (match->batsmen[i].runs * 100.0) / match->batsmen[i].balls : 0;
        printf("%s\t%d\t%d\t%d\t%d\t%.2f\n", match->batsmen[i].name, match->batsmen[i].runs, match->batsmen[i].balls,
               match->batsmen[i].fours, match->batsmen[i].sixes, strikeRate);
    }

    // Display Bowler Stats
    printf("\n===== Bowler Stats =====\n");
    printf("Name\tOvers\tRuns\tWickets\tEconomy\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < 5; i++) { // Assuming 5 bowlers per team
        double economy = (match->bowlers[i].overs > 0) ? (match->bowlers[i].runsConceded / (double)match->bowlers[i].overs) : 0;
        printf("%s\t%d\t%d\t%d\t%.2f\n", match->bowlers[i].name, match->bowlers[i].overs, match->bowlers[i].runsConceded,
               match->bowlers[i].wickets, economy);
    }

    printf("\n===== End of Score Sheet =====\n");
}
