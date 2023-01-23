#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


 // -----------------------------------STRUCTS--------------------------------------

typedef struct  s_numbers
{
    char    oper[6];
    int		x;
    int		isRefX;
    int		y;
    int		isRefY;
    int     answer;
}   t_numbers;

 // -----------------------------------UTILS----------------------------------------

int     array_filter(char arg[6], int *ref)
{
    int     ret;
    char    dif[5];

    if (arg[0] == '_')
    {
        *ref = 0;
        ret = 0;
    }
    else if (arg[0] != '$')
    {
        *ref = 0;
        ret = atoi(arg);
    }
    else
    {
        int i;

        i = 1;
        while (i < 6)
        {
            dif[i - 1] = arg[i];
            i++;
        }
        ret = atoi(dif);
        *ref = 1;
    }
    return (ret);
}

void    run_operation(t_numbers **program, int i)
{
    if (strcmp(program[i]->oper, "VALUE") == 0)
        program[i]->answer = program[i]->x;
    else if (strcmp(program[i]->oper, "ADD") == 0)
        program[i]->answer = program[i]->x + program[i]->y;
    else if (strcmp(program[i]->oper, "SUB") == 0)
        program[i]->answer = program[i]->x - program[i]->y;
    else if (strcmp(program[i]->oper, "MULT") == 0)
        program[i]->answer = program[i]->x * program[i]->y;
}

int     derref_value(t_numbers **program, int i)
{
    int ref;

    if (program[i]->isRefX != 0)
    {
        ref = program[i]->x;
        if (program[ref]->isRefX == 0 && program[ref]->isRefY == 0)
        {
            program[i]->x = program[ref]->answer; 
            program[i]->isRefX = 0;
            return (0);
        }
    }
    if (program[i]->isRefY != 0)
    {
        ref = program[i]->y;
        if (program[ref]->isRefY == 0 && program[ref]->isRefY == 0)
        {
            program[i]->y = program[ref]->answer;
            program[i]->isRefY = 0;
            return (0);
        }
    }
    return (1);
}

void    run_program(t_numbers *program, int size)
{
    int i, start;
    int finished;
    int derref;

    finished = 1;
    i = 0;
    while (i < size)
    {
        if (program[i].isRefX == 0 || program[i].isRefY == 0)
            break;
        i++;
    }
    while (finished != 0)
    {
        while (i < size)
        {
            if (program[i].isRefX != 0 || program[i].isRefY != 0)
            {
                derref = derref_value(&program, i);
                if (derref == 0)
                    run_operation(&program, i);
            }
            else
                run_operation(&program, i);
        	i++;
        }
        for (int j = 0; j < size; j++)
        {
            if (program[j].isRefX != 0 || program[i].isRefY != 0)
                i = 0;
            else
                finished = 0;
        }

    }
}


 // -----------------------------------MAIN-----------------------------------------

int     main()
{
    int         N;
    t_numbers	*program;

    scanf("%d", &N);
    program = (t_numbers *)malloc(sizeof(t_numbers) * N);

    for (int i = 0; i < N; i++)
    {
        char operation[6];
        char arg_1[7];
        char arg_2[7];
        scanf("%s%s%s", operation, arg_1, arg_2);

        strcpy(program[i].oper, operation);
        program[i].x = array_filter(arg_1, &program[i].isRefX);
        program[i].y = array_filter(arg_2, &program[i].isRefY);
    }
    
    run_program(program, N);

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", &program[i].answer);
    }

    free(program);
    return 0;
}