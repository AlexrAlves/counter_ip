#include <stdio.h>
#include "pulp.h"

int main()
{
    printf("Counter IP Test!\n");

    uint32_t count_in = 16;
    uint32_t init_value, count_val, count_val2;
    
    get_count(init_value);

    printf("Initial Value: %d\n", init_value);

    enable_counter();
    get_count(count_val);
    get_count(count_val2);
    disable_counter();

    printf("First reading: count = %d\n", count_val);
    printf("Second reading: count = %d\n", count_val2);

    get_count(count_val);

    printf("After disabling: count = %d\n", count_val);
    printf("After disabling: count = %d\n", count_val);

    return 0;
}