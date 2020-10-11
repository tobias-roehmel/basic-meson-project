#include "example_folder_include.h"

uint32_t add_two(uint32_t value) {
    #if EXAMPLE_DEF
        return value + 2;
    #else
        return value + 3;
    #endif
}
