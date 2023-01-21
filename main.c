#include <rt/rt_api.h>
#include "counter_ip_auto.h"
#include "counter_ip_driver.h"

int __rt_fpga_fc_frequency = 20000000; // e.g. 20000000 for 20MHz;
int __rt_fpga_periph_frequency = 10000000; // e.g. 10000000 for 10MHz;
unsigned int __rt_iodev_uart_baudrate = 9600;

int main()
{
    printf("\rCounter IP Test!\n\r");

    uint32_t count_in = 16;
    uint32_t * init_value; 
    uint32_t * count_val; 
    uint32_t * count_val2;
    
    get_count(init_value);

    printf("Initial Value: %d\n\r", *init_value);

    enable_counter();
    get_count(count_val);
    rt_time_wait_us(10000*1000);
    get_count(count_val2);
    disable_counter();

    printf("First reading: count = %d\n\r", *count_val);
    printf("Second reading: count = %d\n\r", *count_val2);

    get_count(count_val);

    printf("After disabling: count = %d\n\r", *count_val);
    printf("After disabling: count = %d\n\r", *count_val);

    reset_counter_on();
    reset_counter_off();

    return 0;
}