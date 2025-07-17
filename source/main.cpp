#include <iostream>

#include <simple_game.h>
#include <game_logic.h>


int main()
{
    int player_coord_x = 5;
    int player_coord_y = 1;
    int moves_counter = 1;
    int score_counter = 1;

    const int player_marker = 1;
    const int moves_until_barrier = 2;
    const int barriers_marker = 2;

    Field game_field;
    game_field.allocate(11, 9);

    game_field.set_element(player_coord_x, player_coord_y, player_marker);

    Field barriers[5];
    barriers[0].allocate(2, 2);
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            barriers[0].set_element(i, j, barriers_marker);
        }
    }

    barriers[1].allocate(3, 2);
    barriers[1].set_element(0, 0, barriers_marker);
    barriers[1].set_element(0, 1, barriers_marker);
    barriers[1].set_element(1, 0, barriers_marker);
    barriers[1].set_element(2, 0, barriers_marker);

    barriers[2].allocate(3, 3);
    barriers[2].set_element(1, 0, barriers_marker);
    barriers[2].set_element(0, 1, barriers_marker);
    barriers[2].set_element(1, 1, barriers_marker);
    barriers[2].set_element(2, 1, barriers_marker);
    barriers[2].set_element(1, 2, barriers_marker);

    barriers[3].allocate(3, 3);
    barriers[3].set_element(2 , 0, barriers_marker);
    barriers[3].set_element(2 , 1, barriers_marker);
    barriers[3].set_element(1 , 1, barriers_marker);
    barriers[3].set_element(1 , 2, barriers_marker);

    barriers[4].allocate(3, 2);
    barriers[4].set_element(2 , 0, barriers_marker);
    barriers[4].set_element(1 , 0, barriers_marker);
    barriers[4].set_element(0 , 1, barriers_marker);

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
            if(game_field.get_element(player_coord_x - 1, player_coord_y + 1) == barriers_marker)
            {
                std::cout << "game over" << std::endl;
                break;
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
            if(game_field.get_element(player_coord_x + 1, player_coord_y + 1) == barriers_marker)
            {
                break;
            }
            on_player_move(player_coord_x, player_coord_y, player_marker, game_field, turn);
        }
        else
        {
            continue;
        }
        moves_counter += 1;
        score_counter += 1;

        if(moves_counter == moves_until_barrier)
        {
            int random_barrier_index = rand() % 5;
            int random_x = calculate_random_x(game_field.get_columns(), barriers[random_barrier_index].get_columns());
            int position_y = game_field.get_rows() - barriers[random_barrier_index].get_rows();

            game_field.insert_barrier(barriers[random_barrier_index], random_x, position_y);

            moves_counter = 0;
        }
        game_field.print();
    }
    std::cout << "game over" << std::endl;
    std::cout << "your score: " << score_counter;
}
