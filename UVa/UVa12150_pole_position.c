#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curr_pos[1024];
int start_pos[1024];
int adj[1024];

int main()
{
    int num_cars;
    int i;
    int start_index;
    int invalid;
    
    while (1) {
        scanf("%d", &num_cars);
        if (num_cars == 0)
            break;

        for (i = 0; i < num_cars; i++) {
            scanf("%d %d", curr_pos + i, adj + i);
        }

        invalid = 0;
        memset((void*)start_pos, 0, sizeof(int) * num_cars);
        for (i = 0; i < num_cars; i++) {
            start_index = i + adj[i];
            if (start_index < 0 || start_index >= num_cars) {
                invalid = 1;
                break;
            }
            if (start_pos[start_index] != 0) {
                invalid = 1;
                break;
            }
            start_pos[start_index] = curr_pos[i];
        }

        if (invalid) {
            printf("-1\n");
        }
        else {
            for (i = 0; i < num_cars; i++) {
                if (i < (num_cars - 1))
                    printf("%d ", start_pos[i]);
                else
                    printf("%d\n", start_pos[i]);
            }
        }
    }

    return 0;
}



