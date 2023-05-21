#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>


double sqr(double num)
{
    return pow(num, 2);
}

void drawing_head(int size)
{
    //Acceptable distance from circle
    double rate = 0.25 * size; //Increase as size getting bigger
    double radius = size / 2;
    double adjustment;
    if (size % 2 == 0)
    {
        adjustment = 0.5; //Adding 0.5 to shift from left to right
    }
    else
    {
        adjustment = 1; //It needs more adjustmemt when size is odd number
    }
    /*Using equation of circle*/
    /* x^2 + y^2 = r^2 */
    /*Aspect ratio of halfwidth letter is 2 : 1*/
    for (double l = radius * (-1); l <= radius; l += 1)
    {
        for (double w = radius + adjustment; w >= radius * (-1); w -= 0.5)
        {
            /*If distance is acceptable,drawing*/
            if (l * l + w * w > sqr(radius) - rate && l * l + w * w < sqr(radius) + rate)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

}

void drawing_lags(int size)
{
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j < size - i ; j++)
        {
            printf(" ");
        }
        printf("/");
        for (int j = size; j > size - i; j--)
        {
            printf("  ");
        }
        printf(" ");
        printf("\\\n");
    }
}

void drawing_body(int size)
{
    drawing_lags(size); //Sharing same shape
    for (int i = 0; i < size + 1; i++)
    {
        printf(" -");
    }
    printf("\n");
}


int main()
{
	int input = 0;
	printf("What size of stick figuer ? (0 to quit)");
	scanf("%d", &input);

	if(input == 0)
    {
        return 0;//End of program
    }

    printf("\n");
    drawing_head(input);

    drawing_body(input);

    drawing_lags(input);

    main();
}
