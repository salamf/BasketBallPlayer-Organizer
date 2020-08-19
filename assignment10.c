////Salam Fazil
//V00935894

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define THRESHOLD   0.001

// some of these constants will go unused
// we listed them all for completion sake
#define GP      0
#define MPG     1
#define PPG     2
#define RPG     3
#define APG     4
#define SPG     5
#define BPG     6
#define TOPG    7

#define MAX_WORD_LEN        63
#define CHAR_ARRAY_WIDTH    MAX_WORD_LEN+1
#define MAX_PLAYERS         28
#define MAX_TEAMS           30
#define NUM_STATS           8

typedef struct {
    char name[CHAR_ARRAY_WIDTH];
    char pos[CHAR_ARRAY_WIDTH];
    double stats[NUM_STATS];
} Player;

typedef struct {
    int num_players;
    char name[CHAR_ARRAY_WIDTH];
    Player* players[MAX_PLAYERS];
} Team;

int find_team(char name[], Team* teams[], int num_teams);
int read_file(char filename[], Team* teams[]);
int get_high_scorers(Team* teams[], int num_teams, Player* high_scorers[]);
void to_file(char filename[], Team* teams[], int num_teams);
int approximately_equal(double num1, double num2);

int main() {
    ////find_team Test
//Team* team[MAX_TEAMS];
//
//    team[0] = malloc(sizeof(Team));
//    team[1] = malloc(sizeof(Team));
//    team[2] = malloc(sizeof(Team));
//
//
//    strcpy(team[0] -> name,"Goose");
//    strcpy(team[1] -> name,"Salam");
//    strcpy(team[2] -> name,"Mehrad");
//
//    printf("%d ", find_team("Salam", team, 3));

    ////read_file Test
//    Team* teams[MAX_TEAMS];
//    int val = read_file("2017.txt", teams);
//    printf("VAL: %d\n", val);
//
//    for (int i = 0; i < val; ++i) {
//        printf("%s\n", teams[i] -> name);
//        for (int j = 0; j < teams[i] -> num_players; ++j) {
//            printf("%s ", teams[i] -> players[j] -> name);
//        }
//        printf("\n\n");
//    }
//
//    //Freeing players and teams
//    for (int k = 0; k < val; ++k) {
//        for (int i = 0; i < teams[k] -> num_players; ++i) {
//            free(teams[k] -> players[i]);
//        }
//        free(teams[k]);
//    }

    ////get_high_scorers Test
//    Team* zeTe[MAX_TEAMS];
//    Player* zehi[MAX_TEAMS];
//    int numTem = read_file("2017.txt", zeTe);
//    get_high_scorers(zeTe, numTem, zehi);
//
//    for (int i = 0; i < numTem; ++i) {
//        printf("%s\n", zehi[i] -> name);
//    }

    ////to_file Test
    Team* teams[MAX_TEAMS];

    int amount_of_teams = read_file("2017.txt", teams);
    to_file("output_text.txt", teams, amount_of_teams);

    return 0;
}

/* Purpose: Find the index of where the team exists
 * Args: char name - A team name, Team* teams - array of team pointers, int num_teams - number of teams
 * Returns: int - The index of where team found, -1 if team not found */
int find_team(char name[], Team* teams[], int num_teams){

    for (int i = 0; i < num_teams; ++i) {
        if(strcmp(name, teams[i] -> name) == 0){
            return i;
        }
    }
    return -1;
}

/* Purpose: Find the index of where the team exists
 * Args: char name - A team name, Team* teams - array of team pointers, int num_teams - number of teams
 * Returns: int - The index of where team found, -1 if team not found */
