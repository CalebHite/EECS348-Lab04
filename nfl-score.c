#include <stdio.h>

void find_combinations(int score, int td2pt, int tdFG, int td, int fg, int safety) {
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdFG, td, fg, safety);
        return;
    }
    
    if (score >= 8) {
        find_combinations(score - 8, td2pt + 1, tdFG, td, fg, safety);
    }
    if (score >= 7) {
        find_combinations(score - 7, td2pt, tdFG + 1, td, fg, safety);
    }
    if (score >= 6) {
        find_combinations(score - 6, td2pt, tdFG, td + 1, fg, safety);
    }
    if (score >= 3) {
        find_combinations(score - 3, td2pt, tdFG, td, fg + 1, safety);
    }
    if (score >= 2) {
        find_combinations(score - 2, td2pt, tdFG, td, fg, safety + 1);
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
        find_combinations(score, 0, 0, 0, 0, 0);
    }

    return 0;
}
