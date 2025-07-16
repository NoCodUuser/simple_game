#include <simple_game.h>
#include <iostream>


Field::Field()
{

}

Field::~Field()
{
    clear();
}


void Field::allocate(int _columns, int _rows)
{
    clear();
    m_boss_array = new int* [_columns];
    for(int  i = 0; i < _columns; ++i)
    {
        m_boss_array[i] = new int[_rows];

        for(int j = 0; j < _rows; ++j)
        {
            m_boss_array[i][j] = 0;
        }
    }
    m_columns = _columns;
    m_rows = _rows;
}

void Field::clear()
{
    for(int i = 0; i < m_columns; ++i)
    {
        delete m_boss_array[i];
    }
    delete[] m_boss_array;
    m_boss_array = nullptr;
    m_columns = 0;
    m_rows = 0;
}

void Field::set_element(int _index_x, int _index_y, int _number)
{
    m_boss_array[_index_x][_index_y] = _number;
}

int Field::get_element(int _index_x, int _index_y) const
{
    return m_boss_array[_index_x][_index_y];
}

int Field::get_columns() const
{
    return m_columns;
}
int Field::get_rows() const
{
    return m_rows;
}

void Field::print()
{
    for(int j = get_rows() - 1; j > -1; --j)
    {
        for(int i = 0; i < get_columns(); ++i)
        {
            std::cout << m_boss_array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Field::is_out_of_field(int _index_x)
{
    if(_index_x > m_columns - 1 || _index_x < 0)
    {
        return true;
    }
    return false;
}

void Field::insert_barrier(const Field& _barrier, int _column_offset, int _row_offset)
{
    for(int i = 0; i < _barrier.get_columns(); ++i)
    {
        for(int j = 0; j < _barrier.get_rows(); ++j)
        {
            int barrier_element = _barrier.get_element(i, j);
            set_element(i + _column_offset, j + _row_offset, barrier_element);

        }
    }
}

void Field::slide_field_down()
{
    for(int y = 0; y < m_rows - 1; ++y)
    {
        for(int x = 0; x < m_columns; ++x)
        {
            m_boss_array[x][y] = m_boss_array[x][y + 1];
        }
    }
    for(int x = 0; x < m_columns; ++x)
    {
        m_boss_array[x][m_rows - 1] = 0;
    }
}

