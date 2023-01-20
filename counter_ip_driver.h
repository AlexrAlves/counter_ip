#include <stdint.h>

void set_count(uint32_t data_in);
void reset_counter_on(void);
void reset_counter_off(void);
void load_counter_on(void);
void load_counter_off(void);
void enable_counter(void);
void disable_counter(void);
void get_count(uint32_t * count);