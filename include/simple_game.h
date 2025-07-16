#pragma once


class Field
{
private:
    int m_columns = 0;
    int m_rows = 0;
    int** m_boss_array = nullptr;

public:
    Field();
    ~Field();

    void allocate(int _columns, int _rows);
    void clear();

    void print();

    void set_element(int _index_x, int _index_y, int _number);
    int get_element(int _index_x, int _index_y) const;
    int get_columns() const;
    int get_rows() const;

    bool is_out_of_field(int _index_x);

    void slide_field_down();

    void insert_barrier(const Field& _barrier, int _column_offset, int _row_offset);
};





