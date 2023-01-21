#include "counter_ip_auto.h"
#include "counter_ip_driver.h"
#include <stdint.h>
#include <stdio.h>

uint32_t volatile ctrl_reg_sw = 0;

void set_count(uint32_t data_in)
{
    uint32_t volatile * data_in_reg_start = (uint32_t*)COUNTER_IP_DTIN(0);

    *data_in_reg_start = data_in;
}

void reset_counter_on(void)
{
    uint32_t volatile * ctrl_res_reg = (uint32_t*)COUNTER_IP_CTRL(0);

    uint32_t ctrl_old_value = ctrl_reg_sw;
    
    asm volatile ("": : : "memory");        //compiler barrier
    *ctrl_res_reg = ctrl_old_value | (1<<COUNTER_IP_CTRL_RESET);
    asm volatile ("": : : "memory");        //compiler barrier

    ctrl_reg_sw = ctrl_old_value | (1<<COUNTER_IP_CTRL_RESET);
}

void reset_counter_off(void)
{
    uint32_t volatile * ctrl_res_reg = (uint32_t*)COUNTER_IP_CTRL(0);

    uint32_t ctrl_old_value = ctrl_reg_sw;
    
    asm volatile ("": : : "memory");        //compiler barrier
    *ctrl_res_reg = ctrl_old_value & ~(1<<COUNTER_IP_CTRL_RESET);
    asm volatile ("": : : "memory");        //compiler barrier

    ctrl_reg_sw = ctrl_old_value & ~(1<<COUNTER_IP_CTRL_RESET);
}

void load_counter_on(void)
{
    uint32_t volatile * ctrl_ld_reg = (uint32_t*)COUNTER_IP_CTRL(0);

    uint32_t ctrl_old_value = ctrl_reg_sw;

    asm volatile ("": : : "memory");        //compiler barrier
    *ctrl_ld_reg = ctrl_old_value | (1<<COUNTER_IP_CTRL_LOAD);
    asm volatile ("": : : "memory");        //compiler barrier

    ctrl_reg_sw = ctrl_old_value | (1<<COUNTER_IP_CTRL_LOAD);
}

void load_counter_off(void)
{
    uint32_t volatile * ctrl_ld_reg = (uint32_t*)COUNTER_IP_CTRL(0);

    uint32_t ctrl_old_value = ctrl_reg_sw;

    asm volatile ("": : : "memory");        //compiler barrier
    *ctrl_ld_reg = ctrl_old_value & ~(1<<COUNTER_IP_CTRL_LOAD);
    asm volatile ("": : : "memory");        //compiler barrier

    ctrl_reg_sw = ctrl_old_value & ~(1<<COUNTER_IP_CTRL_LOAD);
}

void enable_counter(void)
{
    uint32_t volatile * ctrl_en_reg = (uint32_t*)COUNTER_IP_CTRL(0);

    uint32_t ctrl_old_value = ctrl_reg_sw;

    asm volatile ("": : : "memory");        //compiler barrier
    *ctrl_en_reg = ctrl_old_value | (1<<COUNTER_IP_CTRL_EN);
    asm volatile ("": : : "memory");        //compiler barrier

    ctrl_reg_sw = ctrl_old_value | (1<<COUNTER_IP_CTRL_EN);
}

void disable_counter(void)
{
    uint32_t volatile * ctrl_en_reg = (uint32_t*)COUNTER_IP_CTRL(0);

    uint32_t ctrl_old_value = ctrl_reg_sw;

    asm volatile ("": : : "memory");        //compiler barrier
    *ctrl_en_reg = ctrl_old_value & ~(1<<COUNTER_IP_CTRL_EN);
    asm volatile ("": : : "memory");        //compiler barr

    ctrl_reg_sw = ctrl_old_value & ~(1<<COUNTER_IP_CTRL_EN);
}

uint32_t get_count(void)
{
    uint32_t volatile * count_reg = (uint32_t*)COUNTER_IP_CTOUT(0);

    return *count_reg;
}
