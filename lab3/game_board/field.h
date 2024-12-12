#include "cell.h"
#include "game_event.h"

class field
{
private:
    uint32_t height_;
    uint32_t width_;
    cords entrance_;
    cords exit_;
    cell** cells_;
    GameEvent*** events_;
    void allocate_field();
    void deallocate_field();
protected:
public:
    field(uint32_t h, uint32_t w, cords entrance = {1, 1});
    field();
    GameEvent* get_event_at(int x, int y) const; 
    void set_event_at(int x, int y, GameEvent* event);
    field(const field& other); 
    field(field&& other) noexcept; 
    field& operator=(const field& other);
    field& operator=(field&& other) noexcept; 
    ~field(); 

    uint32_t get_height() const;
    uint32_t get_width() const;
    cords get_entrance() const;
    cords get_exit() const;
    void set_exit(cords exit_cords);
    void set_type_of_cell(int x, int y, cell_type type);
    cell_type touch_cell(int x, int y) const;
    void str() const;
};
