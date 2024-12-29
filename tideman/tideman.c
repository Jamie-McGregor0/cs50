#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }

            else
                vote(j, name, ranks);
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i ++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int k = 0; k < candidate_count - 1; k ++)
    {
        for (int l = k + 1; l < candidate_count; l ++)
        {
            for (int i = 0; i < candidate_count; i ++)
            {
                for (int j = 0; j < candidate_count; j ++)
                {
                    if (ranks[k] == i && ranks[l] == j)
                        preferences[i][j] += 1;
                }
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i ++)
    {
        for (int j = 0; j < candidate_count; j ++)
        {
            for( int k = 0; k < MAX * (MAX - 1) / 2; k ++)
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[k].winner = i;
                    pairs[k].loser = j;

                    pair_count += 1;
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO

    int x;
    int y;

    for (int i = 0; i < pair_count; i ++)
    {
        for (int j = 0; j < pair_count; j ++)
        {
            for (int k = 0; k < candidate_count; k ++)
            {
                for (int l = 0; l < candidate_count; l ++)
                {
                    for (int m = 0; m < candidate_count; m ++)
                    {
                        for (int n = 0; n < candidate_count; n ++)
                        {
                            if (pairs[i].winner == k && pairs[i].loser == l && pairs[j].winner == m && pairs[j].loser == n)
                            {
                                if (preferences[k][l] < preferences[m][n])
                                {
                                    x = pairs[i].winner;
                                    y = pairs[i].loser;

                                    pairs[i].winner = pairs[j].winner;
                                    pairs[j].winner = x;
                                    pairs[i].loser = pairs[j].loser;
                                    pairs[j].loser = y;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO


    for (int i = 0; i < pair_count; i ++)
    {
        for (int j = 0; j < candidate_count; j ++)
        {
            for (int k = 0; k < candidate_count; k ++)
            {
               for (int l = 0; l < candidate_count; l ++)
               {
                    bool af = true;

                    for (int m = 0; m < candidate_count; m ++)
                    {
                        if (locked[l][m])
                        {
                            af = false;
                            break;
                        }
                    }

                    if (!af)
                    {
                        if (pairs[i].winner == j && pairs[i].loser == k)
                        {
                            locked[j][k] = true;
                        }
                    }
               }
            }
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < pair_count; i ++)
    {
        bool is_source = true;

        for (int j = 0; j < pair_count; j ++)
        {
            if (locked[i][j])
            {
                is_source = false;
                break;
            }
        }

        if (is_source)
            {
                printf("%s\n", candidates[i]);
                 return;
            }
    }

}
