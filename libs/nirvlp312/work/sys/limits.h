#ifndef _sys_limits_h
#define _sys_limits_h

#define INT_MIN 0x80000000
#define INT_MAX 0x7FFFFFFF

#define MAX_COST        1000000       /* max eval cost */
#define MAX_READ        50000         /* MAX_BYTE_TRANSFER (read_bytes) and
                                       * READ_FILE_MAX_SIZE (read_file)     */
#define MAX_ARRAY_SIZE  INT_MAX
#define MAX_BITS        1200          /* max bit in a bit-string used by
                                       * set_bit/clear_bit/test_bit         */
#define MAX_PLAYERS     70
#define MAX_LOCAL       50            /* max number of local variables in
                                       * a function                         */
#define MAX_ALLOWED     (96*1048576)  /* 96MB */

#define TIME_TO_RESET   2700
#define TIME_TO_CLEAN_UP 10800

#endif /* _sys_limits_h */
