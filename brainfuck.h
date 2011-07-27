#ifndef BRAINFUCK_H_INCLUDED
#define BRAINFUCK_H_INCLUDED


#include <stdio.h>
#include <string.h>

#define MAX_INPUT 1000
#define MEMORY_LENGTH 30000

int main(void);
void interpret(void);
void jump_for_left_bracket(void);
void jump_for_right_bracket(void);

/* BRAINFUCK_H_INCLUDED*/
#endif
