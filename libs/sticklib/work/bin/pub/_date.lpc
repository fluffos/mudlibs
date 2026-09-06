#include <cmd.h>

varargs nomask int
date_cmd(string str, object me)
{
    if (!me && !(me = TP)) return 0;

    me->force_us((str ? "uptime " + str : "uptime"));
    return 1;
}
