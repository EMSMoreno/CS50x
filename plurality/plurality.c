#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
} candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(string name);
void print_winner(void);

    int main(int argc, string argv[])
    {

    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

    bool vote(string name)
    {
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            ++candidates[i].votes;
            return true;
        }
    }
    return false;
}

    // Print the winner/s of the election
    void print_winner(void)
    {
    // TODO
    int maxvote = -1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (maxvote < candidates[i].votes)
        {
            maxvote = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (maxvote == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
