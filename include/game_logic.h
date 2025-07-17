#include <simple_game.h>

int calculate_random_x(int _field_columns_count, int _barrier_columns_count);

int calculate_random_y(int _lower_bound, int _upper_bound);

void on_player_move(int& _player_coord_x, int& _player_coord_y, int _player_marker, Field& _game_field, char _turn);
