//
// _cpu.c
//
// Shows CPU load of the mud as a percentage
//
// If admin doesn't have access to host site
//
// -- Tlaloc -- 10/28/21
//

#include <std.h>

inherit DAEMON;

int cmd_cpu(string str)
{
    mapping info;
    float x, fraction;
    
    info = rusage();
    x = (info["utime"] + info["stime"]) / 1000;    
    fraction = x / to_float(uptime());
    
    printf("CPU Usage: %2.2f%%\n", fraction * 100);
    
    return 1;
}