#include <stdio.h>
#include <stdlib.h>

void draw_circle(int size) /* �e�� */
{
    int i;
    int j;

    if(size <= 5){
        if(size % 2 == 0){
            for(i = 1; i <= size; i++){
                printf(" ");
            }
            printf("*\n");

            for(i = 1; i <= size / 2; i++){
                for(j = size / 2 - (i - 1); j >= 1; j--){
                    printf(" ");
                }
                printf("*");

                for(j = 1; j <= (size - 1) + 2 * (i - 1); j++){
                    printf(" ");
                }
                printf("*\n");
            }

            for(i = 1; i < size / 2; i++){
                for(j = 1; j < i + 2; j++){
                    printf(" ");
                }
                printf("*");

                for(j = (size - 1) + 2 * (size / 2 - 1 - i); j >= 1; j--){
                    printf(" ");
                }
                printf("*\n");
            }
        }
        else{
            for(i = 1; i <= size; i++){
                printf(" ");
            }
            printf("*\n");

            for(i = 1; i <= (size - 1) / 2; i++){
                for(j = size / 2 - (i - 1); j >= 1; j--){
                    printf(" ");
                }
                printf("*");

                for(j = 1; j <= size + 2 * (i - 1); j++){
                    printf(" ");
                }
                printf("*\n");
            }

            for(i = 1; i <= (size - 1) / 2; i++){
                for(j = 1; j < i + 1; j++){
                    printf(" ");
                }
                printf("*");

                for(j = size + 2 * ((size + 1) / 2 - 1 - i); j >= 1; j--){
                    printf(" ");
                }
                printf("*\n");
            }
        }
    }
    else{
        int head_radius = size / 2; /* �p���Y���b�| */
        int body_height = size; /* �]�w���骺���� */

        for (i = 0; i < size; i++) {
            for (j = 0; j <= size * 2; j++) {
                int dx = abs(j - size);
                int dy = abs(i - head_radius);
                double dist = sqrt(dx*dx + dy*dy);

                if (dist > head_radius - 0.5 && dist < head_radius + 0.5) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

void draw_intersect(int size) /* �e���k����׽u */
{
    int i;
    int j;

    for(i = 1; i <= size; i++){
        for(j = size - i; j >= 1; j--){
            printf(" ");
        }
        printf("/");

        for(j = 1; j < i * 2; j++){
            printf(" ");
        }
        printf("\\\n");
    }
}

void draw_base(int size) /* �e�T���ΤU�������u */
{
    int i;

    for(i = 1; i <= size*2 + 1; i++){
        printf("-");
    }
    printf("\n");
}

void draw_triangle(int size) /* �e�T���� */
{
    draw_intersect(size);
    draw_base(size);
}

int main()
{
    int size;
    printf("input size: "); /* ��J�ϧΤj�p */
    scanf("%d",&size);

    draw_circle(size);
    draw_triangle(size);
    draw_intersect(size);

    return 0;
}

/*THIS CODE IS MY OWN WORK. IT WAS WRITTEN WITHOUT CONSULTING CODE WRITTEN BY OTHER STUDENTS OR ANY ONE WHO IS NOT AWARE OF MY REFERENCE. 410125034 ���\ʹ*/
