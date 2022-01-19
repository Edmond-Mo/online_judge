#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define LIM 200
#define MAX_TEAM 108
#define MAX_PROB 16

struct Submission {
    int team;
    int prob;
    int time;
    char L;
};

struct Rank {
    int team;
    int numSolved;
    int penalty;
};

int main()
{
    int tc;
    char tmp;
    scanf("%d%c", &tc, &tmp);
    scanf("%c", &tmp);
    char line[LIM];
    while (tc--) {
        vector<Submission> submissions;
        while (1) {
            if (fgets(line, LIM, stdin) == NULL || strcmp(line, "\n") == 0)
                break;
            Submission s;
            sscanf(line, "%d %d %d %c", &(s.team), &(s.prob), &(s.time), &(s.L));
            submissions.push_back(s);
        }
        
        int score[MAX_TEAM][MAX_PROB];
        bool solved[MAX_TEAM][MAX_PROB] = {false};
        bool participation[MAX_TEAM] = {false};
        memset(score, 0, sizeof(score));
        for (auto& s : submissions) {
            participation[s.team] = true;
            if (s.L == 'C' && !solved[s.team][s.prob]) {
                score[s.team][s.prob] += s.time;
                solved[s.team][s.prob] = true;
            }
            else if (s.L == 'I' && !solved[s.team][s.prob]) {
                score[s.team][s.prob] += 20;
            }
        }

        vector<Rank> vr;
        for (int i = 0; i < MAX_TEAM; i++) {
            if (!participation[i])
                continue;
            int numProb = 0;
            int penalty = 0;
            for (int j = 0; j < MAX_PROB; j++) {
                if (!solved[i][j])
                    continue;
                numProb++;
                penalty += score[i][j];
            }
            Rank r;
            r.team = i;
            r.numSolved = numProb;
            r.penalty = penalty;
            vr.push_back(r);
        }

        sort(vr.begin(), vr.end(),
             [](Rank& a, Rank& b) {
                if (a.numSolved > b.numSolved)
                    return true;
                if (a.numSolved == b.numSolved) {
                    if (a.penalty < b.penalty)
                        return true;
                    if (a.penalty == b.penalty) {
                        if (a.team < b.team)
                            return true;
                    }
                }
                return false;
            });

        for (int i = 0; i < vr.size(); i++)
            printf("%d %d %d\n", vr[i].team, vr[i].numSolved, vr[i].penalty);

        if (tc)
            printf("\n");
    }

    return 0;
}
