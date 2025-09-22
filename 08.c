#include <stdio.h>
enum shape {
    ROCK,
    PAPER,
    SCISSORS
};
enum result {
    LOSS,
    DRAW,
    WIN
};
void print_shape(enum shape s)
{
    switch (s) {
        case ROCK:     printf("Rock"); break;
        case PAPER:    printf("Paper"); break;
        case SCISSORS: printf("Scissors"); break;
    }
}
void print_result(enum result r)
{
    switch (r) {
        case LOSS: printf("Loss"); break;
        case DRAW: printf("Draw"); break;
        case WIN:  printf("Win"); break;
    }
}
enum result get_result(enum shape a, enum shape b)
{
    if (a == b)
        return DRAW;
    
    switch (a)
    {
        case ROCK:
            if (b == SCISSORS)
                return WIN;
            else
                return LOSS;
        case PAPER:
            if (b == SCISSORS)
                return LOSS;
            else
                return WIN;
        case SCISSORS:
            if (b == ROCK)
                return LOSS;
            else
                return WIN;
    }
}
enum shape get_strength(enum shape s)
{
    switch (s) 
    {
        case ROCK:
            return SCISSORS;
        case PAPER:
            return ROCK; 
        case SCISSORS:
            return PAPER;
    }
}

int main()
{
    enum shape player1 = ROCK;
    enum shape player2 = SCISSORS;
    
    printf("Player 1: ");
    print_shape(player1);
    printf("\nPlayer 2: ");
    print_shape(player2);
    
    enum result res = get_result(player1, player2);
    printf("\nResult: ");
    print_result(res);
    
    printf("\nRock beats: ");
    print_shape(get_strength(ROCK));
}