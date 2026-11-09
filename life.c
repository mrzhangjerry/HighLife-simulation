#include <stdio.h>
#include <stdlib.h>

constexpr int HEIGHT = 30;
constexpr int WIDTH = 30;
constexpr int GENERATIONS = 70;


struct cell{
    bool alive;
    unsigned age;
};
struct rule{
    bool birth[9];
    bool survival[9];
};
struct board{
    struct cell layout[HEIGHT][WIDTH];
};

int main(void){
    
    struct rule Rule = {
        .birth = {
            [3] = true,
            [6] = true
        },
        .survival = {
            [2] = true,
            [3] = true
        }
    };

    struct board Board = {
        .layout = {
            [12][14] = {.alive = true, .age = 0},
            [12][15] = {.alive = true, .age = 0},
            [12][16] = {.alive = true, .age = 0},
            [13][13] = {.alive = true, .age = 0},
            [13][16] = {.alive = true, .age = 0},
            [14][12] = {.alive = true, .age = 0},
            [14][16] = {.alive = true, .age = 0},
            [15][12] = {.alive = true, .age = 0},
            [15][15] = {.alive = true, .age = 0},
            [16][12] = {.alive = true, .age = 0},
            [16][13] = {.alive = true, .age = 0},
            [16][14] = {.alive = true, .age = 0}
        }
    };
    
    printf("Generation 0:");
    printf("\n");
    for(int row = 0; row < HEIGHT; row++){
        for(int col = 0; col < WIDTH; col++){
                if(!Board.layout[row][col].alive){
                    printf(".");

                }else{
                    if(Board.layout[row][col].age == 0){
                        printf("o");
                    }else if(Board.layout[row][col].age == 1){
                        printf("O");
                    }else if(Board.layout[row][col].age > 1){
                        printf("@");
                    }
                }     
        }
        printf("\n");
    };

    for(int n = 0; n < GENERATIONS; n++){                           //loop for each board 70times

        struct board newBoard = {};


        for(int row = 0; row < HEIGHT; row++){                      //loop for each cell  900times
            for(int col = 0; col < WIDTH; col++){
                int count = 0;                                              //alive cell count
                if(Board.layout[row][col].alive){
                    count--;
                }
                for(int i = -1; i < 2; i++){                        //loop for 8 around cells
                    for(int j = -1; j < 2; j++){
                        int r = (row + i + HEIGHT) % HEIGHT;
                        int c = (col + j + WIDTH) % WIDTH;
                        if(Board.layout[r][c].alive){
                            count++;
                        };
                    };
                };

                if(Board.layout[row][col].alive){                  // if this cell alives
                    if(Rule.survival[count]){
                        newBoard.layout[row][col].alive = true;
                            newBoard.layout[row][col].age = Board.layout[row][col].age + 1; 

                    }else{
                        newBoard.layout[row][col].alive = false;
                    }
                }else{
                    if(Rule.birth[count]){
                        newBoard.layout[row][col].alive = true;
                    }else{
                        newBoard.layout[row][col].alive = false;
                    }
                }
            };
        };
        Board = newBoard;

        printf("Generation %d:", n + 1);
        printf("\n");
        for(int row = 0; row < HEIGHT; row++){
            for(int col = 0; col < WIDTH; col++){

                if(!Board.layout[row][col].alive){
                    printf(".");

                }else{
                    if(Board.layout[row][col].age == 0){
                        printf("o");
                    }else if(Board.layout[row][col].age == 1){
                        printf("O");
                    }else if(Board.layout[row][col].age > 1){
                        printf("@");
                    }
                }
            }
        };
        printf("\n");
    };



    return EXIT_SUCCESS;
}