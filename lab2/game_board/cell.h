#include "coordintaion.h"

enum cell_type {Floor, Barrier, Exit};

class cell
{
private:
    cell_type type_;
    cords tp_cords_;
protected:
public:
    cell(cell_type type = Floor, cords tp = {1, 1});
    void set_type(cell_type type);
    cell_type get_type() const;
    cords get_tp_cords() const;
};
