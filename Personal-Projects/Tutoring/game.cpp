#include "game.h"

Game::Game() { //default constructor

    p1 = Player();

    p2 = Player();

}



Game::Game(Player player1, string grid1, Player player2, string grid2) {

    p1 = Player(player1); //nondefault

    p2 = Player(player2);

    

    if(!(!(grid1 == "") && p1.load_grid_file(grid1))) {

        generate_random_grid(p1);

        cout << "Generating random grid for " << p1.get_name() << endl;

    }

    

    if (!(!(grid2 == "") && p2.load_grid_file(grid2))) {

        generate_random_grid(p2);

        cout << "Generating random grid for " << p2.get_name() << endl;

    }

    

}



Player Game::get_p1() { //getter

    return p1;

}



Player Game::get_p2() { //getter

    return p2;

}



string Game::get_move(string player_name) { 

    string move;

    cout << player_name << " enter your move:" << endl; //asks player for input

    cin >> move;

    return move;

}



bool Game::check_valid_move(string move) {

    int size = static_cast<int>(move.size());

       if (size != 2) {

           cout << p1.get_name() << " you entered an invalid input" << endl;

           return false;

       }

    char firstLetter = move.at(0);

    char secondLetter = toupper(move.at(1));

       

       if (((firstLetter >= '1') && (firstLetter <= '8')) && ((secondLetter >= 'A') && (secondLetter <= 'H'))) {

           return true;

       } else {

           cout << p1.get_name() << " you entered an invalid position" << endl;

           return false;

       }

}



void Game::start(char difficulty, int max_num_rounds) {
    int round = 0;
        // loop continues the game until one of these conditions is met
        while ((round < max_num_rounds) && (p1.destroyed() == false) && (p2.destroyed() == false)) {
            // get p1 move
            string p1_move = get_move(p1.get_name());
            // if move invalid, continually ask for a move
            while (check_valid_move(p1_move) == false) {
                    p1_move = get_move(p1.get_name());
            }
            // if move valid, attack p2 at said position
                if (chek_valid_move(p1_move) == true) {
                    char x = p1_move.at(0);
                    char y = p1_move.at(1);
                    Position p1move(x, y);
                    p1.attack(p2, p1move);
                    // get p2 move + attack
                    opponent_make_move(difficulty);

                    // print out both grids
                    cout << "Your grid" << endl;
                    p1.print_grid();
                    cout << p2.get_name() << "'s grid" << endl;
                    p1.print_guess_grid();

                }
            // increment round number
            round += 1;

        }
        // while loop exited, so one of these conditions is now true
        // p1 lost, announce p2 win
        if (p1.destroyed() == true) {
            cout << "Game over, winner is " << p2.get_name() << "in " << round << " rounds" << endl;
        } else if (p2.destroyed() == true) {
            cout << "Game over, winner is " << p1.get_name() << "in " << round << " rounds" << endl;
        } else {
            cout << "Game over, winner is no one in " << round << " rounds" << endl;
        }

    return;

}