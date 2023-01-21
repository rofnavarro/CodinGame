#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


 // -----------------------------------STRUCTS--------------------------------------

typedef struct  s_numbers
{
    long x;
    long y;
}   t_numbers;

typedef struct  s_operation
{
    char    oper[6];
    int     answer;
}   t_operation;

typedef struct   s_program
{
    t_numbers   pair;
    t_operation o_pair;
}   t_program;


 // -----------------------------------UTILS----------------------------------------

int     array_filter(char arg[6])
{
    int     ret;
    char    dif[5];

    if (arg[0] == '_')
        ret = 0;
    else if (arg[0] != '$')
        ret = atoi(arg);
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
        ret = ret + 1000000001;
    }
    return (ret);
}

void    run_operation(t_program *program, int i)
{
    if (strcmp(program[i].o_pair.oper, "VALUE") == 0)
        program[i].o_pair.answer = program[i].pair.x;
    else if (strcmp(program[i].o_pair.oper, "ADD") == 0)
        program[i].o_pair.answer = program[i].pair.x + program[i].pair.y;
    else if (strcmp(program[i].o_pair.oper, "SUB") == 0)
        program[i].o_pair.answer = program[i].pair.x - program[i].pair.y;
    else if (strcmp(program[i].o_pair.oper, "MULT") == 0)
        program[i].o_pair.answer = program[i].pair.x * program[i].pair.y;
}

int     derref_value(t_program *program, int i)
{
    int ref;

    if (program[i].pair.x > 1000000000)
    {
        ref = program[i].pair.x - 1000000001;
        if (program[ref].pair.x < 1000000000 && program[ref].pair.y < 1000000000)
        {
            program[i].pair.x = program[ref].o_pair.answer; 
            return (0);
        }
    }
    if (program[i].pair.y > 1000000000)
    {
        ref = program[i].pair.y - 1000000001;
        if (program[ref].pair.y < 1000000000 && program[ref].pair.y < 1000000000)
        {
            program[i].pair.y = program[ref].o_pair.answer; 
            return (0);
        }
    }
    return (1);
}

void    run_program(t_program *program, int size)
{
    int i, start;
    int finished;
    int derref;

    finished = 1;
    i = 0;
    while (i < size)
    {
        if (program[i].pair.x <= 1000000000 || program[i].pair.y <= 1000000000)
            break;
        i++;
    }
    while (finished != 0)
    {
        while (i < size)
        {
            if (program[i].pair.x > 1000000000 || program[i].pair.y > 1000000000)
            {
                derref = derref_value(program, i);
                if (derref == 0)
                    run_operation(program, i);
            }
            else
                run_operation(program, i);
        i++;
        }
        for (int j = 0; j < size; j++)
        {
            if (program[j].pair.x > 1000000000 || program[i].pair.y > 1000000000)
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
    t_program   *program;

    scanf("%d", &N);
    program = (t_program *)malloc(sizeof(t_program) * N);

    for (int i = 0; i < N; i++)
    {
        char operation[6];
        char arg_1[7];
        char arg_2[7];
        scanf("%s%s%s", operation, arg_1, arg_2);

        strcpy(program[i].o_pair.oper, operation);
        program[i].pair.x = array_filter(arg_1);
        program[i].pair.y = array_filter(arg_2);
    }
    
    run_program(program, N);


    for (int i = 0; i < N; i++)
    {
        printf("%d\n", program[i].o_pair.answer);
    }

    free(program);
    return 0;
}