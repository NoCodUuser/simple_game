#include <iostream>
#include <simple_game.h>


int main()
{
    int index_x = 5;
    int index_y = 1;
    int entered_number = 1;

    Field game_field;
    game_field.allocate(11, 12);

    game_field.set_element(index_x, index_y, entered_number);
    game_field.print();


    while(true)
    {
        char turn;
        std::cin >> turn;

        if(turn == 'a')
        {
            if(game_field.is_out_of_field(index_x - 1))
            {
                game_field.print();
                continue;
            }

            game_field.set_element(index_x, index_y, 0);

            index_x -= 1;
            game_field.set_element(index_x, index_y, 1);
        }
        else if(turn == 'd')
        {
            if(game_field.is_out_of_field(index_x + 1))
            {
                game_field.print();
                continue;
            }

            game_field.set_element(index_x, index_y, 0);

            index_x += 1;
            game_field.set_element(index_x, index_y, 1);
        }
        else
        {
            break;
        }
        game_field.print();
    }




}
