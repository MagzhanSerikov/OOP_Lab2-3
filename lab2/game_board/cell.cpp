#include "cell.h"

cell::cell(cell_type type, cords tp) : type_(type), tp_cords_(tp) {}

void cell::set_type(cell_type type)
{
    type_ = type;
}

cell_type cell::get_type() const
{
    return type_;
}

cords cell::get_tp_cords() const
{
    return tp_cords_;
}
