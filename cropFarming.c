#include <stdio.h>
#define ROWS 8
#define COLS 8

// Initialize the map array to contain hashtags
void initializeMap(char map[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            map[i][j] = '#';
        }
    }
}

// Display the current/updated map
void displayMap(char map[ROWS][COLS], int x, int y)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == y && j == x)
            {
                printf("[T] ");
            }
            else
            {
                printf("[%c] ", map[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to move player
void move(int *x, int *y, char direction, char map[ROWS][COLS])
{
    // Mark the current position as harvested
    map[*y][*x] = '_';
    
    // Check for the direction and move the player if within bounds
    if (direction == 'U' && *y > 0)
    {
        *y -= 1;
    }
    else if (direction == 'D' && *y < ROWS - 1)
    {
        *y += 1;
    }
    else if (direction == 'L' && *x > 0)
    {
        *x -= 1;
    }
    else if (direction == 'R' && *x < COLS - 1)
    {
        *x += 1;
    }
    else
    {
        printf("Please stay within the bounds of the map\n");
    }
}

// Check if all squares are harvested
int checkHarvested(char map[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (map[i][j] == '#')
            {
                return 0; // Found unharvested square
            }
        }
    }
    return 1; // All squares harvested
}

int main(void)
{
    char map[ROWS][COLS];
    int playerX = 0, playerY = 0;
    char direction;
    
    // Initialize the map
    initializeMap(map);
    printf("Initial map: # = wheat, T = player, _ = harvested wheat\n");
    displayMap(map, playerX, playerY);

    // Continue until all wheat is harvested
     while(checkHarvested(map) != 1)
    {
        printf("Enter direction (U/D/L/R): ");
        scanf(" %c", &direction);
        
        move(&playerX, &playerY, direction, map);
        
        printf("CURRENT MAP:\n");
        displayMap(map, playerX, playerY);
        
    }
    printf("Congrats! You harvested all the wheat!\n");
}
