#include <rt/rt_api.h>
#include "counter_ip_auto.h"
#include "counter_ip_driver.h"

int __rt_fpga_fc_frequency = 20000000; // e.g. 20000000 for 20MHz;
int __rt_fpga_periph_frequency = 10000000; // e.g. 10000000 for 10MHz;
unsigned int __rt_iodev_uart_baudrate = 115200;

int main()
{
    uint32_t count_in = 16;
    uint32_t count_val1, count_val2, count_val3, count_val4, count_val5;
    uint32_t count_for[10];
    
    printf("\n\r#####################################################\n\r");
    printf("\rCOUNTER IP TEST!\n\r");
    printf("#####################################################\n\r");

    printf("Getting counter initial value!\n\r");
    printf("--------------------------------------------------\n\n\r");

    printf("Initial Value: %d\n\r", get_count());

    printf("--------------------------------------------------\n\n\r");

    printf("Enabling counter and getting five readings!\n\r");
    printf("--------------------------------------------------\n\n\r");

    enable_counter();

    count_val1 = get_count();
    count_val2 = get_count();
    count_val3 = get_count();
    count_val4 = get_count();
    count_val5 = get_count();

    printf("First reading: count = %d\n\r", count_val1);
    printf("Second reading: count = %d\n\r", count_val2);
    printf("Third reading: count = %d\n\r", count_val3);
    printf("Fourth reading: count = %d\n\r", count_val4);
    printf("Fifth reading: count = %d\n\r", count_val5);

    printf("--------------------------------------------------\n\n\r");

    printf("Reseting counter (Reset bit high)!\n\r");
    printf("--------------------------------------------------\n\n\r");

    reset_counter_on();

    printf("Count value after reseting: count = %d\n\r", get_count());

    printf("Count value reset bit still high: count = %d\n\r", get_count());

    printf("Count value reset bit still high: count = %d\n\r", get_count());

    printf("--------------------------------------------------\n\n\r");

    printf("Setting reset bit to low!\n\r");
    printf("--------------------------------------------------\n\n\r");

    reset_counter_off();

    printf("Count value reset bit low: count = %d\n\r", get_count());

    printf("--------------------------------------------------\n\n\r");

    printf("For loop counting!\n\r");
    printf("--------------------------------------------------\n\n\r");

    for(uint32_t i = 0; i<10; i++)
    {
        count_for[i] = get_count();
    };

    for(uint32_t i = 0; i<10; i++)
    {
        printf("For loop reading(%d): count = %d\n\r", i, count_for[i]);
    };

    printf("--------------------------------------------------\n\n\r");

    printf("Disabling counter (enable bit low)!\n\r");
    printf("--------------------------------------------------\n\n\r");

    disable_counter();

    printf("Count value after disabling: count = %d\n\r", get_count());
    printf("Count value after disabling: count = %d\n\r", get_count());
    printf("Count value after disabling: count = %d\n\r", get_count());

    printf("--------------------------------------------------\n\n\r");

    printf("Loading data (count value %d) to the counter!\n\r", count_in);
    printf("--------------------------------------------------\n\n\r");

    load_counter_on();
    set_count(count_in);
    load_counter_off();

    printf("Count value after loading: count = %d\n\r", get_count());
    printf("Count value after loading: count = %d\n\r", get_count());
    printf("Count value after loading: count = %d\n\r", get_count());

    printf("--------------------------------------------------\n\n\r");

    printf("Enabling counter (enable bit high)!\n\r");
    printf("--------------------------------------------------\n\n\r");

    enable_counter();

    printf("Count value after enabling: count = %d\n\r", get_count());

    printf("--------------------------------------------------\n\n\r");

    for(uint32_t i = 0; i<10; i++)
    {

    };

    printf("Reseting and Finishing!\n\r");
    printf("--------------------------------------------------\n\n\r");

    disable_counter();
    reset_counter_on();
    reset_counter_off();

    printf("Final value: count = %d\n\r", get_count());

    printf("#####################################################\n\n\r");

    return 0;
}
