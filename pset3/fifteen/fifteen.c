/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(int d);
void draw(int d);
bool move(int tile,int d);
bool won(int d);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init(d);

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw(d);

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won(d))
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile,d))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(int d)
{
    int i,j;
    
    if(d==3 || d==5 || d==7 || d==9){
        int temp = (d*d)-1;
        
        for(i=0;i<d;i++){
            for(j=0;j<d;j++){
                board[i][j] = temp;
                temp--;
            }
        }
    }
    
    
    if(d==4 || d==6 || d==8){
        int temp = (d*d)-1;
        for(i=0;i<d;i++){
            for(j=0;j<d;j++){
                board[i][j] = temp;
                temp--;
            }
        }
        
        board[d-1][d-3] = 1;
        board[d-1][d-2] = 2;
        
    }
}

/**
 * Prints the board in its current state.
 */
void draw(int d)
{
    int i,j;
    
    for(i=0;i<d;i++){
        for(j=0;j<d;j++){
            printf("%2d",board[i][j]);
            printf(" ");
        }printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile,int d)
{
    int u,dn,l,r,row,col,i,j;
    for(i=0;i<d;i++){
        for(j=0;j<d;j++){
            if(board[i][j] == tile){
                l = j-1;    if(l == -1)  l = j;
                r = j+1;    if(r == d) r = j;
                u = i-1;    if(u == -1)  u = i;
                dn = i+1;   if(dn == d)  dn = i;
                row = i;
                col = j;
            }
        }
    }
    int x,y;
    for(i=0;i<d;i++){
        for(j=0;j<d;j++){
            if(board[i][j] == 0){
                x = i;
                y = j;
            }
        }
    }
    
    if(board[row][l] == board[x][y]){
        int temp = board[x][y];
        board[x][y] = board[row][col];
        board[row][col] = temp;
        return true;
    }
    
    
    if(board[row][r] == board[x][y]){
        int temp = board[x][y];
        board[x][y] = board[row][col];
        board[row][col] = temp;
        return true;
    }
    
    
    if(board[u][col] == board[x][y]){
        int temp = board[x][y];
        board[x][y] = board[row][col];
        board[row][col] = temp;
        return true;
    }
    
    
    if(board[dn][col] == board[x][y]){
        int temp = board[x][y];
        board[x][y] = board[row][col];
        board[row][col] = temp;
        return true;
    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(int d)
{
    int i,j,temp=0;
    for(i=0;i<d;i++){
        for(j=0;j<d;j++){
            if((i==d-1 && j==d-1) && board[d-1][d-1]==0){
                    return true;
                }
            if(board[i][j]>temp && !(i==d-1 && j==d-1)){
                temp = board[i][j];
            }
            else{
                return false;
            }
        }
    }
    return false;
}