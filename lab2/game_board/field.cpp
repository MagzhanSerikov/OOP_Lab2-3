#include "field.h"
#include <iostream>

void field::allocate_field()
{
    cells_ = new cell*[height_];
    for (uint32_t y = 0; y < height_; y++)
    {
        cells_[y] = new cell[width_];
    }
}

void field::deallocate_field()
{
    if (cells_)
    {
        for (uint32_t y = 0; y < height_; y++)
        {
            delete[] cells_[y];
        }
        delete[] cells_;
    }
}

field::field(uint32_t h, uint32_t w, cords entrance)
    : height_(h), width_(w), entrance_(entrance), exit_({-1, -1})
{
    allocate_field();
    for (uint32_t y = 0; y < height_; y++)
    {
        for (uint32_t x = 0; x < width_; x++)
        {
            if (x == 0 || y == 0 || x == width_ - 1 || y == height_ - 1)
                cells_[y][x].set_type(Barrier);
        }
    }
}

field::field() : field(50, 50, {1, 1}) {}

field::field(const field& other)
{
    height_ = other.height_;
    width_ = other.width_;
    entrance_ = other.entrance_;
    exit_ = other.exit_;
    allocate_field();
    for (uint32_t y = 0; y < height_; y++)
    {
        for (uint32_t x = 0; x < width_; x++)
        {
            cells_[y][x] = other.cells_[y][x];
        }
    }
}

field& field::operator=(const field& other)
{
    if (this != &other)
    {
        deallocate_field();
        height_ = other.height_;
        width_ = other.width_;
        entrance_ = other.entrance_;
        exit_ = other.exit_;
        allocate_field();
        for (uint32_t y = 0; y < height_; y++)
        {
            for (uint32_t x = 0; x < width_; x++)
            {
                cells_[y][x] = other.cells_[y][x];
            }
        }
    }
    return *this;
}

field::field(field&& other) noexcept
    : height_(other.height_), width_(other.width_), entrance_(other.entrance_), exit_(other.exit_), cells_(other.cells_)
{
    other.cells_ = nullptr;
}

field& field::operator=(field&& other) noexcept
{
    if (this != &other)
    {
        deallocate_field();
        height_ = other.height_;
        width_ = other.width_;
        entrance_ = other.entrance_;
        exit_ = other.exit_;
        cells_ = other.cells_;
        other.cells_ = nullptr;
    }
    return *this;
}

field::~field()
{
    deallocate_field();
}

uint32_t field::get_height() const
{
    return height_;
}

uint32_t field::get_width() const
{
    return width_;
}

cords field::get_entrance() const
{
    return entrance_;
}

cords field::get_exit() const
{
    return exit_;
}

void field::set_exit(cords exit_cords)
{
    exit_ = exit_cords;
    cells_[exit_cords.y_][exit_cords.x_].set_type(Exit);
}

void field::set_type_of_cell(int x, int y, cell_type type)
{
    cells_[y][x].set_type(type);
}

cell_type field::touch_cell(int x, int y) const
{
    return cells_[y][x].get_type();
}

void field::str() const
{
    for (uint32_t y = 0; y < height_; y++)
    {
        for (uint32_t x = 0; x < width_; x++)
        {
            std::cout << cells_[y][x].get_type() << ' ';
        }
        std::cout << '\n';
    }
}
