#include <stdio.h>

int main() {
    int n, m, i, j, k, found, deadlock = 0;
    printf("Enter number of processes and resource types: ");
    scanf("%d %d", &n, &m);

    int alloc[n][m], req[n][m], avail[m], finish[n];

    printf("\nEnter Allocation Matrix (%d x %d):\n", n, m);
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&alloc[i][j]);

    printf("\nEnter Request Matrix (%d x %d):\n", n, m);
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&req[i][j]);

    printf("\nEnter Available Resources (%d values):\n", m);
    for(i=0;i<m;i++) scanf("%d",&avail[i]);

    for(i=0;i<n;i++) finish[i]=0;

    do {
        found = 0;
        for(i=0;i<n;i++) if(!finish[i]) {
            for(j=0;j<m;j++) if(req[i][j] > avail[j]) break;
            if(j==m) {
                for(k=0;k<m;k++) avail[k]+=alloc[i][k];
                finish[i]=1; found=1;
                printf("Process P%d has finished, releasing resources.\n", i);
            }
        }
    } while(found);

    for(i=0;i<n;i++) if(!finish[i]) {
        deadlock=1; printf("Process P%d is in deadlock.\n", i);
    }
    if(!deadlock) printf("\nNo Deadlock Detected.\n");
    return 0;
}
