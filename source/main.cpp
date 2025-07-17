#include <iostream>

#include <simple_game.h>
#include <game_logic.h>


int main()
{
    int player_coord_x = 5;
    int player_coord_y = 1;
    int moves_counter = 0;

    const int player_marker = 1;
    const int moves_until_barrier = 4;

    Field game_field;
    game_field.allocate(11, 12);

    game_field.set_element(player_coord_x, player_coord_y, player_marker);

    Field barrier;
    barrier.allocate(2, 2);
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            barrier.set_element(i, j, 2);
        }
    }

    game_field.insert_barrier(barrier, 5, 9);
    game_field.print();

    while(true)
    {
        char turn;
        std::cin >> turn;

        if(turn == 'a')
        {
            if(game_field.is_out_of_field(player_coord_x - 1))
            {
                game_field.print();
                continue;
            }
            on_player_move(player_coord_x, player_coord_y, player_marker, game_field, turn);
        }
        else if(turn == 'd')
        {
            if(game_field.is_out_of_field(player_coord_x + 1))
            {
                game_field.print();
                continue;
            }
            on_player_move(player_coord_x, player_coord_y, player_marker, game_field, turn);
        }
        else
        {
            continue;
        }
        moves_counter += 1;
        if(moves_counter == moves_until_barrier)
        {
            int random_x = calculate_random_x(game_field.get_columns(), barrier.get_columns());
            int random_y = calculate_random_y(6, 9);

            game_field.insert_barrier(barrier, random_x, random_y);

            moves_counter = 0;
        }
        game_field.print();
    }
}