int read_file(char filename[], Team* teams[]){

    //File Open and Check
    FILE* input_file = fopen(filename, "r");
    if (input_file == NULL){
        printf("Error reading file\n");
        printf("Exiting...");
        exit(0);
    }

    //Variable Declarations
    int i = 0;

    int rank = 0;
    int age = 0;

    //Allocate storage for first position of teams and player
    teams[i] = (Team*)malloc(sizeof(Team));
    teams[i] -> players[i] = (Player*)malloc(sizeof(Player));

    //Get first line of info from file and store it into there allocated positions
    while(fscanf(input_file, "%d %s %s %s %d %lf %lf %lf %lf %lf %lf %lf %lf", &rank, teams[i] -> players[0] -> name,
                 teams[i] -> name, teams[i] -> players[0] -> pos, &age, &teams[i] -> players[0] -> stats[0],
                 &teams[i] -> players[0] -> stats[1], &teams[i] -> players[0] -> stats[2],
                 &teams[i] -> players[0] -> stats[3], &teams[i] -> players[0] -> stats[4],
                 &teams[i] -> players[0] -> stats[5], &teams[i] -> players[0] -> stats[6],
                 &teams[i] -> players[0] -> stats[7]) == 13){


        //Check if team I just added already exists in teams at a previous instance
        if(find_team(teams[i] -> name, teams, i) == -1){ //If it doesn't already exist, set the num_players of the team to 1

            teams[i] -> num_players = 1;

            //increment i to move to next index in teams
            i++;
            //Allocate storage for that next index
            teams[i] = (Team*)malloc(sizeof(Team));
            teams[i] -> players[0] = (Player*)malloc(sizeof(Player));

        }else{ //Otherwise if it already exists

            // 1. Find index of already existent team
            // 2. Get the number of already existing players in team
            // 3. Allocate storage for a new player in the existing team
            // 4. Add the player and increase the num_players that already exist
            // 5. Free the index of teams where we stored that player, and set to NULL, then allocate new space

            //Find index of already existent team
            int index_of_team = find_team(teams[i] -> name, teams, i);

            //Get the number of already existing players in team
            int num_existing_players = teams[index_of_team] -> num_players;

            //Allocate storage for a new player in the existing team
            teams[index_of_team] -> players[num_existing_players] = (Player*)malloc(sizeof(Player));

            //Add the player and increase the num_players that already exist
            teams[index_of_team] -> players[num_existing_players] = teams[i] -> players[0];
            (teams[index_of_team] -> num_players)++;

            //Free the index of teams where we stored that player, and set to NULL, then allocate new space
            free(teams[i]);

            teams[i] -> players[0] = NULL;
            teams[i] = NULL;

            teams[i] = (Team*)malloc(sizeof(Team));
            teams[i] -> players[0] = (Player*)malloc(sizeof(Player));
        }
    }

    //Close input_file
    fclose(input_file);

    return i;
}

/* Purpose: Find the highest scorer of each team
 * Args: Team* teams - array of team pointers, int num_teams - number of teams, Player* high_scorers, array of Player pointers
 *       to store the high_scorers
 * Returns: int - the number of player pointers added to high_scorers */
int get_high_scorers(Team* teams[], int num_teams, Player* high_scorers[]){

    Player* highestScorer_of_team;

    for (int i = 0; i < num_teams; ++i) {
        highestScorer_of_team = teams[i] -> players[0];

        for (int j = 0; j < teams[i] -> num_players; ++j) {

            if (teams[i] -> players[j] -> stats[PPG] > highestScorer_of_team -> stats[PPG]){
                highestScorer_of_team = teams[i] -> players[j];

            }else if(approximately_equal(teams[i] -> players[j] -> stats[PPG], highestScorer_of_team -> stats[PPG]) == 1){

                if (teams[i] -> players[j] -> stats[MPG] > highestScorer_of_team -> stats[MPG]) {
                    highestScorer_of_team = teams[i]->players[j];
                }

            }
        }
        high_scorers[i] = highestScorer_of_team;
    }
    return num_teams;
}

/* Purpose: Writes given info into an output file
 * Args: char filename - Desired name for output file, Team* teams - array of team pointers, int num_teams - number of teams
 * Returns: Nothing(void) */
void to_file(char filename[], Team* teams[], int num_teams){

    FILE* output_file = fopen(filename, "w");

    for (int i = 0; i < num_teams; ++i) {
        fprintf(output_file, "%s\n", teams[i] -> name);
        for (int j = 0; j < teams[i] -> num_players; ++j) {
            fprintf(output_file, "%s,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n", teams[i] -> players[j] -> name,
                    teams[i] -> players[j] -> stats[0], teams[i] -> players[j] -> stats[1],
                    teams[i] -> players[j] -> stats[2], teams[i] -> players[j] -> stats[3],
                    teams[i] -> players[j] -> stats[4], teams[i] -> players[j] -> stats[5],
                    teams[i] -> players[j] -> stats[6], teams[i] -> players[j] -> stats[7]);
        }
        fprintf(output_file,"\n");
    }

    fclose(output_file);
}

/*
 * Purpose: determines if num1 and num2 are close enough to be considered equal
 *  NOTE: cannot compare equality of floating point values using ==
 * Params: double num1, double num2
 * Return: int - 1 if num1 and num2 are approximately equal, 0 otherwise
 */
int approximately_equal(double num1, double num2) {
    double diff = num1-num2;

    if (diff<0) {
        diff *= -1;
    }

    if (diff<THRESHOLD) {
        return 1;
    } else {
        return 0;
    }
}
