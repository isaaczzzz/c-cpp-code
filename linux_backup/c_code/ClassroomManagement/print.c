#include <stdio.h>
#include <windows.h>
#include "read_print.h"

void color_print(const char *s, int color)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
    printf(s);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7); //改回默认白色
}

void print_head(void)
{
    color_print("**********************************************\n", 2);
    color_print("*                                            *\n", 2);
    color_print("*              Welcome to use                *\n", 2);
    color_print("*         Classroom Management System        *\n", 2);
    color_print("*                                            *\n", 2);
    color_print("**********************************************\n", 2);
}

void code_error(void) { color_print("Illegal code.\n", 4); }

void database_full(void) { color_print("Database is full; can't add more students.\n", 4); }

void database_empty(void) { color_print("Database is empty. Please insert data.\n", 4); }

void exist(void) { color_print("Student already exists.\n", 2); }

void not_found(void) { color_print("Student not found.\n", 2); }

void lucky_student(int id, char *name)
{
    printf("The lucky student is:\n\n");
    Sleep(2000);
    printf("%d  ", id);
    color_print(name, 2);
    putchar('\n');
}