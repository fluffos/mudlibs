// Last edited by deforce on 03-24-2010
// Yaynu @ red dragon Nov. 1995
#include <mudlib.h>

inherit CMD;

void main()
{
   mapping info = rusage();
   // time is in msec, convert to sec
   outf("CPU usage: %2.2f%%\n", (info["utime"] + info["stime"]) / (10.0 * uptime()));
}