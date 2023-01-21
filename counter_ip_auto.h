// Generated register defines for counter_ip

#ifndef _COUNTER_IP_REG_DEFS_
#define _COUNTER_IP_REG_DEFS_

#ifdef __cplusplus
extern "C" {
#endif
// Register width
#define COUNTER_IP_PARAM_REG_WIDTH 32

// Common Interrupt Offsets

// Data to be loaded to the counter.
#define COUNTER_IP_DTIN(id) (COUNTER_IP##id##_BASE_ADDR + 0x0)
#define COUNTER_IP_DTIN_REG_OFFSET 0x0
#define COUNTER_IP_DTIN_DTIN_MASK 0xffff
#define COUNTER_IP_DTIN_DTIN_OFFSET 0

// Counter current value to be retrieved by software.
#define COUNTER_IP_CTOUT(id) (COUNTER_IP##id##_BASE_ADDR + 0x4)
#define COUNTER_IP_CTOUT_REG_OFFSET 0x4
#define COUNTER_IP_CTOUT_CTOUT_MASK 0xffff
#define COUNTER_IP_CTOUT_CTOUT_OFFSET 0

// Controls reset, load, and enable signal of the counter.
#define COUNTER_IP_CTRL(id) (COUNTER_IP##id##_BASE_ADDR + 0x8)
#define COUNTER_IP_CTRL_REG_OFFSET 0x8
#define COUNTER_IP_CTRL_RESET 0
#define COUNTER_IP_CTRL_LOAD 1
#define COUNTER_IP_CTRL_EN 2

#ifdef __cplusplus
}  // extern "C"
#endif
#endif  // _COUNTER_IP_REG_DEFS_
// End generated register defines for counter_ip
