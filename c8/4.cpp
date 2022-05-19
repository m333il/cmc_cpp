#include <cmath>
#include <algorithm>

namespace Game
{
    template <typename T>
    class Coord 
    {
    public:
        T row, col;
        typedef T value_type;
        Coord(T row = T{}, T col = T{}) : row(row), col(col) {}
    };

    template <typename T>
    T dist(Coord<T> field, Coord<T> x, Coord<T> y) {
        T r1 = x.row - (x.col + (x.col & 1)) / 2;
        T r2 = y.row - (y.col + (y.col & 1)) / 2;
        T d_col = abs(x.col - y.col);
        T t1 = abs(x.col + r1 - y.col - r2);
        T t2 = abs(r1 - r2);
        return (d_col + t1 + t2) / 2;
    }
}