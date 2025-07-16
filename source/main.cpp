#include <iostream>
#include <simple_game.h>


int main()
{
    int player_x = 5;
    int player_y = 1;
    int moves_counter = 0;

    const int player_marker = 1;
    const int moves_until_barrier = 4;

    Field game_field;
    game_field.allocate(11, 12);

    game_field.set_element(player_x, player_y, player_marker);

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
            if(game_field.is_out_of_field(player_x - 1))
            {
                game_field.print();
                continue;
            }

            game_field.set_element(player_x, player_y, 0);

            player_x -= 1;

            game_field.slide_field_down();

            game_field.set_element(player_x, player_y, player_marker);
        }
        else if(turn == 'd')
        {
            if(game_field.is_out_of_field(player_x + 1))
            {
                game_field.print();
                continue;
            }

            game_field.set_element(player_x, player_y, 0);

            player_x += 1;

            game_field.slide_field_down();

            game_field.set_element(player_x, player_y, player_marker);
        }
        else
        {
            continue;
        }

        moves_counter += 1;
        if(moves_counter == moves_until_barrier)
        {
            int max_random_x = game_field.get_columns() - barrier.get_columns() + 1;
            int random_x = rand() % max_random_x;
            int dif_y = 9 - 6;
            int random_y = rand() % dif_y + 6;

            game_field.insert_barrier(barrier, random_x, random_y);
            moves_counter = 0;
        }
        game_field.print();
    }
}
