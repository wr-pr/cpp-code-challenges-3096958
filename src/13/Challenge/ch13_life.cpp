// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define N 30
#define M 30

int wrapN (int i){
    return (i % N + N) % N;
}
int wrapM (int i){
    return (i % M + M) % M;
}

bool live_on (const char game[N][M], int i, int j){
    int neighbors {0};
    bool lives {game[i][j] == 'X'};
    for (int n {-1}; n < 2; ++n)
    {
        std::vector<int> innerloop = n==0 ? std::vector<int>{-1, 1} : std::vector<int>{-1, 0, 1};
        for (int &m : innerloop)
            if (game[wrapN(i+n)][wrapM(j+m)] == 'X') ++neighbors;
    }
    return (1 < neighbors && neighbors < 4 && lives) || (3 == neighbors && !lives);
}

// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
int main(){    
    // The game, initialized with a glider and a blinker.
    char game[N][M];  
    std::memset(game,'-',N*M); // Initialize game with dashes.

    // A glider     // - - - - - - - - - -
    game[1][1]='X'; // - X - - - - - - - -
    game[2][2]='X'; // - - X - - - - - - -
    game[3][0]='X'; // X X X - - - - - - -
    game[3][1]='X';
    game[3][2]='X';

    // A blinker    // - - - - - - - - - -
    game[3][6]='X'; // - - - - - - - - - -
    game[3][7]='X'; // - - - - - - - - - -
    game[3][8]='X'; // - - - - - - X X X -
    
    int generation = 0;
    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";

        // Write your code here
        char oldgame[N][M];
        for (int i = 0; i < N; ++i) std::memcpy(oldgame[i], game[i], M * sizeof(char));

        for (int i {0}; i< N; ++i){
            for (int j {0}; j< N; ++j){
                game[i][j] = live_on(oldgame,i,j) ? 'X' : '-';
        }}
        
        std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    }while(go_on.compare("EXIT")!=0);
    
    return 0;
}
