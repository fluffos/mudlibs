#include <cmd.h>

#define LAGOMETER "/bin/daemons/lagometerd"

nomask int
lagometer_cmd(string str, object me)
{
    if (!me && !(me = this_player())) return 0;

    LAGOMETER->show_lagometer(me);
    return 1;
}
