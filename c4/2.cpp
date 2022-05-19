#include <iostream>

class Arena
{
private:
    Item *arena;
    bool *used;
    size_t ssize;
public:
    Arena(const Arena&) = delete;
    Arena& operator=(const Arena&) = delete;

    explicit Arena(size_t size) : ssize(size / sizeof(Item)) {
        arena = new Item[ssize];
        used = new bool[ssize];
        for (size_t i = 0; i < ssize; ++i) {
            used[i] = false;
        }
    }

    Item *get() {
        for (size_t i = 0; i < ssize; ++i) {
            if (!used[i]) {
                used[i] = true;
                return arena + i;
            }
        }
        return nullptr;
    }

    void put(Item *item) {
        for (size_t i = 0; i < ssize; ++i) {
            if (arena + i == item) {
                used[i] = false;
                return;
            }
        }
    }

    ~Arena() {
        delete[] arena;
        delete[] used;
    }
};

