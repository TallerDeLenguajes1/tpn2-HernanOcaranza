#include <stdio.h>

#define N 4
#define M 5

int main () {
    int f,c;
    double mt[N][M], * pMt = &mt[N][M];

    for(f = 0;f<N; f++) {
        for(c = 0;c<M; c++) {
            *(pMt + (f * M + c)) = f * M + c;
        }
    }

    for(f = 0;f<N; f++) {
        for(c = 0;c<M; c++) {

            printf("%lf ", *(pMt + (f * M + c)));
        }
        printf("\n");
    }
    getchar();
    return 0;

}

