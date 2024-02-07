// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves {};
    int cx = knight.at(0) -'a', cy = knight.at(1) - '0';

    for (int x {1}; x < 3; ++x)
    {
        int y = 3-x;
        int nx = cx+x,ny=cy+y;
        std::string position = "";
        position += static_cast<char>(nx+'a') + std::to_string(ny);
        if (nx < 8 && ny < 9) moves.push_back(position);
        
        y *= -1;
        nx = cx+x; ny=cy+y;
        position = static_cast<char>(nx+'a') + std::to_string(ny);
        if (nx < 8 && ny > 0) moves.push_back(position);

        // 
        x *= -1;
        nx = cx+x; ny=cy+y;
        position = static_cast<char>(nx+'a') + std::to_string(ny);
        if (nx >= 0 && ny > 0) moves.push_back(position);
        
        y *= -1;
        nx = cx+x; ny=cy+y;
        position = static_cast<char>(nx+'a') + std::to_string(ny);
        if (nx >= 0 && ny < 9) moves.push_back(position);

        x*=-1;
    }
    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}