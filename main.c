#include "brainfuck.h"

/* means of chars */
const char increment_pointer_char = '>';
const char decrement_pointer_char = '<';
const char increment_value_char = '+';
const char decrement_value_char = '-';
const char putchar_char = '.';
const char getchar_char = ',';
const char loop_start_char = '[';
const char loop_end_char = ']';

/*vector that save input.*/
char input[MAX_INPUT];
/* input_poiner is pointer of input.
 * At first,the head of input.
 */
char *input_pointer = input;

/*vector that save memory.
 * At first, all value is 0
 */
char memory[MEMORY_LENGTH] = {0};
/* input_poiner is pointer of input.
 * at first,the head of input.
 */
char *memory_pointer = memory;

/*main function*/
int main(void){
    interpret();
    return 0;
}

/* read one line from stdin and execute it*/
void interpret(){
    /* read one line */
    fgets(input,sizeof(input),stdin);
    /* overwrite \n by \0.*/
    input[strlen(input)-1] = '\0';
    /* execute from head of input to tail of input.*/
    while(*input_pointer != '\0'){
        switch(*input_pointer){
            /*increment memory pointer*/
            case increment_pointer_char:
                memory_pointer++;
                /*move forward*/
                input_pointer++;
                break;
            /*decrement memory pointer*/
            case decrement_pointer_char:
                memory_pointer--;
                /*move forward*/
                input_pointer++;
                break;
            /*increment value*/
            case increment_value_char:
                (*memory_pointer)++;
                /*move forward*/
                input_pointer++;
                break;
            /*decrement value*/
            case decrement_value_char:
                (*memory_pointer)--;
                /*move forward*/
                input_pointer++;
                break;
            /*putchar*/
            case putchar_char:
                putchar(*memory_pointer);
                /*move forward*/
                input_pointer++;
                break;
            /*getchar*/
            case getchar_char:
                *memory_pointer = getchar();
                /*move forward*/
                input_pointer++;
                break;
            /*if *memory_pointer == 0 -> call jump_for_left_bracket.
             * else just move forward.
             */
            case loop_start_char:
                if(*memory_pointer==0){
                    jump_for_left_bracket();
                }else{
                    /*move forward*/
                    input_pointer++;
                }
                break;
            /*if *memory_pointer != 0 -> call jump_for_left_bracket.
             * else just move forward.
             */
            case loop_end_char:
                if(*memory_pointer!=0){
                    jump_for_right_bracket();
                }else{
                    /*move forward*/
                    input_pointer++;
                }
                break;
            /* if input char does't have means in bf,
             * just move forwad
             */
            default:
                /*move forward*/
                input_pointer++;
                break;
        }
    }
}

/* jump to one behind matching right bracket. */
void jump_for_left_bracket(){
    int x = 1;
    while(x!=0 || *input_pointer!=loop_end_char){
        input_pointer++;
        if(*input_pointer==loop_start_char){
            x++;
        }else if(*input_pointer==loop_end_char){
            x--;
        }
    }
    input_pointer++;
}

/* jump to matching light bracket. */
void jump_for_right_bracket(){
    int x = 1;
    while(x!=0 || *input_pointer!=loop_start_char){
        input_pointer--;
        if(*input_pointer==loop_end_char){
            x++;
        }else if(*input_pointer==loop_start_char){
            x--;
        }
    }
}
