#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

 typedef struct s_operation
 {
    char oper[6];
    int y;
    int x;
 } t_operation;

int array_filter(char array[6])
{
    int ret;
    char dif[5];
    int i;

    if (array[0] == '_')
        ret = 0;
    else if (array[0] != '$')
        ret = atoi(array);
    else
    {
        i = 1;
        while (i < 6)
        {
            dif[i-1] = array[i];
            i++;
        }
        ret = atoi(dif);
        if (ret < 0)
            ret = ret - 100001;
        else
            ret = ret + 100001;
    }
    return (ret);
}

int *calculate(t_operation **program, int *ref, int N)
{
    int ret;
    int counter;

    counter = 0;
    while (counter < N - 1)
    {
        printf("%s\n", program[counter]->oper);
        if (strcmp(program[counter]->oper, "VALUE") == 0)
        {
            if (program[counter]->x > 100000)
                program[counter]->x = (ref[program[counter]->x - 100001]);
            else if (program[counter]->x < -100000)
                program[counter]->x = (ref[program[counter]->x + 100001]);
            ret = program[counter]->x;
        }
        else if (strcmp(program[counter]->oper, "ADD") == 0)
        {
            if (program[counter]->x > 100000)
            {
                if (program[counter]->y > 100000)
                    program[counter]->y = (ref[program[counter]->y - 100001]);
                else if(program[counter]->y < 100000)
                    program[counter]->y = (ref[program[counter]->y + 100001]);
                ret = program[counter]->x + program[counter]->y;
            }
            else if (program[counter]->x < -100000)
            {
                program[counter]->x = ref[program[counter]->x + 100001];
                if (program[counter]->y > 100000)
                    program[counter]->y = ref[program[counter]->y - 100001];
                else if (program[counter]->y < -100000)
                    program[counter]->y = ref[program[counter]->y + 100001];
                ret = program[counter]->x + program[counter]->y;
            }
            else
            {
                if (program[counter]->y > 100000)
                    program[counter]->y = (ref[program[counter]->y - 100001]);
                else if (program[counter]->y < -100000)
                    program[counter]->y = (ref[program[counter]->y + 100001]);
                ret = program[counter]->x + program[counter]->y;
            }
        }
        else if (strcmp(program[counter]->oper, "SUB") == 0)
        {
            if (program[counter]->x > 100000)
            {
                if (program[counter]->y > 100000)
                    program[counter]->y = (ref[program[counter]->y - 100001]);
                else if(program[counter]->y < 100000)
                    program[counter]->y = (ref[program[counter]->y + 100001]);
                ret = program[counter]->x - program[counter]->y;
            }
            else if (program[counter]->x < -100000)
            {
                program[counter]->x = ref[program[counter]->x + 100001];
                if (program[counter]->y > 100000)
                    program[counter]->y = ref[program[counter]->y - 100001];
                else if (program[counter]->y < -100000)
                    program[counter]->y = ref[program[counter]->y + 100001];
                ret = program[counter]->x - program[counter]->y;
            }
            else
            {
                if (program[counter]->y > 100000)
                    program[counter]->y = (ref[program[counter]->y - 100001]);
                else if (program[counter]->y < -100000)
                    program[counter]->y = (ref[program[counter]->y + 100001]);
                ret = program[counter]->x - program[counter]->y;
            }
        }
        else if (strcmp(program[counter]->oper, "MULT") == 0)
        {
            if (program[counter]->x > 100000)
            {
                if (program[counter]->y > 100000)
                    program[counter]->y = (ref[program[counter]->y - 100001]);
                else if(program[counter]->y < 100000)
                    program[counter]->y = (ref[program[counter]->y + 100001]);
                ret = program[counter]->x * program[counter]->y;
            }
            else if (program[counter]->x < -100000)
            {
                program[counter]->x = ref[program[counter]->x + 100001];
                if (program[counter]->y > 100000)
                    program[counter]->y = ref[program[counter]->y - 100001];
                else if (program[counter]->y < -100000)
                    program[counter]->y = ref[program[counter]->y + 100001];
                ret = program[counter]->x * program[counter]->y;
            }
            else
            {
                if (program[counter]->y > 100000)
                    program[counter]->y = (ref[program[counter]->y - 100001]);
                else if (program[counter]->y < -100000)
                    program[counter]->y = (ref[program[counter]->y + 100001]);
                ret = program[counter]->x * program[counter]->y;
            }
        }
        ref[counter] = ret;
        counter++;
    }
    return (ref);
}

int main()
{
    int         N, i;
    int         *ret;
    t_operation *program;

    scanf("%d", &N);
    program = (t_operation *)malloc(sizeof(t_operation) * N);
    ret = (int *)malloc(sizeof(int) * N);
    
    for (i = 0; i < N; i++) 
    {
        char operation[6];
        char arg_1[7];
        char arg_2[7];
        scanf("%s%s%s", operation, arg_1, arg_2);
        ret[i] = 0;

        for (int j  = 0; j < strlen(operation); j++)
        {
            program[i].oper[j] = operation[j];
        }
        program[i].x = array_filter(arg_1);
        program[i].y = array_filter(arg_2);
        //printf("\n%s,  %d,   %d\n", program[i].oper, program[i].x, program[i].y);
    }
    
    i = 0;

    ret = calculate(&program, ret, N);

    return (0);
}