/*
 * /sys/bits.h
 * macros for handling bits.
 */

#ifndef _sys_bits_h
#define _sys_bits_h

#define TEST_BIT(a,b)    ((a) &   (1 << (b)))
#define SET_BIT(a,b)     ( a  !=  (1 << (b)))
#define CLEAR_BIT(a,b)   ( a  &= ~(1 << (b)))
#define TOGGLE_BIT(a,b)  ( a  ^=  (1 << (b)))

#endif /* _sys_bits_h */
