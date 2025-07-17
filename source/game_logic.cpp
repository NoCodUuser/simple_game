#include <cstdlib>

#include <game_logic.h>
#include <simple_game.h>


int calculate_random_x(int _field_columns_count, int _barrier_columns_count)
{
    int max_random_x = _field_columns_count - _barrier_columns_count + 1;
    int random_x = rand() % max_random_x;
    return random_x;
}

int calculate_position_y(int _lower_bound, int _upper_bound)
{
    int dif_y = _upper_bound - _lower_bound;
    int random_y = rand() % dif_y + _lower_bound;
    return random_y;
}

void on_player_move(int& _player_coord_x, int& _player_coord_y, int _player_marker, Field& _game_field, char _turn)
{
    _game_field.set_element(_player_coord_x, _player_coord_y, 0);
    if(_turn == 'a')
    {
        _player_coord_x -= 1;
    }
    else if(_turn == 'd')
    {
        _player_coord_x += 1;
    }
    _game_field.slide_field_down();
    _game_field.set_element(_player_coord_x, _player_coord_y, _player_marker);
}

