#include <iostream>
using std::cout; using std::endl; using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::find;

/*
0 | 1 | 2
3 | 4 | 5
6 | 7 | 8
*/

bool board_full(vector<char> board){
    cout << endl;
    for (char elem: board){
        if (elem != 'X' && elem != 'O'){
           return false;
        }
    }
    return true;
}


bool win(vector<char> board){
    
    for(int i=0;i<3;i++){
        int pos = i*3;
        // horizontal line win
        if (board[pos] == board[pos+1] && board[pos] == board[pos+2])
        return true;

        // vertical line win
        if (board[pos] == board[pos+3] && board[pos] == board[pos+6])
        return true;
    }

    // diagonal win
    if (board[0] == board[4] && board[0] == board[8])
        return true;
    if (board[2] == board[4] && board[2] == board[6])
        return true;
 
    // no win :(
    return false;
}


bool make_move(vector<char> &board, char player, int pos){
    if (pos > static_cast<int>(board.size() - 1)){
        cout << "Invalid Move!" << endl;
        return false;
    }
    if (board.at(pos) == 'X' || board.at(pos) == 'O'){
        cout << "Invalid Move!" << endl;
        return false;
    } else { 
        board.at(pos) = player;
        return true;
    }
}


void print_board(vector<char> board){
  vector<int> line = {1,4,7};
  vector<int> newline = {2,5,8};
  
  for (int i=0; i < static_cast<int>(board.size()); i++){
    // update the char to be printed
    // if (board.at(i) == 'X' || board.at(i) == 'O') 
    char print = board.at(i);

    // decide how to print char based on index
    if (find(line.begin(), line.end(), i) != line.end()){
      cout << " | "  << print << " | ";
    } else if (find(newline.begin(), newline.end(), i) != newline.end()){
      cout << print << endl;
    } else {
      cout << print;
    }


  }
} 


int main(){
  vector<char> board = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
  char p1 = 'X';
  char p2 = 'O';
  int move=-1;
  for (;;){
      print_board(board);
      cout << endl;
      cout << "Player 1 turn -> ";
      cin >> move;
      cout << endl;
      while (!make_move(board, p1, move)){
        cout << "Player 1 turn -> ";
        cin >> move;
      }
      if (win(board)){
          print_board(board);
          cout << "Player 1 wins!" << endl;
          break;
      }
      if (board_full(board)){
          print_board(board);
          cout << "Cat game!" << endl;
          break;
      }

      print_board(board);
      cout << endl;
      cout << "Player 2 turn -> ";
      cin >> move;
      cout << endl;
      while (!make_move(board, p2, move)){
        cout << "Player 2 turn -> ";
        cin >> move;
      }
      if (win(board)){
          cout << "Player 2 wins!";
          break;
      }
      if (board_full(board)){
          print_board(board);
          cout << "Cat game!" << endl;
          break;
      }
  }

  return 0;
}